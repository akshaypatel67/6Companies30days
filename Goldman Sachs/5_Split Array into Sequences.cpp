class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> mp;
        unordered_map<int, int> mp2;
        for(int i=0; i<nums.size(); i++) mp[nums[i]]++;

        for(int i=-1000; i<=1000; i++) {
            if(!mp[i]) continue;

            int mn = min(mp[i], mp2[i-1]);
            mp[i] -= mn;
            mp2[i] += mn;

            mn = min(min(mp[i+1], mp[i+2]), mp[i]);
            mp[i+1] -= mn;
            mp[i+2] -= mn;
            mp[i] -= mn;

            mp2[i+2] += mn;
        }

        for(int i=-1000; i<=1000; i++) {
            if(mp[i]) return false;
        }

        return true;
    }
};