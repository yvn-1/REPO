import matplotlib.pyplot as plt

file = open("problem2.txt")

x = []
ux = []

for line in file:
    vals = line.split(",")
    x.append(float(vals[0]))
    ux.append(float(vals[1]))

plt.plot(x,ux)
plt.grid(True)
plt.xlabel("x")
plt.ylabel("u(x)")

plt.savefig("problem2.pdf")
