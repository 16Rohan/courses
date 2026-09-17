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
h1 = 1
h2 = 1  
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

    w1 += learning_rate * dw1 
    w2 += learning_rate * dw2 
    bias += learning_rate * db 


if __name__ == "__main__":
    pass
