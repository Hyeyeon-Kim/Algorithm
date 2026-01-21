def solution(park, routes):
    x = 0
    y = 0
    n = len(park)
    m = len(park[0])
    
    for i, pa in enumerate(park):
        for j, p in enumerate(pa): 
            if(park[i][j] == 'S'):
                x = j
                y = i
                break
                
    way = {'N': [0, -1], 'S': [0, 1], 'W': [-1, 0], 'E': [1, 0]}
    
    for r in routes:
        d, c = r.split()
        cnt = 0
        
        nx = x
        ny = y
        
        while nx >= 0 and ny >= 0 and nx < m and ny < n and park[ny][nx] != 'X' and cnt < int(c):
            nx += way[d][0]
            ny += way[d][1]
            
            if not (nx >= 0 and ny >= 0 and nx < m and ny < n and park[ny][nx] != 'X' and cnt < int(c)):
                break
            cnt += 1
        
        if (cnt == int(c)):
            x = nx
            y = ny
            
        print(x, y, (cnt == int(c)))
            
    return [y, x]