vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec;
        int x = nums.size();
        int y;
        unordered_map<int,int> seen;
        for(int i=0; i<x; i++){
            y = target-nums[i];
            if(seen.count(y)){
                vec.push_back(i);
                vec.push_back(seen.at(y));
            }
            else{
                seen[nums[i]]=i;
            }
        }
        return vec;
    }

