const fs = require("fs");
const { mainModule } = require("process");
// TODO: 제출 시 경로 변환 필수 ("/dev/stdin")
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

// 풀이
const ans = [];

function dfs(visit, node, edge) {
  if (visit[node] === 1) return;
  ans[0] += String(node) + " ";
  visit[node] = 1;
  edge[node].sort((a, b) => a - b);
  for (let i = 0; i < edge[node].length; i++) dfs(visit, edge[node][i], edge);
}

function bfs(visit, node, edge) {
  const q = [];
  q.push(node);

  while (q.length != 0) {
    let n = q.shift();

    if (visit[n] === 1) continue;
    ans[1] += String(n) + " ";
    visit[n] = 1;
    edge[n].sort((a, b) => a - b);
    for (let i = 0; i < edge[n].length; i++) {
      q.push(edge[n][i]);
    }
  }
}

function solution(arr) {
  const ar2 = arr[0].split(" ").map(Number);

  const n = ar2[0];
  const m = ar2[1];
  const v = ar2[2];

  const edge = Array.from({ length: n + 1 }, () => []);

  for (let i = 0; i < m; i++) {
    const arrr = arr[i + 1].split(" ").map(Number);
    const a = arrr[0],
      b = arrr[1];

    edge[a].push(b);
    edge[b].push(a);
  }

  ans[0] = "";
  ans[1] = "";
  let visit = Array(n + 1).fill(0);
  dfs(visit, v, edge);
  visit = Array(n + 1).fill(0);
  bfs(visit, v, edge);

  console.log(ans[0]);
  console.log(ans[1]);
}

solution(input);
