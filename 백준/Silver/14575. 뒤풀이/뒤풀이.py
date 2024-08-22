def can(l, r, t, mid):
	more = 0
	min_sum = 0

	for i in range(n):
		if (l[i] > mid):
			return False
		more += min(mid, r[i]) - l[i]
		min_sum += l[i]
	
	if (more >= t - min_sum):
		return True
	return False

n, t = list(map(int, input().split()))

l = []
r = []
minSum = 0
maxSum = 0

e = 0

for i in range(n):
	a, b = list(map(int, input().split()))
	l.append(a)
	r.append(b)
	minSum += a
	maxSum += b
	e = max(e, b)

ans = 1e9

if (minSum > t or maxSum < t):
	ans = -1

s = 0

while (s <= e):
	mid = (s + e) // 2

	if (can(l, r, t, mid)):
		ans = min(ans, mid)
		e = mid - 1
	else:
		s = mid + 1
print(ans)

