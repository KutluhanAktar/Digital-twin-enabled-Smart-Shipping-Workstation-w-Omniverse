         /////////////////////////////////////////////  
        //  Digital twin-enabled Smart Shipping    //
       //       Workstation w/ Omniverse          //
      //           ----------------              //
     //          (Arduino Nano Matter)          //           
    //             by Kutluhan Aktar           // 
   //                                         //
  /////////////////////////////////////////////

//
// Exploring the digital twin synthetic data generation and AI-oriented advancements on real-world shipping operations w/ NVIDIA Omniverse.
//
// For more information:
// https://www.hackster.io/kutluhan-aktar
//
//
// Connections
// Arduino Nano Matter :
//                                Nema 17 (17HS3401) Stepper Motor w/ A4988 Driver Module [Motor 1]
// 3.3V    ------------------------ VDD
// GND     ------------------------ GND
// D2      ------------------------ DIR
// D3      ------------------------ STEP
//                                Nema 17 (17HS3401) Stepper Motor w/ A4988 Driver Module [Motor 2]
// 3.3V    ------------------------ VDD
// GND     ------------------------ GND
// D4      ------------------------ DIR
// D5      ------------------------ STEP
//                                Nema 17 (17HS3401) Stepper Motor w/ A4988 Driver Module [Motor 3]
// 3.3V    ------------------------ VDD
// GND     ------------------------ GND
// D6      ------------------------ DIR
// D7      ------------------------ STEP
//                                Nema 17 (17HS3401) Stepper Motor w/ A4988 Driver Module [Motor 4]
// 3.3V    ------------------------ VDD
// GND     ------------------------ GND
// D8      ------------------------ DIR
// D9      ------------------------ STEP
//                                Tiny (Embedded) Thermal Printer
// D0/TX1  ------------------------ RX
// D1/RX1  ------------------------ TX
// GND     ------------------------ GND
//                                SSD1306 OLED Display (128x64)
// A4/SDA  ------------------------ SDA
// A5/SCL  ------------------------ SCL
//                                Infrared (IR) Break-beam Sensor [Receiver]
// A6      ------------------------ Signal
//                                Control Button (A)
// A0      ------------------------ +
//                                Control Button (B)
// A1      ------------------------ +
//                                Control Button (C)
// A2      ------------------------ +
//                                Micro Switch with Pulley [First]
// A3      ------------------------ +
//                                Micro Switch with Pulley [Second]
// A7      ------------------------ +
//                                5mm Common Anode RGB LED
// D10     ------------------------ R
// D11     ------------------------ G
// D12     ------------------------ B


// Include the required libraries:
#include <Wire.h>
#include "Adafruit_Thermal.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Add the icons to be shown on the SSD1306 OLED display.
#include "logo.h"

/*#########################################################
  Program the required functions and configurations for establishing the BLE data transmission with Nano Matter.
  Since Nano Matter is powered by the MGM240S (32-bit Arm® Cortex®-M33) from Silicon Labs, the connection settings differ from other BLE-oriented Arduino boards.
#########################################################*/

// Define the essential BLE data parameters and configurations by creating a struct — ble_data.
struct ble_data{
  uint8_t default_char_init_value = 0;
};
struct ble_data ble_data;

// Declare the BLE service parameters, including the local name this peripheral advertises.
static const uint8_t advertised_device_name[] = "Shipping Workstation";
static uint16_t      gattdb_session_id;
static uint16_t      generic_access_service_handle;
static uint16_t      device_name_characteristic_handle;
static uint16_t      device_main_service_handle;

// Declare data characteristics for the defined BLE service.
static uint16_t order_tag_a_characteristic_handle, order_tag_b_characteristic_handle, order_tag_c_characteristic_handle, order_tag_d_characteristic_handle;
static uint16_t workstation_control_characteristic_handle;
static uint16_t station_status_characteristic_handle, product_status_characteristic_handle;

