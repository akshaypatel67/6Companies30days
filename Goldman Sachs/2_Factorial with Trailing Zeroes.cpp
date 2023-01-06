class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0, curr = 5;

        while(n / curr > 0) {
            ans += n / curr;
            curr *= 5;
        }

        return ans;
    }
};