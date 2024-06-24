https://leetcode.com/problems/minimum-number-of-chairs-in-a-waiting-room/

class Solution {
public:
    int minimumChairs(string s) {
        int cnt = 0, cnt_E = 0;
        for(auto ch: s){
            if(ch == 'E') cnt_E++;
            else cnt_E--;
            cnt = max(cnt, cnt_E);
        }

        return cnt;
    }
};