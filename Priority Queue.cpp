#include <bits/stdc++.h>
using namespace std;


class PriorityQueue{
    private:
    
    vector<int> heap;
    
    int left(int i){
        return 2 * i + 1;
    }
    
    int right(int i){
        return 2 * i + 2;
    }
    
    int parent(int i){
        return (i - 1) / 2;
    }
    
    void bubbleDown(int i){
        
        int largest = i;
        int leftChild = left(i);
        int rightChild = right(i);
        
        if (leftChild < heap.size() && heap[leftChild] > heap[i]){
            largest = leftChild;
        }
        
        else if (rightChild < heap.size() && heap[rightChild] > heap[i]){
            largest = rightChild;
        }
        
        if (largest != i){
            swap(heap[i],heap[largest]);
            bubbleDown(largest);
        }
    }
    
    void bubbleUp(int i){
        
        int parentIndex = parent(i);
        
        if (parentIndex >= 0 && heap[i] > heap[parentIndex]){
            swap(heap[parentIndex],heap[i]);
            bubbleUp(parentIndex);
        }
    }
    
    public:
    
    
    void push(int value){
        
        heap.push_back(value);
        bubbleUp(heap.size() - 1);
        
    }
    
    void pop(){
        if (heap.empty()) return;
        
        swap(heap[0],heap[heap.size() - 1]);
        heap.pop_back();
        bubbleDown(0);
    }
    
    int extractMax(){
        return heap[0];
    }
    
    int size(){
        return heap.size();
    }
    
    bool empty(){
        return (heap.size() == 0);
    }
    
    void clear(){
        heap.clear();
    }
    
    void display(){
        for(int i = 0;i < heap.size();i++){
            cout << heap[i] << " ";
        }
    }
};



int main(){
    
    
    PriorityQueue pq;
    
    pq.push(10);
    pq.push(100);
    pq.push(1000);
    pq.push(300);
    
    pq.display(); // Output : 1000 300 100 10
    
    /* Actual structure 
    
          1000 
         /    \
       300    100
      /
     10
    */
    
    pq.pop();
    pq.display(); // Output : 300 10 100 
    
    /*Actual structure
    
         300 
       /    \
     10    100
    */
    
    int max_ele = pq.extractMax();
    cout << max_ele; // output 300
    
    cout << pq.size(); // output 3
    
    cout << pq.empty(); // output : 0 (False) (boolean and integer are interconvertable in C++)
    
    pq.clear();
    
    cout << pq.empty(); // output : 1 (True) 

    return 0;
}