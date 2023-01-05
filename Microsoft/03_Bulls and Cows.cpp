class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        unordered_map<char, int> mp;
        vector<int> flag(secret.length(), 1);

        for(int i=0; i<secret.length(); i++) {
            if(secret[i] == guess[i]) bulls++, flag[i] = 0;
            else mp[secret[i]]++;
        }

        for(int i=0; i<secret.length(); i++) {
            if(flag[i] && mp[guess[i]]) cows++, mp[guess[i]]--;
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};