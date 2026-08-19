import matplotlib.pyplot as plt

plt.plot([1, 2, 3], [1, 4, 9])
plt.title("Test Plot")

plt.savefig("plot.svg", dpi=200, bbox_inches="tight")
plt.show()
