class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {

        int n = positions.size();
        vector<int>actual_idx(n);
        for(int i = 0; i < n; i++)
            actual_idx[i] = i;
        
        auto lambda = [&](int & i, int & j){
            return positions[i] < positions[j];
        };

        sort(begin(actual_idx), end(actual_idx), lambda);
        stack<int>st;

        for(int & i : actual_idx){
                if(directions[i] == 'R') //towards right
                    st.push(i);

                else{ //towards left
                    while(!st.empty() && healths[i] > 0){

                        int top_idx = st.top();
                        st.pop();
                        if(healths[top_idx] > healths[i]){
                            healths[i] = 0;
                            healths[top_idx] -= 1; //making changes to original array
                            st.push(top_idx);
                        }
                        else if(healths[top_idx] < healths[i]){
                            healths[top_idx] = 0;
                            healths[i] -= 1;
                            // st.push(i);
                        }
                        else{
                            healths[top_idx] = 0;
                            healths[i] = 0;
                        }
                    }
                }    
        }
        vector<int>ans;
        for(int i = 0; i < n; i++){
            if(healths[i] > 0)
                ans.push_back(healths[i]);
        }
        return ans;
    }
};