// Declare a function to initialize the GATT database of this device, create a new GATT session, and add given services with data characteristics.
static void ble_initialize_gatt_db(){
  sl_status_t sc;
  // Create a new GATT database.
  sc = sl_bt_gattdb_new_session(&gattdb_session_id);
  app_assert_status(sc);

  // Add the Generic Access service to the GATT DB.
  const uint8_t generic_access_service_uuid[] = { 0x00, 0x18 };
  sc = sl_bt_gattdb_add_service(gattdb_session_id,
                                sl_bt_gattdb_primary_service,
                                SL_BT_GATTDB_ADVERTISED_SERVICE,
                                sizeof(generic_access_service_uuid),
                                generic_access_service_uuid,
                                &generic_access_service_handle);
  app_assert_status(sc);

  // By adding the device name characteristic to the Generic Access service, set the advertised local device name.
  const sl_bt_uuid_16_t device_name_characteristic_uuid = { .data = { 0x00, 0x2A } };
  sc = sl_bt_gattdb_add_uuid16_characteristic(gattdb_session_id,
                                              generic_access_service_handle,
                                              SL_BT_GATTDB_CHARACTERISTIC_READ,
                                              0x00,
                                              0x00,
                                              device_name_characteristic_uuid,
                                              sl_bt_gattdb_fixed_length_value,
                                              sizeof(advertised_device_name) - 1,
                                              sizeof(advertised_device_name) - 1,
                                              advertised_device_name,
                                              &device_name_characteristic_handle);
  app_assert_status(sc);

  // Initiate the Generic Access service.
  sc = sl_bt_gattdb_start_service(gattdb_session_id, generic_access_service_handle);
  app_assert_status(sc);

  /*
    NOTE: As required by the Silicon Labs BLE protocol stack [BLE (Silabs)], to add services and data characteristics, the UUID arrays must start with the least significant bit (LSB) from left to right.
  */

  // To add the main device service to the GATT DB, set the main service UUID. 
  // Service UUID: 9485c88d-cae7-43c6-9013-16d456e05bf6
  const uuid_128 blinky_service_uuid = {
    .data = { 0xf6, 0x5b, 0xe0, 0x56, 0xd4, 0x16, 0x13, 0x90, 0xc6, 0x43, 0xe7, 0xca, 0x8d, 0xc8, 0x85, 0x94 }
  };
  sc = sl_bt_gattdb_add_service(gattdb_session_id,
                                sl_bt_gattdb_primary_service,
                                SL_BT_GATTDB_ADVERTISED_SERVICE,
                                sizeof(blinky_service_uuid),
                                blinky_service_uuid.data,
                                &device_main_service_handle);
  app_assert_status(sc);
  
  // Add the order tag data characteristics (divided into four parts) to the main device service.
  // UUID: 9486c88d-cae7-43c6-9013-16d456e05bf6
  const uuid_128 order_tag_a_characteristic_uuid = {
    .data = { 0xf6, 0x5b, 0xe0, 0x56, 0xd4, 0x16, 0x13, 0x90, 0xc6, 0x43, 0xe7, 0xca, 0x8d, 0xc8, 0x86, 0x94 }
  };
  sc = sl_bt_gattdb_add_uuid128_characteristic(gattdb_session_id,
                                               device_main_service_handle,
                                               SL_BT_GATTDB_CHARACTERISTIC_READ | SL_BT_GATTDB_CHARACTERISTIC_WRITE,
                                               0x00,
                                               0x00,
                                               order_tag_a_characteristic_uuid,
                                               sl_bt_gattdb_fixed_length_value,
                                               1,                                                // max length
                                               sizeof(ble_data.default_char_init_value),         // initial value length
                                               &ble_data.default_char_init_value,                // initial value
                                               &order_tag_a_characteristic_handle);
  // UUID: 9487c88d-cae7-43c6-9013-16d456e05bf6
  const uuid_128 order_tag_b_characteristic_uuid = {
    .data = { 0xf6, 0x5b, 0xe0, 0x56, 0xd4, 0x16, 0x13, 0x90, 0xc6, 0x43, 0xe7, 0xca, 0x8d, 0xc8, 0x87, 0x94 }
  };
  sc = sl_bt_gattdb_add_uuid128_characteristic(gattdb_session_id,
                                               device_main_service_handle,
                                               SL_BT_GATTDB_CHARACTERISTIC_READ | SL_BT_GATTDB_CHARACTERISTIC_WRITE,
                                               0x00,
                                               0x00,
                                               order_tag_b_characteristic_uuid,
                                               sl_bt_gattdb_fixed_length_value,
                                               1,                                                // max length
                                               sizeof(ble_data.default_char_init_value),         // initial value length
                                               &ble_data.default_char_init_value,                // initial value
                                               &order_tag_b_characteristic_handle);
  // UUID: 9488c88d-cae7-43c6-9013-16d456e05bf6
  const uuid_128 order_tag_c_characteristic_uuid = {
    .data = { 0xf6, 0x5b, 0xe0, 0x56, 0xd4, 0x16, 0x13, 0x90, 0xc6, 0x43, 0xe7, 0xca, 0x8d, 0xc8, 0x88, 0x94 }
  };
  sc = sl_bt_gattdb_add_uuid128_characteristic(gattdb_session_id,
                                               device_main_service_handle,
                                               SL_BT_GATTDB_CHARACTERISTIC_READ | SL_BT_GATTDB_CHARACTERISTIC_WRITE,
                                               0x00,
                                               0x00,
                                               order_tag_c_characteristic_uuid,
                                               sl_bt_gattdb_fixed_length_value,
                                               1,                                                // max length
                                               sizeof(ble_data.default_char_init_value),         // initial value length
                                               &ble_data.default_char_init_value,                // initial value
                                               &order_tag_c_characteristic_handle);
  // UUID: 9489c88d-cae7-43c6-9013-16d456e05bf6
  const uuid_128 order_tag_d_characteristic_uuid = {
    .data = { 0xf6, 0x5b, 0xe0, 0x56, 0xd4, 0x16, 0x13, 0x90, 0xc6, 0x43, 0xe7, 0xca, 0x8d, 0xc8, 0x89, 0x94 }
  };
  sc = sl_bt_gattdb_add_uuid128_characteristic(gattdb_session_id,
                                               device_main_service_handle,
                                               SL_BT_GATTDB_CHARACTERISTIC_READ | SL_BT_GATTDB_CHARACTERISTIC_WRITE,
                                               0x00,
                                               0x00,
                                               order_tag_d_characteristic_uuid,
                                               sl_bt_gattdb_fixed_length_value,
                                               1,                                                // max length
                                               sizeof(ble_data.default_char_init_value),         // initial value length
                                               &ble_data.default_char_init_value,                // initial value
                                               &order_tag_d_characteristic_handle);
  // Add the workstation control characteristic to the main device service.
  // UUID: 9490c88d-cae7-43c6-9013-16d456e05bf6
  const uuid_128 workstation_control_characteristic_uuid = {
    .data = { 0xf6, 0x5b, 0xe0, 0x56, 0xd4, 0x16, 0x13, 0x90, 0xc6, 0x43, 0xe7, 0xca, 0x8d, 0xc8, 0x90, 0x94 }
  };
  sc = sl_bt_gattdb_add_uuid128_characteristic(gattdb_session_id,
                                               device_main_service_handle,
                                               SL_BT_GATTDB_CHARACTERISTIC_READ | SL_BT_GATTDB_CHARACTERISTIC_WRITE,
                                               0x00,
                                               0x00,
                                               workstation_control_characteristic_uuid,
                                               sl_bt_gattdb_fixed_length_value,
                                               1,                                                // max length
                                               sizeof(ble_data.default_char_init_value),         // initial value length
                                               &ble_data.default_char_init_value,                // initial value
                                               &workstation_control_characteristic_handle);                                                                                                                                                                                              

  // Add the station status and product characteristics to the main device service to notify the remote GATT client (central device) over BLE.
  // UUID: 9491c88d-cae7-43c6-9013-16d456e05bf6
  const uuid_128 station_status_characteristic_uuid = {
    .data = { 0xf6, 0x5b, 0xe0, 0x56, 0xd4, 0x16, 0x13, 0x90, 0xc6, 0x43, 0xe7, 0xca, 0x8d, 0xc8, 0x91, 0x94 }
  };
  sc = sl_bt_gattdb_add_uuid128_characteristic(gattdb_session_id,
                                               device_main_service_handle,
                                               SL_BT_GATTDB_CHARACTERISTIC_READ | SL_BT_GATTDB_CHARACTERISTIC_NOTIFY,
                                               0x00,
                                               0x00,
                                               station_status_characteristic_uuid,
                                               sl_bt_gattdb_fixed_length_value,
                                               1,                                                // max length
                                               sizeof(ble_data.default_char_init_value),         // initial value length
                                               &ble_data.default_char_init_value,                // initial value
                                               &station_status_characteristic_handle);
  // UUID: 9492c88d-cae7-43c6-9013-16d456e05bf6
  const uuid_128 product_status_characteristic_uuid = {
    .data = { 0xf6, 0x5b, 0xe0, 0x56, 0xd4, 0x16, 0x13, 0x90, 0xc6, 0x43, 0xe7, 0xca, 0x8d, 0xc8, 0x92, 0x94 }
  };
  sc = sl_bt_gattdb_add_uuid128_characteristic(gattdb_session_id,
                                               device_main_service_handle,
                                               SL_BT_GATTDB_CHARACTERISTIC_READ | SL_BT_GATTDB_CHARACTERISTIC_NOTIFY,
                                               0x00,
                                               0x00,
                                               product_status_characteristic_uuid,
                                               sl_bt_gattdb_fixed_length_value,
                                               1,                                                // max length
                                               sizeof(ble_data.default_char_init_value),         // initial value length
                                               &ble_data.default_char_init_value,                // initial value
                                               &product_status_characteristic_handle);                                               

  // Initiate the main device service.
  sc = sl_bt_gattdb_start_service(gattdb_session_id, device_main_service_handle);
  app_assert_status(sc);

  // Then, commit the GATT DB updates.
  sc = sl_bt_gattdb_commit(gattdb_session_id);
  app_assert_status(sc);
}

