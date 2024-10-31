# Digital twin-enabled Smart Shipping Workstation w/ Omniverse
#
# Raspberry Pi 5
#
# By Kutluhan Aktar
#
# Exploring the digital twin synthetic data generation and AI-oriented
# advancements on real-world shipping operations w/ NVIDIA Omniverse.
# 
#
# For more information:
# https://www.hackster.io/kutluhan-aktar


import cv2
import numpy
from edge_impulse_linux.image import ImageImpulseRunner
import os
import json
import datetime
from time import sleep

class product_classification():
    def __init__(self, model_file):
        # Initialize the USB high-quality camera feed.
        self.camera = cv2.VideoCapture(0)
        sleep(3)
        # Define the required variables to configure camera settings.
        self.cam_init = True
        self.frame_size = (320,320)
        # Define the required configurations to run the Edge Impulse FOMO object detection model.
        self.dir_path = os.path.dirname(os.path.realpath(__file__))
        self.model_file = os.path.join(self.dir_path, model_file)
        self.detected_class = "None"
        self.activate_model_result_send = False
        
    def run_inference(self, show_img=False, debug=False, bb_offset={"x": 12, "y": 15}):
        # Run inference to detect unique product samples.
        with ImageImpulseRunner(self.model_file) as runner:
            try:
                # Print the information of the Edge Impulse model converted to a Linux (AARCH64) application (.eim).
                model_info = runner.init()
                if(debug): print('Loaded runner for "' + model_info['project']['owner'] + ' / ' + model_info['project']['name'] + '"')
                labels = model_info['model_parameters']['labels']
                # Get the latest captured image (frame) with the high-quality USB camera and alter the frame depending on the given model so as to run an inference.
                features, cropped = runner.get_features_from_image(self.latest_frame)
                res = runner.classify(features)
                # Obtain the prediction (detection) results for each label (class).
                if "bounding_boxes" in res["result"].keys():
                    if(debug): print('Found %d bounding boxes (%d ms.)' % (len(res["result"]["bounding_boxes"]), res['timing']['dsp'] + res['timing']['classification']))
                    # If the Edge Impulse model predicts a class successfully:
                    if(len(res["result"]["bounding_boxes"]) == 0):
                        self.detected_class = "None"
                    else:
                        for bb in res["result"]["bounding_boxes"]:
                            # According to the detected label, print the generated bounding boxes on the given frame to produce the model resulting image.
                            self.detected_class = bb['label']
                            if(debug): print('\t%s (%.2f): x=%d y=%d w=%d h=%d' % (bb['label'], bb['value'], bb['x'], bb['y'], bb['width'], bb['height']))
                            cropped = cv2.rectangle(cropped, (bb['x'] - bb_offset["x"], bb['y'] - bb_offset["y"]), (bb['x'] + bb['width'] + bb_offset["x"], bb['y'] + bb['height'] + bb_offset["y"]), (255, 0, 255), 3)
                # If requested, show the model detection image with the added bounding boxes if any on the screen.
                if(show_img):
                    cv2.imshow("Model Detection Image", cropped)
                # As detecting a class successfully, save the produced model resulting image and activate the model resulting data transfer.
                if(self.detected_class != "None"):
                    self.save_img(self.detected_class, cropped)
                    self.activate_model_result_send = True
            # Stop the running inference.    
            finally:
                if(runner):
                    runner.stop()

    def get_latest_camera_frame(self, show_img=False):
        if(self.cam_init == True):
            # Obtain the real-time video stream generated by the USB camera.
            ret, img = self.camera.read()
            # Resize the captured frame depending on the given object detection model.
            mod_img = cv2.resize(img, self.frame_size)
            self.latest_frame = mod_img
            # If requested, show the modified frame on the screen.
            if(show_img):
                cv2.imshow("Latest Camera Image!", self.latest_frame)
        # Stop the camera feed if requested.
        if cv2.waitKey(1) & 0xFF == ord('q'):
            self.camera.release()
            cv2.destroyAllWindows()
            print("\nCamera Feed Stopped!")

    def save_img(self, given_class, given_frame):
        # Create the file name for the given image.
        date = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
        self.resulting_img_filename = "/product_verification_images/IMG_{}_{}.jpg".format(given_class, date)
        # Save the modified model resulting image.
        cv2.imwrite(self.dir_path.replace("/object_detection_model", self.resulting_img_filename), given_frame)

    def generate_model_resulting_info(self):
        # Depending on the model results, produce the model resulting information.
        resulting_info = {"product_confirmation_image": "None", "detected_product_class": "None"}
        if(self.activate_model_result_send):
            resulting_info = {"product_confirmation_image": self.resulting_img_filename[1:], "detected_product_class": self.detected_class}
            self.activate_model_result_send = False
        # Then, pass the generated data packet as a JSON object.
        print(json.dumps(resulting_info))
    
    def classify_products(self):
        self.get_latest_camera_frame()
        self.run_inference()
        self.generate_model_resulting_info()
        
# Define the product_classification object.
product_classification = product_classification("digital-twin-enabled-smart-shipping-workstation-linux-aarch64-v2.eim")

# Initiate the product classification process for once.
product_classification.classify_products()
