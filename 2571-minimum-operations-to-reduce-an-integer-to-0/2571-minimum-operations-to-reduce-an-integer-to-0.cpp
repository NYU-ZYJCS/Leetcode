class Solution {
public:
    int minOperations(int n) {
        int res = 0, count1 = 0;
        
        while (n) {
            if (n & 1) count1++;
            else {
                if (count1 == 1) ++res, count1 = 0;
                else if (count1 > 1) ++res, count1 = 1;
            }
            
            n >>= 1;
        }
        
        if (count1 == 1) ++res;
        else if (count1 > 1) res += 2;
        
        return res;
    }
};