class Solution {
public:
    typedef long long ll;
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<ll, int> mp;
        int ans = 0;
        int len = 0;

        for (int i = 0; i < n; i ++) 
            mp[nums[i]] += 1;

        if(mp[1] % 2 == 0)
            ans = mp[1] - 1;
        else
            ans = mp[1]; 

        for (auto &m : mp) {
            ll num = m.first;

            if(num == 1)
                continue;
                
            len = 0;
            
            while (mp.count(num) && mp[num] > 1) {
                len += 2;
                num = num * num;
            }

            if(mp.count(num) == 1)
                len += 1;
            else    
                len -= 1;

            ans = max(len, ans);
        }
        return ans;
    }
};