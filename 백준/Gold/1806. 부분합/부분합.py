n, s = map(int, input().split())
input = list(map(int, input().split()))

r = 0
l = 0
# input.sort()

ans = 1e5 + 1
sum = input[r]

while True:
	if (sum < s):
		l += 1
		if (l == n):
			break
		sum += input[l]
	else:
		ans = min(ans, l-r+1)
		sum -= input[r]
		r += 1

if (ans == 1e5 + 1):
	print(0)
else:
	print(ans)