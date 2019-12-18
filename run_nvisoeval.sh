
g++ nvisoeval/nvisoeval.cpp -o nviso_imagenet_eval

./nviso_imagenet_eval mobilenet_v2_imagenet.txt data/ground_truth_labels_10K.txt data/labels.txt