def solution(s):
    
    words = ["zero","one","two","three","four","five","six","seven","eight","nine"]
    
    # print(s.isnumeric())
    # end = false
    st = 0
    
    while (s.isnumeric() == False):
        if s[st:st+1].isnumeric():
            st += 1

        for i, word in enumerate(words):
            if (word == s[st:st + len(word)]):
                ns = s[:st]
                ns += str(i)
                ns += s[st + len(word):]
                s = ns
                st += 1
        
    # print(s)
    # answer = 1
    answer = int(s)
    return answer