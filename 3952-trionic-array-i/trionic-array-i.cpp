class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
            while( i + 1 < n && nums[i] < nums[i + 1]){
                i++;
            }
            if(i == 0 || i == n - 1) //agar sirf increasing he nahi hai tab
                //aur poore mai sirf increasing he hai --> [1, 3, 5]
                return false;
            while(i + 1 < n && nums[i] > nums[i + 1]){
                i++;
            }
            if(i == n - 1) //poore array mai sirf increasing or dec he hai vaps inc nahi hai 
                return false;
            while(i + 1 < n && nums[i] < nums[i + 1]){
                i++;
            }//sab kuch hai 
        
        if(i == n - 1)//last tak pahuch gaya inc + dec + inc
            return true;
        return false;
    }
};