// Declare a function to start the BLE advertisement and configure advertisement parameters.
static void ble_start_advertising(){
  static uint8_t advertising_set_handle = 0xff;
  static bool init = true;
  sl_status_t sc;
  
  // For once, create an advertising set and configure the advertising interval as 100ms.
  if (init){    
    sc = sl_bt_advertiser_create_set(&advertising_set_handle);
    app_assert_status(sc);

    sc = sl_bt_advertiser_set_timing(
      advertising_set_handle,
      160,   // minimum advertisement interval (milliseconds * 1.6)
      160,   // maximum advertisement interval (milliseconds * 1.6)
      0,     // advertisement duration
      0);    // maximum number of advertisement events
    app_assert_status(sc);

    init = false;
  }

  // Generate the advertising information packet.
  sc = sl_bt_legacy_advertiser_generate_data(advertising_set_handle, sl_bt_advertiser_general_discoverable);
  app_assert_status(sc);

  // Start advertising and enable BLE connections.
  sc = sl_bt_legacy_advertiser_start(advertising_set_handle, sl_bt_advertiser_connectable_scannable);
  app_assert_status(sc);
}
/*#########################################################
  BLE Configuration Completed!
#########################################################*/

// Define the thermal printer object for passing commands through the hardware serial port of Nano Matter — Serial1.
Adafruit_Thermal printer(&Serial1);

