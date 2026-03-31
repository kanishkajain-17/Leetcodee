class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int>st;
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && st.top() > 0 && asteroids[i] < 0){
                int sum = st.top() + asteroids[i];
                if(sum < 0){//move left side
                    st.pop();
                }
                else if(sum > 0){
                    asteroids[i] = 0; //bcz while mai 0 par check ne hora
                }
                else{
                    st.pop();
                    asteroids[i] = 0;
                } //sum = 0
            }
                if(asteroids[i] != 0)
                    st.push(asteroids[i]);   
        }
        int s = st.size();
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};