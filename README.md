# ILSVRC2012 ImageNet 10K Validataion Images and devkit for Evaluation



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
source imagenet_eval.sh
```