// LeetCode -> 79. Word Search
https://leetcode.com/problems/word-search/description/



class Solution {
public:

    bool dfs(int i, int j, vector<vector<char>>& board, string &word, int idx){
        if(idx >= word.size()){
            return true ;
        }

        char temp = board[i][j] ;
        board[i][j] = '$' ;

        int m = board.size(), n = board[0].size() ;
        int dRow[] = {-1, 1, 0, 0} ;
        int dCol[] = {0, 0, -1, 1} ;

        for(int k=0 ; k<4 ; k++){
            int nb_i = i + dRow[k] ;
            int nb_j = j + dCol[k] ;

            if(nb_i >= 0 && nb_i < m && nb_j >= 0 && nb_j < n){
                if(word[idx] == board[nb_i][nb_j]){
                    if(dfs(nb_i, nb_j, board, word, idx+1)) {
                        return true ;
                    }
                }
            }
        }

        board[i][j] = temp ;
        return false ;
    }


    bool exist(vector<vector<char>>& board, string word) {
        int len = word.size() ;
        int idx = 0 ;
        int m = board.size(), n = board[0].size() ;
        //vector<vector<int>> vis(m, vector<int> (n, 0)) ;

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(board[i][j] == word[idx]){
                    if(dfs(i, j, board, word, idx+1)){
                        return true ;
                    }
                }
            }
        }

        return false ;
    }
};





class Solution {
public:

    bool dfs(int i, int j, vector<vector<char>>& board, string &word, vector<vector<int>> &vis, int idx){
        vis[i][j] = 1 ;
        if(idx >= word.size()){
            return true ;
        }

        int m = board.size(), n = board[0].size() ;
        int dRow[] = {-1, 1, 0, 0} ;
        int dCol[] = {0, 0, -1, 1} ;

        for(int k=0 ; k<4 ; k++){
            int nb_i = i + dRow[k] ;
            int nb_j = j + dCol[k] ;

            if(nb_i >= 0 && nb_i <m && nb_j >= 0&& nb_j < n){
                if(word[idx] == board[nb_i][nb_j] && !vis[nb_i][nb_j]){
                    if(dfs(nb_i, nb_j, board, word, vis, idx+1)) {
                        return true ;
                    }
                }
            }
        }

        vis[i][j] = 0 ;
        return false ;
    }


    bool exist(vector<vector<char>>& board, string word) {
        int len = word.size() ;
        int idx = 0 ;
        int m = board.size(), n = board[0].size() ;
        vector<vector<int>> vis(m, vector<int> (n, 0)) ;

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(board[i][j] == word[idx]){
                    if(dfs(i,    j, board, word, vis, idx+1)){
                        return true ;
                    }
                }
            }
        }

        return false ;


        /*
        // BFS solution will not work here bcz in for the follwoing test cases and in BFS you can't 
        // apply backtracking kind of things which are needed in the following test cases
        // board = [["a","a"]]
        // word  = "aa"  

        // board = [["a","b"]]
        // word  = "aba" 
        // your O/P = true 


        int len = word.size() ;
        int idx = 0 ;
        int m = board.size(), n = board[0].size() ;
        vector<vector<int>> vis(m, vector<int> (n, 0)) ;
        queue<pair<int, pair<int, int>>> q ; // <level, <i, j>> 

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(board[i][j] == word[idx]){
                    q.push({0, {i, j}}) ;
                    //vis[i][j] = 1 ;
                }
            }
        }

        idx++ ;
        int dRow[] = {-1, 1, 0, 0} ;
        int dCol[] = {0, 0, -1, 1} ;

        while(!q.empty()){

            int size = q.size() ;
            if(idx >= len){
                return true ;
            }

            for(int sz = 1 ; sz<=size ; sz++){
                auto it = q.front() ;
                q.pop() ;
                int level = it.first ;
                int i = it.second.first ;
                int j = it.second.second ;

                for(int k=0 ; k<4 ; k++){
                    int nb_i = i + dRow[k] ;
                    int nb_j = j + dCol[k] ;

                    if(nb_i >= 0 && nb_i <m && nb_j >= 0&& nb_j < n){
                        if(word[idx] == board[nb_i][nb_j] && idx == level+1 && !vis[nb_i][nb_j]){
                            q.push({level+1, {nb_i, nb_j}}) ;
                            vis[nb_i][nb_j] = 1 ;
                        }
                    }
                }
            }
            idx++ ;
        }

        return false ;

        */
    }
};