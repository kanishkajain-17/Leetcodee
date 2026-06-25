class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> st;
        int count = 0;
        int maxCount = 0;

        for (int i = 0; i < n; i ++)
            st.insert(nums[i]);

        for (int num : st) {

            count = 0;

            if(st.find(num - 1) == st.end()) {
                //then nums[i] is the starting value bcz isse ek phle koi value nahi

                int x = num;
                
                while (st.find(x) != st.end()) {

                    count += 1;
                    x += 1;
                }

                maxCount = max(maxCount, count);
            }
            else
                continue;
        }
        return maxCount;
    }
};