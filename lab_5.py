def factorial(i):
    if i > 0:
        return factorial(i - 1) * i
    else:
        return 1

e = pow(10, -5)

total = 0
for x in range(1, 6):
    k = 0
    while True:
        result = pow(-1, k) * (pow(x, 2 * k + 1) / factorial(k) * (2 * k + 1))
        total += result
        k += 1
        if abs(result) < e:
            break
    print(total)

