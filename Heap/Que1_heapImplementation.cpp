#include <bits/stdc++.h>
using namespace std;

class Heap {
public:
    int arr[100];
    int size;

    Heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while(index > 1) {
            int parent_idx = index / 2;

            if(arr[parent_idx] < arr[index]) {
                swap(arr[parent_idx], arr[index]);
                index = parent_idx;
            } else {
                return;
            }
        }
    }

    void deleteFromHeap() {
        if(size == 0) {
            cout << "Heap is empty" << endl;
            return;
        }

        // step 1 -> put the last node at top
        arr[1] = arr[size];

        // step 2 -> remove the last node
        size--;

        int idx = 1;
        while(idx <= size) {
            int leftIdx = 2 * idx;
            int rightIdx = 2 * idx + 1;
            int largest = idx;

            if(leftIdx <= size && arr[largest] < arr[leftIdx]) {
                //swap(arr[idx], arr[leftIdx]);
                largest = leftIdx;
            }
            
            if(rightIdx <= size && arr[largest] < arr[rightIdx]) {
                //swap(arr[idx], arr[rightIdx]);
                //swap(arr[leftIdx], arr[rightIdx]);
                largest = rightIdx;
            }

            if(largest != idx) {
                swap(arr[idx], arr[largest]);
                idx = largest;
            } else return;
        }
    }


    void print() {
        for(int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};



void heapifyMaxHeap(int i, int n, int arr[]) {
    // consider 1 based indexing
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if(left <= n && arr[largest] < arr[left]) {
        largest = left;
    }

    if(right <= n && arr[largest] < arr[right]) {
        largest = right;
    }

    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapifyMaxHeap(largest, n, arr);
    }
}

void heapifyMinHeap(int i, int n, vector<int>& arr) {
    // consider 0 based indexing
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[smallest] > arr[left]) {
        smallest = left;
    }

    if(right < n && arr[smallest] > arr[right]) {
        smallest = right;
    }

    if(smallest != i) {
        swap(arr[i], arr[smallest]);
        heapifyMinHeap(smallest, n, arr);
    }
}


vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size();
    for(int i = n/2-1; i >= 0; i--){
        heapifyMinHeap(i, n, arr);
    }
    return arr;
}

void buildMaxHeap(int arr[], int n)
{
    // consider 1 based indexing
    for(int i = n/2; i > 0; i--){
        heapifyMaxHeap(i, n, arr);
    }
}


void heapSort(int arr[], int n){
    // consider 1 based indexing
    int size = n;
    
    while(size > 1) {
        // step 1
        swap(arr[1], arr[size]);
        
        // step 2
        size--;

        // step3 
        heapifyMaxHeap(1, size, arr);
    }
}

int main() {
    Heap h;

    h.insert(55);
    h.insert(53);
    h.insert(54);
    h.insert(50);
    h.insert(52);
    h.print();

    h.deleteFromHeap();
    h.print();

    int arr[] = {-1, 53, 52, 55, 54, 50};
    int n = 5;
    buildMaxHeap(arr, n);

    for(int i = 1; i <= n; i++) {
        cout << arr[i] << " "; 
    }
    cout << endl;

    heapSort(arr, n);
    for(int i = 1; i <= n; i++) {
        cout << arr[i] << " "; 
    }
    cout << endl;
}