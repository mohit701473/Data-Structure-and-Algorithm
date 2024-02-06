// leetCode -> 733. Flood Fill
https://leetcode.com/problems/flood-fill/description/

// Approch -> BFS or DFS
// T.C. = O(N^2)
// S.C. = O(N^2)
class Solution {

    void dfs(int i, int j, int color, int initialColor, vector<vector<int>>& image, vector<vector<int>>& vis) {

        vis[i][j] = 1;
        image[i][j] = color ;

        // call dfs for neighbors of node which are same initial color and not visited
        // UP
        if (i - 1 >= 0 && !vis[i - 1][j] && image[i-1][j] == initialColor) {
            dfs(i-1, j, color, initialColor, image, vis) ;
        }

        // Down
        if (i + 1 < n && !vis[i + 1][j] && image[i+1][j] == initialColor) {
            dfs(i+1, j, color, initialColor, image, vis) ;
        }

        // Left
        if (j - 1 >= 0 && !vis[i][j - 1] && image[i][j-1] == initialColor) {
            dfs(i, j-1, color, initialColor, image, vis) ;
        }

        // Right
        if (j + 1 < m && !vis[i][j + 1] && image[i][j+1] == initialColor) {
            dfs(i, j+1, color, initialColor, image, vis) ;
        }
    }

public:
    int n , m ;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size(), m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int initialColor = image[sr][sc];
        dfs(sr, sc, color, initialColor, image, vis);
        return image;
    }
};