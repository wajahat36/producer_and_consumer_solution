#ifndef RING_BUFFER_HPP
#define RING_BUFFER_HPP
#include <iostream>
using namespace std;
template<typename T>
class ring_buffer {
    int buffer_size;
    T* data;
    int top = 0;
    int rear = 0;
    int data_count=0;

public:
    ring_buffer(int size_to_be_set) {
      buffer_size=size_to_be_set;
      data= new T[buffer_size];
    }

    ~ring_buffer() {
        delete[] data;
    }

    void push_back(T value){
         if (!is_full()) {
            top = (top + 1) % buffer_size;
            data[top] = value;
            data_count++;
        } else {
            cout << "The queue is full" << endl;
        }
    }
    T pop_front() {
         T value = T(); 
        if (!is_empty()) {
            rear = (rear + 1) % buffer_size;
            value = data[rear];
            data_count--;
        } else {
            std::cout << "The queue is empty" << endl;
        }
        return value;
    }
    bool is_empty() {
        return (rear == top);
    }
    bool is_full() {
        return ((top + 1) % buffer_size) == rear;
    }
    int get_buffer_size() {
        return buffer_size; 
    }
    int get_data_size() {
        return data_count;
    }
    
};
#endif 

