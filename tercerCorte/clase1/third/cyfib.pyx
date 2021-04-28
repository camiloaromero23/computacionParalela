#cython language_level=3
def fib(int n):
    cdef int i
    cdef double a, b
    a, b = 0.0, 1.0
    for i in range(n):
        a, b = a+b, a
    return a


if __name__ == '__main__':
    import sys
    # cdef int i, arg, numiter
    arg, numiter = map(int, sys.argv[1:])

    for i in range(numiter):
        fib(arg)

