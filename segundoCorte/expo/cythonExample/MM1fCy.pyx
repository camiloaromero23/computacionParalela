from time import time
import cython
from cython.parallel import parallel,prange

def printMatrix(int MATRIX_SIZE, matrix,str matrixName):
    if(MATRIX_SIZE <= 5):
        print("\n", matrixName, end="\n")
        for i in range(MATRIX_SIZE):
            for j in range(MATRIX_SIZE):
                print(matrix[i][j], end="\t")
            print(end="\n")

cdef int i,j,k
cdef int MATRIX_SIZE = 400


cdef list matrixA = []
cdef list matrixB = []
cdef list result = []
cdef list transposeMatrixB = []

for i in range(MATRIX_SIZE):
    matrixA.append([])
    matrixB.append([])
    result.append([])
    transposeMatrixB.append([])


for i in range(MATRIX_SIZE):
    for j in range(MATRIX_SIZE):
        result[i].append(0.0)

cdef double start = time()


# with cython.nogil, parallel():
for i in range(MATRIX_SIZE):
    for j in range(MATRIX_SIZE):
        matrixA[i].append(2.0 * (i+j))
        matrixB[i].append(3.0 * (i-j))

for i in range(MATRIX_SIZE):
    for j in range(MATRIX_SIZE):
        transposeMatrixB[i].append(matrixB[j][i])

# with cython.nogil, parallel():
for i in range(MATRIX_SIZE):
        for j in range(MATRIX_SIZE):
            for k in range(MATRIX_SIZE):
                result[i][j] += matrixA[i][k] * transposeMatrixB[j][k]
# printMatrix(MATRIX_SIZE,result,"Result")            
cdef double end = time()

cdef double total_time = end - start

# print(start)
# print(end)
print("Total Time",total_time)
