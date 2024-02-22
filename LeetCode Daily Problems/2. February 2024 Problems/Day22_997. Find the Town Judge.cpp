https://leetcode.com/problems/find-the-town-judge/description/


// Approch -> Hash table
// N -> Size of Trust vector
// T.C. = O(N + N)
// S.C. = O(2N)
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        if(trust.size() == 0 && n == 1) return 1 ;

        unordered_map<int, int> mp ;

        for(int i=0 ; i<trust.size() ; i++){
            int  person = trust[i][0] ;
            int trusted = trust[i][1] ;
            mp[trusted]++ ;
            mp[person] = INT_MIN ;
        }

        for(auto it: mp){
            if(it.second == n-1){
                return it.first ;
            }
        }
        
        return -1 ;
    }
};



// Approch -> Graph
// N -> Size of Trust vector
// T.C. = O(N + N)
// S.C. = O(2N)
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //if(trust.size() == 0 && n == 1) return 1 ;
        vector<int> indegree(n+1, 0) ;
        vector<int> outEdge(n+1, 0) ;

        for(int i=0 ; i<trust.size() ; i++){
            int person = trust[i][0] ;
            int trusted = trust[i][1] ;

            indegree[trusted]++ ;
            outEdge[person] = 1 ;
        }

        for(int i=1 ; i<= n ; i++){
            if(indegree[i] == n-1 && outEdge[i] == 0){
                return i ;
            }
        }

        return -1 ;
    }
};




class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size() == 0 && n == 1) return 1 ;
        vector<int> indegree(n+1, 0) ;
        vector<int> outEdge(n+1, 0) ;
        int judge = -1 ;

        for(int i=0 ; i<trust.size() ; i++){
            int person = trust[i][0] ;
            int trusted = trust[i][1] ;

            indegree[trusted]++ ;
            outEdge[person] = 1 ;

            if(indegree[trusted] == n-1 && outEdge[trusted] == 0){
                judge = trusted ;
            }

            if(judge == person){
                judge = -1 ;
            }
        }

        // for(int i=1 ; i<= n ; i++){
        //     if(indegree[i] == n-1 && outEdge[i] == 0){
        //         return i ;
        //     }
        // }

        return judge ;
    }
};