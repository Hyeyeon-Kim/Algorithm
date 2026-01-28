def solution(n, arr1, arr2):
    answer = ["" for _ in range(n)]
    
    for i in range(n):
        bit = arr1[i] | arr2[i]
        bit = bin(bit).lstrip('0b').zfill(n)

        for b in bit:
            if b == "1":
                answer[i] += "#"
            else:
                answer[i] += " "
    
    return answer