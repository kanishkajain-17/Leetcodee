class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        priority_queue<int> pq;
        vector<int> freq(26);

        for (auto &t : tasks)
            freq[t - 'A'] += 1;
        
        for (auto &f : freq)
            if(f > 0)
                pq.push(f);
        
        while (!pq.empty()) {

            vector<int> temp;
            for (int i = 1; i <= n + 1; i += 1) {
                if(!pq.empty()) {
                    int frequency = pq.top();
                    pq.pop();
                    frequency--;
                    temp.push_back(frequency);
                }
            }

            for (auto &t : temp)
                if(t > 0)
                    pq.push(t);
            
            if(pq.empty())
                time += temp.size();
            else
                time += n + 1;
        }
        return time;
    }
};