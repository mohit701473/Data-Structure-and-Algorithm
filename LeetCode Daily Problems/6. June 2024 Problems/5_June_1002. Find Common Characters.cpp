https://leetcode.com/problems/find-common-characters/description/

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> cnt(26, 0);
        int n = words.size();

        for(int i = 0; i < words[0].size(); i++){
            cnt[words[0][i] - 'a']++;
        }

        for(int i = 1; i < n; i++){
            vector<int> temp(26, 0);
            for(int j = 0; j < words[i].size(); j++){
                temp[words[i][j] - 'a']++;
            }

            for(int k = 0; k < 26; k++){
                cnt[k] = min(cnt[k], temp[k]);
            }
        }

        vector<string> ans;
        for(int i = 0; i < 26; i++){
            while(cnt[i]--){
                string str(1, i+'a');
                ans.push_back(str);
            }
        }

        return ans;
    }
};