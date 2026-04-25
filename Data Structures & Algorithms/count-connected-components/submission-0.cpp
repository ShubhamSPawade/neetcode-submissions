class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            auto it = edges[i];
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }  

        int cnt = 0;
        vector<int> vis(n, 0);
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, vis, adj);
            }
        }   

        return cnt;
    }

    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj){
        vis[node] = 1;
        for(auto i : adj[node]){
            if(!vis[i]){
                dfs(i, vis, adj);
            }
        }
    }
};
