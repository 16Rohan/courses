import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import math


# Load data
data = pd.read_csv("tips.csv")

bill = data["total_bill"].to_numpy()
tip = data["tip"].to_numpy()


def calculate_weights(point, bills, bandwidth):
    """Give nearby bills more weight than distant bills."""

    distance = bills - point

    weights = np.exp(-(distance**2) / (2 * bandwidth**2))

    return weights


def predict_tip(point, bills, tips, bandwidth):
    """Predict tip for a given bill amount."""

    weights = calculate_weights(point, bills, bandwidth)

    # Weighted averages
    weighted_bill = np.sum(weights * bills)
    weighted_tip = np.sum(weights * tips)
    total_weight = np.sum(weights)

    bill_mean = weighted_bill / total_weight
    tip_mean = weighted_tip / total_weight

    numerator = np.sum(weights * (bills - bill_mean) * (tips - tip_mean))

    denominator = np.sum(weights * (bills - bill_mean) ** 2)

    slope = numerator / denominator

    intercept = tip_mean - slope * bill_mean

    prediction = intercept + slope * point

    return prediction

len_tip = len(tip)
mean_tip = sum(tip) / len_tip

sd = math.sqrt(sum(x ** 2 for x in tip) / len_tip - mean_tip )

print(f"Mean tip: {mean_tip}")


bandwidth = 2.0

user_input = input("Enter total bill: ")

if not user_input.isnumeric():
    print("This value is not a number")
    exit(1)

bill_amount = float(user_input)

predicted_tip = predict_tip(bill_amount, bill, tip, bandwidth)

print(f"Predicted tip: ${predicted_tip:.2f}")
