import pandas as pd
import numpy as np
import os


class TreeNode:
    def __init__(self, attribute):
        self.attribute = attribute
        self.children = []


def find_dataset():
    filepath = input("Enter the dataset name: ")
    if ".csv" not in filepath:
        filepath += ".csv"
    if not os.path.exists(filepath):
        print("Dataset does not exist. Check File Path.")
        exit(0)
    else:
        print("Dataset found.")
    return filepath

def calc_entropy(attribute: str, attrdict: dict[str: set[str]]) -> int:
    return 0

# [['Sunny' 'Warm' 'Normal' 'Strong' 'Warm' 'Same' 'Yes']
#  ['Sunny' 'Warm' 'High' 'Strong' 'Warm' 'Same' 'Yes']
#  ['Rainy' 'Cold' 'High' 'Strong' 'Warm' 'Change' 'No']
#  ['Sunny' 'Warm' 'High' 'Strong' 'Cool' 'Change' 'Yes']]

# print(data.values)


def decisionTree(df: pd.DataFrame):
    data = df.values
    rows, cols = df.shape
    # Because The first row of data is always the attributes
    attrdict: dict[str, set[str]] = df.to_dict()

    for key in attrdict.keys():
        attrset = set()
        for k in attrdict[key].keys():
            attrset.add(attrdict[key][k])
        attrdict[key] = attrset
    print(attrdict)

    entropylist = []
    for attribute in attrdict.keys():
        entropylist.append(calc_entropy(attribute, data))

    print(entropylist)
    pass


if __name__ == "__main__":
    dataset = find_dataset()
    df = pd.read_csv(dataset)
    decisionTree(df)
