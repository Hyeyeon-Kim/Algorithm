def solution(s):
    
    answer = len(s)

    for i in range(1, len(s)):
        start = 0
        end = 0

        if len(s) <= i:
            len(s)-2

        m = {}
        pre = ''
        sentence = ''

        while end < len(s):
            start = end
            end = start + i
            word = s[start:end]

            if end >= len(s):
                if word == '':
                    break
                if pre != word:
                    if pre != '' and m[pre] > 1:
                        sentence += str(m[pre]) + pre
                    else:
                        sentence += pre
                    m[word] = 1
                else:
                    m[word] += 1

                if m[word] > 1:
                    sentence += str(m[word]) + word
                else:
                    sentence += word
                break

            if pre == word:
                prin = word
                m[word] += 1
            else :
                m[word] = 1  
                if start == 0:
                    pre = word
                    continue
                if m[pre] > 1:
                    sentence += str(m[pre]) + pre
                else:
                    sentence += pre
                m[pre] = 0

            pre = word
        
        answer = min(answer, len(sentence))

    return answer