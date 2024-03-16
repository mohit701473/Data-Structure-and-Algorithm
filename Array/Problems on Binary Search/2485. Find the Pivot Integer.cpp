// LeetCode -> 2485. Find the Pivot Integer
https://leetcode.com/problems/find-the-pivot-integer/description/

class Solution {
public:
    int pivotInteger(int n) {
        int tSum = (n*(n+1))/2 ;
        int st = 1, e = n ;

        while(st <= e){
            int mid = (st+e) / 2 ;
            int lSum = (mid*(mid+1)) / 2 ;
            int rSum = tSum - lSum + mid ;
            if(lSum == rSum){
                return mid ;
            }
            else if(lSum < rSum){
                st = mid+1 ;
            }
            else{
                e = mid -1 ;
            }
        }

        return -1 ;
    }
};