function solution(arr)
{
    var idx = 1;
    var pre_val = arr[0];
    var answer = [arr[0]];
    
    while (idx < arr.length){
        if (pre_val !== arr[idx])
        {
            answer.push(arr[idx]);
            pre_val = arr[idx];
        }
        idx++;
    }
    return answer;
}