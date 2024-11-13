from itertools import combinations

def solution(orders, course):
    answer = []
    count = {}
    
    for order in orders:
        for cnt in course:
            for comb in combinations(order, cnt):
                tmp = sorted(comb)
                perm = ''.join(tmp) 
                
                if perm in count:
                    count[perm] += 1
                else:
                    count[perm] = 1
    
    # count
    # print(count)
    
    for cnt in course:
        max_ = 0
        kind = []
        for c in count:
            if len(c) == cnt and count[c] >= 2:
                if max_ < count[c]:
                    kind = [c]
                    max_ = count[c]
                elif max_ == count[c]:
                    kind.append(c)
        # print(kind)
        if kind:
            answer += kind
    answer.sort()
    return answer