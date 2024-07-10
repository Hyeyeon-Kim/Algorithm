var ans = 0;

function dfs(sum, target, cnt, numbers){
    if (cnt == numbers.length) {
        if (target == sum)
            ans++;
        return ;
    }
    
    dfs(sum+numbers[cnt], target, cnt + 1, numbers);
    dfs(sum-numbers[cnt], target, cnt + 1, numbers);
}

function solution(numbers, target) {
    dfs(0, target, 0, numbers);
    
    var answer = ans;
    return answer;
}