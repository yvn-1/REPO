import numpy as np
import matplotlib.pyplot as plt

general_avg_N = []
improved_avg_N = []

for N in [10,100,1000,10000,100000,1000000]:
    improved = open(f"problem10improved{N}.txt")
    general = open(f"problem10general{N}.txt")
    
    avg_improved = 0
    len_improved = 0
    for li in improved:
        avg_improved+=float(li)
        len_improved+=1
    avg_improved /= len_improved

    avg_general = 0
    len_general = 0
    for lg in general:
        avg_general +=float(lg)
        len_general += 1
    avg_general /= len_general

    general_avg_N.append((N,avg_general))
    improved_avg_N.append((N,avg_improved))

plt.plot(general_avg_N,label="General")
plt.plot(improved_avg_N,label="Improved")
plt.grid(True)
plt.xlabel("Number of steps N")
plt.ylabel("Average timing [s]")
plt.savefig("problem10.pdf")
