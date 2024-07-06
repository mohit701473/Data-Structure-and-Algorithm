// LeetCode -> 846. Hand of Straights
https://leetcode.com/problems/hand-of-straights/description/


class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mp;

        for(auto &it: hand){
            mp[it]++;
        }

        while(!mp.empty()){
            int curr = mp.begin() -> first;

            for(int i = 0; i < groupSize; i++){
                if(mp[curr + i] == 0){
                    return false;
                }

                mp[curr + i]--;

                if(mp[curr + i] == 0){
                    mp.erase(curr + i);
                }
            }
        }

            return true;
    }
};





class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int i = 0, j = 0;
        int n = hand.size();
        int cnt = 0, last_ele = -1;
        unordered_map<int, int> mp;
        sort(hand.begin(), hand.end());

        while(i < n){
            cnt = 1;
            last_ele = hand[i];
            mp[i] = 1;
            j++;

            while(j < n && cnt != groupSize){
                if(hand[j] == last_ele + 1 && !mp[j]){
                    cnt++;
                    last_ele = hand[j];
                    mp[j] = 1;
                }
                j++;
            }

            if(cnt != groupSize) return false;

            while(i < n && mp[i]){
                i++;
            }
            j = i;
        }
        return true;
    }
};