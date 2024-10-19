class Solution {
public:
    char findKthBit(int n, int k) {
        if (k == 1) return '0';
        
        int mid = 1 << (n - 1);
        if (k == mid) return '1';
        if (k < mid) return findKthBit(n - 1, k);
        
        return findKthBit(n - 1, 2 * mid - k) == '0' ? '1' : '0';
    }
};