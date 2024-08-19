n, m = map(int, input().split())
A = list(map(int, input().split()))

l = 1
r = 10**12

while (l <= r):
    mid = (l+r) // 2
    cnt = 0
	
    for a in A:
        cnt += mid // a
	
    if (cnt >= m):
        r = mid - 1
        result = mid
    else:
        l = mid + 1
        
print(result)