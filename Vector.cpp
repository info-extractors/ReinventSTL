#include <bits/stdc++.h>
using namespace std;


class Vector{
    
    int *arr;
    int size_;
    int capacity_;
    
    
    void resize(int new_capacity){
        int *new_arr = new int[new_capacity];
        
        for(int i = 0;i < size_;i++){
            new_arr[i] = arr[i];
        }
        
        delete[] arr; // delete the previous array
        arr = new_arr; //reassign the previous array with new array
        capacity_ = new_capacity;
    }
    
    public:
    
    Vector(){
        size_ = 0;
        capacity_ = 2;
        arr = new int[capacity_];
    }
    
    void push_back(int value){
        if (size_ == capacity_){
            resize(size_);
        }
        
        arr[size_++] = value;
    }
    
    void pop_back(){
        if (size_ == 0){
            throw out_of_range("Pop from empty vector");
        }
        size_--;
    }
    
    int at(int index){
        if (index < 0 || index >= size_){
            throw out_of_range("Index out of range");
        }
        return arr[index];
    }
    
    int size(){
        return size_;
    }
    
    int capacity(){
        return capacity_;
    }
};

int main(){
    
    Vector arr;
    
    arr.push_back(10);
    arr.push_back(11);
    arr.push_back(123);
    arr.push_back(1000);
    arr.push_back(34324);
    
    for(int i = 0;i < arr.size();i++){
        cout << arr.at(i) << " ";
    }

    return 0;
}
