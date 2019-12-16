# ILSVRC2012 ImageNet 10K Validataion Images and devkit

ILSVRC2012 ImageNet 10K Validataion Images and devkit for tflite Evaluation in Edge Devices [example: Pi3/4]  
  
```
git clone https://github.com/ghimiredhikura/ILSVRC2012_img_val_10K
cd ILSVRC2012_img_val_10K
```

```
cd ILSVRC2012_img_val_10K
source generate_validation_labels.sh
mv validataion_labels.txt ../validataion_labels.txt
cd ../
```

```
download_ILSVRC2012_img_val_10K.sh
```

```
git clone https://github.com/tensorflow/tensorflow
cd tensorflow
git reset --hard 64c3d382cadf7bbe8e7e99884bede8284ff67f56 # tensorflow-2.0.0
cd ../
source imagenet_eval.sh
```