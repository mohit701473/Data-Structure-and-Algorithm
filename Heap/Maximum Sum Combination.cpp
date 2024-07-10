// GFG -> Maximum Sum Combination
https://www.geeksforgeeks.org/problems/maximum-sum-combination/1

class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        set<pair<int, int>> st;
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<int> ans;
        int sum = A[N-1] + B[N-1];
        pq.push({sum, {N-1, N-1}});
        st.insert({N-1, N-1});
        
        while(K--) {
            auto p = pq.top();
            int sum = p.first;
            int i = p.second.first;
            int j = p.second.second;
            ans.push_back(sum);
            pq.pop();
            
            if(i-1 >= 0 && st.find({i-1, j}) == st.end()) {
                sum = A[i-1] + B[j];
                pq.push({sum, {i-1, j}});
                st.insert({i-1, j});
            }
            
            if(j-1 >= 0 && st.find({i, j-1}) == st.end()) {
                sum = A[i] + B[j-1];
                pq.push({sum, {i, j-1}});
                st.insert({i, j-1});
            }
        }
        
        return ans;
    }
};