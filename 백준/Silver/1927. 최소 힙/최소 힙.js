const fs = require("fs");
const { mainModule } = require("process");
// TODO: 제출 시 경로 변환 필수 ("/dev/stdin")
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

// 풀이

class MiniHeap {
  constructor() {
    this.heap = [];
  }
  size() {
    return this.heap.length;
  }
  add(num) {
    this.heap.push(num);

    let index = this.heap.length - 1;

    while (index > 0) {
      let pIndex = Math.floor((index - 1) / 2);

      if (this.heap[pIndex] <= this.heap[index]) break;

      [this.heap[index], this.heap[pIndex]] = [
        this.heap[pIndex],
        this.heap[index],
      ];
      index = pIndex;
    }
  }

  del() {
    if (this.heap.length == 0) return 0;
    if (this.heap.length == 1) return this.heap.pop();

    let min = this.heap[0];
    this.heap[0] = this.heap.pop();
    let index = 0;

    while (index * 2 + 1 < this.heap.length) {
      let leftIndex = index * 2 + 1;
      let rightIndex = index * 2 + 2;
      let minIndex = leftIndex;

      if (
        rightIndex < this.heap.length &&
        this.heap[rightIndex] < this.heap[leftIndex]
      )
        minIndex = rightIndex;
      if (this.heap[minIndex] >= this.heap[index]) break;

      [this.heap[minIndex], this.heap[index]] = [
        this.heap[index],
        this.heap[minIndex],
      ];
      index = minIndex;
    }
    return min;
  }
}

function solution(arr) {
  let ans = [];
  arr = arr.map(Number);
  let h = new MiniHeap();
  for (let i = 1; i < arr.length; i++) {
    if (arr[i] == 0) ans.push(h.del());
    else h.add(arr[i]);
  }
  return ans;
}

console.log(solution(input).join("\n"));
