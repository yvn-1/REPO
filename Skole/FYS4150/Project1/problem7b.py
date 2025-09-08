import matplotlib.pyplot as plt

def handle_file(f):
    fil = open(f"problem7{f}.txt")
    x = []
    v = []
    for l in fil:
        vals = l.split(",")
        x.append(float(vals[0]))
        v.append(float(vals[1]))
    return x,v

sizes = [10,100,1000,10000,100000]

for s in sizes:
    xv = handle_file(s)
    plt.plot(xv[0],xv[1],label=f"N={s}")
fil = open("problem2.txt")

x =[]
v = []
for l in fil:
    vals = l.split(",")
    x.append(float(vals[0]))
    v.append(float(vals[1]))
plt.plot(x,v,label="Analytical")

plt.xlabel('x')
plt.ylabel('v_i')
plt.grid(True)
plt.legend()
plt.savefig("problem7b.pdf")

    
