class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        priority_queue<int, vector<int>, greater<int>>pq;

        for(int i = 0; i < nums.size(); i++){
            pq.push(nums[i]);
        }
        int count = 1;
        int maxi = 1;
        int x = pq.top();
        pq.pop();

        while(!pq.empty()){

            int y = pq.top();
            pq.pop();
            if(x == y)  
                continue;
            if(y - x == 1){
                count++;
                maxi = max(maxi, count);
            }
            else 
                count = 1;
            x = y;

        }
        return maxi;
    }
};