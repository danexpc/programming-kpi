import copy

print("_____________________________________________1_ЧАСТИНА__________________________________________________________\n")

def readFile(array):
    with open("input.txt") as file:
        for line in file:
            array.append(line.split())

    for item in range(len(array)):
            array[item][0] = int(array[item][0])
            array[item][1] = int(array[item][1])


def creatingArray(m, n):
    array = [[0 for j in range(n)] for i in range(m)]
    return array


def creatingMatrixAdjance(array, date):
    for i in date:
        array[i[0] - 1][i[1] - 1] = 1
        array[i[1] - 1][i[0] - 1] = 1


def printMatrix(array, m, n):
    for i in range(m):
        for j in range(n):
            print(f"{array[i][j]:2}", end="  ")
        print("\n")


def matrixMultiplication(matrix, m, n):
    counter = 1
    totalMatrix = copy.deepcopy(matrix)
    while counter < n:
        timeMatrix = copy.deepcopy(totalMatrix)
        counter += 1
        for i in range(m):
            for j in range(m):
                c = 0
                for k in range(m):
                    c += timeMatrix[i][k] * matrix[k][j]
                totalMatrix[i][j] = c
    return totalMatrix


def compare(matrix1, matrix2, m, n):
    for i in range(m):
        for j in range(m):
            if (matrix1[i][j] == 'oo') and (matrix2[i][j] > 0) and (matrix2[i][j] <= n):
                matrix1[i][j] = n


def creatingMatrixDistance(matrixAd, m):
    matrixDis = copy.deepcopy(matrixAd)
    for i in range(m):
        for j in range(m):
            if i != j and matrixDis[i][j] == 0:
                matrixDis[i][j] = 'oo'
    counter = 1
    isContinue = True
    while(isContinue):
        for i in range(m):
            for j in range(m):
                if i != j and matrixDis[i][j] == 'oo':
                    counter += 1
                    matrixCounter = matrixMultiplication(matrixAd, m, counter)
                    compare(matrixDis, matrixCounter, m, counter)
                    break
                else:
                    isContinue = False
    return matrixDis


def correctMatrix(matrix, m):
    for i in range(m):
        for j in range(m):
            if matrix[i][j] == 'oo':
                pass
            elif matrix[i][j] > 1:
                matrix[i][j] = 1
    return matrix


def creatingMatrixAchievability(matrixDis, m):
    matrixAch = creatingArray(m, m)
    for i in range(m):
        for j in range(m):
            if matrixDis[i][j] == 'oo':
                matrixAch[i][j] = 0
            else:
                matrixAch[i][j] = matrixDis[i][j]
            if i == j:
                matrixAch[i][j] += 1
    correctMatrix(matrixAch, m)
    return matrixAch


def metricCharateristiks(matrixAd, m):
    dictionary = {}
    for i in range(m):
        dictionary[f"v{i+1}"] = max(matrixAd[i])
    print(F"Diametr = {max(dictionary.values())}")
    r = min(dictionary.values())
    print(F"Radius = {r}")
    for k, v in dictionary.items():
        if v == r:
            print(f"Center graphs: {k}")


def tiersGraph(matrixDis):
    tiers = 0
    dictionary = {}
    top = int(input("Enter top: "))
    for i in matrixDis[top - 1]:
        dictionary[f"v{tiers+1}"] = i
        tiers += 1
    [print(f"{key} -- {value} tiers ") for (key, value) in sorted(dictionary.items(), key=lambda x: x[1])]

def menu_1():
    arrayInput = []
    readFile(arrayInput)
    m = arrayInput[0][0]
    n = arrayInput[0][1]
    arrayInput = arrayInput[1::]

    matrixAdjance = creatingArray(m, m)
    creatingMatrixAdjance(matrixAdjance, arrayInput)
    matrixDistance = creatingMatrixDistance(matrixAdjance, m)
    matrixAchievability = creatingMatrixAchievability(matrixDistance, m)


    while True:
        print(f"Choose operation: "
              f"\n\t Output matrix distance - 1"
              f"\n\t Output matrix achievability - 2"
              f"\n\t Output matrix metric charateristiks - 3"
              f"\n\t Output tiers graph - 4"
              f"\n\t Exit - 5\n")
        choose = int(input())
        if choose == 1:
            printMatrix(matrixDistance, m, m)
        elif choose == 2:
            printMatrix(matrixAchievability, m, m)
        elif choose == 3:
            metricCharateristiks(matrixDistance, m)
        elif choose == 4:
            tiersGraph(matrixDistance)
        elif choose == 5:
            break
        else:
            print("Command not found")


def creatingMatrixAdjanceOr(array, date):
    for i in date:
        array[i[0] - 1][i[1] - 1] = 1

def transMatrix(matrix, m):
    matrix_tr = creatingArray(m, m)
    for i in range(m):
        for j in range(m):
            matrix_tr[j][i] = matrix[i][j]
    return matrix_tr


def totalMatrix(matrix1, matrix2, m):
    sumMatrix = creatingArray(m, m)
    for i in range(m):
        for j in range(m):
            sumMatrix[i][j] = matrix1[i][j] + matrix2[i][j]
    return sumMatrix


def connectednessMatrix(matrixAd, matrixAch, m):
    isRevisor = True
    for items in matrixAch:
        for i in items:
            if i != 1:
                isRevisor = False
                break
        if not isRevisor:
            break
    if isRevisor:
        return "Strong typing"

    isRevisor = True

    uniMatrix = correctMatrix(totalMatrix(matrixAch, transMatrix(matrixAch, m), m), m)
    for items in uniMatrix:
        for i in items:
            if i != 1:
                isRevisor = False
                break
        if not isRevisor:
            break
    if isRevisor:
        return "Unilateral typing"

    isRevisor = True
    sumMatrix = totalMatrix(matrixAd, transMatrix(matrixAd, m), m)
    for i in range(m):
        for j in range(m):
            if i == j:
                sumMatrix[i][j] += 1
    weaklyMatrix = correctMatrix(sumMatrix, m)
    for items in weaklyMatrix:
        for i in items:
            if i != 1:
                isRevisor = False
                break
        if not isRevisor:
            break
    if isRevisor:
        return "Weakly typing"
    else:
        return "Not typing"

def menu_2():

    print("_____________________________________________2_ЧАСТИНА__________________________________________________________\n")\

    arrayInput = []
    readFile(arrayInput)
    m = arrayInput[0][0]
    n = arrayInput[0][1]
    arrayInput = arrayInput[1::]

    matrixAdjanceOr = creatingArray(m, m)
    creatingMatrixAdjanceOr(matrixAdjanceOr, arrayInput)
    matrixDistanceOr = creatingMatrixDistance(matrixAdjanceOr, m)
    matrixAchievabilityOr = creatingMatrixAchievability(matrixDistanceOr, m)

    while True:
        print(f"Choose operation: "
              f"\n\t Output matrix distance - 1"
              f"\n\t Output matrix achievability - 2"
              f"\n\t Output typing connectedness of matrix - 3"
              f"\n\t Exit - 4\n")
        choose = int(input())
        if choose == 1:
            printMatrix(matrixDistanceOr, m, m)
        elif choose == 2:
            printMatrix(matrixAchievabilityOr, m, m)
        elif choose == 3:
            print(connectednessMatrix(matrixAdjanceOr, matrixAchievabilityOr, m))
        elif choose == 4:
            break
        else:
            print("Command not found")

if __name__ == '__main__':
    menu_1()
    menu_2()