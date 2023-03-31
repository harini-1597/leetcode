vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> umap;
        vector<int> res;
        int i;
        for(i=0; i<nums1.size(); i++)
            umap[nums1[i]]++;
        for(i=0; i<nums2.size(); i++){
            if(umap.count(nums2[i])){
                if(umap.at(nums2[i])>0){
                    res.push_back(nums2[i]);
                    umap[nums2[i]]--;
                }
            }
        }
        return res;
    }
