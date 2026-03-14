//Approach-2 (Khandani Backtracking remplate - Without storing all possible strings)
//T.C : O(n * 3 * 2^(n-1)) ~= O(n*2^n)
//S.C : O(n) by recursion system stack
class Solution {
public:
    void solve(int n, string &curr, int &count, int k, string &result) {
        if (curr.length() == n) {
            count++;
            if (count == k) {
                result = curr;  // Store only the k-th string
            }
            return;
        }
        
        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (!curr.empty() && curr.back() == ch)
                continue;
            
            // Do
            curr.push_back(ch);

            // Explore
            solve(n, curr, count, k, result);

            // If result is found, exit early
            if (!result.empty()) return;

            // Undo
            curr.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        string result = "";
        int count = 0;
        
        solve(n, curr, count, k, result);

        return result;
    }
};