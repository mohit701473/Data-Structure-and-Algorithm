// LeetCode -> 452. Minimum Number of Arrows to Burst Balloons
https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/


// Intution -> Sorting + Overlaping Interval
// T.C. = o(nlog(n))
// S.C. = o(log(n))
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int minErrow = 0 ;
        sort(points.begin(), points.end()) ; // O(nlog(n))
        int newIntervalSt = points[0][0] ;
        int newIntervalEnd = points[0][1] ;
        int i=1 ;

        while(i<points.size()){ // O(n)
            int intervalSt = points[i][0] ;
            int intervalEnd = points[i][1] ;

            if(intervalSt > newIntervalEnd){
                minErrow++ ;
                newIntervalSt = intervalSt ;
                newIntervalEnd = intervalEnd ;
            }
            else{
                newIntervalSt = max(newIntervalSt, intervalSt) ;
                newIntervalEnd = min(newIntervalEnd, intervalEnd) ;
            }

            i++ ;
        }

        minErrow++ ;
        return minErrow ;
    }
};

// ------------------------------------------------------------------------------------------------------


/*
No offense but the currently highest voted java solution is not ideal, the sorting can be adjusted so that there's no need to check again in the for loop.

Idea:
We know that eventually we have to shoot down every balloon, so for each ballon there must be an arrow whose position is between balloon[0] and balloon[1] inclusively. Given that, we can sort the array of balloons by their ending position. Then we make sure that while we take care of each balloon in order, we can shoot as many following balloons as possible.

So what position should we pick each time? We should shoot as to the right as possible, because since balloons are sorted, this gives you the best chance to take down more balloons. Therefore the position should always be balloon[i][1] for the ith balloon.

This is exactly what I do in the for loop: check how many balloons I can shoot down with one shot aiming at the ending position of the current balloon. Then I skip all these balloons and start again from the next one (or the leftmost remaining one) that needs another arrow.

Example:

balloons = [[7,10], [1,5], [3,6], [2,4], [1,4]]
After sorting, it becomes:

balloons = [[2,4], [1,4], [1,5], [3,6], [7,10]]
So first of all, we shoot at position 4, we go through the array and see that all first 4 balloons can be taken care of by this single shot. Then we need another shot for one last balloon. So the result should be 2.
*/


// Intution -> Greedy + Sorting based of ending i.e ballons[i][1]
// T.C. = O(nlog(n))
// S.C. = O(log(n))
public int findMinArrowShots(int[][] points) {
        if (points.length == 0) {
            return 0;
        }
        Arrays.sort(points, (a, b) -> a[1] - b[1]);
        int arrowPos = points[0][1];
        int arrowCnt = 1;
        for (int i = 1; i < points.length; i++) {
            if (arrowPos >= points[i][0]) {
                continue;
            }
            arrowCnt++;
            arrowPos = points[i][1];
        }
        return arrowCnt;
    }