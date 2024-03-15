// GFG -> Minimum Multiplications to reach End
https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

// T.C. = O()


class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int, int>> q ;
        vector<int> dist(100000, INT_MAX) ;
        
        q.push({0, start}) ;
        dist[start] = 0 ;
        
        while(!q.empty()){
            int steps = q.front().first ;
            int node = q.front().second ;
            q.pop() ;
            
            if(node == end){
                return steps ;
            }
            
            for(auto num: arr){
                int val = (node * num) % 100000 ;
                if(steps + 1 < dist[val]){
                    q.push({steps+1, val}) ;
                    dist[val] = steps+1 ;
                }
            }
        }
        
        return -1 ;
    }
};