
cd tensorflow

IMAGENET_IMAGES_DIR="../ILSVRC2012_img_val_10K/"
VALIDATION_LABELS="../validataion_labels.txt"
MODEL_LABELS_TXT="../labels.txt"

bazel-1.1.0 run -c opt \
  --cxxopt='--std=c++11' \
  -- \
  //tensorflow/lite/tools/accuracy/ilsvrc:imagenet_accuracy_eval \
  --model_file=../mobilenet_v2_1.4_224.tflite \
  --ground_truth_images_path=${IMAGENET_IMAGES_DIR} \
  --ground_truth_labels=${VALIDATION_LABELS} \
  --model_output_labels=${MODEL_LABELS_TXT} \
  --output_file_path=accuracy_output.txt \
  --num_images=0 # Run on all images.