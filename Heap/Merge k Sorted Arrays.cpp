// GFG -> Merge k Sorted Arrays
https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=merge-k-sorted-arrays


/*
Approch -> 1: use the concept of the merge two sorted arrays

why this is not a godd approch -> here we are comparing same element so may times bcz suppose u take two sorted arrays arr[0] and arr[1] u merge them and now for arr[2] u also comparing all element with arr[2] and so on

for arr[0] and arr[1] you process K + k = 2K elements
now for ans and arr[2] you process 2K + K = 3K elemenst
and for ans and arr[3] you process 3K + K = 4K elemenst
and so on thats why it is not a good approch
 
is this is necessary or we can improve it? 
sol -> see the second approch

T.C. = O(K^3)
S.C. = O(K^2)
*/
class Solution
{
    public:
    
    vector<int> mergeTwoSortedArray(vector<int>& arr1, vector<int>& arr2) {
        int i = 0, j = 0;
        int n1 = arr1.size(), n2 = arr2.size();
        vector<int> ans;
        
        while(i < n1 && j < n2) {
            if(arr1[i] < arr2[j]) {
                ans.push_back(arr1[i]);
                i++;
            } else {
                ans.push_back(arr2[j]);
                j++;
            }
        }
        
        while(i < n1) {
            ans.push_back(arr1[i]);
            i++;
        }
        
        while(j < n2) {
            ans.push_back(arr2[j]);
            j++;
        }
        
        return ans;
    }
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> res = arr[0];
        
        for(int i = 1; i < K; i++){
            res = mergeTwoSortedArray(res, arr[i]);
        }
        
        return res;
    }
};


/*
Approch -> 2: Use min priority queue
Insert first element of all arrays into pq i.e. now ur min_pq have minium element at top and arrays are sorted then minimum element of individual array persent at 0-th index and we inserted that into min_pq so min_top's top have minimum ele.

now pop() the top() element and push_back() this ele into ans vector and sath hi yah element jis array ka hai uska next elemnt agr ho to pq m dal do to eske liye hume yah bhi store krna hoga ki ele konse arary ka hai and us array m konsi index pr that i.e. u have to stoe {ele, i, j} into pq.
to store all these thing into pq u can create a class or struct of node which conatin these things

now min_pq ko process krte jao jb tk ki empty na ho jaye and ans vector me push krte jao
*/

// T.C. = O(Klog(K) + K^2log(K))
// S.C. = O(K^2 + K)
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> res;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> >pq;
        
        for(int i = 0; i < K; i++){
            int ele = arr[i][0];
            pq.push({ele, {i, 0}});
        }
        
        while(!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            
            int ele = node.first;
            int i = node.second.first;
            int j = node.second.second;
            
            res.push_back(ele);
            
            if(j + 1 < K) {
                pq.push({arr[i][j+1], {i, j+1}});
            }
        }
        
        return res;
    }
};