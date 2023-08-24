#include <iostream>
#include<mutex>
#include<thread>
#include<deque>
#include<condition_variable>
#include"ring_buffer.hpp"
using namespace std;
mutex m1;
int result_count=0;
condition_variable cv;
ring_buffer<int>* rb = nullptr;

void consumer(int number_of_values_to_count) {
    if(number_of_values_to_count==0)
      return;
    while (true) {
        {
            try
            {
                unique_lock<mutex> consumer_lock(m1);
                if (!rb) throw runtime_error("rb pointer is null");
                cv.wait(consumer_lock, [] { return rb && !rb->is_empty(); });
                int value = rb->pop_front();
                result_count+=value;
                consumer_lock.unlock();
                cv.notify_one(); 
                if(value==number_of_values_to_count-1)
                    break;                  
            }
            catch(const std::exception& e)
            {
               cerr << "Consumer exception: " << e.what() << endl;
               return;
            }
            
        }
    }
}


void producer(int number_of_values_to_produce) {
    for (int i = 0; i < number_of_values_to_produce; i++) {
        {
            try
            {
                unique_lock<mutex> producer_lock(m1);
                if (!rb) throw runtime_error("rb pointer is null");
                cv.wait(producer_lock, [] { return rb && !rb->is_full(); });
                rb->push_back(i);
                producer_lock.unlock();
                cv.notify_one(); 
            }
            catch(const std::exception& e)
            {
                cerr << "Producer exception: " << e.what() << endl;
                return;
            } 

        }
    }
}


int main(int arg,char** arr) {
    try
    {
        if (arg != 3) {
        cout << "Usage: " << arr[0] << " <producer_value> <buffer_size>" << endl;
        return 1;
    } 
        int number_of_values=atoi(arr[1]);
        int ring_buffer_size = atoi(arr[2]);
        if(ring_buffer_size<2) throw runtime_error(" THE RING BUFFER'S SIZE SHOULD BE GREATER THAN 1"); 
        rb = new ring_buffer<int>(ring_buffer_size);
        thread producer_thread(producer,number_of_values);
        thread consumer_thread(consumer,number_of_values);   
        producer_thread.join();
        consumer_thread.join();
        cout<<"The sum of all values produced by the producer "<<result_count<<endl; 
        delete rb;
    }
    catch(const std::exception& e)
    {
        cerr << "Main exception: " << e.what() << endl;
        return 1;
    }
    
}
