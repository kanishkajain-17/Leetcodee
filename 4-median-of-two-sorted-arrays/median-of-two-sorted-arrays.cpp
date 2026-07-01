class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int size = m + n;

        int idx1 = (size - 1) / 2;
        int idx2 = size / 2;

        int ele1 = 0, ele2 = 0;
        int i = 0, j = 0;
        int k = 0;

        while (i < m && j < n) {

            if(nums1[i] < nums2[j]) {
                
                if(k == idx1) {
                    ele1 = nums1[i];
                }
                    
                if(k == idx2) {
                    ele2 = nums1[i];
                }
                    
                i += 1;
            }
            else{

                if(k == idx1) {
                      ele1 = nums2[j];
                }
                  
                if(k == idx2) {
                    ele2 = nums2[j];
                }
                    
                j += 1;
            }
            k += 1;
        }
        while (i < m) {
                if(k == idx1) {
                     ele1 = nums1[i];
                }
                   
                if(k == idx2) {
                     ele2 = nums1[i];
                }
                   
                i += 1;
                k += 1;
        }
        while(j < n) {
            if(k == idx1) {
                ele1 = nums2[j];
            }
                    
            if(k == idx2) {
                    ele2 = nums2[j];
            }
                   
                j += 1;
                k += 1;
        }
        if(size % 2 == 1)
            return ele2;
        return (ele1 + ele2) / 2.0;
    }
    
};