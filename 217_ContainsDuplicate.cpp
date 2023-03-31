//-> brute & better sorting the array and checking if two adjacent are equal     or not 
// tc-> o(nlogn) {better than o(n^2) of bf}

bool containsDuplicate(vector<int>& nums) {
        int x=nums.size()-1;   // minus 1 way more important than you think
        sort(nums.begin(), nums.end());    //kinda important ; couldn't figure out
        for(int i=0; i<x; i++){
            if(nums[i]==nums[i+1])
                return true;
        }
        return false;
    }
