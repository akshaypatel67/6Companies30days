class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size() + 1, ans = INT_MIN;
        vector<vector<int>> adj(n);
        vector<int> time(n, INT_MAX);
        vector<int> vis(n, 0);

        for(int i=0; i<n-1; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        function<bool(int, int)> dfs1 = [&] (int i, int t) {
            vis[i] = 1;
            time[i] = t;

            if(i == 0) return true;

            for(int j : adj[i]) {
                if(!vis[j]) {
                    if(dfs1(j, t+1)) return true;
                }
            }

            time[i] = INT_MAX;
            return false;
        };

        dfs1(bob, 0);

        fill(vis.begin(), vis.end(), 0);

        function<void(int, int, int)> dfs2 = [&] (int i, int t, int income) {
            vis[i] = 1;

            if(t < time[i]) income += amount[i];
            else if(t == time[i]) income += amount[i] / 2;

            int flag = 1;
            for(int j : adj[i]) {
                if(!vis[j]) dfs2(j, t+1, income), flag = 0;
            }

            if(flag) ans = max(ans, income);
        };

        dfs2(0, 0, 0);

        return ans;
    }
};