// Define the SSD1306 OLED screen settings:
#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define OLED_RESET    -1  // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Define the signal pin of the IR break-beam sensor receiver.
#define IR_receiver       A6

// Define the control button pins.
#define control_button_A  A0
#define control_button_B  A1
#define control_button_C  A2

// Define the calibration micro switch pins.
#define f_calibration_switch  A3
#define s_calibration_switch  A7

// Define the RGB LED pins.
#define red_pin           10
#define green_pin         11
#define blue_pin          12

// Define the required stepper motor (w/ A4988 driver) configurations by creating a struct — stepper_config.
struct stepper_config{
  int _pins[4][2] = {{2, 3}, {4, 5}, {6, 7}, {8, 9}}; // (DIR, STEP)
  // Assign the required revolution and speed variables per stepper motor.
  int stepsPerRevolution[4] = {36, 64, 100, 50};
  int assigned_speed[4] = {16000, 12000, 12000, 1000};
  // Define stepper motor homing configurations.
  int home_step_number[4] = {1, 1, 3, 1};
  // Assign stepper motor tasks based on the associated part.
  int platform_first_rotation = 1;
  int platform_second_rotation = 2;
  int carrier_direction = 3;
  int carrier_arm = 4;
};

// Define the data holders:
struct stepper_config stepper_config;
String passed_order_tag = "";
String homing_confirmation_msg = "";
volatile boolean order_tag_transfer_completed = false;
volatile boolean homing_sequence_start = false;
int on_device_stepper_control = 0;
int active_task = 0;

void setup(){
  Serial.begin(115200);

	// Activate the given stepper motor DIR and STEP pins connected to the A4988 driver module. 
  for(int i = 0; i < 4; i++){ pinMode(stepper_config._pins[i][0], OUTPUT); pinMode(stepper_config._pins[i][1], OUTPUT); }
  
  // Register pin configurations.
  pinMode(IR_receiver, INPUT_PULLUP);
  pinMode(control_button_A, INPUT_PULLUP); pinMode(control_button_B, INPUT_PULLUP); pinMode(control_button_C, INPUT_PULLUP);
  pinMode(f_calibration_switch, INPUT_PULLUP); pinMode(s_calibration_switch, INPUT_PULLUP);
  pinMode(red_pin, OUTPUT); pinMode(green_pin, OUTPUT); pinMode(blue_pin, OUTPUT);
  adjustColor(0,0,0);  

  // Initiate the serial communication between the thermal printer and Nano Matter.
  Serial1.begin(9600);
  // Initialize the thermal printer data transmission.
  printer.begin();
  delay(2000);

  // Initialize the SSD1306 OLED screen.
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(1000);  
}

