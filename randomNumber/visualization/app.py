import matplotlib.pyplot as plt
import csv

x_vals = []
y_vals = []

with open('file.csv', 'r') as file:
    reader = csv.reader(file)
    for row in reader:
        x_vals.append(int(row[0]))
        y_vals.append(int(row[1]))

plt.plot(x_vals, y_vals)
plt.xlabel("Increasing Number")
plt.ylabel("Generated Random Number")
plt.title("Random Number Generation")
plt.show()