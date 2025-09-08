import matplotlib.pyplot as plt
import numpy as np


def read_and_analyze(filename):
    fil = open(filename)
    x = []
    v = []
    for l in fil:
        vals = l.split(",")
        x.append(float(vals[0]))
        v.append(float(vals[1]))
    u = []
    for e in x:
        u.append(1-(1-np.exp(-10))*e-np.exp(-10*e))
    err = []
    for i in range(1,len(x)):
        err.append(np.maximum(np.log10(abs(u[i]-v[i])),1e-300))
    plt.plot(x[1:],err,label=f"Error when N={len(x)}")

read_and_analyze("problem710.txt")
read_and_analyze("problem7100.txt")
read_and_analyze("problem71000.txt")
read_and_analyze("problem710000.txt")
read_and_analyze("problem7100000.txt")

plt.grid(True)
plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.savefig("problem8a.pdf")


