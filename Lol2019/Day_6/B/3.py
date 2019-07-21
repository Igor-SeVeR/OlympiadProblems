a, b = map(int, input().split())
c, d = map(int, input().split())

dist = 10 ** 9
for i in range(-10000, 10001):
    L1 = abs(a - i)
    L2 = abs(c - i)
    L3 = abs(i)
    for j in [b + L1, b - L1, d + L2, d - L2, L3, -L3]:
        dist = min(dist, max(abs(a - i), abs(b - j)) + max(abs(c - i), abs(d - j)) + max(abs(i), abs(j)))

print(dist)
