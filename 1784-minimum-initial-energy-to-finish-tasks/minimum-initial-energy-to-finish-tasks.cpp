class Solution {
public:
    bool isPossible(vector<vector<int>>& tasks, int mid) {
        for(auto &t: tasks) {
            int actual = t[0];
            int mini = t[1];

            if (mid < mini)
                return false;
            
            mid -= actual;
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int l = 0;
        int r = 1e9;
        int ans = INT_MAX;

        auto lamda = [] (auto &tasks1, auto &tasks2) {
            int diff1 = tasks1[1] - tasks1[0];
            int diff2 = tasks2[1] - tasks2[0];

            return diff1 > diff2;
        };

        sort(begin(tasks), end(tasks), lamda);
        while (l <= r) { 
            int mid = l + (r - l) / 2;
            if (isPossible(tasks, mid)) {
                ans = mid;
                r = mid - 1;
            }
            else 
                l = mid + 1;
        }
        return ans;
    }
};