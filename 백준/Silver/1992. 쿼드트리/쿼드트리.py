video = []
n = 0
ans = ""
	

def isSame(size, val, x, y):
	for i in range(size):
		for j in range(size):
			t = y + i
			a = x + j
			tmp = video[y + i][x + j] 
			if (video[y + i][x + j] != val):
				return False
	return True

def quadTree(size, val, x, y):
	global ans

	if size == 1 or isSame(size, val, x, y):
		ans += val
		return
	
	else:
		ans += "("
		nsize = size // 2
		for i in range(4):
			ny = nsize * (i // 2) + y
			nx = nsize * (i % 2) + x
			quadTree(size // 2, video[ny][nx], nx, ny)
		ans += ")"
	
n = int(input())

for i in range(n):
	video.append(input())

quadTree(n, video[0][0], 0, 0)
print(ans)