
DUMP_DATA=$1

g++ nvisoeval/nvisoeval.cpp -o nviso_imagenet_eval

./nviso_imagenet_eval $DUMP_DATA data/ground_truth_labels_10K.txt data/labels.txt