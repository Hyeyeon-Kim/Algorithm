def solution(s, skip, index):
    answer = ''
    alpha = {}
    skip = set(skip)

    for i in range(26):
        c = chr(97 + i)
        if c not in skip:
            idx = len(alpha) // 2
            alpha[idx] = c
            alpha[c] = idx

    # print(alpha)
    for c in s:
        # print(alpha[c], alpha[c] + index, (alpha[c] + index) % (len(alpha) // 2))
        answer += alpha[(alpha[c] + index) % (len(alpha) // 2)]

    
    return answer