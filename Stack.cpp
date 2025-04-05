#include <bits/stdc++.h>
using namespace std;


class Stack{
    private:
    
    class Node{
        public:
        
        int data;
        Node* next;
        
        Node(int data){
            this -> data = data;
            this -> next = nullptr;
        }
    };
    
    
    Node* topNode;
    int current_size;
    
    public:
    
    Stack(){
        topNode = nullptr;
        current_size = 0;
    }
    
    void push(int data){
        
        Node* newNode = new Node(data);
        current_size += 1;
        
        if (topNode == nullptr){
            
            topNode = newNode;
            return;
        }
        
        newNode -> next = topNode;
        topNode = newNode;
    return;
    }
    
    void pop(){
        
        if (current_size == 0){
            throw runtime_error("Stack is empty");
        }
        
        current_size--;
        Node* temp = topNode;
        topNode = topNode -> next;
        delete temp;
    }
    
    int top(){
        
        if (current_size == 0){
            throw runtime_error("Stack is empty");
        }
        
        return topNode -> data;
    }
    
    int size(){
        return current_size;
    }
    
    bool empty(){
        return (current_size == 0);
    }
    
    void display(){
        Node* curr = topNode;
        
        while(curr != nullptr){
            cout << curr -> data <<" ";
            curr = curr -> next;
        }
    cout << endl;
    return;
    }
};

int main(){
    
    Stack s;
    
    s.push(10);
    s.push(11);
    s.push(111);
    
    s.display();
    // output : 111 11 10
    
    s.pop();
    
    s.display();
    //output : 11 10
    
    s.pop();
    
    cout << s.top();

    return 0;
}
