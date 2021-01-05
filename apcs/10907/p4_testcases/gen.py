from random import *


def task1_0():
    n, m = 1000 - randint(0, 10), 80 - randint(0, 10)
    print(n, m)
    for i in range(1, n + 1):
        DNA = ''.join([choice("AUCG") for _ in range(m)])
        if i == 1:
            print(1, 1, DNA)
        else:
            print(i, randint(1, i - 1), DNA)


def task1_2():
    n, m = 1000 - randint(0, 10), 80 - randint(0, 10)
    print(n, m)
    for i in range(1, n + 1):
        DNA = ''.join([choice("AUCG") for _ in range(m)])
        if i == 1:
            print(1, 1, DNA)
        else:
            print(i, randint(max(1, i - 5), i - 1), DNA)


def task1_3():
    n, m = 1000 - randint(0, 10), 80 - randint(0, 10)
    print(n, m)
    for i in range(1, n + 1):
        DNA = ''.join([choice("AUCG") for _ in range(m)])
        if i == 1:
            print(1, 1, DNA)
        else:
            print(i, i - 1, DNA)


def task2_4():
    n, m = 1000 - randint(0, 10), 80 - randint(0, 10)
    print(n, m)
    for i in range(1, n + 1):
        DNA = ''.join([choice("@AUCG") for _ in range(m)])
        if i == 1:
            print(1, 1, DNA)
        else:
            print(i, randint(1, i - 1), DNA)


def task2_8():
    n, m = 1000 - randint(0, 10), 80 - randint(0, 10)
    print(n, m)
    for i in range(1, n + 1):
        DNA = ''.join([choice("@AUCG") for _ in range(m)])
        if i == 1:
            print(1, 1, DNA)
        else:
            print(i, randint(max(1, i - 5), i - 1), DNA)


def task2_10():
    n, m = 1000 - randint(0, 10), 80 - randint(0, 10)
    print(n, m)
    for i in range(1, n + 1):
        DNA = ''.join([choice("@AUCG") for _ in range(m)])
        if i == 1:
            print(1, 1, DNA)
        else:
            print(i, i - 1, DNA)


def task3_12():
    n, m = 1000 - randint(0, 10), 80 - randint(0, 10)
    print(n, m)

    p = [i + 1 for i in range(n)]
    shuffle(p)
    p = [0] + p

    edges = []
    for i in range(1, n + 1):
        DNA = ''.join([choice("@AUCG") for _ in range(m)])
        if i == 1:
            edges.append([p[1], p[1], DNA])
        else:
            edges.append([p[i], p[randint(1, i - 1)], DNA])
    shuffle(edges)
    for e in edges:
        print(e[0], e[1], e[2])


def task3_14():
    n, m = 1000 - randint(0, 10), 80 - randint(0, 10)
    print(n, m)

    p = [i + 1 for i in range(n)]
    shuffle(p)
    p = [0] + p

    edges = []
    for i in range(1, n + 1):
        DNA = ''.join([choice("@AUCG") for _ in range(m)])
        if i == 1:
            edges.append([p[1], p[1], DNA])
        else:
            edges.append([p[i], p[randint(1, min(4, i-1))], DNA])
    shuffle(edges)
    for e in edges:
        print(e[0], e[1], e[2])


def task3_16():
    n, m = 1000 - randint(0, 10), 80 - randint(0, 10)
    print(n, m)

    p = [i + 1 for i in range(n)]
    shuffle(p)
    p = [0] + p

    edges = []
    for i in range(1, n + 1):
        DNA = ''.join([choice("@AUCG") for _ in range(m)])
        if i == 1:
            edges.append([p[1], p[1], DNA])
        else:
            edges.append([p[i], p[randint(max(1, i-5), i - 1)], DNA])
    shuffle(edges)
    for e in edges:
        print(e[0], e[1], e[2])


def task3_18():
    n, m = 1000 - randint(0, 10), 80 - randint(0, 10)
    print(n, m)

    p = [i + 1 for i in range(n)]
    shuffle(p)
    p = [0] + p

    edges = []
    for i in range(1, n + 1):
        DNA = ''.join([choice("@AUCG") for _ in range(m)])
        if i == 1:
            edges.append([p[1], p[1], DNA])
        else:
            edges.append([p[i], p[i-1], DNA])
    shuffle(edges)
    for e in edges:
        print(e[0], e[1], e[2])


task3_14()
