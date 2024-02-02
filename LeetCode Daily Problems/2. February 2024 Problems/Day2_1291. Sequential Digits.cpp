https://leetcode.com/problems/sequential-digits/description/

// T.C. = O(8 * 8)
// S.C. = O(9)
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789" ;
        vector<int> ans ;

        for(int len = 2 ; len <= digits.size() ; len++){
            for(int st_idx = 0 ; st_idx <= digits.size() - len ; st_idx++){
                string temp = digits.substr(st_idx, len) ;
                int val = stoi(temp) ;
                
                if(val >= low && val <= high){
                    ans.push_back(val) ;
                }

                if(val > high) return ans ;
            }
        }

        return ans ;
    }
};