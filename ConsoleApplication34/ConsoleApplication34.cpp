#include <iostream>
using namespace std;

class Queue {
    int* arr;  
    int size;   
    int front;  
    int back;   
    int count;  

public:
    Queue() {
        size = 2;        
        arr = new int[size];
        front = 0;
        back = -1;
        count = 0;
    }

    void enqueue(int value) {
        if (count == size) {   
            resize();          
        }
        back = back + 1;       
        arr[back] = value;
        count++;
    }

    void dequeue() {
        if (count == 0) {
            cout << "Queue is empty\n";
            return;
        }
        front = front + 1;  
        count--;
    }

    int peek() {
        if (count == 0) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front]; 
    }

    void resize() {
        int* temp = new int[size * 2];  
        for (int i = 0; i < count; i++) {
            temp[i] = arr[front + i];  
        }
        delete[] arr; 
        arr = temp;    
        size = size * 2;
        front = 0;
        back = count - 1;
    }

    ~Queue() {
        delete[] arr;  
    }
};

int main() {
    Queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);

    cout << "First element: " << q.peek() << endl;
    q.dequeue();
    cout << "First element after dequeue: " << q.peek() << endl;
}
