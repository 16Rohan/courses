import pandas as pd
import numpy as np

df = pd.read_csv(r"car_find-s2.csv")
print("Dataset:", df.values)
attribute_count = len(df.columns) - 1

print("Number of attributes:",attribute_count)
hyp = ["NULL",] * attribute_count

for instance in df.values:
    if instance[-1] == "+":
        for idx in range(attribute_count):        
            if instance[idx] != hyp[idx] and hyp[idx] == "NULL":
                hyp[idx] = instance[idx]
            elif instance[idx] != hyp[idx]:
                hyp[idx] = "?"


print("The most specific hypothesis consistent with the dataset is:",hyp)
