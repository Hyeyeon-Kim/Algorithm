def solution(arr, divisor):
    answer = []
    
    for n in arr:
        if n % divisor == 0:
            answer.append(n)
    
    if answer == []:
        answer = [-1]
    return sorted(answer)