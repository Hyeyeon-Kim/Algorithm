def solution(survey, choices):
    mbti = {'R':0, 'T':0, 'C':0, 'F':0, 'J':0, 'M':0, 'A':0, 'N':0}
    
    for i in range(0, len(survey)):
        if choices[i] < 4:
            mbti[survey[i][0]] += 4 - int(choices[i])
        
        elif (choices[i] > 4):
            mbti[survey[i][1]] += int(choices[i]) - 4
        
    answer = ['R','C','J','A']
    
    if mbti['R'] < mbti['T']:
        answer[0] = 'T'
    if mbti['C'] < mbti['F']:
        answer[1] = 'F'
    if mbti['J'] < mbti['M']:
        answer[2] = 'M'
    if mbti['A'] < mbti['N']:
        answer[3] = 'N'
    print(mbti)
    return ''.join(answer)

#     if mbti['R'] < mbti['T']:
        # answer[0] = 'T'