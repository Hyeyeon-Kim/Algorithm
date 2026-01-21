def solution(answers):
    
    one = [1, 2, 3, 4, 5]
    two = [2, 1, 2, 3, 2, 4, 2, 5]
    thre = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    
    ans = {i: 0 for i in range(1, 4)}
    
    for i, a in enumerate(answers):
        if a == one[i % len(one)]:
            ans[1] += 1
        if a == two[i % len(two)]:
            ans[2] += 1
        if a == thre[i % len(thre)]:
            ans[3] += 1
    
    max_ = max(ans.values())
    
    answer = [a for a in ans if ans[a] == max_]
    
    
    return sorted(answer, key = lambda k:ans[k])