class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        

        int n = nums.size();
        vector<vector<int>>bucket(n + 1);

        unordered_map<int, int>mp;

        for(int &i :nums)
        mp[i]++;

        for(auto &it : mp){
            int element = it.first;
            int freq = it .second;

            bucket[freq].push_back(element);
        }

        vector<int>res;

        for(int i = n; i >= 0; i--){
            if(bucket[i].size() == 0)
            continue;

            while(bucket[i].size() > 0 && k > 0){

                res.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return res;
    }
};