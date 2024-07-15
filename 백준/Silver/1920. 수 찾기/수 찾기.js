const fs = require("fs");
// TODO: 제출 시 경로 변환 필수 ("/dev/stdin")
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

// 풀이

function binary(target, arr, n, start, end) {
  if (end < start) return false;

  const mid = Math.floor((start + end) / 2);

  if (arr[mid] === target) return true;
  if (arr[mid] > target) return binary(target, arr, n, start, mid - 1);
  else return binary(target, arr, n, mid + 1, end);
}

function solution(arr) {
  let n = arr[0];
  let arr1 = arr[1]
    .split(" ")
    .map(Number)
    .sort((a, b) => a - b);
  let m = arr[2];
  let q = arr[3].split(" ").map(Number);

  for (let i = 0; i < q.length; i++) {
    // console.log(q[i]);
    if (binary(q[i], arr1, n, 0, n - 1) === true) console.log("1");
    else console.log("0");
  }
}

solution(input);
