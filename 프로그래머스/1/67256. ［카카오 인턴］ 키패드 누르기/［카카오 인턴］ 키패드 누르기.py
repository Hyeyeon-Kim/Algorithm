def solution(numbers, hand):
    
    key = {i: [(i - 1) // 3, (i - 1) % 3] for i in range(1, 10)}
    key[0] = [3, 1]

    answer = ''
    l = [3, 0] 
    r = [3, 2]
    
    for num in numbers:
        if num in (1, 4, 7):
            answer += 'L'
            l = key[num]
        elif num in (3, 6, 9):
            answer += 'R'
            r = key[num]
        else:
            ld = abs(l[0] - key[num][0]) + abs(l[1] - key[num][1])
            rd = abs(r[0] - key[num][0]) + abs(r[1] - key[num][1])
            
            if ld < rd:
                answer += 'L'
                l = key[num]
            elif ld > rd:
                answer += 'R'
                r = key[num]
            else:
                if hand == 'left':
                    answer += 'L'
                    l = key[num]
                else:
                    answer += 'R'
                    r = key[num]
            
        #     print(ld, rd, num)
        # print(answer, num , l, r)
    
    return answer