class Solution {
public:
    long long minEnd(int n, int x) {
        n--;
        long long res = x;
        int i = 0;
        
        while (n) {
            if ((res >> i & 1) == 0) {
                res |= (long long) (n & 1) << i;
                n >>= 1;
            }
            
            ++i;
        }
        
        return res;
    }
};