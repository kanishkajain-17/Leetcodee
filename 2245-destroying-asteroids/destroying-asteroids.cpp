class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long Mass = mass;
        sort(begin(asteroids), end(asteroids));
        int n = asteroids.size();
        int sum = 0;
        for (int i = 0; i < n; i += 1) {
        
            if(Mass < asteroids[i]) {
                return false;
            }
            Mass += asteroids[i];
        }
        return true;
    }
};