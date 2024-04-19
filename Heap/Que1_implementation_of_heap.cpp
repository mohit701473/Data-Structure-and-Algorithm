#include<iostream>
using namespace std ;

class Heap{

    public:
        int arr[100] ;
        int size ;

        Heap(){
            arr[0] = -1 ;
            this -> size = 0 ;
        }

        void insert(int val){
            // find the index where you want to insert the val
            // insert the ever new value at teh last index
            size = size+1 ;
            int index = size ;

            // step 1 -> insert teh value at the end 
            arr[index] = val ;

            // setp 2 -> check for the heap property satisfys or not
            while(index > 1){
                int parent_idx = index / 2 ;

                if(arr[parent_idx] < arr[index]){
                    swap(arr[parent_idx], arr[index]);
                    index = parent_idx ;
                }
                else{
                    return;
                }
            }
        }


        void deleteFromHeap(){
            if(size == 0){
                cout << "Empty" << endl ;
                return ;
            }
            
            // step -> 1: put the last node at the top
            arr[1] = arr[size] ;

            // step -> 2: remove the last node
            size-- ;

            // step -> 3: correct the heap porperty for first node
            int i = 1 ;
            while(i <= size){
                int left_child = 2 * i ;
                int right_child = 2 * i + 1 ;
                int target_idx = i ;


                if(left_child <= size && arr[left_child] >= arr[target_idx]){
                    target_idx = left_child ;
                } 

                if(right_child <= size && arr[right_child] >= arr[target_idx]){
                    target_idx = right_child ;
                }

                if(i != target_idx){
                    swap(arr[i], arr[target_idx]) ;
                    i = target_idx ;
                }
                else return ;
                    
            }
        }

        


        void print(){
        for(int i=1 ; i<=size ; i++){
            cout<<arr[i]<< " ";
        }cout<<endl;
    }
};

void heapify(int arr[], int n, int i){
    int largest = i ;
    int left = 2 * i ;
    int right = 2 * i + 1 ;

    if(left <= n && arr[left] >= arr[largest]){
        largest = left ;
    } 

    if(right <= n && arr[right] >= arr[largest]){
        largest = right ;
    }

    if(largest != i){
        swap(arr[i], arr[largest]) ;
        heapify(arr, n, largest) ;
    }

}


int main()
{
    Heap h ;
    h.insert(55) ;
    h.insert(53) ;
    h.insert(54) ;
    h.insert(50) ;
    h.insert(52) ;

    h.print() ;
    h.deleteFromHeap() ;
    h.print() ;

    int arr[6] = {-1, 54, 53, 55, 50, 52} ;
    int n = 5 ;

    for(int i=n/2 ; i>=1 ; i--){
        heapify(arr, n, i) ;
    }

    for(int i=1 ; i<=n ; i++){
        cout<<arr[i]<< " ";
    }cout<<endl;
}