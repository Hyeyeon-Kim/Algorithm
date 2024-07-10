function solution(answers) {
    
    var arr = [[ 1, 2, 3, 4, 5], [2, 1, 2, 3, 2, 4, 2, 5], [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]];
    
    var scores = [0, 0, 0];
    
    answers.forEach(function(answer, idx){
        for (i = 0; i < 3; i++)
        {
            var len  = arr[i].length;
            if(arr[i][idx % len] == answer)
                scores[i]++;
        }
    });
    
    var max_score = Math.max(scores[0], scores[1], scores[2]);
    var answer = [];
    
    scores.forEach(function(score, idx){
        if (max_score == score)
            answer.push(idx + 1);        
    });
    
    return answer;
}