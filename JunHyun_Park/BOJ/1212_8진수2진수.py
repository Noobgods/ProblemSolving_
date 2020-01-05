# 1212_8진수2진수 [진법]
c = ('000', '001', '010', '011', '100', '101', '110', '111')
o = input()

o = list(o)
for i in range(len(o)):
	if i == 0 and int(o[i]) in [0, 1]:
		print(c[int(o[i])][2:], end='')
	elif i == 0 and int(o[i]) in [2, 3]:
		print(c[int(o[i])][1:], end='')
	else:
		print(c[int(o[i])], end='')