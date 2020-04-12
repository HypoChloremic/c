import matplotlib.pyplot as plt
import numpy as np
im

# Note that we are working with the same
# values, so this x,y is not really required
# we can do it differently.
# x = np.arange(0,10, 0.1)
# y = np.arange(0,10, 0.1)

i = np.arange(0,10, 0.1)

# Note: we are using the same `i`, angle,
# for both of the functions. 
x = np.multiply(200, np.sin(i))
y = np.multiply(200, np.cos(i))

y2 = np.arange(0,10, 0.1)
y2 = np.multiply(200, np.cos(np.multiply(2,y2)))



fig, axs = plt.subplots(ncols=2)
axs = axs.flatten()

axs[0].scatter(x,y)
axs[1].scatter(x,y2)

plt.show()