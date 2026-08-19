# To find Distinct, Syntactically Distinct, and Semantically Distinct examples: 

num_attr = input("Enter number of attributes: ")
attr_val_count = list(int(x) for x in input(f"Enter number of distinct values of {num_attr} attributes: ").split())

prod = 1
for i in range(len(attr_val_count)):
    prod *= attr_val_count[i]
print("Distinct Hypo:", prod)

prod = 1
for i in range(len(attr_val_count)):
    prod *= (attr_val_count[i] + 1)
print("Semantically Distinct Hypo:", prod + 1)

prod = 1
for i in range(len(attr_val_count)):
    prod *= (attr_val_count[i] + 2)
print("Syntactically Distinct Hypo:", prod)