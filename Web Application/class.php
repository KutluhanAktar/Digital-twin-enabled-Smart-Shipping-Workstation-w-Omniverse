<?php

// Define the workstation class and its functions.
class workstation{
	public $conn;
	private $database_table = "orders";
	public $necessary_order_parameters = array("firstname", "lastname", "email", "address", "product_name");
	
	public function __init__($conn){
		$this->conn = $conn;
	}
	
	// MariaDB Database ==> Append new order with shipping information
	public function append_new_order($order_info){
		// Inspect the passed order information to register an accurate shipping entry.
		$firstname = array_key_exists("firstname", $order_info) ? $order_info["firstname"] : "empty";
		$lastname = array_key_exists("lastname", $order_info) ? $order_info["lastname"] : "empty";
		$email = array_key_exists("email", $order_info) ? $order_info["email"] : "empty";
		$address = array_key_exists("address", $order_info) ? $order_info["address"] : "empty";
		$product_name = array_key_exists("product_name", $order_info) ? $order_info["product_name"] : "empty";
		$product_id = array_key_exists("product_id", $order_info) ? $order_info["product_id"] : -1;
		$order_img = array_key_exists("order_img", $order_info) ? $order_info["order_img"] : "empty";
		
		// Assign a unique order tag (barcode) to the generated shipping entry — EAN-8.
		$N = 8;
		$order_tag = rand(pow(10, $N-1), (pow(10, $N)-1));
		
		// Update the order status and date.
		$date = date("Y/m/d__h:i:s");
		$order_status = "created";
		
		// Insert the generated shipping entry into the given MariaDB database table.
		$sql = "INSERT INTO `$this->database_table` (`date`, `firstname`, `lastname`, `email`, `address`, `product_name`, `product_id`, `order_img`, `order_tag`, `order_status`)
		        VALUES ('$date', '$firstname', '$lastname', '$email', '$address', '$product_name', '$product_id', '$order_img', '$order_tag', '$order_status')";
	    mysqli_query($this->conn, $sql);		
	}
	
	// MariaDB Database ==> Update the shipping information of the requested order
	public function update_order_info($column, $up_data, $order_tag){
		$sql = ($column == "date") ? "UPDATE `$this->database_table` SET $column=CONCAT($column, ',$up_data') WHERE `order_tag`=$order_tag" 
		                           : "UPDATE `$this->database_table` SET $column='$up_data' WHERE `order_tag`=$order_tag";
								   
		mysqli_query($this->conn, $sql);
	}
	
	// MariaDB Database ==> Optain, modify, and pass required shipping (order) entries
	public function optain_modify_entries(){
		$generated_orders = [];
		// Obtain all generated order entries waiting to be processed by the shipping workstation.
		$sql = "SELECT * FROM `$this->database_table` WHERE `order_status`='created' ORDER BY `id` DESC";
		$result = mysqli_query($this->conn, $sql);
		$check = mysqli_num_rows($result);
		if($check > 0){
			while($row = mysqli_fetch_assoc($result)){
				if($row["order_status"] == "created"){
					// Remove the unnecessary array items from the retrieved shipping information.
					unset($row["id"], $row["firstname"], $row["lastname"], $row["email"], $row["product_id"], $row["order_img"], $row["order_status"]);
					// Then, append the modified shipping information to the associated array to create a chronological list of pending shipping entries.
					array_push($generated_orders, $row);	
				}
			}
		}else{
			$generated_orders = array(["date" => "No data!", "address" => "No data!", "product_name" => "No data!", "order_tag" => "00000000"]);
		}
		// Finally, return the generated pending shipping entry list (array).
		$pending_order_list = ["pending_order_list" => $generated_orders];
		return $pending_order_list;
	}
	
	// MariaDB Database ==> Optain, modify, and pass completed shipping (order) entries
	public function obtain_completed_orders($order_tag){
		$order_status = [];
		// Obtain all completed order entries indicating transported and packaged products.
		$sql = "SELECT * FROM `$this->database_table` WHERE `order_status`='completed' AND `order_tag` = '$order_tag'";
		$result = mysqli_query($this->conn, $sql);
		$check = mysqli_num_rows($result);
		if($check > 0 && $row = mysqli_fetch_assoc($result)){
			// Remove the unnecessary array items from the retrieved shipping information.
			unset($row["id"], $row["product_id"], $row["order_status"]);
            // Then, append the modified shipping information to the associated array to pass the order status.
            $order_status = ["completed_order_info" => $row];			
		}else{
			$order_status = ["completed_order_info" => array("date" => "No data!")];
		}
		// Finally, return the generated completed order information (array).
		return $order_status;
	}
	
	// By executing a Python script (run_FOMO_object_detection_model.py), run an inference with the Edge Impulse FOMO (object detection) model on Raspberry Pi 5.
	public function run_object_detection_model($order_tag){
		$model_result = "";
		// First, obtain the requested product information associated with the passed order tag (barcode).
		$sql = "SELECT * FROM `$this->database_table` WHERE `order_tag`='$order_tag'";
		$result = mysqli_query($this->conn, $sql);
		$check = mysqli_num_rows($result);		
		if($check > 0 && $row = mysqli_fetch_assoc($result)){
			// Get the requested product name from the MariaDB database table.
			$requested_product = $row["product_name"];
			// Then, execute the given Python script to classify the product sample currently positioned under the USB camera.
			$path = str_replace("/assets", "/object_detection_model", dirname(__FILE__));
			$run_Python_script = shell_exec('sudo python3 "'.$path.'/run_FOMO_object_detection_model.py" 2>&1'); // Add 2>&1 for debugging errors directly on the browser.
			// Decode the JSON object transferred by the Python script to obtain the model resulting information.
			$model_resulting_data = json_decode($run_Python_script);
			// As the Python script transfers the detected product class after running the FOMO object detection model, check whether the ordered product was successfully found.
			if($model_resulting_data->detected_product_class == $requested_product){
				// If so, make the shipping workstation transportation request via the Android application.
				$model_result = "Model_Result%Product_Detected";
				// Change the order status to completed.
				$this->update_order_info("order_status", "completed", $order_tag);
				// Then, update the order completion date of the given order (shipping) entry.
				$date = date("Y/m/d__h:i:s");
				$this->update_order_info("date", $date, $order_tag);
				// Also, append the product confirmation (model resulting) image path generated by the Python script to the order entry.
				$this->update_order_info("order_img", $model_resulting_data->product_confirmation_image, $order_tag);
			}else{
				// Otherwise, make the shipping workstation current product position change request.
				$model_result = "Model_Result%Product_Not_Found";
			}
		}else{
			$model_result = "The passed order tag does not exist in the MariaDB database.";
		}
		// Finally, return the model detection result.
		return $model_result;
	}
}

// Define the MariaDB server and database connection settings.
$server = array(
	"server" => "localhost",
	"username" => "root",
	"password" => "",
	"database" => "shipping_workstation"
);

$conn = mysqli_connect($server["server"], $server["username"], $server["password"], $server["database"]);

?>
