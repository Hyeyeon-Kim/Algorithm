import sys, math

def solution(n, arr1, arr2):
    
    map = [" " * n for i in range(n)]

#     print(map)
    
    for i in range(n):
        num = arr1[i] | arr2[i]
        b = str(bin(num).lstrip('0b'))
        
        t = []
        
        if (len(b) < n):
            t += [' '] * (n - len(b))
            
        t += ["#" if b[i] == '1' else " " for i in range(len(b))]
        t = ''.join(t)
        
        map[i] = t

    return map