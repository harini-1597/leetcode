class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(n!=m) return false;
        unordered_multiset<char> uset;
        for(int i=0; i<n; i++){
            uset.insert(s[i]);
        }
        for(int i=0; i<m; i++){
            if(uset.find(t[i])!=uset.end()){
                auto it=uset.find(t[i]);
                uset.erase(it);
            }
            else{
                return false;
            }
        }
        return true;
    }
};
