def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a


a = int(input())
b = int(input())
c = int(input())
d = int(input())

ans = 0
while a * d < c * b:
    a += 1
    b += 1
    m = gcd(a, b)
    a //= m
    b //= m
    ans += 1
if a == c and b == d:
    print(ans)
else:
    print(0)
