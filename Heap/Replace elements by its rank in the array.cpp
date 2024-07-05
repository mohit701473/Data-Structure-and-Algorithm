// GFG -> Replace elements by its rank in the array
https://www.geeksforgeeks.org/problems/replace-elements-by-its-rank-in-the-array/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=replace-elements-by-its-rank-in-the-array


/*
Expected Time Complexity: O(N * logN)
Expected Auxiliary Space: O(N)
*/
class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(int i = 0; i < N; i++) {
            pq.push({arr[i], i});
        }
        
        int rank = 0;
        int prev = -1;
        while(!pq.empty()) {
            int val = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            
            if(val != prev) {
                prev = val;
                rank++;
            }
            
            arr[idx] = rank;
        }
        
        return arr;
    }

};


