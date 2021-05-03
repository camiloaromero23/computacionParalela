from functionE import rbf_network
from cy_functionE import cy_rbf_network
import numpy as np
import time

D = 5
N = 1500
X = np.array([np.random.rand(N) for d in range(D)]).T
beta = np.random.rand(N)
theta = 10

start = time.time()
rbf_network(X, beta, theta)


total_time = time.time() - start

start = time.time()
cy_rbf_network(X, beta, theta)
cy_total_time = time.time() - start

speedUp = round(total_time/cy_total_time, 3)
print("Python time: {} \n".format(total_time))
print("Cython time: {} \n".format(cy_total_time))
print("SpeedUp: {} \n".format(speedUp))
