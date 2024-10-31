#define home_width  32
#define home_height 40
PROGMEM static const unsigned char home_bits[] = {
0x00, 0x00, 0x40, 0x00, 0x00, 0x07, 0xC0, 0x00, 0x00, 0x07, 0xE0, 0x00, 0x00, 0x07, 0xE0, 0x00,
0x00, 0x07, 0xE0, 0x00, 0x00, 0x07, 0xE0, 0x00, 0x00, 0x07, 0xE0, 0x00, 0x00, 0x07, 0xE0, 0x00,
0x0B, 0xF7, 0xFF, 0xD0, 0x1F, 0xE7, 0xE7, 0xF8, 0x1F, 0x07, 0xE0, 0xF8, 0x3E, 0x07, 0xE0, 0x7C,
0x3E, 0x00, 0x00, 0xFC, 0x7F, 0xC0, 0x03, 0xFE, 0x7F, 0xFF, 0xFF, 0xFE, 0x9F, 0xFF, 0xFF, 0xFB,
0x60, 0x00, 0x00, 0x0C, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

#define platform_1_width  32
#define platform_1_height 32
PROGMEM static const unsigned char platform_1_bits [] = {
0x00, 0x0F, 0xF0, 0x00, 0x00, 0x7F, 0xFE, 0x00, 0x00, 0xF8, 0x1F, 0x00, 0x03, 0xFC, 0x3F, 0xC0,
0x07, 0xFF, 0xFF, 0xE0, 0x0F, 0xFC, 0x3F, 0xF0, 0x0F, 0xF0, 0x0F, 0xF0, 0x1F, 0xC0, 0x03, 0xF8,
0x1F, 0x83, 0xC1, 0xF8, 0x3F, 0x83, 0xF1, 0xFC, 0x3F, 0x03, 0xF8, 0xFC, 0x3F, 0x03, 0xF8, 0xFC,
0x3F, 0x3F, 0xFC, 0xFC, 0x3E, 0x3F, 0xFC, 0x7C, 0x3F, 0x3F, 0xFC, 0xFC, 0x3F, 0x1F, 0xF8, 0xFC,
0x3F, 0x1F, 0xF8, 0xFC, 0x3F, 0x8F, 0xF1, 0xFC, 0x1F, 0xC1, 0x83, 0xF8, 0x1F, 0xE0, 0x07, 0xF8,
0x0F, 0xF0, 0x0F, 0xF0, 0x07, 0xFF, 0xFF, 0xE0, 0x03, 0xFF, 0xFF, 0xC0, 0x01, 0xFF, 0xFF, 0x80,
0x00, 0xFF, 0xFF, 0x00, 0x00, 0x3F, 0xFC, 0x00, 0x00, 0x03, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x0F, 0xF0, 0x00, 0x03, 0xFF, 0xFF, 0xC0, 0x03, 0xFF, 0xFF, 0xC0, 0x03, 0xFF, 0xFF, 0xC0
};

#define platform_2_width  32
#define platform_2_height 32
PROGMEM static const unsigned char platform_2_bits [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00,
0x00, 0x01, 0xFF, 0x00, 0x00, 0x00, 0x7F, 0xC0, 0x00, 0x10, 0x1F, 0xF0, 0x00, 0x7C, 0x07, 0xFC,
0x00, 0xFF, 0x01, 0xFE, 0x00, 0x3F, 0xC0, 0x78, 0x03, 0x8F, 0xF0, 0x03, 0x03, 0xE3, 0xFE, 0x0F,
0x03, 0xF8, 0xFC, 0x0F, 0xFF, 0xFE, 0x31, 0x0F, 0xFF, 0xFF, 0x87, 0x0F, 0x03, 0xFF, 0xCF, 0x0F,
0x1F, 0xFF, 0xEF, 0x3F, 0x03, 0xFF, 0xEF, 0xFF, 0x03, 0xFF, 0xEF, 0xFF, 0x07, 0x3F, 0xEF, 0xFF,
0x03, 0x8F, 0xEF, 0xFF, 0x03, 0xEF, 0xEF, 0xFF, 0x03, 0x3F, 0xEF, 0xFF, 0x01, 0x9F, 0xEF, 0xFF,
0x00, 0xFF, 0xEF, 0xFC, 0x00, 0x3F, 0xEF, 0xF0, 0x00, 0x0F, 0xEF, 0xC0, 0x00, 0x03, 0xEF, 0x00,
0x00, 0x00, 0xEC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

#define move_carrier_width  32
#define move_carrier_height 32
PROGMEM static const unsigned char move_carrier_bits [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x03, 0xFF, 0xFF, 0x00, 0x1F, 0xFF, 0xFF, 0x00, 0x00, 0x1F, 0xFF, 0x00, 0x7F, 0xFF, 0xFF, 0xF0,
0x00, 0x7F, 0xFF, 0x88, 0x3F, 0xFF, 0xFF, 0x84, 0x00, 0x1F, 0xFF, 0x82, 0xFF, 0xFF, 0xFF, 0xFF,
0x00, 0xFF, 0xFF, 0xFF, 0x07, 0xFF, 0xFF, 0xFF, 0x07, 0xCF, 0xFF, 0xCF, 0x07, 0x77, 0xFF, 0xBB,
0x07, 0xDB, 0xFF, 0x6F, 0x00, 0x88, 0x00, 0x4C, 0x00, 0xD8, 0x00, 0x48, 0x00, 0x70, 0x00, 0x70,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

#define carrier_arm_width  32
#define carrier_arm_height 32
PROGMEM static const unsigned char carrier_arm_bits [] = {
0x00, 0x1C, 0x00, 0x00, 0x00, 0x7F, 0x00, 0x00, 0x00, 0xE3, 0x80, 0x00, 0x01, 0xC1, 0xC0, 0x00,
0x01, 0x9E, 0xC0, 0x00, 0x01, 0xBE, 0xC0, 0x00, 0x0D, 0xBE, 0xC0, 0x00, 0x3D, 0x9C, 0xC0, 0x00,
0xFC, 0xC1, 0xC0, 0x00, 0xFE, 0xF7, 0x80, 0x00, 0xFE, 0x7F, 0x20, 0x00, 0xFF, 0x88, 0x60, 0x00,
0xFF, 0x01, 0xF0, 0x00, 0xFC, 0x03, 0xF8, 0x00, 0xF8, 0x03, 0xFE, 0x00, 0xE0, 0x01, 0xFF, 0x80,
0xC0, 0x01, 0xC1, 0x80, 0x00, 0x01, 0x9D, 0xC0, 0x00, 0x01, 0xBC, 0xFC, 0x00, 0x01, 0xBC, 0xFF,
0x00, 0x01, 0x9D, 0xFE, 0x00, 0x00, 0xC1, 0xFE, 0x00, 0x00, 0xFF, 0x86, 0x00, 0x00, 0xFE, 0x0C,
0x00, 0x00, 0xF8, 0x0C, 0x00, 0x00, 0xF0, 0x0C, 0x00, 0x01, 0xE0, 0x0C, 0x00, 0x01, 0xE0, 0x08,
0x00, 0x01, 0xFC, 0x08, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x03, 0xC0, 0x00, 0x00, 0x00, 0x00
};

// Define the assigned interface logo information as arrays.
PROGMEM static const unsigned char *interface_logos[] = {home_bits, platform_1_bits, platform_2_bits, move_carrier_bits, carrier_arm_bits};
int interface_widths[] = {home_width, platform_1_width, platform_2_width, move_carrier_width, carrier_arm_width};
int interface_heights[] = {home_height, platform_1_height, platform_2_height, move_carrier_height, carrier_arm_height};


#define task_home_width  40
#define task_home_height 40
PROGMEM static const unsigned char task_home_bits [] = {
0x00, 0x04, 0x00, 0x20, 0x00, 0x00, 0x04, 0x00, 0x20, 0x00, 0x00, 0x02, 0x3C, 0x40, 0x00, 0x00,
0x03, 0xFF, 0xC0, 0x00, 0x00, 0x07, 0xFF, 0xE0, 0x00, 0x00, 0x0F, 0xFF, 0xF0, 0x00, 0x00, 0x1F,
0xFF, 0xF8, 0x00, 0x00, 0x3C, 0xFF, 0x3C, 0x00, 0x00, 0x3F, 0xFF, 0xFC, 0x00, 0x00, 0x7F, 0xFF,
0xFE, 0x00, 0x00, 0x7F, 0xFF, 0xFE, 0x00, 0x00, 0x7F, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x0E, 0x3F, 0xFF, 0xFC, 0x70, 0x1F, 0x7F, 0xFF, 0xFE, 0xF8, 0x1F, 0x7F, 0xFF, 0xFE, 0xF8,
0x1F, 0x7F, 0xFF, 0xFE, 0xF8, 0x1F, 0x7F, 0xFF, 0xFE, 0xF8, 0x1F, 0x7F, 0xFF, 0xFE, 0xF8, 0x1F,
0x7F, 0xFF, 0xFE, 0xF8, 0x1F, 0x7F, 0xFF, 0xFE, 0xF8, 0x1F, 0x7F, 0xFF, 0xFE, 0xF8, 0x1F, 0x7F,
0xFF, 0xFE, 0xF8, 0x1F, 0x7F, 0xFF, 0xFE, 0xF8, 0x1F, 0x7F, 0xFF, 0xFE, 0xF8, 0x1F, 0x7F, 0xFF,
0xFE, 0xF8, 0x1F, 0x7F, 0xFF, 0xFE, 0xF8, 0x0E, 0x7F, 0xFF, 0xFE, 0x70, 0x00, 0x7F, 0xFF, 0xFE,
0x00, 0x00, 0x7F, 0xFF, 0xFE, 0x00, 0x00, 0x7F, 0xFF, 0xFE, 0x00, 0x00, 0x3F, 0xFF, 0xFC, 0x00,
0x00, 0x07, 0xC3, 0xE0, 0x00, 0x00, 0x07, 0xC3, 0xE0, 0x00, 0x00, 0x07, 0xC3, 0xE0, 0x00, 0x00,
0x07, 0xC3, 0xE0, 0x00, 0x00, 0x07, 0xC3, 0xE0, 0x00, 0x00, 0x07, 0xC3, 0xE0, 0x00, 0x00, 0x03,
0xC3, 0xC0, 0x00, 0x00, 0x01, 0x81, 0x80, 0x00, 
};

#define task_not_found_width  40
#define task_not_found_height 40
const unsigned char task_not_found_bits [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x7F, 0xF8, 0x00, 0x00, 0x00,
0xFF, 0xFE, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0x00, 0x00, 0x07, 0xE0, 0x1F, 0x80, 0x00, 0x0F, 0x80,
0x07, 0xC0, 0x00, 0x1F, 0x00, 0x03, 0xE0, 0x00, 0x1E, 0x00, 0x01, 0xE0, 0x00, 0x3C, 0x00, 0x00,
0xF0, 0x00, 0x3C, 0x00, 0x00, 0xF0, 0x00, 0x38, 0x1C, 0x60, 0x70, 0x00, 0x38, 0x1C, 0xE0, 0x78,
0x00, 0x78, 0x1F, 0xE0, 0x78, 0x00, 0x78, 0x07, 0xC0, 0x78, 0x00, 0x78, 0x07, 0x80, 0x78, 0x00,
0x78, 0x0F, 0xE0, 0x78, 0x00, 0x78, 0x1E, 0xE0, 0x78, 0x00, 0x38, 0x1C, 0xF0, 0x70, 0x00, 0x3C,
0x00, 0x00, 0xF0, 0x00, 0x3C, 0x00, 0x00, 0xF0, 0x00, 0x1E, 0x00, 0x01, 0xE0, 0x00, 0x1F, 0x00,
0x03, 0xE0, 0x00, 0x0F, 0x80, 0x07, 0xC0, 0x00, 0x07, 0xE0, 0x1F, 0xE0, 0x00, 0x03, 0xFF, 0xFF,
0xF0, 0x00, 0x01, 0xFF, 0xFE, 0xFF, 0x00, 0x00, 0x7F, 0xF8, 0x7F, 0x80, 0x00, 0x0F, 0xC0, 0x3F,
0xC0, 0x00, 0x00, 0x00, 0x3F, 0xE0, 0x00, 0x00, 0x00, 0x3F, 0xF0, 0x00, 0x00, 0x00, 0x3F, 0xF8,
0x00, 0x00, 0x00, 0x1F, 0xFC, 0x00, 0x00, 0x00, 0x0F, 0xFE, 0x00, 0x00, 0x00, 0x07, 0xFE, 0x00,
0x00, 0x00, 0x03, 0xFC, 0x00, 0x00, 0x00, 0x01, 0xFC, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x00, 0x00,
0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

#define task_detected_width  40
#define task_detected_height 40
const unsigned char task_detected_bits [] = {
0x00, 0x00, 0x18, 0x00, 0x00, 0x07, 0xFC, 0x3C, 0x3F, 0xE0, 0x1F, 0xFC, 0x3C, 0x3F, 0xF8, 0x30,
0x00, 0x18, 0x00, 0x0C, 0x20, 0x00, 0x18, 0x00, 0x04, 0x60, 0x00, 0x18, 0x00, 0x06, 0x60, 0x00,
0x18, 0x00, 0x06, 0x60, 0x00, 0x7E, 0x00, 0x06, 0x60, 0x01, 0xDB, 0x80, 0x06, 0x60, 0x07, 0x18,
0xE0, 0x06, 0x60, 0x0C, 0x18, 0x30, 0x06, 0x60, 0x38, 0x18, 0x1C, 0x06, 0x60, 0x60, 0x18, 0x06,
0x06, 0x60, 0xC0, 0x18, 0x03, 0x06, 0x00, 0xF0, 0x18, 0x0F, 0x00, 0x00, 0x9C, 0x18, 0x39, 0x00,
0x00, 0x86, 0x00, 0x61, 0x00, 0x00, 0x83, 0x99, 0xC1, 0x00, 0x60, 0x80, 0xFF, 0x01, 0x06, 0xFF,
0xFF, 0x66, 0xFF, 0xFF, 0xFF, 0xFF, 0x66, 0xFF, 0xFF, 0x60, 0x80, 0x3C, 0x01, 0x06, 0x00, 0x80,
0x18, 0x01, 0x00, 0x00, 0x80, 0x00, 0x01, 0x00, 0x00, 0x80, 0x18, 0x01, 0x00, 0x00, 0x80, 0x18,
0x01, 0x00, 0x60, 0xC0, 0x18, 0x03, 0x06, 0x60, 0x60, 0x18, 0x06, 0x06, 0x60, 0x38, 0x18, 0x1C,
0x06, 0x60, 0x0C, 0x18, 0x30, 0x06, 0x60, 0x07, 0x18, 0xE0, 0x06, 0x60, 0x01, 0xDB, 0x80, 0x06,
0x60, 0x00, 0x7E, 0x00, 0x06, 0x60, 0x00, 0x18, 0x00, 0x06, 0x60, 0x00, 0x18, 0x00, 0x06, 0x20,
0x00, 0x18, 0x00, 0x04, 0x30, 0x00, 0x18, 0x00, 0x0C, 0x1F, 0xFC, 0x3C, 0x3F, 0xF8, 0x07, 0xFC,
0x3C, 0x3F, 0xE0, 0x00, 0x00, 0x18, 0x00, 0x00, 
};

#define task_move_width  40
#define task_move_height 40
PROGMEM static const unsigned char task_move_bits [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00,
0x00, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0x00,
0xFF, 0x00, 0x00, 0x00, 0x01, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x1C,
0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00,
0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x80,
0x03, 0x00, 0x00, 0x00, 0xC0, 0x07, 0x00, 0x00, 0x00, 0xF0, 0x1F, 0x00, 0x00, 0x00, 0xF8, 0x3F,
0xFE, 0x00, 0x7F, 0xFC, 0x7F, 0xFE, 0x00, 0x7F, 0xFE, 0x1F, 0xFE, 0x00, 0x7F, 0xF8, 0x0F, 0x00,
0x00, 0x00, 0xF0, 0x03, 0x00, 0x00, 0x00, 0xE0, 0x01, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x3C,
0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00,
0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00,
0x00, 0x01, 0xFF, 0x80, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x00, 0x00, 0x00,
0x00, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00,
0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

#define task_delivery_width  40
#define task_delivery_height 40
PROGMEM static const unsigned char task_delivery_bits [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xE0, 0x00, 0x00, 0x00, 0x07, 0xFC, 0x00,
0x00, 0x00, 0x1F, 0xFE, 0x00, 0x00, 0x00, 0x3E, 0x0F, 0x00, 0x00, 0x00, 0x78, 0x07, 0xF8, 0x00,
0x00, 0x70, 0xC3, 0xFC, 0x00, 0x00, 0x60, 0xC1, 0xFC, 0x00, 0x00, 0xE0, 0xC1, 0xFC, 0xFF, 0xC0,
0xE0, 0xC0, 0xFD, 0xFF, 0xC0, 0xE0, 0xC0, 0xFD, 0xFF, 0xE0, 0xE0, 0x60, 0xFD, 0xF8, 0xF0, 0xE0,
0x31, 0xFD, 0xF0, 0x70, 0x60, 0x11, 0xFD, 0xF0, 0x38, 0x70, 0x03, 0xFD, 0xF0, 0x1C, 0x78, 0x07,
0xFD, 0xF0, 0x1C, 0x3E, 0x0F, 0xFD, 0xF0, 0x0E, 0x3F, 0xFF, 0xFD, 0xF0, 0x07, 0x3F, 0xFF, 0xFD,
0xFF, 0xFF, 0x3F, 0xFF, 0xFD, 0xFF, 0xFF, 0x3F, 0xFF, 0xFD, 0xFF, 0xFF, 0x3F, 0xFF, 0xFD, 0xFF,
0xFF, 0x3F, 0xFF, 0xFD, 0xFF, 0xFF, 0x3F, 0xFF, 0xFD, 0xFF, 0xFF, 0x3F, 0xFF, 0xFD, 0xFF, 0xFF,
0x3F, 0xFF, 0xFD, 0xFF, 0xFF, 0x3F, 0xC3, 0xFD, 0xFC, 0x3F, 0x3F, 0x83, 0xF8, 0xF8, 0x3F, 0x01,
0x83, 0x80, 0x18, 0x38, 0x01, 0xC3, 0x00, 0x1C, 0x30, 0x01, 0xFF, 0x00, 0x1F, 0xF0, 0x00, 0xFE,
0x00, 0x0F, 0xE0, 0x00, 0x3C, 0x00, 0x03, 0xC0, 
};

#define task_product_check_width  40
#define task_product_check_height 40
PROGMEM static const unsigned char task_product_check_bits [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x03, 0xFE, 0x00, 0x00, 0x00,
0x1F, 0x9F, 0x80, 0x00, 0x00, 0x7E, 0x03, 0xF0, 0x00, 0x03, 0xF8, 0x00, 0xFC, 0x00, 0x0F, 0xFF,
0x00, 0x1F, 0x80, 0x7E, 0x0F, 0xC0, 0x07, 0xE0, 0xF8, 0x01, 0xF8, 0x01, 0xF0, 0xFC, 0x00, 0x7E,
0x03, 0xF0, 0xFF, 0x00, 0x0F, 0x8F, 0xF0, 0xFF, 0xE0, 0x03, 0xFE, 0x30, 0xFF, 0xF8, 0x01, 0xF8,
0x30, 0xFF, 0xFF, 0x0F, 0xC0, 0x30, 0xFF, 0xFF, 0xFF, 0x00, 0x30, 0xFF, 0xFF, 0xF8, 0x00, 0x30,
0xFF, 0xFF, 0xE0, 0x00, 0x30, 0xFF, 0xFF, 0xE0, 0x00, 0x30, 0xFF, 0xFF, 0xE0, 0x00, 0x30, 0xFF,
0xFF, 0xE0, 0x00, 0x30, 0xFF, 0xFF, 0xE0, 0x00, 0x30, 0xFF, 0xFF, 0xE0, 0x00, 0x30, 0xFF, 0xFF,
0xE0, 0x00, 0x30, 0xFF, 0xFF, 0xE0, 0x00, 0x30, 0xFF, 0xFF, 0xE0, 0x03, 0xF0, 0xFF, 0xFF, 0xE0,
0x07, 0xFC, 0xFF, 0xFF, 0xE0, 0x0F, 0xFC, 0xFF, 0xFF, 0xE0, 0x0F, 0xFE, 0xFF, 0xFF, 0xE0, 0x1F,
0xFE, 0xFF, 0xFF, 0xE0, 0x1F, 0xCF, 0xFF, 0xFF, 0xE0, 0x1E, 0xCF, 0xFF, 0xFF, 0xE0, 0x1C, 0x1F,
0x7F, 0xFF, 0xE0, 0x1E, 0x1F, 0x1F, 0xFF, 0xE0, 0x1E, 0x3F, 0x07, 0xFF, 0xE0, 0x7F, 0x7E, 0x00,
0xFF, 0xE3, 0xFF, 0xFE, 0x00, 0x3F, 0xEF, 0xCF, 0xFC, 0x00, 0x07, 0xFE, 0x07, 0xFC, 0x00, 0x01,
0xF8, 0x03, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

// Define the assigned ongoing task logo information as arrays. 
PROGMEM static const unsigned char *task_logos[] = {task_home_bits, task_not_found_bits, task_detected_bits, task_move_bits, task_delivery_bits, task_product_check_bits};
int task_widths[] = {task_home_width, task_not_found_width, task_detected_width, task_move_width, task_delivery_width, task_product_check_width};
int task_heights[] = {task_home_height, task_not_found_height, task_detected_height, task_move_height, task_delivery_height, task_product_check_height};


#define homing_sequence_width  48
#define homing_sequence_height 48
PROGMEM static const unsigned char homing_sequence_bits [] = {
0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x03, 0xC0,
0x00, 0x00, 0x00, 0x00, 0x03, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xE0, 0x00, 0x00, 0x00, 0x00,
0xFF, 0xF1, 0x00, 0x00, 0x00, 0x03, 0xFF, 0xE3, 0xC0, 0x00, 0x00, 0x0F, 0xC3, 0xC3, 0xF0, 0x00,
0x00, 0x1F, 0x07, 0x80, 0xF8, 0x00, 0x00, 0x3C, 0x07, 0x00, 0x3C, 0x00, 0x00, 0x78, 0x00, 0x00,
0x1E, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x0F, 0x00, 0x01, 0xE0, 0x00, 0x00, 0x07, 0x80, 0x01, 0xC0,
0x00, 0x00, 0x03, 0x80, 0x03, 0x80, 0x01, 0x80, 0x01, 0xC0, 0x03, 0x80, 0x03, 0xC0, 0x01, 0xC0,
0x07, 0x00, 0x0F, 0xF0, 0x00, 0xE0, 0x07, 0x00, 0x1F, 0xF8, 0x00, 0xE0, 0x0E, 0x00, 0x3F, 0xFC,
0x00, 0x70, 0x0E, 0x00, 0xFF, 0xFF, 0x00, 0x70, 0x0E, 0x01, 0xFF, 0xFF, 0x80, 0x70, 0x0E, 0x03,
0xFF, 0xFF, 0x80, 0x70, 0x0E, 0x03, 0xFF, 0xFF, 0xC0, 0x70, 0x0E, 0x03, 0xFF, 0xFF, 0xC0, 0x70,
0x0E, 0x03, 0xFF, 0xFF, 0xC0, 0x70, 0x0E, 0x03, 0xFF, 0xFF, 0xC0, 0x70, 0x0E, 0x03, 0xFF, 0xFF,
0xC0, 0x70, 0x0E, 0x03, 0xFE, 0x7F, 0xC0, 0x70, 0x0E, 0x03, 0xFE, 0x7F, 0xC0, 0x70, 0x0E, 0x03,
0xFE, 0x7F, 0xC0, 0x70, 0x07, 0x03, 0xFE, 0x7F, 0xC0, 0xE0, 0x07, 0x03, 0xFE, 0x7F, 0xC0, 0xE0,
0x03, 0x81, 0xFE, 0x7F, 0x81, 0xC0, 0x03, 0x80, 0x00, 0x00, 0x01, 0xC0, 0x01, 0xC0, 0x00, 0x00,
0x03, 0x80, 0x01, 0xE0, 0x00, 0x00, 0x07, 0x80, 0x00, 0xF0, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x78,
0x00, 0x00, 0x1E, 0x00, 0x00, 0x3C, 0x00, 0x60, 0x3C, 0x00, 0x00, 0x1F, 0x00, 0xE0, 0xF8, 0x00,
0x00, 0x0F, 0xC1, 0xC3, 0xF0, 0x00, 0x00, 0x03, 0xC3, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0xC7, 0xFF,
0x00, 0x00, 0x00, 0x00, 0x07, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x03, 0xC0, 0x00, 0x00, 0x00, 0x00,
0x01, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00
};


// Define the assigned shipping receipt logos for the thermal printer.
#define printer_shipping_width  80
#define printer_shipping_height 80
PROGMEM static const unsigned char printer_shipping_bits [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xFF,
0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x00,
0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xFC,
0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xFF, 0x8E, 0x3F, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F,
0xFE, 0x0E, 0x1F, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFC, 0x0E, 0x0F, 0xBF, 0xC0, 0x00,
0x00, 0x00, 0x01, 0xFE, 0x78, 0x0E, 0x07, 0xCF, 0xF0, 0x00, 0x00, 0x00, 0x03, 0xF8, 0xF0, 0x0E,
0x03, 0xC7, 0xF8, 0x00, 0x00, 0x00, 0x07, 0xF0, 0xF0, 0x1E, 0x01, 0xE1, 0xFC, 0x00, 0x00, 0x00,
0x0F, 0xC1, 0xE0, 0x1E, 0x01, 0xE0, 0xFE, 0x00, 0x00, 0x00, 0x1F, 0x83, 0xC0, 0x1E, 0x00, 0xF0,
0x7F, 0x00, 0x00, 0x00, 0x3F, 0x03, 0xC0, 0x0E, 0x00, 0x70, 0x3F, 0x00, 0x00, 0x00, 0x7F, 0x83,
0x80, 0x0E, 0x00, 0x78, 0x7F, 0x80, 0x00, 0x00, 0xFF, 0xF7, 0x80, 0x0E, 0x00, 0x39, 0xFF, 0xC0,
0x00, 0x00, 0xFF, 0xFF, 0x80, 0x0E, 0x00, 0x3F, 0xFF, 0xE0, 0x00, 0x01, 0xF8, 0xFF, 0xF0, 0x0E,
0x01, 0xFF, 0xE3, 0xE0, 0x00, 0x01, 0xF0, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0xF0, 0x00, 0x03,
0xE0, 0x0F, 0xFF, 0xFF, 0xFF, 0xFE, 0x01, 0xF0, 0x00, 0x03, 0xE0, 0x0E, 0x7F, 0xFF, 0xFF, 0x9E,
0x00, 0xF8, 0x00, 0x07, 0xC0, 0x1E, 0x00, 0xFF, 0xE0, 0x0E, 0x00, 0xF8, 0x00, 0x07, 0xC0, 0x1E,
0x00, 0x0E, 0x00, 0x0E, 0x00, 0x7C, 0x00, 0x0F, 0x80, 0x1C, 0x00, 0x1E, 0x00, 0x0F, 0x00, 0x7C,
0x00, 0x0F, 0x80, 0x1C, 0x00, 0x1E, 0x00, 0x0F, 0x00, 0x3C, 0x00, 0x0F, 0x80, 0x3C, 0x00, 0x1E,
0x00, 0x0F, 0x00, 0x3E, 0x00, 0x0F, 0x00, 0x3C, 0x00, 0x1E, 0x00, 0x07, 0x00, 0x3E, 0x00, 0x1F,
0x00, 0x3C, 0x00, 0x0E, 0x00, 0x07, 0x00, 0x3E, 0x00, 0x1F, 0x00, 0x38, 0x00, 0x0E, 0x00, 0x07,
0x00, 0x1E, 0x00, 0x1E, 0x00, 0x38, 0x00, 0x0E, 0x00, 0x07, 0x00, 0x1E, 0x00, 0x1E, 0x00, 0x38,
0x00, 0x1E, 0x00, 0x07, 0x80, 0x1F, 0x00, 0x1E, 0x00, 0x38, 0x00, 0x1E, 0x00, 0x07, 0x80, 0x1F,
0x00, 0x1E, 0x00, 0x38, 0x00, 0x0E, 0x00, 0x07, 0x80, 0x1F, 0x00, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x3F,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0x00, 0x3E, 0x00, 0x38, 0x00, 0x0E, 0x00, 0x07, 0x80, 0x1F, 0x00, 0x1E, 0x00, 0x38,
0x00, 0x1E, 0x00, 0x07, 0x80, 0x1F, 0x00, 0x1E, 0x00, 0x38, 0x00, 0x1E, 0x00, 0x07, 0x80, 0x1F,
0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x07, 0x80, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E,
0x00, 0x07, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x07, 0x00, 0x1E, 0x7F, 0xFF,
0xFF, 0xFF, 0xC0, 0x1E, 0x00, 0x07, 0x00, 0x3E, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x0E, 0x00, 0x07,
0x00, 0x3E, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x06, 0x00, 0x0F, 0x00, 0x3C, 0xFF, 0xFF, 0xFF, 0xFF,
0xE0, 0x02, 0x00, 0x0F, 0x00, 0x7C, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x0E, 0x00, 0x7C,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x0E, 0x00, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0,
0x7F, 0x9E, 0x00, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x3F, 0xFE, 0x01, 0xF0, 0xFF, 0xFF,
0xFF, 0xFF, 0xFE, 0x3C, 0x1F, 0xFF, 0x01, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x1E, 0x03, 0xFF,
0xC3, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x0F, 0x00, 0x3F, 0xF7, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF,
0xFE, 0x07, 0x80, 0x3F, 0xFF, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x03, 0xC0, 0x78, 0x7F, 0x80,
0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x01, 0xE0, 0x78, 0x3F, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00,
0xF0, 0x70, 0x3F, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x78, 0x70, 0xFE, 0x00, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x21, 0xFC, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x03,
0xF8, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x0F, 0xF0, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFE, 0x3F, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x80, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFE, 0x3C, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x30, 0x00, 0x00, 0xFF, 0xE0,
0xFF, 0xFF, 0xFE, 0x07, 0xFE, 0x00, 0x00, 0x00, 0xFF, 0x80, 0x3F, 0xFF, 0xFC, 0x03, 0xFE, 0x00,
0x00, 0x00, 0xFF, 0x1F, 0x1F, 0xFF, 0xF9, 0xF9, 0xFE, 0x00, 0x00, 0x00, 0xFE, 0x7F, 0x8F, 0xFF,
0xF3, 0xFC, 0xFE, 0x00, 0x00, 0x00, 0xFE, 0x7F, 0xCF, 0xFF, 0xE7, 0xFE, 0x7C, 0x00, 0x00, 0x00,
0x7C, 0xE1, 0xCF, 0xFF, 0xE7, 0x0E, 0x7C, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0x00, 0x06, 0x06,
0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0x00, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0,
0xE0, 0x00, 0x07, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF1, 0xC0, 0x00, 0x07, 0x1E, 0x00, 0x00,
0x00, 0x00, 0x00, 0x7F, 0xC0, 0x00, 0x03, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x80, 0x00,
0x01, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00
};

#define printer_shipping_2_width  80
#define printer_shipping_2_height 80
PROGMEM static const unsigned char printer_shipping_2_bits [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xF0,
0x00, 0x00, 0x00, 0x00, 0x01, 0xF8, 0x00, 0x00, 0x0F, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x07, 0xFF,
0xC0, 0x00, 0x3F, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xFF, 0xFE, 0x00, 0x7F, 0xFE, 0x00, 0x00,
0x00, 0x00, 0x1F, 0xFF, 0xFF, 0xF1, 0xFE, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xC7, 0xFF, 0xFF,
0xF8, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xE0, 0x3F, 0xFF, 0xF0, 0x7F, 0x00, 0x00, 0x00, 0x00,
0x07, 0xF8, 0x01, 0xFF, 0xC1, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFE, 0x00, 0x0F, 0x07, 0xFC,
0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x80, 0x00, 0x0F, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F,
0xC0, 0x00, 0x3F, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xF0, 0x00, 0xFF, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x03, 0xFC, 0x01, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFE, 0x07,
0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x1F, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00,
0x1C, 0x03, 0xFC, 0x7F, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x07, 0xF8, 0xFF, 0x00, 0x0F,
0xF0, 0x00, 0x00, 0x00, 0x3F, 0xFF, 0xE3, 0xFC, 0x01, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0x3F, 0xFF,
0x8F, 0xF0, 0x0F, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x3F, 0xFF, 0x1F, 0xE0, 0x3F, 0xFF, 0xFF, 0xFC,
0x00, 0x00, 0x3F, 0xFC, 0x7F, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x3E, 0x31, 0xFE, 0x03,
0xFF, 0xFF, 0xFF, 0x7F, 0xC0, 0x00, 0x1F, 0x87, 0xFC, 0x07, 0xF8, 0xFF, 0xFF, 0x1F, 0xE0, 0x00,
0x0F, 0xCF, 0xF0, 0x0F, 0xE1, 0xFB, 0xCF, 0x87, 0xF0, 0x00, 0x07, 0xFF, 0xC0, 0x1F, 0x83, 0xF3,
0xC7, 0xC1, 0xFC, 0x00, 0x03, 0xFF, 0x00, 0x3F, 0x03, 0xE3, 0xC7, 0xE0, 0xFE, 0x00, 0x01, 0xFE,
0x00, 0x7E, 0x07, 0xC3, 0xC3, 0xE0, 0x3F, 0x00, 0x00, 0xF8, 0x00, 0xF8, 0x0F, 0x83, 0xC1, 0xF0,
0x1F, 0x00, 0x00, 0x20, 0x01, 0xFC, 0x0F, 0x03, 0xC0, 0xF8, 0x3F, 0x80, 0x1C, 0x00, 0x03, 0xFF,
0xDF, 0x03, 0xC0, 0xFB, 0xFF, 0xC0, 0x3C, 0x00, 0x03, 0xFF, 0xFF, 0x03, 0xC0, 0xFF, 0xFF, 0xE0,
0x3E, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x3C, 0x00, 0x0F, 0x87, 0xFF, 0xFF,
0xFF, 0xFF, 0xE1, 0xF0, 0x7C, 0x00, 0x0F, 0x80, 0x7F, 0xFF, 0xFF, 0xFE, 0x00, 0xF0, 0x78, 0x00,
0x1F, 0x00, 0x7D, 0xFF, 0xFF, 0xBE, 0x00, 0xF8, 0x78, 0x00, 0x1E, 0x00, 0x78, 0x03, 0xC0, 0x1E,
0x00, 0x78, 0x78, 0x00, 0x1E, 0x00, 0xF8, 0x03, 0xC0, 0x1F, 0x00, 0x7C, 0x78, 0x00, 0x3E, 0x00,
0xF8, 0x03, 0xC0, 0x0F, 0x00, 0x3C, 0xF8, 0x00, 0x3C, 0x00, 0xF0, 0x03, 0xC0, 0x0F, 0x00, 0x3C,
0xF0, 0x00, 0x3C, 0x00, 0xF0, 0x03, 0xC0, 0x0F, 0x00, 0x3E, 0xF0, 0x00, 0x7C, 0x00, 0xF0, 0x03,
0xC0, 0x0F, 0x80, 0x1E, 0xF0, 0x00, 0x78, 0x01, 0xF0, 0x03, 0xC0, 0x0F, 0x80, 0x1E, 0x78, 0x00,
0x78, 0x01, 0xF0, 0x03, 0xC0, 0x07, 0x80, 0x1E, 0x78, 0x00, 0x78, 0x01, 0xE0, 0x03, 0xC0, 0x07,
0x80, 0x1E, 0x78, 0x00, 0x78, 0x01, 0xF0, 0x03, 0xE0, 0x0F, 0x80, 0x1E, 0x78, 0x00, 0x7F, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x78, 0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
0x7C, 0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x3C, 0x00, 0x7F, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFE, 0x3C, 0x00, 0x78, 0x01, 0xE0, 0x03, 0xC0, 0x07, 0x80, 0x1E, 0x3E, 0x00,
0x78, 0x01, 0xF0, 0x03, 0xC0, 0x07, 0x80, 0x1E, 0x1F, 0x00, 0x78, 0x01, 0xF0, 0x03, 0xC0, 0x07,
0x80, 0x1E, 0x1F, 0x00, 0x7C, 0x00, 0xF0, 0x03, 0xC0, 0x0F, 0x80, 0x1E, 0x0F, 0x80, 0x3C, 0x00,
0xF0, 0x03, 0xC0, 0x0F, 0x00, 0x3E, 0x0F, 0x80, 0x3C, 0x00, 0xF0, 0x03, 0xC0, 0x0F, 0x00, 0x3C,
0x07, 0xC0, 0x3E, 0x00, 0xF0, 0x03, 0xC0, 0x0F, 0x00, 0x3C, 0x03, 0xE0, 0x3E, 0x00, 0xF8, 0x03,
0xC0, 0x1F, 0x00, 0x7C, 0x03, 0xF0, 0x1E, 0x00, 0x78, 0x03, 0xC0, 0x1F, 0x00, 0x78, 0x01, 0xF8,
0x1F, 0x00, 0x7C, 0x7F, 0xFE, 0x1E, 0x00, 0xF8, 0x00, 0xFC, 0x0F, 0x00, 0x7F, 0xFF, 0xFF, 0xFE,
0x00, 0xF0, 0x00, 0x7E, 0x0F, 0x83, 0xFF, 0xFF, 0xFF, 0xFF, 0xC1, 0xF0, 0x00, 0x3F, 0x07, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x1F, 0x87, 0xFF, 0xFF, 0xC3, 0xC3, 0xFF, 0xFF, 0xE0,
0x00, 0x0F, 0xC3, 0xFF, 0xFF, 0x03, 0xC0, 0xFF, 0xFF, 0xC0, 0x00, 0x07, 0xE1, 0xFE, 0x0F, 0x03,
0xC0, 0xF8, 0x3F, 0x80, 0x00, 0x03, 0xF0, 0xF8, 0x0F, 0x83, 0xC1, 0xF0, 0x1F, 0x80, 0x00, 0x01,
0xF8, 0xFC, 0x07, 0xC3, 0xC3, 0xE0, 0x3F, 0x00, 0x00, 0x00, 0xF8, 0x7F, 0x07, 0xE3, 0xC3, 0xE0,
0x7E, 0x00, 0x00, 0x00, 0x30, 0x3F, 0x83, 0xE3, 0xC7, 0xC1, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x0F,
0xE1, 0xF3, 0xCF, 0x87, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x07, 0xF8, 0xFF, 0xFF, 0x1F, 0xE0, 0x00,
0x00, 0x00, 0x00, 0x03, 0xFE, 0xFF, 0xFF, 0x7F, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,
0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x0F, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xC0,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

#define printer_shipping_3_width  80
#define printer_shipping_3_height 80
PROGMEM static const unsigned char printer_shipping_3_bits [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x01, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xFF, 0xF8, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x3F, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,
0xFF, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00,
0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0xFC, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x07, 0xFF,
0xFF, 0xFF, 0xC0, 0x03, 0xF8, 0x00, 0x00, 0x00, 0x3F, 0xFF, 0xFF, 0xFF, 0x00, 0x1F, 0xFE, 0x00,
0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x7F, 0xFF, 0x80, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xF0,
0x01, 0xFF, 0xFF, 0xE0, 0x00, 0x0F, 0xFF, 0xFF, 0xFF, 0x80, 0x07, 0xFF, 0xFF, 0xF8, 0x00, 0x1F,
0xFF, 0xFF, 0xFE, 0x00, 0x1F, 0xFF, 0xFF, 0xFC, 0x00, 0x3F, 0xFF, 0xFF, 0xF8, 0x00, 0x7F, 0xFF,
0xFF, 0xFE, 0x00, 0x3F, 0xFF, 0xFF, 0xE0, 0x01, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x3F, 0xFF, 0xFF,
0x80, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x7F, 0xFF, 0xFE, 0x00, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF,
0x00, 0x7F, 0xFF, 0xF8, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x7F, 0xFF, 0xE0, 0x03, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x7F, 0xFF, 0x80, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x7F,
0xFF, 0x80, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x7F, 0xFF, 0x80, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0x00, 0x7F, 0xFF, 0x81, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x7F, 0xFF, 0x81,
0xFF, 0xFF, 0xFF, 0xFF, 0xF9, 0xFF, 0x00, 0x7F, 0xFF, 0x81, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xFF,
0x00, 0x7F, 0xFF, 0x81, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0xFF, 0x00, 0x7F, 0xFF, 0x81, 0xFF, 0xFF,
0xFF, 0xFF, 0xF0, 0x7F, 0x00, 0x7F, 0xFF, 0x81, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x3F, 0x00, 0x7F,
0xFF, 0x81, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x1F, 0x00, 0x7F, 0xFF, 0x81, 0xFF, 0xFF, 0xFF, 0xFF,
0xC0, 0x3F, 0x00, 0x7F, 0xFF, 0xC1, 0xFF, 0xFF, 0xFE, 0xFF, 0xC0, 0xFF, 0x00, 0x7F, 0xFF, 0xF9,
0xFF, 0xFF, 0xFC, 0x7F, 0x80, 0xFF, 0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x3F, 0x80, 0xFF,
0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x1F, 0xE0, 0xFF, 0x00, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF,
0xF8, 0x1F, 0xE0, 0xFF, 0x00, 0x20, 0x0F, 0xFF, 0xFF, 0xFF, 0xF0, 0x0F, 0xE0, 0xFF, 0x00, 0x00,
0x01, 0xFF, 0xFF, 0xFF, 0xF0, 0x1F, 0xE0, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xE0, 0x7F,
0xE0, 0xFF, 0x00, 0x07, 0x80, 0x3F, 0xFF, 0xFF, 0xE0, 0x7F, 0xE0, 0xFF, 0x00, 0x7F, 0xF8, 0x1F,
0xFF, 0xFF, 0xE8, 0x7F, 0xE0, 0xFF, 0x01, 0xFF, 0xFE, 0x0F, 0xFF, 0xFF, 0xF8, 0x7F, 0xE0, 0xFF,
0x03, 0xFF, 0xFF, 0x07, 0xFF, 0xFF, 0xF8, 0x7F, 0xE0, 0xFF, 0x07, 0xFF, 0xFF, 0x83, 0xFF, 0xFF,
0xF8, 0x7F, 0xE0, 0xFF, 0x0F, 0xFF, 0xFF, 0xC1, 0xFF, 0xFF, 0xF8, 0x7F, 0xE1, 0xFF, 0x1F, 0xFF,
0xFF, 0xE1, 0xFF, 0xFF, 0xF8, 0x7F, 0xFF, 0xCF, 0x3F, 0xFF, 0xFF, 0xF0, 0xFF, 0xFF, 0xF8, 0x7F,
0xFE, 0x0F, 0x3F, 0xFF, 0xFE, 0xF0, 0xFF, 0xFF, 0xF8, 0x7F, 0xF8, 0x3F, 0x7F, 0xFF, 0xF8, 0x78,
0x7F, 0xFF, 0xF8, 0x7F, 0xE0, 0xFF, 0x7F, 0xFF, 0xF0, 0x78, 0x7F, 0xFF, 0xF8, 0x7F, 0x03, 0xFF,
0x7F, 0xFF, 0xE0, 0x7C, 0x7F, 0xFF, 0xF8, 0x7C, 0x1F, 0xFE, 0xFF, 0xFF, 0xC0, 0x7C, 0x7F, 0xFF,
0xF9, 0xF0, 0x7F, 0xFE, 0xFF, 0xFF, 0xC0, 0xFC, 0x7F, 0xFF, 0xFF, 0x83, 0xFF, 0xFC, 0xFE, 0x7F,
0x81, 0xFC, 0x7F, 0xFF, 0xFE, 0x0F, 0xFF, 0xF8, 0xFC, 0x3F, 0x03, 0xFC, 0x3F, 0xFF, 0xF0, 0x3F,
0xFF, 0xE0, 0xFC, 0x0E, 0x07, 0xFC, 0x7F, 0xFF, 0xC1, 0xFF, 0xFF, 0x00, 0xFC, 0x04, 0x0F, 0xFC,
0x7F, 0xFF, 0x87, 0xFF, 0xFC, 0x00, 0xFE, 0x00, 0x1F, 0xFC, 0x7F, 0xFF, 0x9F, 0xFF, 0xF0, 0x00,
0x7F, 0x00, 0x3F, 0xF8, 0x7F, 0xFF, 0xFF, 0xFF, 0x80, 0x00, 0x7F, 0x80, 0x3F, 0xF8, 0x7F, 0xFF,
0xFF, 0xFE, 0x00, 0x00, 0x7F, 0xE0, 0x7F, 0xF8, 0xFF, 0xFF, 0xFF, 0xF8, 0x00, 0x00, 0x3F, 0xF0,
0xFF, 0xF0, 0xFF, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x3F, 0xFF, 0xFF, 0xF0, 0x7F, 0xFF, 0xFF, 0x00,
0x00, 0x00, 0x1F, 0xFF, 0xFF, 0xE0, 0x0F, 0xFF, 0xFC, 0x00, 0x00, 0x00, 0x0F, 0xFF, 0xFF, 0xC0,
0x03, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x07, 0xFF, 0xFF, 0x80, 0x00, 0xFF, 0x80, 0x00, 0x00, 0x00,
0x03, 0xFF, 0xFF, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFC, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};