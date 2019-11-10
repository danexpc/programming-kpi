import math

def integral(a, b, n):
    total = 0
    for i in range(1, n + 1):
        h1 = math.pi / n
        x1 = a + i * h1 - h1 / 2
        total += h1 * math.log1p(2 + math.sin(x1))

        h2 = (b - a) / n
        x2 = a + i * h2 - h2 / 2
        total += h2 * pow(math.atan(x2), 2)

    return total

print('Задайте границы: ')
try:
    a = int(input('От: '))
    b = int(input('До: '))
    n = int(input('Задайте n: '))
    while n <= 0:
        print('Неверное значение n(n > 0)')
        n = int(input('Задайте n: '))
except ValueError:
    print('Вводьте только целые числа!')
print(f"Результат: {integral(a, b, n)}")
