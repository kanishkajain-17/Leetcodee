class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        int n = nums.size();
        unordered_set<int> st;

        for (int i = 0; i < n; i ++)
            st.insert(nums[i]);
        
        int minn = *min_element(begin(nums), end(nums));
        int maxx = *max_element(begin(nums), end(nums));

        vector<int> ans;

        for (int i = minn + 1; i < maxx; i ++) {

            if(st.count(i) == 0)
                ans.push_back(i);
        }

        return ans;
    }
};