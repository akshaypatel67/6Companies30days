class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> vec;
        priority_queue<int> pq;

        for(int i=0; i<profits.size(); i++) vec.push_back({capital[i], profits[i]});

        sort(vec.begin(), vec.end());

        int i = 0;
        while(i < vec.size() && vec[i].first <= w) pq.push(vec[i].second), i++;

        while(!pq.empty() && k > 0) {
            int mxProfit = pq.top();
            pq.pop();

            w += mxProfit;

            while(i < vec.size() && vec[i].first <= w) pq.push(vec[i].second), i++;
            k--;
        }

        return w;
    }
};