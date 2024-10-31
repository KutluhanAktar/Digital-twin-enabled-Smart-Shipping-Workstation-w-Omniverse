<?php

include_once "assets/class.php";

// Define the workstation object of the workstation class.
$workstation = new workstation();
$workstation->__init__($conn);


if(isset($_GET["i"])){
	// Check whether the obtained GET array contains the essential shipping information by comparing the GET array keys with the passed parameter names.
	$order_info = $_GET["i"];
	$check_parameters = array_diff($workstation->necessary_order_parameters, array_keys($order_info));
	// If the required information is received successfully, append a new shipping entry to the given database table.
	if(count($check_parameters) == 0){
		$workstation->append_new_order($order_info);
		echo "Database => New shipping entry registered successfully!";
	}else{
		echo "Database => Necessary shipping information is missing!";
	}
}

else if(isset($_GET["latest_order_entries"])){
	// Convert the generated pending shipping entry list (array) to a JSON object.
	// Then, return the created JSON object. 
	$pending_order_list = $workstation->optain_modify_entries();
	echo "Latest Order List%".json_encode($pending_order_list);
}

else if(isset($_GET["check_order_status"])){
	// Convert the generated completed order information (array) to a JSON object.
    // Then, return the created JSON object.
	$order_status = $workstation->obtain_completed_orders($_GET["check_order_status"]);
	echo "Order Status%".json_encode($order_status);
}

else if(isset($_GET["run_model"]) && isset($_GET["order_tag"])){
	// Run the Edge Impulse FOMO (object detection) model on Raspberry Pi 5 via the given Python script to find the requested product associated with the passed order tag.
	$model_result = $workstation->run_object_detection_model($_GET["order_tag"]);
	echo $model_result;
}
?>