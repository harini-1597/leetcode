class Solution {
public:
    int binarySearch(vector<int>&arr, int l, int r, int target){
        if(l==r && arr[l]==target)
            return l;
        if(l<r){
            int mid=l+(r-l)/2;
            if(arr[mid]==target)
                return mid;
            if(arr[mid]<target)
                return binarySearch(arr,mid+1,r,target);
            if(arr[mid]>target)
                return binarySearch(arr,l,mid,target);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return binarySearch(nums,0,nums.size()-1,target);
    }
};
