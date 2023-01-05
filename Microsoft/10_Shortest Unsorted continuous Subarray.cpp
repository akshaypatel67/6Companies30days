class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sortednums;
        for(int i=0; i<nums.size(); i++) sortednums.push_back(nums[i]);
        sort(sortednums.begin(), sortednums.end());

        int i = 0, j = nums.size()-1;
        while(i <= j && nums[i] == sortednums[i]) i++;
        while(i <=j && nums[j] == sortednums[j]) j--;

        return j-i+1;
    }
};