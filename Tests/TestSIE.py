import numpy as np
import matplotlib.pyplot as plt
import os

os.system('./TestSIE > output.txt')
output = np.loadtxt('output.txt')

n = np.int64(np.sqrt(output.size/3))
x = output[0:n**2]
y = output[n**2:2*n**2]
sigma = output[2*n**2:3*n**2]
h = x[1] - x[0]

x = x.reshape((n,n))
y = y.reshape((n,n))
sigma = sigma.reshape((n,n))
sigma[np.nonzero(sigma == np.max(sigma))] = 0.

inside = np.nonzero(x**2 + y**2 < 1.)
mass = np.sum(sigma[inside]*h**2)

plt.imshow(np.log(sigma))
plt.title(mass)
plt.show()

