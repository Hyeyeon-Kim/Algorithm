def solution(numbers, hand):
    core = {i: [(i-1) // 3, (i-1) % 3] for i in range(1, 10)}
    core[0] = [3, 1]
    
    l = [3, 0]
    r = [3, 2]
    ans = ''
    
    for num in numbers:
        if num in (1, 4, 7):
            l = core[num]
            ans += 'L'
        elif num in (3, 6, 9):
            r = core[num]
            ans += 'R'
        else:
            Ldist = abs(core[num][0] - l[0]) + abs(core[num][1] - l[1])
            Rdist = abs(core[num][0] - r[0]) + abs(core[num][1] - r[1])
            
            if Ldist < Rdist:
                l = core[num]
                ans += 'L'
            elif Ldist > Rdist:
                r = core[num]
                ans += 'R'
            else:
                if hand == 'right':
                    r = core[num]
                    ans += 'R'
                else:
                    l = core[num]
                    ans += 'L'
                
    return ans