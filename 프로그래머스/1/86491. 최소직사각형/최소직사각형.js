function solution(sizes) {
   
    var row_max = 0, col_max = 0;
    
    sizes.forEach(function(number){
        row_max = Math.max(row_max, number[0], number[1]);
        col_max = Math.max(col_max, Math.min(number[0], number[1]));
    })
    var answer = row_max * col_max;
    return answer;
}