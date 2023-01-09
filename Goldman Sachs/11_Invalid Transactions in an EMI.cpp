class Solution {
public:
    vector<string> split_string(string s, char del) {
        vector<string> result;
        stringstream ss(s);
        string word;
        while (!ss.eof()) {
            getline(ss, word, del);
            result.push_back(word);
        }
        return result;
    }

    vector<string> invalidTransactions(vector<string>& transactions) {
        unordered_map<string, vector<int>> mp;
        vector<string> ans;
        set<int> ansSet;

        for(int i=0; i<transactions.size(); i++) {
            vector<string> t = split_string(transactions[i], ',');

            for(int ind : mp[t[0]]) {
                vector<string> t2 = split_string(transactions[ind], ',');

                if(abs(stoi(t[1]) - stoi(t2[1])) <= 60 && t[3] != t2[3]) {
                    ansSet.insert(i);
                    ansSet.insert(ind);
                }
            }

            if(stoi(t[2]) > 1000) {
                ansSet.insert(i);
            }

            mp[t[0]].push_back(i);
        }

        for(auto i : ansSet) {
            ans.push_back(transactions[i]);
        }

        return ans;
    }
};