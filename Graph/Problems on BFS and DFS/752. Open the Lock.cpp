/*
    Also popular as              : Minimum rotations to unlock a circular lock
    Company Tags                 : META
    Leetcode Link                : https://leetcode.com/problems/open-the-lock/
    
    Similar Question :  1. Word Ladder (Leetcode) 
                        2. Gene Mutation (Leetcode)
                        3. Sequential Digits (Leetcode)
                        4. Print all Jumping Numbers smaller than or equal to a given value (GFG)
                        
    
*/


/**************************************************** C++ *********************************************/
//Using BFS
//T.C : We have n = 10 slots in each wheel and we have w = 4 wheels. In worst case we will explore all possible combinations.
//      Total Combinations = O(n^w)
//S.C : In worst case we will store all possible combinations in queue O(n^w)

class Solution {
public:
    
    void fillNeighbors(queue<string>& que, string& curr, unordered_set<string>& dead) {
        for(int i = 0; i<4; i++) {
            char ch  = curr[i];

            char dec = ch=='0' ? '9' : ch-1;
            char inc = ch=='9' ? '0' : ch+1;

            curr[i]  = dec;
            if(dead.find(curr) == dead.end()) {
                dead.insert(curr);
                que.push(curr);
            }

            curr[i] = inc;
            if(dead.find(curr) == dead.end()) {
                dead.insert(curr);
                que.push(curr);
            }
            curr[i] = ch;
        }
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(begin(deadends), end(deadends));
        
        string start = "0000";        
        if(dead.find(start) != dead.end())
            return -1;
        
        queue<string> que;
        que.push(start);
        
        int level = 0;
        while(!que.empty()) {
            int n = que.size();
            
            while(n--) {
                string curr = que.front();
                que.pop();
                if(curr == target)
                    return level;
                
                fillNeighbors(que, curr, dead);
            }
            level++;
        }
        return -1;
    }
};