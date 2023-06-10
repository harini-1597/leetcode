// 6461 Check if The Number is Fascinating
// Biweekly Contest 106 10 June 23

class Solution {
public:
    bool isFascinating(int n) {
        int x=n; vector<int> num;
        while(x!=0){
            num.push_back(x%10);
            x=x/10;
        }
        int x2=2*n;
        int x3=3*n;
        if(x2%10==0 || x3%10==0){
            return false;
        }
        while(x2!=0){
            num.push_back(x2%10);
            x2=x2/10;
        }
        while(x3!=0){
            num.push_back(x3%10);
            x3=x3/10;
        }
        unordered_set<int> uset;
        for(int i=0; i<num.size(); i++){
            if(num[i]==0){
                return false;
            }
        }
        for(int i=0; i<num.size(); i++){
            if(uset.find(num[i])!=uset.end()){
                return false;
            }
            else{
                uset.insert(num[i]);
            }
        }
        return true;
    }
};
