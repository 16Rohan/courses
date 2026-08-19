import pandas as pd
import numpy as np
import random

def dist(a: np.ndarray, b: np.ndarray) -> float:
    total = 0
    for i in range(4):
        total += (a[i] - b[i]) ** 2
    return total

def check_tolerance(old_centers, new_centers, tol: float = 0.01):
    pass

data = pd.read_csv('iris.csv')
n = len(data.values)
k = int(input("Enter K: "))
tol = float(input("Enter tolerance: "))

centers = []
groups = list([] for _ in range(k))
print(f"Number of groups: {k}")

for i in range(k):
    # Randomly choose K centers
    centers.append(random.randint(0,n))

# ONE iteration of KMC

for i in range(n):
    curPoint = data.values[i]
    minGrpIdx = 0
    minDist = 99999
    
    for j in range(k):
        curCenter = data.values[centers[j]]
        curDist = dist(curPoint, curCenter)
        if curDist < minDist:
            minDist = curDist
            minGrpIdx = j
    
    groups[minGrpIdx].append(i)


for c in centers:
    print(c, data.values[c])
for i in range(k):
    print("Group", i)
    print(groups[i])

# Remaining iterations unless the centers reach a level of tolerance 


old_centers = 

# print(data.values)


# for obj in data.values:





