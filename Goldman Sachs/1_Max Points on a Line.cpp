class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() == 1) return 1;

        map<long long, map<long long, int>> mp;

        sort(points.begin(), points.end());

        for(int i=0; i<points.size(); i++) {
            for(int j=i+1; j<points.size(); j++) {
                double slope, intercept;
                if(points[j][0] - points[i][0] == 0) slope = INT_MAX, intercept = points[j][0];
                else {
                    slope = (((float) points[j][1] - points[i][1]) / ((float) points[j][0] - points[i][0]));
                    intercept = ((float) points[i][1] - points[i][0] * slope);

                    slope = round(slope / 0.0001) * 0.0001;
                    intercept = round(intercept / 0.0001) * 0.0001;
                }
                
                // cout<<mp[(long long)(slope*10000)][(long long)(intercept*10000)]<<endl;
                mp[(long long)(slope*10000)][(long long)(intercept*10000)]++;
                // cout<<(long long)(slope*10000)<<" "<<(long long)(intercept*10000)<<endl;
                
            }
        }

        int ans = INT_MIN;
        for(auto x : mp) {
            for(auto y : x.second) {
                ans = max(ans, y.second);
            }
        }

        // cout<<ans<<endl;

        double a = 1, b = -1, c = -2*ans;
        double disc = b*b - 4*a*c;

        return max((-b + sqrt(disc))/(2*a), (-b - sqrt(disc))/(2*a));
    }
};