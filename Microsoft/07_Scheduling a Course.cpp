class Solution {
public:
    bool dfs(int i, vector<vector<int>>& adj, vector<int>& vis) {
        vis[i] = 1;
        
        for(auto j : adj[i]) {
            if(vis[j] == 1) return false;
            if(!vis[j]) {
                if(!dfs(j, adj, vis)) return false;
            }
        }
        
        vis[i] = 2;
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses, 0);
        
        for(int i=0; i<prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        for(int i=0; i<numCourses; i++) {
            if(!vis[i]) {
                if(!dfs(i, adj, vis)) return false;
            }
        }
        return true;
    }
};