## ILSVRC2012 ImageNet Accuracy Benchmarking on 10K Validataion Images

ILSVRC2012 ImageNet 10K Validataion Images and devkit for Top-1 & Top-5 Accuracy Benchmarking in Edge Devices [example: RPi3/4]  
  
```
git clone https://github.com/ghimiredhikura/ILSVRC2012_img_val_10K
cd ILSVRC2012_img_val_10K/data/
unzip mobilenet_v2_imagenet.zip
rm -rf mobilenet_v2_imagenet.zip
mv mobilenet_v2_imagenet.txt ../mobilenet_v2_imagenet.txt
cd ../
```

Download ILSVRC2012 validataion images - 10K images and use your inference engine to get dump file. 
Example: [inference script](https://gitlab.com/bonseyes/misc/devplatform-rasberrypi3/blob/master/benchmark/frameworks/opencv-4/benchmark/benchmark-nviso/benchmark_imagenet_eval.cpp), [reference models running scipt](https://gitlab.com/bonseyes/misc/devplatform-rasberrypi3/blob/master/benchmark/frameworks/opencv-4/imagenet_eval.sh). 

```
chmod +x scripts/download_ILSVRC2012_img_val_10K.sh
./scripts/download_ILSVRC2012_img_val_10K.sh
```

Now use your prediction dump file generated using your favorite inference engine to get top-1 and top-5 accuracies. Here we provide an example imagenet dump file on 10K images using [opencv-4.1.1 dnn classification engine](https://gitlab.com/bonseyes/misc/devplatform-rasberrypi3/blob/master/benchmark/frameworks/opencv-4/benchmark/benchmark-nviso/benchmark_imagenet_eval.cpp) with mobilenetv2 caffe model. Once you have this dump file you can use following command to get top-1 and top-5 accuracies. 
```
source run_nvisoeval.sh mobilenet_v2_imagenet.txt
```

## **Results**

| **Inference Engine**| **Model**  	  | **Valid Images** |  **RaspberryPi4B-armv7l**| **RaspberryPi4B-armv7l** | **RaspberryPi4B-aarch64**  | **RaspberryPi4B-aarch64** |
|------------------- | ------------- | :---------: | :---------:   | :---------: |:---------: |:---------: |
|      	              |               |    | Top-1 Accuracy | Top-5 Accuracy | Top-1 Accuracy | Top-5 Accuracy| 
| opencv-4.1.1    | [Mobilenet_V2_1.0_224_caffe](https://github.com/shicai/MobileNet-Caffe)| 10K |   62.32 %   | 84.04 %       |               |              |
| tflite-2.0.0    | [Mobilenet_V2_1.0_224_tflitehm](https://storage.googleapis.com/download.tensorflow.org/models/tflite_11_05_08/mobilenet_v2_1.0_224.tgz)| 10K |   71.06 %   | 90.10 %       |               |              |