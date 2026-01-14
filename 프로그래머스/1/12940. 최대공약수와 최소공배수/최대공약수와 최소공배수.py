def solution(n, m):
    a = n
    b = m
    
    while (n % m):
        t = n
        n = m
        m = t % m
    
    return[m, a * b // m]