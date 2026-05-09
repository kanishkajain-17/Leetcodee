class Solution {
public:

    void dfs(int start,
             string &s,
             vector<int> &first,
             vector<int> &last,
             int &end,
             bool &valid) {

        for(int i = start; i <= end; i++) {

            int ch = s[i] - 'a';

            // invalid interval
            if(first[ch] < start) {
                valid = false;
                return;
            }

            // expand like SCC expansion
            end = max(end, last[ch]);
        }
    }


    vector<string> maxNumOfSubstrings(string s) {

        int n = s.size();

        vector<int> first(26, n);
        vector<int> last(26, -1);

        // first & last occurrence
        for(int i = 0; i < n; i++) {

            first[s[i] - 'a'] =
                min(first[s[i] - 'a'], i);

            last[s[i] - 'a'] = i;
        }

        vector<pair<int,int>> intervals;

        // build complete components/intervals
        for(int ch = 0; ch < 26; ch++) {

            if(last[ch] == -1)
                continue;

            int start = first[ch];
            int end = last[ch];

            bool valid = true;

            // expand whole dependency group
            dfs(start, s, first, last, end, valid);

            if(valid) {
                intervals.push_back({start, end});
            }
        }

        // greedy by ending
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a.second < b.second;
             });

        vector<string> ans;

        int prevEnd = -1;

        for(auto &it : intervals) {

            int start = it.first;
            int end = it.second;

            if(start > prevEnd) {

                ans.push_back(
                    s.substr(start, end - start + 1)
                );

                prevEnd = end;
            }
        }

        return ans;
    }
};