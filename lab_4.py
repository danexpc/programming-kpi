import math
def root_sequence(n):
    y = math.sqrt(3 * n)
    for i in range(n - 1, 0, -1):
        y = math.sqrt(3 * i + y)
    return y

n = int(input('n: '))
print(root_sequence(n))
