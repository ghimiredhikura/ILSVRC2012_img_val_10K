
g++ nvisoeval/nvisoeval.cpp -o nvisoeval

./nvisoeval mobilenet_v2_imagenet.txt data/ground_truth_labels_10K.txt data/labels.txt

rm -rf nvisoeval