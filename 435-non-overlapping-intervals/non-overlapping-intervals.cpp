class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size();

        sort(begin(intervals), end(intervals));
        int prevEnd = intervals[0][1];
        int count = 0;

        for (int i = 1; i < n; i ++) {

            if(intervals[i][0] < prevEnd) {
                count += 1;
                prevEnd = min(prevEnd, intervals[i][1]);
            }
            else
                prevEnd = intervals[i][1];
        }
        return count;
    }
};