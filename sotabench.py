import numpy as np

from sotabencheval.image_classification import ImageNetEvaluator

evaluater = ImageNetEvaluator(
            model_name='MobileNet-v2',
            paper_arxiv_id='1801.04381')

with open('mobilenet_v2_imagenet.txt', 'r') as file:
    lines = readlines(file)
    for line in lines:
        image_id, preds = line.split(":")
        preds = preds.lstrip().rstrip()
        preds = np.asarray(preds)
        print(image_id, preds)
    break
