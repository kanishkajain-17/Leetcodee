class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();

        vector<int>ans;
        
        for(int i = 0; i < n; i++){

            vector<int>temp;

            int num = nums[i];
            
            while(num > 0){

                int rem = num % 10;
                temp.push_back(rem);
                num = num / 10;
            }
            for(int j = temp.size() - 1; j >= 0; j--)
                ans.push_back(temp[j]);
            
        }
        return ans;
    }
};