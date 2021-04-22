def fib(n):
    a, b = 0.0, 1.0
    for _ in range(n):
        a, b = a+b, a
    return a


if __name__ == '__main__':
    import sys
    arg, numiter = map(int, sys.argv[1:])

    for _ in range(numiter):
        fib(arg)
