// LeetCode -> 2812. Find the Safest Path in a Grid


// Optimal Approch
/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=8I0Z_eajcvs
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/
*/


/************************************************************ C++ ************************************************************************/
//T.C : O(log(n) * n^2)
//S.C : O(n^2)
class Solution {
public:
    // Variables
    int n;
    vector<vector<int>> cellSf;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};


    void computeCellSf(vector<vector<int>>& grid){
        cellSf = vector<vector<int>> (n, vector<int> (n, 0));
        vector<vector<int>> vis(n, vector<int> (n, 0));
        int level = 1;
        queue<pair<int, int>> q;

        for(int i=0; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j]){
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            int size = q.size();

            for(int i=0 ; i<size; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(int k=0; k<4; k++){
                    int new_x = x + dr[k];
                    int new_y = y + dc[k];

                    if(new_x >= 0 && new_x < n && new_y >=0 && new_y < n && !vis[new_x][new_y]){
                        cellSf[new_x][new_y] = level;
                        vis[new_x][new_y] = 1;
                        q.push({new_x, new_y});
                    }
                }
            }

            level++;
        }
    }

    
    bool checkSf(vector<vector<int>>& grid, int midSf){
        vector<vector<int>> vis(n, vector<int> (n, 0));
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = 1;

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if(x == n-1 && y == n-1){
                return true;
            }

            for(int k=0; k<4; k++){
                int new_x = x + dr[k];
                int new_y = y + dc[k];

                if(new_x >= 0 && new_x < n && new_y >=0 && new_y < n && cellSf[new_x][new_y] >= midSf && !vis[new_x][new_y]){
                    vis[new_x][new_y] = 1;
                    q.push({new_x, new_y});
                }
            }
        }

        return false;
    }


    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();

        if(grid[0][0] || grid[n-1][n-1]){
            return 0;
        }

        // step -> 1: computing each cell safeness factor 
        computeCellSf(grid);

        // step -> 2: using binary search
        int l = 1;
        int h = min(cellSf[0][0], cellSf[n-1][n-1]);
        int result = 0;

        while(l <= h){
            int midSf = l + (h-l)/2;
            
            if(checkSf(grid, midSf)){
                result = midSf;
                l = midSf+1;
            }
            else{
                h = midSf-1;
            }
        }
        
        return result;
    }
};







class Solution {
public:

    int n;
    vector<pair<int, int>> vec; 
    vector<vector<int>> vis;

    int calManhattanDis(int i, int j){
        int dis = INT_MAX;

        for(auto it: vec){
            int val = abs(i - it.first) + abs(j - it.second);
            dis = min(dis, val);
        }

        return dis;
    }

    int solve(int i, int j, vector<vector<int>>& grid, int pathDis){
        if(i == n-1 && j == n-1){
            int final = min(pathDis, calManhattanDis(i, j));
            // cout << "(" << i << ", " << j << ", " << final << ")" << endl << endl;
            return final;
        }

        if(grid[i][j] == 1){
            return 0;
        }

        vis[i][j] = 1;
        int ans = 0;
        pathDis = min(pathDis, calManhattanDis(i, j));
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // cout << "(" << i << ", " << j << ", " << pathDis << ")" << " -> ";

        for(int k=0; k<4 ; k++){
            int adj_i = i + dr[k];
            int adj_j = j + dc[k];

            if(adj_i >= 0 && adj_i < n && adj_j >= 0 && adj_j < n && !vis[adj_i][adj_j]){
                ans = max(ans, solve(adj_i, adj_j, grid, pathDis));
            }
        }

        vis[i][j] = 0;
        return ans;
    }


    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();

        if(grid[0][0] || grid[n-1][n-1]){
            return 0;
        }

        for(int i=0; i<n ; i++){
            for(int j=0; j<n ; j++){
                if(grid[i][j]){
                    vec.push_back({i, j});
                }
            }
        }
        
        vis = vector<vector<int>> (n, vector<int> (n, 0));

        return solve(0, 0, grid, INT_MAX);
    }
};