class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<vector<int>> dp(aliceArrows.size()+1, vector<int>(numArrows+1, 0));
        vector<int> ans(aliceArrows.size(), 0);

        for(int i=1; i<=aliceArrows.size(); i++) {
            for(int j=1; j<=numArrows; j++) {
                if(aliceArrows[i-1]+1 <= j) {
                    dp[i][j] = max(dp[i-1][j], i - 1 + dp[i-1][j - aliceArrows[i-1] - 1]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        int i = aliceArrows.size(), j = numArrows;
        while(i > 0 && j > 0) {
            if(dp[i-1][j] != dp[i][j]) {
                ans[i-1] = aliceArrows[i-1] + 1;
                j -= aliceArrows[i-1] + 1;
            }
            i--;
        }

        if(j > 0) {
            for(int i=0; i<aliceArrows.size(); i++) {
                if(!ans[i]) {
                    ans[i] = j;
                    break;
                }
            }
        }

        return ans;
    }
};