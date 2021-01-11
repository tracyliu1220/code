# Copyright (C) Algo Seacow. 2020. All Rights Reserved.

n, d = map(int, input().split())

assert 1<=n and n<=100
assert 0<=d and d<=100


cnt = 0
total = 0

for _ in range(n):
    a = map(int, input().split())
    a = list(sorted(a))
    assert len(a) == 3
    if a[2] - a[0] >= d:
        cnt += 1
        assert sum(a) % 3 == 0
        total += sum(a) // 3
print(cnt, total)

