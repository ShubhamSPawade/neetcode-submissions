class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cntFresh = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
                if (grid[i][j] == 1) cntFresh++;
            }
        }

        int time = 0, cnt = 0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int r = it.first.first;
            int c = it.first.second;
            int t = it.second;

            time = max(time, t);

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr >= 0 && nc >= 0 && nr < n && nc < m && vis[nr][nc] != 1 &&
                    grid[nr][nc] == 1) {
                    vis[nr][nc] = 1;
                    q.push({{nr, nc}, t + 1});
                    cnt++;
                }
            }
        }
        if (cnt != cntFresh) return -1;

        return time;
    }
};
