from random import *
from sys import argv

n = int(argv[1])
sh = int(argv[2])
seed(argv[-1])

par = [0] * n
for i in range(1, n):
	par[i] = 0
perm = list(range(1, n + 1))
shuffle(perm)

el = []
for i in range(1, n):
	el.append([perm[i], perm[par[i]]])
shuffle(el)

print(n)
for i in el:
	if sh == 1 and randint(1, 2) == 2:
		print(i[1], i[0])
	else:
		print(i[0], i[1])