void loop(){
  // Depending on the ongoing operation, display the associated interface on the SSD1306 screen and activate the manual stepper motor controls.
  if(!order_tag_transfer_completed){
    if(!homing_sequence_start){
      // Select a stepper motor incrementally by pressing the control button B.
      if(!digitalRead(control_button_B)){   
        on_device_stepper_control++;
        if(on_device_stepper_control > 4) on_device_stepper_control = 0;
        delay(1000);
      }
      // By utilizing the control buttons (A and C), alter the position of the selected stepper motor.
      if(!digitalRead(control_button_A)) stepper_move(on_device_stepper_control, 1, 1, "CW");
      if(!digitalRead(control_button_C)) stepper_move(on_device_stepper_control, 1, 1, "CCW");

      show_interface("main", on_device_stepper_control);
    }else{
      show_interface("homing", 0);
    }
  }else{
    show_interface("task_activated", active_task);
  }
}

/***
  This function is called when an event happens on the BLE protocol stack.
  Thus, it handles all incoming and outgoing BLE procedures while transferring or receiving data packets.

  @param[in] evt BLE protocol stack event
***/
void sl_bt_on_event(sl_bt_msg_t *evt){
  // As a BLE stack event is triggered:
  switch (SL_BT_MSG_ID(evt->header)) {
    // Check the BLE service and radio initialization status.
    // NOTE: BLE stack commands do not work before receiving this boot event!
    case sl_bt_evt_system_boot_id:
      Serial.println("BLE (Silabs) protocol stack => Booted");
      // Initialize the defined (device-specific) GATT table.
      ble_initialize_gatt_db();
      // Then, start advertising.
      ble_start_advertising();
      Serial.println("BLE initialization is successful!\n");
    break;
    
    // Check for a new BLE connection.
    case sl_bt_evt_connection_opened_id:
      Serial.println("BLE connection => Established\n");
    break;

    // Check for a disconnected BLE connection.
    case sl_bt_evt_connection_closed_id:
      Serial.println("\nBLE connection => Disconnected");
      // Restart the BLE advertisement.
      ble_start_advertising();
      Serial.println("BLE advertisement => Restarted\n");
    break;

    // Assign event handlers for the data characteristics in the local GATT database modified (written) by the central device (remote GATT client) via the Android application.
    // In this regard, obtain the transferred (written) data packets from the Android application over BLE.
    case sl_bt_evt_gatt_server_attribute_value_id:
      if(workstation_control_characteristic_handle == evt->data.evt_gatt_server_attribute_value.attribute){
        // If the received data packet is not empty, obtain the transmitted byte.
        if (evt->data.evt_gatt_server_attribute_value.value.len == 0) break;
        // According to the received command, activate the requested workstation task.
        uint8_t command = evt->data.evt_gatt_server_attribute_value.value.data[0];
        if(command == 10){
          // Swivel the first platform by 60 degrees to position the subsequent product under the camera.
          stepper_move(stepper_config.platform_first_rotation, 1, 1, "CW");
          Serial.println("New product positioned successfully!");
          // After completing the given task, inform the central device (remote GATT client) over BLE via the Android application.
          update_BLE_characteristics(product_status_characteristic_handle, 20); active_task = 1;
        }else if(command == 11){
          /***
            Note: After completing each assigned task, inform the central device (remote GATT client) over BLE via the Android application.
          ***/
          // Swivel the first platform by 180 degrees to prepare the requested product for transportation.
          stepper_move(stepper_config.platform_first_rotation, 2, 1, "CCW");
          update_BLE_characteristics(product_status_characteristic_handle, 21); active_task = 2;
          // Bring the carrier near the first platform.
          stepper_move(stepper_config.carrier_direction, 2, 1, "CW");
          // Adjust the carrier arm to pull the ordered product.
          stepper_move(stepper_config.carrier_arm, 3, 1, "CCW");
          // Move the carrier to the road midpoint while transporting the ordered product.
          stepper_move(stepper_config.carrier_direction, 5, 1, "CCW");
          // Rearrange the carrier position to place the ordered product to the front.
          stepper_move(stepper_config.carrier_arm, 1, 1, "CW");
          stepper_move(stepper_config.carrier_direction, 6, 1, "CW");
          // Adjust the carrier arm to push the ordered product.
          stepper_move(stepper_config.carrier_arm, 3, 1, "CW");
          update_BLE_characteristics(product_status_characteristic_handle, 22); active_task = 3;
          // Move the carrier to the second platform.
          stepper_move(stepper_config.carrier_direction, 5, 1, "CCW");
          // After transporting the product successfully, return the carrier to its default position.
          stepper_move(stepper_config.carrier_direction, 3, 1, "CW");
          stepper_move(stepper_config.carrier_arm, 1, 1, "CCW");
          // Finally, swivel the second platform by 180 degrees to present the retrieved product.
          stepper_move(stepper_config.platform_second_rotation, 2, 1, "CW");
          update_BLE_characteristics(product_status_characteristic_handle, 23); active_task = 4;
          delay(6000);
          stepper_move(stepper_config.platform_second_rotation, 2, 1, "CCW");
          // After retrieving the ordered product successfully, activate the thermal printer to print the order (shipping) receipt.
          if(order_tag_transfer_completed){
            thermal_printer_commit("receipt");
            update_BLE_characteristics(product_status_characteristic_handle, 24); active_task = 5; show_interface("task_activated", active_task);
            // Release the latest registered order tag.
            order_tag_transfer_completed = false;
            passed_order_tag = "";
            delay(500);
          }
        }else if(command == 30){
          /***
            Note: After completing each assigned task, inform the central device (remote GATT client) over BLE via the Android application.
          ***/          
          // Initiate the homing sequence for the shipping workstation, which employs the specifically positioned switches.
          homing_sequence_start = true; show_interface("homing", 0);
          homing_confirmation_msg = stepper_homing_sequence(stepper_config.platform_first_rotation, IR_receiver, 1, "CCW");
          if(homing_confirmation_msg == "homing_completed_" + String(stepper_config.platform_first_rotation)){ update_BLE_characteristics(station_status_characteristic_handle, 31); delay(2000); }
          homing_confirmation_msg = stepper_homing_sequence(stepper_config.platform_second_rotation, f_calibration_switch, 1, "CCW");
          if(homing_confirmation_msg == "homing_completed_" + String(stepper_config.platform_second_rotation)){ update_BLE_characteristics(station_status_characteristic_handle, 32); delay(2000); }
          homing_confirmation_msg = stepper_homing_sequence(stepper_config.carrier_direction, s_calibration_switch, 1, "CCW");
          if(homing_confirmation_msg == "homing_completed_" + String(stepper_config.carrier_direction)){ update_BLE_characteristics(station_status_characteristic_handle, 33); delay(5000); homing_sequence_start = false; }
        }
      }else if(order_tag_a_characteristic_handle == evt->data.evt_gatt_server_attribute_value.attribute){
        // If the received data packet is not empty, obtain the transmitted byte.
        if (evt->data.evt_gatt_server_attribute_value.value.len == 0) break;
        // As separately transferred over BLE by the Android application, register the first part of the passed order (shipping) tag.
        uint8_t received_data = evt->data.evt_gatt_server_attribute_value.value.data[0];
        if(!order_tag_transfer_completed) passed_order_tag = passed_order_tag + String(received_data);
      }else if(order_tag_b_characteristic_handle == evt->data.evt_gatt_server_attribute_value.attribute){
        // If the received data packet is not empty, obtain the transmitted byte.
        if (evt->data.evt_gatt_server_attribute_value.value.len == 0) break;
        // As separately transferred over BLE by the Android application, register the second part of the passed order (shipping) tag.
        uint8_t received_data = evt->data.evt_gatt_server_attribute_value.value.data[0];
        if(!order_tag_transfer_completed) passed_order_tag = passed_order_tag + String(received_data);
      }else if(order_tag_c_characteristic_handle == evt->data.evt_gatt_server_attribute_value.attribute){
        // If the received data packet is not empty, obtain the transmitted byte.
        if (evt->data.evt_gatt_server_attribute_value.value.len == 0) break;
        // As separately transferred over BLE by the Android application, register the third part of the passed order (shipping) tag.
        uint8_t received_data = evt->data.evt_gatt_server_attribute_value.value.data[0];
        if(!order_tag_transfer_completed) passed_order_tag = passed_order_tag + String(received_data);
      }else if(order_tag_d_characteristic_handle == evt->data.evt_gatt_server_attribute_value.attribute){
        // If the received data packet is not empty, obtain the transmitted byte.
        if (evt->data.evt_gatt_server_attribute_value.value.len == 0) break;
        // As separately transferred over BLE by the Android application, register the fourth part of the passed order (shipping) tag.
        uint8_t received_data = evt->data.evt_gatt_server_attribute_value.value.data[0];
        if(!order_tag_transfer_completed){
          passed_order_tag = passed_order_tag + String(received_data);
          // If the order tag is received and registered successfully, conclude the collection process.
          order_tag_transfer_completed = true; active_task = 0;
          Serial.println("\nOrder tag transfer is completed.\nRegistered tag: " + passed_order_tag);
        }else{
          Serial.println("\nReceived order tag is still in session.\nPrevious tag: " + passed_order_tag);
        }
      }     
    break;

    // Assign event handlers to enable remote GATT client BLE notifications based on the declared GATT characteristic status changes.
    case sl_bt_evt_gatt_server_characteristic_status_id:
      if(evt->data.evt_gatt_server_characteristic_status.characteristic == station_status_characteristic_handle){
        if(evt->data.evt_gatt_server_characteristic_status.client_config_flags & sl_bt_gatt_notification){
          Serial.println("BLE [Station Status] notification => Enabled\n");
        } else {
          Serial.println("BLE [Station Status] notification => Disabled\n");
        }
      }   
      if(evt->data.evt_gatt_server_characteristic_status.characteristic == product_status_characteristic_handle){
        if(evt->data.evt_gatt_server_characteristic_status.client_config_flags & sl_bt_gatt_notification){
          Serial.println("BLE [Product Status] notification => Enabled\n");
        } else {
          Serial.println("BLE [Product Status] notification => Disabled\n");
        }
      }
    break;

    // Default event handler.
    default:
      // ...
    break;
  }
}

