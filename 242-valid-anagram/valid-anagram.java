class Solution {
    public boolean isAnagram(String s, String t) {

        if(s.length() != t.length())    
            return false;
        
        int[] count = new int[26];

        char[] s1 = s.toCharArray();
        char[] t1 = t.toCharArray();

        int n = s.length();

        for (int i = 0; i < n; i++) {
            count[s1[i] - 'a'] ++;
            count[t1[i] - 'a'] --;
        }

        for (int  i = 0; i < 26; i++)
            if(count[i] != 0)
                return false;
            
        return true;
    }
}