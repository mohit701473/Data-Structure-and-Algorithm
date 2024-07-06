// LeetCode -> 347. Top K Frequent Elements
https://leetcode.com/problems/top-k-frequent-elements/description/


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans;

        for(auto num: nums)
            freq[num]++;

        for(auto &it: freq) {
            if(pq.size() < k) {
                pq.push({it.second, it.first});
            } else if(pq.top().first < it.second) {
                pq.pop();
                pq.push({it.second, it.first});
            }
        }

        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
 
        return ans;
    }
};