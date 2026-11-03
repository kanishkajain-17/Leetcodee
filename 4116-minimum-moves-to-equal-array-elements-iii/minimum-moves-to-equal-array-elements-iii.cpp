class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int max_ele = *max_element(begin(nums), end(nums));
        int moves = 0;

        for (int i = 0; i < n; i++)
            moves += max_ele - nums[i];
        
        return moves;
    }
};