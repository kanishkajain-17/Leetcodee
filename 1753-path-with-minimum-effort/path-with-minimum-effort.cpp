class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    vector<vector<int>> directions{{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        priority_queue<p, vector<p>, greater<p>> pq;
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));

        ans[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {

            int dist = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;

            pq.pop();

            if(dist > ans[x][y])
                continue;

            for (auto &dir : directions) {

                int new_x = x + dir[0];
                int new_y = y + dir[1];
                
                if((new_x >= 0 && new_x < m) && (new_y >= 0 && new_y < n)) {

                    int absVal = abs(heights[new_x][new_y] - heights[x][y]);
                    int maxDiff = max(dist, absVal);
                    if(maxDiff < ans[new_x][new_y]) {

                        ans[new_x][new_y] = maxDiff;
                        pq.push({ans[new_x][new_y], {new_x, new_y}});

                    }
                }       
            }
        }
        return ans[m - 1][n - 1];
    }
};