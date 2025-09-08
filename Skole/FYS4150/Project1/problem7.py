import matplotlib.pyplot as plt

file = open("problem7.txt")

x = []
v = []

for line in file:
    vals = line.split(",")
    x.append(vals[0])
    v.append(vals[1])

plt.plot(x,v)
plt.savefig("problem7a.pdf")
