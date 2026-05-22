class Solution {
public:
   int findpivot(vector<int>& nums,int n)
   {
      int l=0; int r=n-1;
      while(l<r)
      {
        int mid=l+(r-l)/2;
        if(nums[mid]>nums[r])
        l=mid+1;
        else
        r=mid;
      }
      return r;
   }
   int binary(int l,int r,vector<int>& nums,int target)
   {
     int indx=-1;
     while(l<=r)
     {
        int mid=l+(r-l)/2;
        if(nums[mid]==target)
         return mid;
        else if(nums[mid]<target)
        l=mid+1;
        else
        r=mid-1;
     }
     return indx;
   }
   int search(vector<int>& nums,int target)
   {
        int n=nums.size();
        int pivot_index=findpivot(nums,n);
        int indx=binary(0,pivot_index-1,nums,target);
        if(indx!=-1)
        return indx;
        indx=binary(pivot_index,n-1,nums,target);
        return indx;
   }
   
};