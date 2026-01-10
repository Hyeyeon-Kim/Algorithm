def solution(numbers, hand):
    
    pos = {num: [(num - 1)//3, (num - 1) % 3] for num in range(1, 10)}
    pos[0] = [3,1]
    
    L = [3, 0]
    R = [3, 2]
    
    ans = ''
    
    for num in numbers:
        if num in [1, 4, 7]:
            L = pos[num]
            ans += 'L'
        elif num in [3, 6, 9]:
            R = pos[num]
            ans += 'R'
        else:
            Ldist = abs(L[0] - pos[num][0]) + abs(L[1] - pos[num][1])
            Rdist = abs(R[0] - pos[num][0]) + abs(R[1] - pos[num][1])

            if Ldist < Rdist:
                L = pos[num]
                ans += 'L'
            elif Ldist > Rdist:
                R = pos[num]
                ans += 'R'
            else:
                if hand == "right":
                    R = pos[num]
                    ans += 'R'
                else:
                    L = pos[num]
                    ans += 'L'
                    
#             print(Ldist, Rdist)
                    
#         print(L, R, ans, pos[num], num)
            
    return ans