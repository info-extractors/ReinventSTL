#include <bits/stdc++.h>
using namespace std;


class Queue{
    private:
    
    class QueueNode{
        public:
        int data;
        QueueNode* prev;
        QueueNode* next;
        
        QueueNode(int data){
            this -> data = data;
            this -> prev = nullptr;
            this -> next = nullptr;
        }
    };
    
    QueueNode* head;
    QueueNode* tail;
    
    public:
    
    Queue(){
        head = nullptr;
        tail = nullptr;
    }
    
    void push(int val){
        
        if (!head && !tail){
            
            QueueNode* firstNode = new QueueNode(val);
            head = firstNode;
            tail  = firstNode;
        return;
        }
        
        QueueNode* new_node = new QueueNode(val);
        new_node -> prev = tail;
        tail -> next = new_node;
        
        tail = tail -> next;
        
        return;
    }
    
    void pop(){
        while(head == nullptr){
            throw runtime_error("Queue empty");
        }
        
        QueueNode* temp = head;
        head= temp -> next;
        head -> prev = nullptr;
        temp -> next = nullptr;
        
        delete temp;
    }
    
    int front(){
        if (head == nullptr){
            throw runtime_error("Queue empty");
        }
        
        return head -> data;
    }
    
    int rear(){
        if (tail == nullptr){
            throw runtime_error("Queue empty");
        }
        
        return tail -> data;
    }
    
    void display(){
        QueueNode* current = head;
        
        while(current != nullptr){
            cout << current -> data <<" ";
            current = current -> next;
        }
        cout << endl;
        return;
    }
};


int main(){
    
    Queue q;
    
    q.push(1);
    q.push(23);
    q.push(100);
    q.push(10000);
    
    cout << "Current queue: ";
    q.display(); // result  1 23 100 10000
    
    /*
     Actual structure:
     
      |   1   | 
      |   23  |
      |  100  | 
      | 10000 |
    
    */
    
    
    
    q.pop(); // Node poped
    
    cout << "Current queue:";
    q.display(); // result 23 100 10000

    /*
       Actual structure 
      |   23  |
      |  100  | 
      | 10000 |
      
    */
    
    
    cout << "Front Node:"<<q.front() << endl; // result : 23
    cout << "Rear Node:"<<q.rear() << endl;   // result 10000

    return 0;
}
