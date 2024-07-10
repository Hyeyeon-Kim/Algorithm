

function solution(numbers, target) {
    var answer = 0;
    
    dfs(0, 0);
    
    function dfs(sum, cnt){
        if (cnt < numbers.length) {
            dfs(sum+numbers[cnt], cnt + 1);
            dfs(sum-numbers[cnt], cnt + 1);
        }
        else
        {
            if (target == sum)
                answer++;
            return ;
        }
    };
    return answer;
}