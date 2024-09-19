class Solution {
public:
    int n, m;
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, -1, 0, 1};
    vector<vector<int>> dp;

    bool dfs(int i, int j, vector<vector<int>>& grid, int currHealth) {
        if (currHealth < 1)
            return false;
        
        if (i == n-1 && j == m-1)
            return true;

        int temp = grid[i][j];
        bool ans = false;
        grid[i][j] = -1;
        for (int k = 0; k < 4; k++) {
            int x = i + dr[k];
            int y = j + dc[k];

            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != -1) {
                int health = currHealth - grid[x][y];
                if (health > dp[x][y]) {
                    dp[x][y] = health;
                    if (dfs(x, y, grid, health))
                        return true;
                }
            }
        }

        grid[i][j] = temp;
        return false;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        n  = grid.size();
        m  = grid[0].size();
        dp = vector<vector<int>> (n, vector<int> (m, 0));
        health -= grid[0][0];
        dp[0][0] = health;

        return dfs(0, 0, grid, health);
    }
};


class Solution {
public:
    int n, m;
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, -1, 0, 1};
    
    bool dijkstra(vector<vector<int>>& grid, int health) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int d = p.first;
            int i = p.second.first;
            int j = p.second.second;

            for (int k = 0; k < 4; k++) {
                int x = i + dr[k];
                int y = j + dc[k];

                if (x >= 0 && x < n && y >= 0 && y < m) {
                    int wt = grid[x][y];
                    if (d + wt < dist[x][y]) {
                        dist[x][y] = d + wt;
                        pq.push({dist[x][y], {x, y}});
                    }
                }
            }
        }

        return (health - dist[n-1][m-1]) > 0;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        n  = grid.size();
        m  = grid[0].size();
        return dijkstra(grid, health);
    }
};



/*
 * Approch 3 -> Shortest Path using 0/1 BSF
 * T.C. = 
 */
class Solution {
public:
    int n, m;
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, -1, 0, 1};

    bool BFS_0_1(vector<vector<int>>& grid, int health) {
        vector<vector<int>> level(n, vector<int> (m, 1e9));
        deque<pair<int, int>> dq;
        level[0][0] = grid[0][0];
        dq.push_back({0, 0});

        while(!dq.empty()) {
            int i = dq.front().first;
            int j = dq.front().second;
            dq.pop_front();
            int lvl = level[i][j];

            for (int k = 0; k < 4; k++) {
                int x = i + dr[k];
                int y = j + dc[k];

                if (x >= 0 && x < n && y >= 0 && y < m) {
                    int l = grid[x][y];
                    if (lvl + l < level[x][y]) {
                        level[x][y] = lvl + l;
                        if (l == 1) dq.push_back({x, y});
                        else dq.push_front({x, y});
                    }
                }
            }
        }

        return (health- level[n-1][m-1]) > 0;
    }


    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        n  = grid.size();
        m  = grid[0].size();
        return BFS_0_1(grid, health);
    }
};