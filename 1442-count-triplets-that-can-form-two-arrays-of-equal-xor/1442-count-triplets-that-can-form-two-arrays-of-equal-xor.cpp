class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        vector<int> prefix(n + 1);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }
        
        // i..j-1  =>  prefix[]
        // j..k  =>  
        for (int i = 0; i < n; ++i) {
            for (int k = i + 1; k < n; ++k) {
                if (prefix[k + 1] == prefix[i]) {
                    res += k - i;
                }
            }
        }
        
        return res;
    }
};