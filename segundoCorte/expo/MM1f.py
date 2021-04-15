from sys import argv
from typing import List
from time import time

Matrix = List[List[float]]


def initMatrix(matrixA: Matrix, matrixB: Matrix):
    for i in range(MATRIX_SIZE):
        for j in range(MATRIX_SIZE):
            matrixA[i][j] = 2.0 * (i+j)
            matrixB[i][j] = 3.0 * (i-j)


def printMatrix(matrix: Matrix, matrixName: str):
    if(len(matrix) <= 5):
        print("\n", matrixName, end="\n")
        for i in range(len(matrix)):
            for j in range(len(matrix)):
                print(matrix[i][j], end="\t")
            print(end="\n")


def multiplyMatrix(matrixA: Matrix,  transposeMatrixB: Matrix,  result: Matrix):
    for i in range(MATRIX_SIZE):
        for j in range(MATRIX_SIZE):
            for k in range(MATRIX_SIZE):
                result[i][j] += matrixA[i][k] * transposeMatrixB[j][k]


def transposeMatrix(matrix: Matrix) -> Matrix:
    return [[matrix[j][i]
             for j in range(MATRIX_SIZE)] for i in range(MATRIX_SIZE)]


if (len(argv) != 2):
    print("python3", argv[0], "<matrix size>")
    exit(-1)

MATRIX_SIZE = int(argv[1])

matrixA = [[0.0] * MATRIX_SIZE for _ in range(MATRIX_SIZE)]
matrixB = [[0.0] * MATRIX_SIZE for _ in range(MATRIX_SIZE)]
transposeMatrixB = [[0.0] * MATRIX_SIZE for _ in range(MATRIX_SIZE)]
result = [[0.0] * MATRIX_SIZE for _ in range(MATRIX_SIZE)]


initMatrix(matrixA, matrixB)

# printMatrix(matrixA, "Matrix A")
# printMatrix(matrixB, "Matrix B")
start = time()
transposeMatrixB = transposeMatrix(matrixB)
# printMatrix(transposeMatrixB, "Transpose B")

multiplyMatrix(matrixA, transposeMatrixB, result)
end = time()
print("Total Time", end-start)
# printMatrix(result, "result")
