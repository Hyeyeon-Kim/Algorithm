def solution(n):
    cnt = bin(n).count('1')
    x = n + 1
    while bin(x).count('1') != cnt:
        x += 1
    return x
