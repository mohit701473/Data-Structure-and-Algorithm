// LeetCode -> 621. Task Scheduler
https://leetcode.com/problems/task-scheduler/description/

// Intution -> Priority Queue
// T.C. = O(10^4 * 100) => O(N * n)
// S.C. = O(26)
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0) ;  
        int minCycle = 0 ;
        priority_queue<int> pq ;
        
        // O(N)
        for(char &ch: tasks){
            freq[ch-'A']++ ;
        }

        // O(26)
        for(auto &it: freq){
            if(it > 0){
                pq.push(it) ;
            }
        }

        // Worst case when tast array size is 10^4 and n = 100 and all Tasks are same then this loop will run fro
        // O(10^4 * 100) => O(N * n)
        while(!pq.empty()){

            vector<int> temp ;

            for(int i=1 ; i<=n+1 ; i++){
                if(!pq.empty()){
                    int maxFreq = pq.top() ;
                    pq.pop() ;
                    maxFreq-- ;
                    temp.push_back(maxFreq) ;
                }
            }

            for(auto &it: temp){
                if(it > 0){
                    pq.push(it) ;
                }
            }

            if(pq.empty()){
                minCycle += temp.size() ;
            }
            else{
                minCycle += (n+1) ;
            }
        }

        return minCycle ;
    }
};