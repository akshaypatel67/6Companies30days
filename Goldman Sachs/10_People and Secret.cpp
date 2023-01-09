class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> persons(n, 0);
        persons[0] = 1;
        long long ans = 0, mod = 1e9+7;

        for(int i=0; i<n; i++) {
            for(int j=i+delay; j<min(i+forget, n); j++) {
                persons[j] = (persons[j] + persons[i]) % mod;
            }

            ans = ans + persons[i];
            if(i-forget >= 0) ans -= persons[i-forget];
        }

        return ans % mod;
    }
};