import matplotlib.pyplot as plt

datax = []
datay = []
f = open("battery_life_data.txt", "r")
for line in f:
    datax.append(line.split(",")[0])
    datay.append(line.split(",")[1])
f.close()

plt.plot(datax, datay, 'ro')
plt.savefig('battery_life_data.png', bbox_inches='tight')
plt.show()
