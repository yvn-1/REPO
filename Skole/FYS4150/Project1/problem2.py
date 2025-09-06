import matplotlib.pyplot as plt

file = open("problem2.txt")

x = []
ux = []

for line in file:
    vals = line.split(",")
    x.append(vals[0])
    ux.append(vals[1])

plt.plot(x,ux)
plt.savefig("problem2.pdf")
