class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans; multiset<int> set; int i1=0, i2=0;
        for(i1=0 ;i1<k; i1++)
            set.insert(nums[i1]);
        ans.push_back(*set.rbegin());
        for(i1=k; i1<nums.size(); i1++){
            set.erase(set.find(nums[i2++]));
            set.insert(nums[i1]);
            ans.push_back(*set.rbegin());
        }
        return ans;
    }
};
