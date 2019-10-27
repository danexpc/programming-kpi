import math

def func(n):
    y = y_0 = math.sqrt(3 * n)

    for i in range(n-1, 0, -1):
        y = math.sqrt(3*i + y_0)
        y_0 = y
    return y

n = int(input('n: '))
print(func(n))
