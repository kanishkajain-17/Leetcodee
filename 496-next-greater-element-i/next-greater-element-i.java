class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int m = nums2.length;

        HashMap<Integer, Integer> mp = new HashMap<>();
        Stack<Integer> st = new Stack<>();

        for (int i = m - 1; i >= 0; i--) {
            
            while (!st.isEmpty() && st.peek() <= nums2[i]) 
                st.pop();

            if(st.isEmpty())
                mp.put(nums2[i], -1);
            else
                mp.put(nums2[i], st.peek());
            st.push(nums2[i]);
        }

        int[] ans = new int[n];

        for (int i = 0; i < n; i++)
            ans[i] = mp.get(nums1[i]);
        
        return ans;
    }
}