void update_BLE_characteristics(uint16_t selected_characteristic, uint8_t msg){
  // Update the selected data characteristic over BLE to notify the remote GATT client (central device).
  sl_status_t sc = sl_bt_gatt_server_notify_all(selected_characteristic,
                                                sizeof(msg),
                                                (const uint8_t*)&msg);
  if(sc == SL_STATUS_OK){
    Serial.println("\nGATT client => Notification transferred!\n");
  }else{
    Serial.println("\nGATT client => Notification failed!\n");
  }
}

void thermal_printer_commit(String command){
  if(command == "receipt"){
    printer.boldOn();
    printer.printBitmap(printer_shipping_width, printer_shipping_height, printer_shipping_bits);
    printer.feed(2);
    printer.printBitmap(printer_shipping_2_width, printer_shipping_2_height, printer_shipping_2_bits);
    printer.feed(2);
    printer.printBitmap(printer_shipping_3_width, printer_shipping_3_height, printer_shipping_3_bits);
    printer.feed(2);
    printer.println("Order Tag: ");
    printer.println(passed_order_tag);
    printer.setBarcodeHeight(100);
    printer.printBarcode(passed_order_tag.c_str(), EAN8);
    printer.feed(5);
    printer.setDefault(); // Restore printer to defaults.
  }
  delay(2000);
}

