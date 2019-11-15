import random
import numpy as np

def matrix_creation(n_rows, n_columns):
    mx = np.array([[random.randint(-5, 5) for i in range(n_columns)] for j in range(n_rows)])

    return mx

def average_values_rows_matrix(matrix, n_rows, n_columns ):
    array = []
    for j in range(n_columns):
        b = 0
        for i in range(n_rows):
            b += matrix[i][j]
        b = b / n_rows
        array.append(b)

    return array

def value_Y(array1, array2):
    Y = abs(array1[0] - array2[0])
    for i in range(1, len(array1)):
        Y += abs(array1[i] - array2[i])

    return Y

print('Укажите размеры матриц вида m x n')

m = int(input('m = '))
n = int(input('n = '))

mx_1 = matrix_creation(m, n)
mx_2 = matrix_creation(m, n)
print(mx_1)
print(mx_2)

B = average_values_rows_matrix(mx_1, m, n)
T = average_values_rows_matrix(mx_2, m, n)

print(F"Y = {value_Y(B, T)}")
