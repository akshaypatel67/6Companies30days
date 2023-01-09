class Solution {
public:
    int reverseNum(int num) {
        int rev = 0;
        while(num > 0) {
            rev = rev*10;
            rev += num%10;
            num /= 10;
        }
        return rev;
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<long long, long long> mp;
        long long ans = 0, mod = 1e9+7;

        for(int i=0; i<nums.size(); i++) {
            mp[nums[i] - reverseNum(nums[i])]++;
        }

        for(auto x : mp) {
            ans = (ans + x.second * (x.second - 1) / 2) % mod;
        }

        return ans;
    }
};