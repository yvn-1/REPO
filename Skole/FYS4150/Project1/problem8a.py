import matplotlib.pyplot as plt
import numpy as np


def read_and_analyze(filename,N):
    fil = open(filename)
    x = []
    error = []
    for l in fil:
        vals = l.split(",")
        x.append(float(vals[0]))
        error.append(float(vals[1]))
    plt.plot(x,error,label=f"Error when N={N}")

read_and_analyze("problem710.txt",10)
read_and_analyze("problem7100.txt",100)
read_and_analyze("problem71000.txt",1000)
read_and_analyze("problem710000.txt",10000)
read_and_analyze("problem7100000.txt",100000)
read_and_analyze("problem71000000.txt",1000000)
read_and_analyze("problem710000000.txt",10000000)

plt.grid(True)
plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.savefig("problem8a.pdf")


