class MyCircularQueue {

    int* arr;
    int front,rear;
    int size;

public:
    MyCircularQueue(int k) {
        arr = new int[k];
        front = -1;
        rear = -1;
        size = k;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        if (isEmpty()) {
            front = rear = 0;

        } else {
            rear = (rear + 1) % size;
        }
        arr[rear] = value;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        return true;
    }

    int Front() {
        if (!isEmpty()) {
            return arr[front];
        } else {
            return -1;
        }
    }

    int Rear() {
        if (!isEmpty()) {
            return arr[rear];
        } else {
            return -1;
        }
    }

    bool isEmpty() { return front == -1; }

    bool isFull() { return (((rear + 1) % size) == front); }
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