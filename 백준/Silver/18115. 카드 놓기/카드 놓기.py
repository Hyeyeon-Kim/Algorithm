from collections import deque

n = int(input())
tec = list(map(int, input().split()))

tec.reverse()

ans = deque()

for i in range(n):

	if tec[i] == 1:
		ans.appendleft(i+1)
	elif tec[i] == 2:
		ans.insert(1, i+1) 
	else:
		ans.append(i+1)

print(*ans)