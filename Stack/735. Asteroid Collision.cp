// LeetCode -> 735. Asteroid Collision


/*
Similar Question -> https://leetcode.com/problems/robot-collisions/description/
Approch of this question is writtin in the Similar Question
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            if(!ans.empty()) {
                bool flag = true;
                while(!ans.empty() && (ans.back() > 0 && asteroids[i] < 0)) {
                    if(ans.back() == abs(asteroids[i])) {
                        flag = false;
                        ans.pop_back();
                        break;
                    } else if(ans.back() > abs(asteroids[i])) {
                        flag = false;
                        break;
                    } else {
                        ans.pop_back();
                        flag = true;
                    }
                }

                if(flag) {
                    ans.push_back(asteroids[i]);
                }
            } else {
                ans.push_back(asteroids[i]);
            }
        }

        return ans;
    }
};