void stepper_move(int target_motor, int step_number, int acc, String _dir){
  // Move the targeted stepper motor according to the passed step number and direction.
  // CW:  Clockwise
  // CCW: Counter-clockwise

  if(_dir == "CW"){ digitalWrite(stepper_config._pins[target_motor-1][0], HIGH); }
  else if(_dir == "CCW"){ digitalWrite(stepper_config._pins[target_motor-1][0], LOW); }
	
	for(int x = 0; x < stepper_config.stepsPerRevolution[target_motor-1]*step_number; x++){
	  digitalWrite(stepper_config._pins[target_motor-1][1], HIGH);
		delayMicroseconds(stepper_config.assigned_speed[target_motor-1]/acc);
		digitalWrite(stepper_config._pins[target_motor-1][1], LOW);
		delayMicroseconds(stepper_config.assigned_speed[target_motor-1]/acc);
	}
	delay(2000);
}

String stepper_homing_sequence(int target_motor, int switch_pin, int acc, String _dir){
  // Depending on the associated switch (IR or micro) and the passed direction, home the targeted stepper motor position.
  // CW:  Clockwise
  // CCW: Counter-clockwise

  if(_dir == "CW"){ digitalWrite(stepper_config._pins[target_motor-1][0], HIGH); }
  else if(_dir == "CCW"){ digitalWrite(stepper_config._pins[target_motor-1][0], LOW); }

 	while(digitalRead(switch_pin)){
    for(int x = 0; x < stepper_config.stepsPerRevolution[target_motor-1]; x++){
	    digitalWrite(stepper_config._pins[target_motor-1][1], HIGH);
		  delayMicroseconds(stepper_config.assigned_speed[target_motor-1]/acc);
		  digitalWrite(stepper_config._pins[target_motor-1][1], LOW);
		  delayMicroseconds(stepper_config.assigned_speed[target_motor-1]/acc);
	  } if(switch_pin == IR_receiver) delay(500);
  } delay(2000);

  if(_dir == "CW"){ digitalWrite(stepper_config._pins[target_motor-1][0], LOW); }
  else if(_dir == "CCW"){ digitalWrite(stepper_config._pins[target_motor-1][0], HIGH); }

	for(int x = 0; x < stepper_config.stepsPerRevolution[target_motor-1]*stepper_config.home_step_number[target_motor-1]; x++){
	  digitalWrite(stepper_config._pins[target_motor-1][1], HIGH);
		delayMicroseconds(stepper_config.assigned_speed[target_motor-1]/acc);
		digitalWrite(stepper_config._pins[target_motor-1][1], LOW);
		delayMicroseconds(stepper_config.assigned_speed[target_motor-1]/acc);
	} delay(2000);

  // Return the sequence confirmation message after homing the given stepper motor position.
  return "homing_completed_" + String(target_motor);
}

