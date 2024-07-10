class MiniHeap{
    constructor(){
        this.heap = [];
    }

    size() {
        return this.heap.length;
    }
    
    peek(){
        return this.heap[0];
    }
    
    add(value){
        this.heap.push(value);
        
        let index = this.heap.length - 1;
        
        while (index > 0) {
            let parentIndex = Math.floor((index - 1) / 2);
            
            if (this.heap[parentIndex] <= this.heap[index]) {
                break;
            }
            
            [this.heap[parentIndex], this.heap[index]] = [this.heap[index], this.heap[parentIndex]];
            index = parentIndex;
        }
    }
    
    del(){
        if (this.heap.length === 0) 
            return null;
        if (this.heap.length === 1) 
            return this.heap.pop();

        const minValue = this.heap[0]; 
        this.heap[0] = this.heap.pop();
        let index = 0;

        while (index * 2 + 1 < this.heap.length) {
            let leftChildIndex = index * 2 + 1;
            let rightChildIndex = index * 2 + 2;
            let smallerChildIndex = leftChildIndex;

            if (rightChildIndex < this.heap.length && this.heap[rightChildIndex] < this.heap[leftChildIndex]) {
                smallerChildIndex = rightChildIndex;
            }

            if (this.heap[index] <= this.heap[smallerChildIndex]) {
                break;
            }

            [this.heap[index], this.heap[smallerChildIndex]] = [this.heap[smallerChildIndex], this.heap[index]];
            index = smallerChildIndex;
        }
        return minValue;
    }
}

function solution(scoville, K) {
    var answer = 0;
    
    const miniheap = new MiniHeap;
    
    for (scov of scoville)
        miniheap.add(scov);
    
    while (miniheap.heap[0] < K)
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