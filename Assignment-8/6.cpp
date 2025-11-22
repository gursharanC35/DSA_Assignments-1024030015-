#include <iostream>
using namespace std;

class MaxHeap {
    int heap[100];
    int size;

public:
    MaxHeap() {
        size = 0;
    }

    void insert(int value) {
        if (size == 100) {
            cout << "Heap is full!\n";
            return;
        }
        size++;
        int i = size;
        heap[i] = value;

        while (i > 1 && heap[i / 2] < heap[i]) {
            int temp = heap[i];
            heap[i] = heap[i / 2];
            heap[i / 2] = temp;
            i = i / 2;
        }
    }

    int maximum() {
        if (size == 0) {
            cout << "Heap is empty!\n";
            return -1;
        }
        return heap[1];
    }

    int extractMax() {
        if (size == 0) {
            cout << "Heap is empty!\n";
            return -1;
        }

        int maxVal = heap[1];
        heap[1] = heap[size];
        size--;

        int i = 1;
        while (true) {
            int left = 2 * i;
            int right = 2 * i + 1;
            int largest = i;

            if (left <= size && heap[left] > heap[largest])
                largest = left;
            if (right <= size && heap[right] > heap[largest])
                largest = right;

            if (largest != i) {
                int temp = heap[i];
                heap[i] = heap[largest];
                heap[largest] = temp;
                i = largest;
            } else
                break;
        }

        return maxVal;
    }

    void increaseKey(int i, int newValue) {
        if (i < 1 || i > size) {
            cout << "Invalid index!\n";
            return;
        }
        if (newValue < heap[i]) {
            cout << "New key is smaller than current key!\n";
            return;
        }
        heap[i] = newValue;

        while (i > 1 && heap[i / 2] < heap[i]) {
            int temp = heap[i];
            heap[i] = heap[i / 2];
            heap[i / 2] = temp;
            i = i / 2;
        }
    }

    void display() {
        cout << "Heap elements: ";
        for (int i = 1; i <= size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap pq;
    int choice, value, index;

    while (true) {
        cout << "\n--- Priority Queue (Max Heap) ---\n";
        cout << "1. Insert\n";
        cout << "2. Maximum\n";
        cout << "3. Extract-Max\n";
        cout << "4. Increase-Key\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                pq.insert(value);
                break;
            case 2:
                cout << "Maximum value: " << pq.maximum() << endl;
                break;
            case 3:
                cout << "Extracted Max: " << pq.extractMax() << endl;
                break;
            case 4:
                cout << "Enter index (1-based): ";
                cin >> index;
                cout << "Enter new value: ";
                cin >> value;
                pq.increaseKey(index, value);
                break;
            case 5:
                pq.display();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
