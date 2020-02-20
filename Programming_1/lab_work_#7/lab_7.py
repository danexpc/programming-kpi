import random

def array_creation(n, a, b):
    array = [random.randint(a, b) for i in range(n)]
    return array

def dictionary_creation(array):
    dictionary = {}
    for i in array:
        dictionary[i] = array.count(i)
    return dictionary

def appear_the_most(dictionary, max_number):
    min_key = max_number
    max_value = max(dictionary.values())

    for k, v in dictionary.items():
        if v == max_value and min_key > k:
            min_key = k

    return min_key

n = int(input("Введите размер массива: "))

print("Задайте диапазон целых чисел в массиве: ")
a = int(input("От: "))
b = int(input("До: "))
arr = array_creation(n, a, b)
print(arr)

dictionary = dictionary_creation(arr)

popular_number = appear_the_most(dictionary, b)
print(F'Наиболее встречаемое число -- {popular_number}')
