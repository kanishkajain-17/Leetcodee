class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        int n = asteroids.size();
        stack<int> st;

        for (int i = 0; i < n; i ++) {

            while (!st.empty() && st.top() > 0 && asteroids[i] < 0) {
                int sum = asteroids[i] + st.top();

                if(sum > 0) {
                    asteroids[i] = 0;
                    break;
                }
                else if(sum < 0)    
                    st.pop();
                else {
                    st.pop();
                    asteroids[i] = 0;
                }
                
            }
            if(asteroids[i] != 0)
                st.push(asteroids[i]);
                
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};