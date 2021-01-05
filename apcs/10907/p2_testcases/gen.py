from random import *


def task1():
    n, m = 1, randint(1, 100)
    print(n, m)
    for i in range(m):
        print(1, randint(-2, -1))


def task2():
    n, m = randint(2, 20), randint(90, 100)
    print(n, m)
    for i in range(m):
        a = randint(1, n)
        b = randint(-2, 0)
        if b == 0:
            b = randint(1, n-1)
            if b>=a:
                b = b+1
        print(a, b)


task1()
