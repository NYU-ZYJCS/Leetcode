class Solution {
public:
    string kthLuckyNumber(int k) {
        k = k + 1;
        
        string result;
        
        while (k > 1) {
            result.insert(0, ((k & 1) ? "7" : "4"));
            k >>= 1;
        }
        
        return result;
    }
};