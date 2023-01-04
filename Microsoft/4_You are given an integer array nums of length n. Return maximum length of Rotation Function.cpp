class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans = 0, sum = 0, curr, n = nums.size();
        for(int i=0; i<n; i++) {
            ans += (i * nums[i]);
            sum += nums[i];
        }

        curr = ans;
        for(int i=n-1; i>=1; i--) {
            curr += sum - nums[i];
            curr -= (n-1) * nums[i];
            ans = max(ans, curr);
        }

        return ans;
    }
};