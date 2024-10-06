class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res(k, 0);
        int m = nums1.size(), n = nums2.size();
        
        // s length from s1, k - s length from s2
        for (int s = max(0, k - n); s <= min(k, m); ++s) {
            vector<int> temp;
            
            vector<int> temp1 = maxKsequence(nums1, s);
            vector<int> temp2 = maxKsequence(nums2, k - s);
            
            auto iter1 = temp1.begin(), iter2 = temp2.begin();
            while (iter1 != temp1.end() || iter2 != temp2.end()) {
                temp.push_back(lexicographical_compare(iter1, temp1.end(), iter2, temp2.end()) ? *iter2++ : *iter1++);
            }
            res = lexicographical_compare(res.begin(), res.end(), temp.begin(), temp.end()) ? temp : res;
        }
        
        return res;
    }
    
    vector<int> maxKsequence(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= k) return nums;
        
        vector<int> res;
        int pop = n - k;
        for (auto num : nums) {
            // decreasing
            while (pop && res.size() > 0 && num > res.back()) {
                res.pop_back();
                --pop;
            }
            res.push_back(num);
        }
        
        res.resize(k);
        return res;
    }
};