class MyCircularQueue {
private:
    struct Node {
        int val;
        Node* next;
        Node(int v) : val(v), next(nullptr) {}
    };

    Node* head;   // front of queue
    Node* tail;   // rear of queue
    int size;     // max capacity
    int currSize; // current count

public:
    MyCircularQueue(int k) {
        head = nullptr;
        tail = nullptr;
        size = k;
        currSize = 0;
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
            tail->next = head; // circular link
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head; // maintain circular link
        }
        currSize++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        if (currSize == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node* temp = head;
            head = head->next;
            tail->next = head; // update circular link
            delete temp;
        }
        currSize--;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return head->val;
    }

    int Rear() {
        if (isEmpty()) return -1;
        return tail->val;
    }

    bool isEmpty() {
        return currSize == 0;
    }

    bool isFull() {
        return currSize == size;
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