#cython: language_level=3
import numpy as np
cimport numpy as np

cdef extern from "math.h":
    double exp(double x) nogil
    double pow(double x, double y) nogil
    
ctypedef np.double_t DTYPE_t
def cy_rbf_network(np.ndarray[DTYPE_t, ndim=2] X, np.ndarray[DTYPE_t, ndim=1] beta, int theta):
    cdef int N
    cdef np.ndarray[DTYPE_t, ndim=1] Y

    N = X.shape[0]
    Y = np.zeros(N)
    doY(X, Y, beta, theta, N)
    
    return Y

cdef void doY(np.ndarray[DTYPE_t, ndim=2] X, np.ndarray[DTYPE_t, ndim=1] Y, np.ndarray[DTYPE_t, ndim=1] beta, int theta, int N) :
    cdef int i, j, d, D 
    cdef double r 

    D = X.shape[1]

    for i in range(N):
        for j in range(N):
            r = 0
            for d in range(D):
                r += pow(X[j, d] - X[i, d], 2)
            r = pow(r, 0.5)
            Y[i] += beta[j] * exp(-pow((r * theta), 2))

