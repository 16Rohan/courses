import math
import sys
import random
from typing import Callable

sigmoid_function = lambda x: 1 / (1 + math.exp(-x))
step_function = lambda x: 1 if x >= 0 else 0

activation_function: Callable[[float], float] | None = None

# Initial values
w1 = 1
w2 = 1
bias = -1.5
learning_rate = 0.2
epochs = 10

AND_TABLE = {
    (0, 0): 0,
    (0, 1): 0,
    (1, 0): 0,
    (1, 1): 1,
}

OR_TABLE = {
    (0, 0): 0,
    (0, 1): 1,
    (1, 0): 1,
    (1, 1): 1,
}


def calculate_output(x1, x2):
    global w1, w2, bias

    x1 = int(x1)
    x2 = int(x2)

    z = (w1 * x1) + (w2 * x2) + bias

    if activation_function is not None:
        return activation_function(z)
    else:
        raise RuntimeWarning("Activation Function has not been configured")


def learn(x1, x2, table):
    global w1, w2, bias

    x1 = int(x1)
    x2 = int(x2)

    expected = table[(x1, x2)]
    result = calculate_output(x1, x2)

    err = expected - result

    dw1 = err * x1
    dw2 = err * x2
    db = err

    w1 += learning_rate * dw1 + (random.random() - 0.5)/10
    w2 += learning_rate * dw2 + (random.random() - 0.5)/10 
    bias += learning_rate * db + (random.random() - 0.5)/10

    return result, expected, err

def test_table(table):
    for x1, x2 in table:
        result = calculate_output(x1, x2)
        print(f"{x1} {x2}: {result}")


def autolearn(table):
    for epoch in range(epochs):
        for x1, x2 in table:
            learn(x1, x2, table)

    print(f"After {epochs} epochs, " f"w1: {w1}, w2: {w2}, bias: {bias}")
    test_table(table)


if __name__ == "__main__":
    activation_function = step_function

    if len(sys.argv) > 1:
        if sys.argv[1] == "--al2":
            autolearn(OR_TABLE)

        elif sys.argv[1] == "--al1":
            autolearn(AND_TABLE)

        sys.exit(0) 

    while True:
        inputs = input("Enter inputs (q to quit): ")

        if inputs.lower() == "q":
            break

        if len(inputs) != 2:
            print("Input limit exceeded. Please enter exactly 2 digits (e.g., 01).")
            continue

        if inputs[0] not in "01" or inputs[1] not in "01":
            print("Inputs should be 0 or 1")
            continue

        table_choice = input("1. AND\n2. OR\nEnter Choice: ")

        if table_choice not in ("1", "2"):
            print("Enter integer between 1 and 2")
            continue

        table = AND_TABLE if table_choice == "1" else OR_TABLE

        result = calculate_output(inputs[0], inputs[1])

        print(f"Current output for {inputs} is: {result}")

        for _ in range(10):
            learn(inputs[0], inputs[1], table)

        print(f"After learning: w1={w1}, w2={w2}, bias={bias}")

    print("Exiting...")
