def solution(s, skip, index):
    answer = ''
    alpha = []
    skip = set(skip)

    for i in range(26):
        c = chr(97 + i)
        if c not in skip:
            alpha.append(c)

    print(alpha)
    for c in s:
        answer += alpha[(alpha.index(c) + index) % len(alpha)]

    
    return answer