import matplotlib.pyplot as plt
import numpy as np

a = int(input("please enter a ->"))
b = int(input("please enter b ->"))
c = int(input("please enter c ->"))

x = np.arange(-100, 100)
y = [(a * i * i + b * i + c) for i in x]
print(type(y))
# y = [(a * i * i) for i in x]
plt.plot(x, y)
plt.show()
