class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        auto lambda = [](vector<int> vec1, vector<int> vec2) {

            if(vec1[0] == vec2[0])
                return vec1[1] > vec2[1];

            return vec1[0] < vec2[0];
        };
        
        sort(begin(intervals), end(intervals), lambda);
        int n = intervals.size();
        int count = 1;
        int maxEnd = intervals[0][1];

        for (int i = 1; i < n; i ++) {
           
            if(maxEnd >= intervals[i][1])
                continue;
            maxEnd = intervals[i][1];
            count += 1;
        }
        return count;   
    }
};