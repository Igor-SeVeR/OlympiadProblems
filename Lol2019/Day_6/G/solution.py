s1 = input()
s2 = input()
pairs = set()
for i in range(len(s2) - 1):
    pairs.add(s2[i:i + 2])
ans = 0
for i in range(len(s1) - 1):
    if s1[i: i + 2] in pairs:
        ans += 1
print(ans)
