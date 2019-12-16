echo "Downloading ILSVRC2012_img_val_10K dataset!"
python google_drive_download.py

tar -xvf ILSVRC2012_img_val_10K.zip
rm -rf ILSVRC2012_img_val_10K.zip

echo "Complete: Downloading ILSVRC2012_img_val_10K dataset!"