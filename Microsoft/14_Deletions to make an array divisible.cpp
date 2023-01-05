class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(), nums.end());
        int currGcd = numsDivide[0];
        
        for(int i=1; i<numsDivide.size(); i++) {
            currGcd = __gcd(currGcd, numsDivide[i]);
        }

        for(int i=0; i<nums.size(); i++) {
            if(currGcd % nums[i] == 0) return i;
        }

        return -1;
    }
};