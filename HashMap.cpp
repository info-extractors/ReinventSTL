#include <bits/stdc++.h>
using namespace std;

class HashMap{
    
    class Node{
        public:
        int key;
        int val;
        Node* next;
        
        Node(int key,int val){
            this -> key = key;
            this -> val = val;
        }
        
    };
    
    vector<Node*> hashMap;
    
    public:
    
    HashMap(){
        hashMap = vector<Node*>(1000);
    }
    
    void put(int key,int val){
        
        int index = key % 1000;
        
        if (hashMap[index] == nullptr){
            hashMap[index] = new Node(key,val);
            return;
        }
        
        Node* curr = hashMap[index];
        
        while(curr -> next != nullptr && curr -> key != key){
            curr = curr -> next;
        }
        
        if (curr -> key == key){
            curr -> val = val;
        return;
        }
        else{
            curr -> next = new Node(key,val);
        }
    }
    
    int get(int key){
        
        int index = key % 1000;
        
        if (!hashMap[index]){
            throw runtime_error("Key Error");
        }
        
        Node* curr = hashMap[index];
        
        while(curr != nullptr){
            
            if (curr -> key == key){
                return curr -> val;
            }
            
            curr = curr -> next;
        }
        
       throw runtime_error("Key Error");
    }
    
    void display(){
        
        for(int i = 0;i < hashMap.size();i++){
            
            if (hashMap[i]){
                
                Node* curr = hashMap[i];
                
                while(curr != nullptr){
                    cout << curr -> key <<" : "<<curr -> val << endl;
                    curr = curr -> next;
                }
            }
        }
    }
};

int main(){
    
    
    HashMap hm;
    
    hm.put(10,1);
    hm.put(100,3);
    hm.put(1000,4);
    hm.erase(1000);
    hm.display();

    return 0;
}
