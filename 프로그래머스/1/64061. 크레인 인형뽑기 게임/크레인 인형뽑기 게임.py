def solution(boards, moves):
    boards = list(zip(*boards))
    boards = [[b for b in board[::-1] if b != 0] for board in boards]
    
    s = []
    ans = 0
    
    print(boards)
    
    for move in moves:
        tem = None
        
        if (boards[move - 1]):
            tem = boards[move - 1][-1]
            boards[move - 1].pop()
        
        if (tem == None):
            continue
            
        if len(s):
            if s[-1] == tem:
                s.pop()
                ans += 2
            else:
                s.append(tem)
        else:
            s.append(tem)
        
        # print(move, tem, s, '     ',boards)
    return ans