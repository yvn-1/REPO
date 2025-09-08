import matplotlib.pyplot as plt

def handle_file(f):
    file = open(f"problem7{f}.txt")
    x = []
    v = []
    for l in file:
        vals = file.split(",")
        x.append(vals[0])
        v.append(vals[1])
    return x,v

sizes = [10,100,1000,10000,100000]

for s in sizes:
    xv = handle_file(s)
    plt.plot(xv[0],xv[1])

plt.savefig("problem7b.pdf")

    
