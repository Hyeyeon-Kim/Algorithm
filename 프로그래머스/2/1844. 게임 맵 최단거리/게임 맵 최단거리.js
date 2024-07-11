function solution(maps) {
    var answer = -1;

    // n행 m열
    let n = maps.length, m = maps[0].length;
    let q = [];
    let visit = Array.from({ length: n }, () => Array.from({ length: m }, () => 0));

    q.push([0, 0, 1]);

    let nextX = [0, 1, 0, -1];
    let nextY = [1, 0, -1, 0];

    while (q.length > 0)
    {
        let pos = q.shift();

        let y = pos[0];
        let x = pos[1];
        let cost = pos[2];

        // 목적지에 도착하면 결과 반환
        if (y === n-1 && x === m-1)
        {
            answer = cost;
            break;
        }

        visit[y][x] = 1;

        for (let i = 0; i < 4; i++)
        {
            let nx = x + nextX[i];
            let ny = y + nextY[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n)
                if (visit[ny][nx] === 0 && maps[ny][nx] === 1)
                {
                    visit[ny][nx] = 1; // 방문 처리
                    q.push([ny, nx, cost + 1]);
                }
        }
    }

    return answer;
}
