function solution(progresses, speeds) {
    var answer = [];
    

    var pre_time = Math.ceil((100-progresses[0])/speeds[0]);
    var i = 1;
    var cnt = 1;

    while (i < progresses.length){
        var pro_time = Math.ceil((100-progresses[i])/speeds[i]);
        if (pre_time < pro_time)
        {
            answer.push(cnt);
            pre_time = pro_time;
            cnt = 1;
        }
        else
            cnt++;
        i++;
    }
    answer.push(cnt);

    return answer;
}