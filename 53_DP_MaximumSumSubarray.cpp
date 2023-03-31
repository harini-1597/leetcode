
// -> O(N^2) kinda optimized reduced to two loops ; still tle

int maxSubArray(vector<int>& nums) {
        int x=nums.size();
        int maxSum=INT_MIN;
        if(x==1){return nums[0];}
        for(int i=0; i<x; i++){
            int currentSum=0;
            for(int j=i; j<x; j++){
                currentSum+=nums[j];
                if(currentSum > maxSum){
                    maxSum = currentSum;
                }
            }
        }
        return maxSum;
    }


// -> O(N) - kadane’s algorithm - dp

int maxSubArray(vector<int>& nums) {
        int x=nums.size();
        int maxSum=INT_MIN;
        int currentSum=0;
        for(int i=0; i<x; i++){
            currentSum += nums[i];
            if(currentSum > maxSum)
                maxSum=currentSum;
            if(currentSum < 0)
                currentSum = 0;
        }
        return maxSum;
    }
