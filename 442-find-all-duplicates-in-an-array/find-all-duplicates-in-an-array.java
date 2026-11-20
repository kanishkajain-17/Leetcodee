class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        int n = nums.length;
        List<Integer> ans = new ArrayList<>();
        HashMap<Integer, Integer> mp = new HashMap<>();

        for (int i = 0; i < n; i++) {
            
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
        }

       for (Map.Entry<Integer, Integer> m : mp.entrySet()) {
            if(m.getValue() > 1)
                ans.add(m.getKey());
       }
        return ans;
    }
}