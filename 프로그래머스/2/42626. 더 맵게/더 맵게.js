class MiniHeap {
  constructor() {
    this.arr = [];
  }
  size() {
    return this.arr.length;
  }
  add(num) {
    this.arr.push(num);

    let index = this.arr.length - 1;
    while (index > 0) {
      let pIndex = Math.floor((index - 1) / 2);

      if (this.arr[pIndex] <= this.arr[index]) break;
      [this.arr[pIndex], this.arr[index]] = [this.arr[index], this.arr[pIndex]];
      index = pIndex;
    }
  }

  del() {
    if (this.arr.length === 0) return null;
    if (this.arr.length === 1) return this.arr.pop();

    const min = this.arr[0];
    this.arr[0] = this.arr.pop();
    let index = 0;

    while (index * 2 + 1 < this.arr.length) {
      let leftIndex = index * 2 + 1;
      let rightIndex = index * 2 + 2;
      let minIndex = leftIndex;

      if (
        rightIndex < this.arr.length &&
        this.arr[leftIndex] > this.arr[rightIndex]
      )
        minIndex = rightIndex;

      if (this.arr[minIndex] >= this.arr[index]) break;

      [this.arr[minIndex], this.arr[index]] = [this.arr[index], this.arr[minIndex]];
      index = minIndex;
    }
    return min;
  }
}

function solution(scoville, K) {
    var answer = 0;
    
    const miniheap = new MiniHeap;
    
    for (scov of scoville)
        miniheap.add(scov);
    
    while (miniheap.arr[0] < K)
    {
        if (miniheap.size() == 1)
        {
            answer = -1;
            break;
        }
        
        let a = miniheap.del();
        let b = miniheap.del();

        miniheap.add(a + b * 2);
        answer++;
    }
    
    return answer;
}