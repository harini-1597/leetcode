vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        vector<int> common;
        std::set_intersection(nums1.begin(), 				   nums1.end(),nums2.begin(), nums2.end(),
        std::back_inserter(common));
        return common;
    }
