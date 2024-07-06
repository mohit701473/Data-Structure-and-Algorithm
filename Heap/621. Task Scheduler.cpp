// LeetCode -> 621_Task Scheduler
https://leetcode.com/problems/task-scheduler/

/*
This problem can be solved using two methods
first one using priority queue
second one using the Greedy
*/

/*
Approch -> 1: Using Priority Queue

Intution -> 
Greedy -> Q ki hum greedyly higest frequency valo ko phle process kr rhe hai
Hashmap -> to store frequencies
Why the need of Priority Queue -> Bcz jiski frequecny sabse jyda h sabse phle usko process kr rhe hai 

*/
// T.C. = O(N) -> bcz u r visiting each task at max onec
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0) ;  
        int minCycle = 0 ;
        priority_queue<int> pq ;

        for(char &ch: tasks){
            freq[ch-'A']++ ;
        }

        for(auto &it: freq){
            if(it > 0){
                pq.push(it) ;
            }
        }

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




/*
Approch -> 1: greedy method

Intution -> 
    We always process maxium frequency task first i.e. we pick taks in decending order of frequency
    Greedy -> Q ki hum greedyly higest frequency valo ko phle process kr rhe hai
    Hashmap -> to store frequencies

    ["A","A","A","B","B","B"], k = 2
    A-3
    b-3
    A _ _ A _ _ A
    Number of chunks     = freq('A')-1 = 2
    Number of idol spots = (Number of chunks)*(p) = 2*2 = 4
            
    Now, we will try to fill these 4 idol spots
    If at the end idol spots is 0, it means all idol spots were enough
    to accomodate all other taks. So, out result will be tasks.size();
        
    If, idol spots are not empty, it means that we need more spaces (equal to idol spots)
    than the tasks.size() to accomodate all tasks.
    So, result = tasks.size() + idol_spots
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n == 0)
            return tasks.size();

        vector<int> freq(26, 0);
        for(char &ch : tasks) {
            freq[ch-'A']++;
        }
        
        sort(begin(freq), end(freq));
        
        int maxFreq     = freq[25];
        int gaddhe      = maxFreq-1;
        int idolSpots   = gaddhe*n;
        
        for(int i = 24; i>=0 ; i--) {
            idolSpots -= min(gaddhe, freq[i]);
        }
        
        if(idolSpots > 0)
            return tasks.size() + idolSpots;
        
        return tasks.size();
    }
};