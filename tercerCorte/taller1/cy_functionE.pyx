#cython: language_level=3
import numpy as np
cimport numpy as np

cdef extern from "math.h":
    double exp(double x) nogil
    double pow(double x, double y) nogil
    
ctypedef np.double_t DTYPE_t
def rbf_network(np.ndarray[DTYPE_t, ndim=2] X, np.ndarray[DTYPE_t, ndim=1] beta, int theta):
    cdef int N, D, i, j, d
    cdef np.ndarray[DTYPE_t, ndim=1] Y
    cdef double r 

    N = X.shape[0]
    D = X.shape[1]

    Y = np.zeros(N)

    for i in range(N):
        for j in range(N):
            r = 0
            for d in range(D):
                r += pow(X[j, d] - X[i, d], 2)
            r = pow(r, 0.5)
            Y[i] += beta[j] * exp(-pow((r * theta), 2))

    return Y
