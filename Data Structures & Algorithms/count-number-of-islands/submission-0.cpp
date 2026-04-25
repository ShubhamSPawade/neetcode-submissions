class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    dfs(i, j, n, m, vis, grid);
                }
            }
        }

        return cnt;
    }

    void dfs(int i, int j, int n, int m, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[i][j] = 1;
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for(int k = 0; k<4; k++){
            int nr = i + dr[k];
            int nc = j + dc[k];

            if(nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc] && grid[nr][nc] == '1'){
                dfs(nr, nc, n, m, vis, grid);
            } 
        }
    }
};
