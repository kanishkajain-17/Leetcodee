class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        int n = bulbs.size();
        set<int>st;
        for(int i = 0; i < n; i++){
            if(st.find(bulbs[i]) == st.end())
                st.insert(bulbs[i]);
            else
                st.erase(bulbs[i]);
        }
        vector<int>ans;
        for(auto & it: st)
            ans.push_back(it);
        return ans;
    }
};