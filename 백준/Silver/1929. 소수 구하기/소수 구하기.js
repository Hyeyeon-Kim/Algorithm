const fs = require("fs");
// TODO: 제출 시 경로 변환 필수 ("/dev/stdin")
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

// 풀이
function solution(arr) {
  const m = Number(arr[0].split(" ")[0]);
  const n = Number(arr[0].split(" ")[1]);
  let isPrime = new Array(n + 1).fill(true);

  isPrime[0] = isPrime[1] = false; // 0과 1은 소수가 아님

  for (let i = 2; i * i <= n; i++) {
    if (isPrime[i]) {
      for (let j = i * i; j <= n; j += i) {
        isPrime[j] = false;
      }
    }
  }

  let result = [];
  for (let i = m; i <= n; i++) {
    if (isPrime[i]) {
      result.push(i);
    }
  }

  console.log(result.join("\n"));
}

solution(input);
