n = int(input())
request = list(map(int, input().split()))
budget = int(input())

s = 1
e = max(request) 
ans = budget
max_buget = 0

while (s <= e):
	mid = (s+e) // 2
	total = 0

	for req in request:
		if mid < req:
			total += mid
		else:
			total += req

	if (total > budget):
		e = mid-1
	else:
		if (max_buget < total):
			max_buget = total
			ans = mid
		s = mid+1

print(ans)