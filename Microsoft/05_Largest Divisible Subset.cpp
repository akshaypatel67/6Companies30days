class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int count = 0, prev = -1;
        vector<int> ans;
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++) {
            for(int j=0; j<i; j++) {
                if(nums[i] % nums[j] == 0) dp[i] = max(dp[i], dp[j] + 1);
            }
            count = max(count, dp[i]);
        }

        for(int i=nums.size()-1; i>=0; i--) {
            if(dp[i] == count && (prev == -1 || prev % nums[i] == 0)) {
                ans.push_back(nums[i]);
                prev = nums[i];
                count--;
            }
        }

        return ans;
    }
};