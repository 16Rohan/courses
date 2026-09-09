import math
import sys

sigmoid_function = lambda x: (1 / (1 + math.exp(-1 * x)))
step_function = lambda x: 1 if x >= 0 else 0
activation_function = None

# Defining constants
w1 = 1
w2 = 1
bias = -1.5
learning_rate = 0.2

AND_TABLE = {(0,0):0,(0,1):0,(1,0):0,(1,1):1,}
OR_TABLE = {(0,0):0,(0,1):1,(1,0):1,(1,1):1,}

def calculate_output(x1, x2):
    global w1
    global w2
    global bias

    x1 = int(x1)
    x2 = int(x2)

    z = (w1 * x1) + (w2 * x2) + bias
    res = activation_function(z)

    return res

def learn(x1, x2, result, table, count, relearn):
    global w1
    global w2
    global bias
    og_count = count
    x1, x2 = int(x1), int(x2)

    err = table[(x1, x2)] - result
    dw1 = err * x1
    dw2 = err * x2
    db = err

    w1 = w1 + learning_rate * dw1
    w2 = w2 + learning_rate * dw2
    bias = bias + learning_rate * db

    for i in range(count):
        if not relearn: break
        

    


def autolearn():
    raise NotImplementedError

if __name__ == "__main__":
    if(sys.argv[0] == "--al"):
        autolearn()
    while True:
        inputs = input("Enter inputs (q to quit): ")
        if "q" in inputs:
            break
        # Input Validation
        if len(inputs) != 2:
            print("Input limit exceeded. Please enter exactly 2 digits (e.g., 01).")
            continue  # use continue instead of break to let them try again

        # Now check if characters are valid
        if inputs[0] not in "01" or inputs[1] not in "01":
            print("Inputs should be 0 or 1")
            continue

        table = input("1. AND \n2. OR\nEnter Choice: ")
        try:
            if not table.isnumeric():
                print("Non-Numeric Value Entered.")
                raise Exception
            if len(table) > 1 :
                print("Enter integer between 1 and 2")
                raise Exception
        except:
            continue

        if table == "1":
            table = AND_TABLE
        elif table == "2":
            table = OR_TABLE    

        activation_function = step_function
        result = calculate_output(inputs[0], inputs[1])
        print(f"Current output for {inputs} is: {result}")

        learn(inputs[0], inputs[1], result, table, 10)

print("Exiting...")