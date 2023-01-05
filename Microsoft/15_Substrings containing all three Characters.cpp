class Solution {
public:
    int numberOfSubstrings(string s) {
        int prev = 0, prevj = -1, ans = 0;
        unordered_map<char, int> mp;

        int j = 0;
        for(int i=0; i<s.length(); i++) {
            mp[s[i]]++;
            if(mp['a'] && mp['b'] && mp['c']) {
                while(mp['a'] && mp['b'] && mp['c']) {
                    mp[s[j]]--;
                    j++;
                }
                prev = j-1 - prevj - 1;
                prevj = j-1;
                ans++;
                ans += prev;
                ans += s.length() - i - 1;
                ans += prev * (s.length() - i - 1);
            }
        }

        return ans;
    }
};