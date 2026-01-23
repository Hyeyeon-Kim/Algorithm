def solution(survey, choices):
    state = {i: 0 for i in "RTCFJMAN"}
    
    for i, s in enumerate(survey):
        n, p = s[0], s[1]
        score = choices[i]
        
        if (score < 4):
            state[n] += 4 - score
        else:
            state[p] += score - 4
    # print(state)
    answer = ['R','C','J','A']
    
    if state['T'] > state['R']:
        answer[0] = 'T'
    if state['F'] > state['C']:
        answer[1] = 'F'
    if state['M'] > state['J']:
        answer[2] = 'M'
    if state['N'] > state['A']:
        answer[3] = 'N'
        
    return ''.join(answer)
