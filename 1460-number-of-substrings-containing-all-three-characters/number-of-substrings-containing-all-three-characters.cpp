class Solution {
public:
    //ideal problem of sliding window
    //tc = O(2n) = O(n) har element 2 baar visit hora hai, ek baar i se ek baar j se
    //sc = O(1)
    int numberOfSubstrings(string s) {
        int n = s.length();
        int l = 0;
        int r = 0;
        int count = 0;
        vector<int> mp(3, 0);

        while (r < n) {

            mp[s[r] - 'a'] += 1;

            while (mp[0] > 0 && mp[1] > 0 && mp[2] > 0) {
                count += n - r; //bcz abc toh hai he, baki bache bhi substring m count honge
                mp[s[l] - 'a'] -= 1;
                l += 1;
            }

            r += 1;
        }
        return count;
    

    //BRUTE FORCE
        /* int n = s.length();
        int count = 0;

        for (int i = 0; i < n; i += 1) {

            int a = 0, b = 0, c = 0;

            for (int j = i; j < n; j += 1) {

                if(s[j] == 'a')
                    a += 1;
                else if(s[j] == 'b')
                    b += 1;
                else
                    c += 1;

                if(a > 0 && b > 0 && c > 0)
                    count += 1;
            }
            
        }
        return count;
        */
    }
};