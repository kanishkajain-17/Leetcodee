class Solution {
public:
    //same N meeting in one room
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(begin(intervals), end(intervals));
        int n = intervals.size();
        int count = 0;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < n; i += 1) {
            if(prevEnd > intervals[i][0]) {
                count += 1;
                prevEnd = min(prevEnd, intervals[i][1]);
            }
            else
                prevEnd = intervals[i][1];
        }
        return count;
    }
};