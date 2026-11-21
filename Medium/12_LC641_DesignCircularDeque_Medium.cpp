class MyCircularDeque {
private:
    vector<int> buf;
    int front;
    int size;
    int capacity;

public:
    MyCircularDeque(int k) : buf(k, 0), front(0), size(0), capacity(k) {
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        front = (front - 1 + capacity) % capacity;
        buf[front] = value;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        int rearIdx = (front + size) % capacity;
        buf[rearIdx] = value;
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return buf[front];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        int rearIdx = (front + size - 1) % capacity;
        return buf[rearIdx];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};
