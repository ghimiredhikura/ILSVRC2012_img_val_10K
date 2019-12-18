
echo "Downloading ILSVRC2012_img_val_10K dataset!"
python scripts/google_drive_download.py

unzip ILSVRC2012_img_val_10K.zip
rm -rf ILSVRC2012_img_val_10K.zip

echo "Complete: Downloading ILSVRC2012_img_val_10K dataset!"