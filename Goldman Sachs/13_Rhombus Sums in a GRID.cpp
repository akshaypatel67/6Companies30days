class Solution {
public:
    int findSum(int i, int j, int size, vector<vector<int>>& grid) {
        if(i+2*size-2 >= grid.size() || j-size+1 < 0 || j+size-1 >= grid[0].size()) {
            return 0;
        }

        if(size == 1) return grid[i][j];

        int sum = 0;
        for(int k=0; k<size-1; k++) {
            i++, j--;
            sum += grid[i][j];
            
        }
        for(int k=0; k<size-1; k++) {
            i++, j++;
            sum += grid[i][j];
            
        }
        for(int k=0; k<size-1; k++) {
            i--, j++;
            sum += grid[i][j];
            
        }
        for(int k=0; k<size-1; k++) {
            i--, j--;
            sum += grid[i][j];
            
        }

        return sum;
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<int> ans(3, 0);
        int currans;
        
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                for(int k=1; k<=max(grid.size(), grid[0].size()); k++) {
                    currans = findSum(i, j, k, grid);
                    if(currans > 0) {
                        if(ans.size() < 3) ans.push_back(currans);
                        else if(ans[0] < currans && ans[1] != currans && ans[2] != currans) {
                            ans[0] = currans;
                        }
                        sort(ans.begin(), ans.end());
                    }
                }
            }
        }

        sort(ans.rbegin(), ans.rend());
        while(ans.size() && ans[ans.size()-1] == 0) ans.pop_back();

        return ans;
    }
};