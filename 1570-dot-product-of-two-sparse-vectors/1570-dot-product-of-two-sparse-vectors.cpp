class SparseVector {
public:
    
    SparseVector(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i]) {
                sparseVec.push_back({i, nums[i]});
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int i = 0, j = 0;
        int result = 0;
        while (i < sparseVec.size() && j < vec.sparseVec.size()) {
            if (sparseVec[i].first < vec.sparseVec[j].first) ++i;
            else if (sparseVec[i].first > vec.sparseVec[j].first) ++j;
            else {
                result += sparseVec[i].second * vec.sparseVec[j].second;
                ++i, ++j;
            }
        }
        return result;
    }
    
private:
    vector<pair<int, int>> sparseVec;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);