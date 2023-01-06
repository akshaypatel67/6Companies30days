class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> ind;
        int ans = INT_MAX;

        for(int i=0; i<cards.size(); i++) {
            if(ind.find(cards[i]) != ind.end()) {
                ans = min(ans, i - ind[cards[i]] + 1);
            }
            ind[cards[i]] = i;
        }

        return ans != INT_MAX ? ans : -1;
    }
};