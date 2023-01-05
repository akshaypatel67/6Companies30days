class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        vector<int> lps;
        int pre = 0;
        lps.push_back(0);

        for(int i=1; i<n; i++) {
            if(s[i] == s[pre]) {
                pre++;
                lps.push_back(pre);
            } else if(pre > 0) {
                pre = lps[pre - 1];
                i--;
            } else {
                lps.push_back(0);
            }
        }

        return s.substr(0, lps[n-1]);
    }
};