def readFile(array):
    with open('input.txt') as file:
        for line in file:
            array.append(line.split())

        for item in range(len(array)):
            array[item][0] = int(array[item][0])
            array[item][1] = int(array[item][1])


def creatingArray(m, n):
    array = [[0 for j in range(n)] for i in range(m)]
    return array


def creatingDictionary(array, m):
    dictionary = {}
    for i in range(m):
        arr = []
        for j in range(m):
            if array[i][j] == 1:
                arr.append(j+1)
        dictionary[i+1] = arr
    return dictionary


def creatingAdjency(array, date, typeGraph):
    for index in date:
        if typeGraph == 1:
            array[index[0] - 1][index[1] - 1] = 1
        else:
            array[index[0] - 1][index[1] - 1] = 1
            array[index[1] - 1][index[0] - 1] = 1


def iteractive_dfs(graph):
    start = int(input("Input start top: "))
    path, q, counter = [start], [start], 1
    print(f'DFS-номер: {counter} \t Вершина: {q[-1]} \t Стек: {q}')
    while q:
        v = q[-1]
        for u in graph[v]:
            if u not in path:
                counter += 1
                path += [u]
                q += [u]
                print(f'DFS-номер: {counter} \t Вершина: {u} \t Стек: {q}')
                break
        else:
            q.pop()
            print(f'DFS-номер: - \t Вершина: - \t Стек: {q}')


def iteractive_bfs(graph):
    start = int(input("Input start top: "))
    path, q, counter = [start], [start], 1
    print(f'BFS-номер: {counter} \t Вершина: {q[0]} \t Очередь: {q}')
    while q:
        v = q[0]
        for u in graph[v]:
            if u not in path:
                counter += 1
                path += [u]
                q += [u]
                print(f'BFS-номер: {counter} \t Вершина: {u} \t Очередь: {q}')
        else:
            q.pop(0)
            print(f'BFS-номер: - \t Вершина: - \t Очередь: {q}')


def menuBar():
    inputFile = []
    readFile(inputFile)
    m = inputFile[0][0]
    inputFile = inputFile[1::]
    matrix_Ad = creatingArray(m, m)
    typeGraph = int(input('Выбере тип графа: \n'
                          '\t1)Ориентированный граф\n'
                          '\t2)Неориентированный граф\n'))

    creatingAdjency(matrix_Ad, inputFile, typeGraph)
    graph = creatingDictionary(matrix_Ad, m)
    exit = False
    while not exit:
        choose = int(input('Выберете действие:\n'
                            '\t1)Обойти граф в ширину \n'
                            '\t2)Обойти граф в глубину \n'
                            '\t3)Выйти\n'))
        if choose == 1:
            iteractive_bfs(graph)
            print()
        elif choose == 2:
            iteractive_dfs(graph)
            print()
        elif choose == 3:
            exit = True
        else:
            print(f"Command '{choose}' not found!")


def main():
    menuBar()


if __name__ == '__main__':
    main()