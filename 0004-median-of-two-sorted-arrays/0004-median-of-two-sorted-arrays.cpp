class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int size = m + n;
        // size is an odd number
        if (size & 1) {
            return findKth(nums1, nums2, size / 2 + 1);
        } else {
            return 0.5 * findKth(nums1, nums2, size / 2) +
                    0.5 * findKth(nums1, nums2, size / 2 + 1);
        }
    }
    
    int findKth(vector<int> &nums1, vector<int> &nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        int begin1 = 0, begin2 = 0;
        
        // k / 2 - 1
        // k / 2 - 1
        while (true) {
            if (begin1 == m) return nums2[begin2 + k - 1];
            if (begin2 == n) return nums1[begin1 + k - 1];
            if (k == 1) return min(nums1[begin1], nums2[begin2]);
            
            int end1 = min(begin1 + k / 2 - 1, m - 1);
            int end2 = min(begin2 + k / 2 - 1, n - 1);
            
            if (nums1[end1] <= nums2[end2]) {
                k -= end1 - begin1 + 1;
                begin1 = end1 + 1;
            } else {
                k -= end2 - begin2 + 1;
                begin2 = end2 + 1;
            }
        }
        
    }
};