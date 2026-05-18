class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        vector<bool> visited(n, false); //so that any index should not go on same index twice
        queue<int> que; //que stores indicies
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i += 1) {
            mp[arr[i]].push_back(i);
        }

        que.push(0); //pushing starting index
        visited[0] = true;

        int steps = 0;

        while (!que.empty()) {

            int size = que.size();

            while (size--) {

                int curIdx = que.front();
                que.pop();

                if(curIdx == n - 1)
                    return steps;
                
                int left = curIdx - 1;
                int right = curIdx + 1;

                if(left >= 0 && !visited[left]) { // i + 1 case
                    que.push(left); 
                    visited[left] = true;
                }

                if(right <= n - 1 && !visited[right]) { // i - 1 case
                    que.push(right);
                    visited[right] = true;
                }

                for (int &idx : mp[arr[curIdx]]) { // j case
                    if(!visited[idx]) {
                        que.push(idx);
                        visited[idx] = true;
                    }
                }
                mp.erase(arr[curIdx]);
            }
            steps += 1;
        }
        return -1;
    }
};