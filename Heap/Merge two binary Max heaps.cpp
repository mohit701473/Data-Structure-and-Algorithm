// GFG -> Merge two binary Max heaps
// https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1


class Solution{
    public:
    void heapify(int i, int size, vector<int>& arr) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        
        if(l < size && arr[largest] < arr[l])
            largest = l;
            
        if(r < size && arr[largest] < arr[r])
            largest = r;
            
        if(largest != i) {
            swap(arr[largest], arr[i]);
            heapify(largest, size, arr);
        }
    }
    
    void buildHeap(vector<int>& arr) {
        int size = arr.size();
        for(int i = size/2 - 1; i >= 0; i--) {
            heapify(i, size, arr);
        }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        for(int i = 0; i < m; i++) {
            a.push_back(b[i]);
        }
        
        buildHeap(a);
    
        return a;
    }
};