#include <bits/stdc++.h>
using namespace std;

// Creating a node
class Node{
    public:
    
    int data;
    Node*prev;
    Node*next;
    
    Node(int val){
        this -> data = val;
        this -> prev = nullptr;
        this -> next = nullptr;
    }
};

class Deque{
    private:
    
    Node* head;
    Node* tail;
    int size_;
    
    public:
    
    Deque(){
        head = nullptr;
        tail = nullptr;
        size_ = 0;
    }
    
    void push_front(int val){
        size_ += 1;
        
        if (head == nullptr && tail == nullptr){
            
            Node* newNode = new Node(val);
            head = newNode;
            tail = newNode;
        return;
        }
        
        Node* newNode = new Node(val);
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode;
        
    return;
    }
    
    void pop_front(){
        if (head == tail){
            
            if (head == nullptr){
                cout << "Deque empty";
                return;
            }
            
            size_ -= 1;
            Node* frontNode = head;
            head = nullptr;
            tail = nullptr;
            
            delete frontNode;
        }
        
        size_ -= 1;
        Node* frontNode = head;
        head = head -> next;
        head -> prev = nullptr;
        
        delete frontNode;
    }
    
    void push_back(int val){
        size_ += 1;
        
        if (head == nullptr && tail == nullptr){
            
            Node* newNode = new Node(val);
            head = newNode;
            tail = newNode;
        return;
        }
        
        Node* newNode = new Node(val);
        newNode -> prev = tail;
        tail -> next = newNode;
        tail = newNode;
        
        return;
    }
    
    void pop_back(){
        
        if (size_ == 0){
            cout << "Dequeu is empty";
            return;
        }
        
        if (head == tail){
            
            Node* backNode = tail;
            head = nullptr;
            tail = nullptr;
            size_ -= 1;
            
            delete backNode;
        }
        
        size_ -= 1;
        Node* backNode = tail;
        tail = tail -> prev;
        tail -> next = nullptr;
        
        delete backNode;
    }
    
    
    int front(){
        if (head == nullptr){
            cout << "Deque empty";
            return -1;
        }
        
        return head -> data;
    }
    
    
    int back(){
        
        if (tail == nullptr){
            cout << "Deque empty";
            return -1;
        }
        
        return tail -> data;
    }
    
    
    int size(){
        return size_;
    }
    
    
    
    int isEmpty(){
        return (size_ == 0);
    }
    
    void display(){
        
        Node* curr = head;
        
        while(curr != nullptr){
            cout << curr -> data <<" ";
            curr = curr -> next;
        }
        
    return;
    }
};

int main(){
    
    Deque d;
    
    d.push_front(2);
    d.push_front(10);
    d.push_front(11);
    d.push_back(100);
    
    d.pop_back();
    d.pop_front();
    
    d.display();

    return 0;
}
