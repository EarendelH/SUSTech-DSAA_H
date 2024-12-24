#include <iostream>
#include <vector>
using namespace std;

class PrinterScheduler {
private:
    vector<int> queue;
    int front, rear, size, capacity;

public:
    PrinterScheduler(int capacity) : capacity(capacity), front(0), rear(0), size(0) {
        queue.resize(capacity);
    }

    void processRequest(int request) {
        if (request == 0) {
            if (size == 0) {
                cout << "underflow" << endl;
            } else {
                front = (front + 1) % capacity;
                size--;
                printQueue();
            }
        } else {
            if (size == capacity) {
                cout << "overflow" << endl;
            } else {
                queue[rear] = request;
                rear = (rear + 1) % capacity;
                size++;
                printQueue();
            }
        }
    }

    void printQueue() {
        if (size == 0) {
            cout << "empty" << endl;
        } else {
            int count = size;
            int index = front;
            while (count > 0) {
                cout << queue[index] << " ";
                index = (index + 1) % capacity;
                count--;
            }
            cout << endl;
        }
    }
};

int main() {
    PrinterScheduler s(9);
    int request;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> request;
        s.processRequest(request);
    }
}