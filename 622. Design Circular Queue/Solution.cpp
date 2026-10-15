struct Node{
    int val;
    Node* next;

    Node(int v) {
        val = v;
        next = nullptr;
    }
};

class MyCircularQueue {
private:
    Node* front;
    Node* rear;
    int maxSize;
    int currentCapacity;
public:
    
    MyCircularQueue(int k) {
        front = NULL;
        rear = NULL;
        maxSize = k;
        currentCapacity = 0;
    }
    
    bool enQueue(int value) {
        if(isFull())return false;
        Node* newNode = new Node(value);
        if(isEmpty()){
            front = newNode;
            rear = newNode;
            newNode->next = front;
            currentCapacity++;
            return true;
        }
        rear->next = newNode;
        newNode->next = front;
        rear = newNode;
        currentCapacity++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())return false;
        Node* temp = front;
        front = front->next;
        rear->next = front;
        temp ->next = NULL;
        currentCapacity--;
        delete temp;
        return true;
    }
    
    int Front() {
        if(isEmpty())return -1;
        return front->val;
    }
    
    int Rear() {
        if(isEmpty())return -1;
        return rear->val;
    }
    
    bool isEmpty() {
        if(currentCapacity == 0)return true;
        return false;
    }
    
    bool isFull() {
        if(currentCapacity == maxSize)return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */