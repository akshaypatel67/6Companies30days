class Solution {
public:
    void combination(int k, int n, int prev, unordered_map<int, int>& mp, vector<int>&curr, vector<vector<int>>& ans) {
        if(k == 0 && n == 0) {
            ans.push_back(curr);
            return;
        } else if(k == 0 || n == 0) {
            return;
        }

        for(int i=prev+1; i<=min(9, n); i++) {
            if(!mp[i]) {
                curr.push_back(i);
                mp[i] = 1;
                combination(k-1, n-i, i, mp, curr, ans);
                curr.pop_back();
                mp[i] = 0;
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        vector<vector<int>> ans;
        unordered_map<int, int> mp;

        combination(k, n, 0, mp, curr, ans);

        return ans;
    }
};