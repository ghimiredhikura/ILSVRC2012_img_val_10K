import numpy as np

from sotabencheval.image_classification import ImageNetEvaluator

evaluater = ImageNetEvaluator(
            model_name='MobileNet-v2',
            paper_arxiv_id='1801.04381')

image_ids = []
preds = []
with open('mobilenet_v2_imagenet.txt', 'r') as file:
    lines = file.readlines()
    for line in lines:
        image_id, pred = line.split(":")
        image_id = image_id.rstrip().lstrip()
        pred = pred.lstrip().rstrip()
        pred = np.fromstring(pred, dtype=float, sep=' ')
        image_ids.append(image_id)
        preds.append(pred)

    evaluater.add(dict(zip(image_ids, preds)))

    evaluater.get_results()
