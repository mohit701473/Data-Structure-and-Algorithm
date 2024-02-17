https://leetcode.com/problems/furthest-building-you-can-reach/description/


// Approch -> greedy + Min heap
// T.C. = O(nlog(n))
// S.C. = O(n)
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        priority_queue<int, vector<int>, greater<int>> pq ;
        for(int i=0 ; i<heights.size() - 1; i++){
            int jumpLen = heights[i+1] - heights[i] ;

            if(jumpLen > 0) pq.push(jumpLen) ;
            if(pq.size() > ladders){
                bricks -= pq.top() ;
                pq.pop() ;
            }

            if(bricks < 0) return i ;
        }

        return heights.size() - 1 ;

    }
};




class Solution {

    int solve(int i, int &bricks, int &ladders, vector<int>& h){
        if(i >= h.size() -1)
            return i ;

        if(ladders <= 0 && bricks < h[i+1] - h[i])
            return i ;

        int res1 = -1, res2 = -1, res3 = -1 ;
        if(h[i] >= h[i+1]){
            return solve(i+1, bricks, ladders, h) ;
        }
        else{
            if(bricks >= h[i+1] - h[i]){
                bricks -= (h[i+1] - h[i]) ;
                res2 = solve(i+1, bricks, ladders, h) ;
                bricks += (h[i+1] - h[i]) ;
            }

            if(ladders > 0){
                ladders-- ;
                res3 = solve(i+1, bricks, ladders, h) ;
                ladders++ ;
            }
        }

        return max({res1, res2, res3}) ;
    }

public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        priority_queue<int, vector<int>, greater<int>> pq ;
        for(int i=0 ; i<heights.size() - 1; i++){
            int jumpLen = heights[i+1] - heights[i] ;

            if(jumpLen > 0) pq.push(jumpLen) ;
            if(pq.size() > ladders){
                bricks -= pq.top() ;
                pq.pop() ;
            }

            if(bricks < 0) return i ;
        }

        return heights.size() - 1 ;




        // int n = heights.size() ;
        // int i = 0 ;
        // return solve(i, bricks, ladders, heights) ;

        // int i = 0, n = heights.size() ;
        // while(i < n-1){
        //     if(heights[i] < heights[i+1]){
        //         // first use bricks 
        //         if(bricks >= (heights[i+1] - heights[i])){
        //             bricks -= (heights[i+1] - heights[i]) ;
        //         }
        //         else if(ladders > 0){ // if bricks are not sufficient then use ladder
        //             ladders-- ;
        //         }
        //         else return i ; // if both are not sufficient then we can't go further
        //     }
        //     i++ ;
        // }

        // return n-1 ;
    }
};