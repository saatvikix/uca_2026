#include <iostream>
#include <vector>
using namespace std;

class Heap {

private:
    vector<int> list;

public:
    int getParent(int index) { 
        return (index - 1) / 2; 
    }

    int getLeft(int index) {
        return 2 * index + 1;
    }

    int getRight(int index) {
        return 2 * index + 2;
    }

    int size() {
        return list.size();
    }

    void insert(int value) {
        list.push_back(value);
        int index = list.size() - 1;

        while(index > 0 && list[index] >= list[getParent(index)]) {
            swap(list[index], list[getParent(index)]);
            index = getParent(index);
        }
    }

    void pop() {
        if(list.size() == 0) {
            cout<<"The heap is empty!"<<endl;
            return;
        }

        int last = list.size() - 1;
        list[0] = list[last];
        list.pop_back();

        if(list.size() == 1) {
            return;
        }

        downHeap(0, list.size());        
    }

    void downHeap(int index, int size) {
        int left = getLeft(index);
        int right = getRight(index);

        int max = index;
        if(left < size && list[left] > list[index]) {
            max = left;
        }
        if(right < size && list[right] > list[max]) {
            max = right;
        }

        if(max != index) {
            swap(list[index], list[max]);
            downHeap(max, size);
        }
    }

    
    void print() {
        for (int i = 0; i < list.size(); i++) {
            cout << list[i] << " ";
        }
        cout << endl;
    }

    Heap() {}
    
    Heap(vector<int> v) {
        
        list = v;

        for(int i = list.size()/2 - 1; i >= 0; i--) {
            downHeap(i, list.size());
        }
    }

    void HeapSort() {

        int n = list.size();

        for(int end = n - 1; end > 0; end--) {

            // Maximum is at index 0.
            // Put it in its final position.
            swap(list[0], list[end]);

            // Restore max heap in the unsorted portion.
            downHeap(0, end);
        }
    }
};

int main() {
    Heap myHeap( {0, 3, 2, 1, 10, 5, 6, 9, 8, 7, 4} );
    cout<<"Initial List : "; 
    myHeap.print();
    
    cout<<"Sorted List  : "; 
    myHeap.HeapSort();
    myHeap.print();
}
