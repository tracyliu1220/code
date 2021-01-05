from random import *


def task1():
    b = 100
    a, b = sample(range(1, b + 1), 2)
    print(a, b)
    t = randint(1, 100)
    print(t)
    for _ in range(t):
        x, y = sample(range(1, b + 1), 2)
        print(x, y, 0)


def task2():
    b = 5
    a, b = sample(range(1, b + 1), 2)
    print(a, b)
    t = randint(1, 100)
    print(t)
    for _ in range(t):
        s = randint(1, 100)
        cnt = [0 for i in range(102)]
        arr = []
        for _s in range(s):
            n = randint(1, 100)
            if cnt[n] == 0 or (cnt[n] > 0 and randint(0, 1) == 0):
                arr.append(n)
                cnt[n] += 1
            else:
                arr.append(-n)
                cnt[n] -= 1
        print(*arr, 0)


task1()