void show_interface(String com, int menu_option){
  if(com == "main"){
    // Get the assigned interface logo information.
    int l_w = interface_widths[menu_option];
    int l_h = interface_heights[menu_option];
    int x_offset = 8, y_offset = 15, y_start = 5;
    adjustColor(255, 255, 255);
    display.clearDisplay();
    display.drawBitmap(0, (SCREEN_HEIGHT-l_h)/2, interface_logos[menu_option], l_w, l_h, SSD1306_WHITE);
    display.setTextSize(1);
    (menu_option == 1) ? display.setTextColor(SSD1306_BLACK, SSD1306_WHITE) : display.setTextColor(SSD1306_WHITE);
    display.setCursor(l_w+x_offset, y_start); display.println("Platform [1]");
    (menu_option == 2) ? display.setTextColor(SSD1306_BLACK, SSD1306_WHITE) : display.setTextColor(SSD1306_WHITE);
    display.setCursor(l_w+x_offset, y_start+y_offset); display.println("Platform [2]");   
    (menu_option == 3) ? display.setTextColor(SSD1306_BLACK, SSD1306_WHITE) : display.setTextColor(SSD1306_WHITE);
    display.setCursor(l_w+x_offset, y_start+(2*y_offset)); display.println("Move Carrier"); 
    (menu_option == 4) ? display.setTextColor(SSD1306_BLACK, SSD1306_WHITE) : display.setTextColor(SSD1306_WHITE);
    display.setCursor(l_w+x_offset, y_start+(3*y_offset)); display.println("Carrier Arm"); 
    display.display();
  }else if(com == "task_activated"){
    // Get the assigned task logo information.
    int l_w = task_widths[menu_option];
    int l_h = task_heights[menu_option];
    int x_offset = 6, y_offset = 12;
    display.clearDisplay();
    display.drawBitmap(0, 0, task_logos[0], task_widths[0], task_heights[0], SSD1306_WHITE);
    if(menu_option > 0) display.drawBitmap(SCREEN_WIDTH-l_w, 0, task_logos[menu_option], l_w, l_h, SSD1306_WHITE);
    display.setTextSize(1); display.setTextColor(SSD1306_WHITE);
    display.setCursor(x_offset, SCREEN_HEIGHT-y_offset); display.println("Order Tag: " + passed_order_tag);
    switch(menu_option){
      case 1: adjustColor(255, 0, 0); break;
      case 2: adjustColor(0, 0, 255); break;
      case 3: adjustColor(255, 255, 0); break;
      case 4: adjustColor(255, 0, 255); break;
      case 5: adjustColor(0, 255, 0); delay(5000); break;
      default: break;
    }
    display.display();      
  }else if(com == "homing"){
    // Get the assigned homing sequence logo information.
    int l_w = homing_sequence_width;
    int l_h = homing_sequence_height;
    int x_offset = 11, y_offset = 7;
    adjustColor(0, 255, 0);
    display.clearDisplay();
    display.drawBitmap((SCREEN_WIDTH-l_w)/2, 0, homing_sequence_bits, l_w, l_h, SSD1306_WHITE);
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(x_offset, SCREEN_HEIGHT-y_offset); 
    display.println(homing_confirmation_msg);
    display.display();    
  }
}

void adjustColor(int r, int g, int b){
  analogWrite(red_pin, (255-r));
  analogWrite(green_pin, (255-g));
  analogWrite(blue_pin, (255-b));
}