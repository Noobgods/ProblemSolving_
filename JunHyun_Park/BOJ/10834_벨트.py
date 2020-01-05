# 10834_벨트 [규칙]
m = 0
r = 1

n= int(input())
a = [[]*3 for i in range(n)]

for i in range(n):
	b = map(int, input().split())
	for j in b:
		a[i].append(j)
	r *= (a[i][1] / a[i][0])
	m = (m + a[i][2]) % 2

print("{0} {1}".format(m, int(r+0.5)))