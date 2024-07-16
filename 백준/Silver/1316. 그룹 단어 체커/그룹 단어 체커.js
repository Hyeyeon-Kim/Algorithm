const fs = require("fs");
const { mainModule } = require("process");
// TODO: 제출 시 경로 변환 필수 ("/dev/stdin")
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

// 풀이

function solution(arr) {
  const n = arr[0];
  let ans = 0;

  for (let i = 1; i < arr.length; i++) {
    // console.log(arr[i]);
    let isUsed = Array(26).fill(0);
    let isGroup = 0;
    for (let j = 0; j < arr[i].length; j++) {
      let alpha = arr[i][j];
      if (j > 0 && alpha === arr[i][j - 1]) {
        isGroup++;
        continue;
      }
      let idx = alpha.charCodeAt() - "a".charCodeAt();
      if (isUsed[idx] !== 1) {
        isGroup++;
        isUsed[idx] = 1;
      }
    }
    if (isGroup === arr[i].length) ans++;
  }
  console.log(ans);
}

solution(input);
