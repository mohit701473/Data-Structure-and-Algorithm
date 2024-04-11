// LeetCode -> 2073. Time Needed to Buy Tickets
https://leetcode.com/problems/time-needed-to-buy-tickets/description/


class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0 ;

        for(int i=0 ; i<tickets.size() ; i++){
            if(i <= k){
                time += tickets[i] <= tickets[k] ? tickets[i] : tickets[k] ;
            }
            else{
                time += tickets[i] < tickets[k] ? tickets[i] : tickets[k]-1 ;
            }
        }

        return time ;
    }
};