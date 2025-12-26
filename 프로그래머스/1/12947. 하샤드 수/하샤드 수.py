def solution(x):
    num_sum = sum(map(int, str(x)))
    return x % num_sum == 0