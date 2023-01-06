class Solution {
public:
    int fact(int i){
        if (i <= 1) return 1;
        else return i*fact(i-1);
    }

    double dist(vector<int>& p1, vector<int>& p2) {
        return (double) sqrt((double) pow(p1[0]-p2[0], 2) + pow(p1[1]-p2[1], 2));
    }

    int numberOfBoomerangs(vector<vector<int>>& points) {
        vector<map<double, int>> boom(points.size());

        for(int i=0; i<points.size(); i++) {
            for(int j=0; j<points.size(); j++) {
                if(i == j) continue;

                boom[i][dist(points[i], points[j])]++;
            }
        }

        int ans = 0;

        for(int i=0; i<points.size(); i++) {
            for(auto x : boom[i]) {
                ans += fact(x.second) / (2 * fact(x.second - 2));
            }
        }

        return ans * 2;
    }
};