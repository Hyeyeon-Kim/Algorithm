import re

def solution(babbling):
    cnt = 0
    
    for s in babbling:
        can = True
        pre = ''
        
        while len(s):
            if s[:3] != pre and (s[:3] == "aya" or s[:3] == "woo"):
                pre = s[:3]
                s = s[3:]
            elif s[:2] != pre and (s[:2] == "ye" or s[:2] == "ma"):
                pre = s[:2]
                s = s[2:]   
            else:
                can = False
                break
        
        if can:
            cnt += 1
                
    return cnt