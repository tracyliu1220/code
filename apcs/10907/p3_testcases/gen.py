from random import *

def task1_0():
    n, m = randint(1, 100), randint(1, 100)
    print(n, m)
    a = [randint(1, 10000000) for i in range(n)]
    print(*a)
    s = 0
    for x in a:
        s += x
    b = [randint(1, s) for i in range(m)]
    print(*b)

def task1():
    n, m = randint(1, 100), randint(1, 100)
    print(n, m)
    a = [randint(1, 3) for i in range(n)]
    print(*a)
    s = 0
    for x in a:
        s += x
    b = [randint(1, s) for i in range(m)]
    print(*b)

def task2_0():
    n, m = 200000 - randint(0, 100), 20000 - randint(0, 100)
    print(n, m)
    a = [randint(1, 5000) for i in range(n)]
    print(*a)
    s = 0
    for x in a:
        s += x
    s = min(s, 10**9)
    b = [randint(1, s) for i in range(m)]
    print(*b)

def task2_1():
    n, m = 200000 - randint(0, 100), 20000 - randint(0, 100)
    print(n, m)
    a = [randint(1, 500) for i in range(n)]
    print(*a)
    s = 0
    for x in a:
        s += x
    s = min(s, 20)
    b = [randint(1, s) for i in range(m)]
    print(*b)

def task2():
    n, m = 200000 - randint(0, 100), 20000 - randint(0, 100)
    print(n, m)
    a = [randint(1, 3) for i in range(n)]
    print(*a)
    s = 0
    for x in a:
        s += x
    b = [randint(1, s) for i in range(m)]
    print(*b)

task2()
