import heapq

user_input = input()
numbers = list(map(int, user_input.split()))

n = numbers[0]
m = numbers[1]

user_input = input()
numbers = list(map(int, user_input.split()))

que = []
for i in range(n):
    heapq.heappush(que, (numbers[i], i))

ans = 0

for i in range(m):
    val, idx = heapq.heappop(que)
    ans = val
    heapq.heappush(que, (val + numbers[idx], idx))

print(ans)
