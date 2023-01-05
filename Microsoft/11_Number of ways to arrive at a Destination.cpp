class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        vector<long long> times(n, 9223372036854775807);
        vector<int> ways(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        int mod = 1e9+7;

        for(int i=0; i<roads.size(); i++) {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        times[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while(!pq.empty()) {
            int u = pq.top().second;
            long long time = pq.top().first;
            pq.pop();

            for(auto v : adj[u]) {
                if(time + v.second < times[v.first]) {
                    times[v.first] = (time + v.second);
                    ways[v.first] = ways[u];
                    pq.push({time + v.second, v.first});
                } else if(time + v.second == times[v.first]) {
                    ways[v.first] = (ways[v.first] + ways[u]) % mod;
                }
            }
        }

        return ways[n-1];
    }
};