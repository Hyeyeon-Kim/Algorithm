def solution(park, routes):
    n, m = len(park), len(park[0])
    ways = {"W":[-1, 0], "N":[0, -1], "S":[0, 1], "E":[1, 0]}
    s = [0, 0]
    
    for i in range(n):
        for j in range(m):
            if park[i][j] == 'S':
                s[0] = j
                s[1] = i
                break
    
    x, y = s[0], s[1]
    print(y, x)
    for route in routes:
        w, cnt = route.split(' ')
        cnt = int(cnt)
        
        nx, ny = x, y
        ok = True
        for i in range(cnt):
            nx += ways[w][0]
            ny += ways[w][1]
            
            if nx < 0 or ny < 0 or nx >= m or ny >= n or park[ny][nx] == 'X':
                ok = False
                break
            
        if ok:
            x = nx
            y = ny
        print(y, x)
        
    return [y, x]