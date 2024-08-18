class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(n);
        res[0] = 1;
        int idx2 = 0, idx3 = 0, idx5 = 0;
        for (int i = 1; i < n; ++i) {
            res[i] = min(res[idx2] * 2, min(res[idx3] * 3, res[idx5] * 5));
            if (res[i] == res[idx2] * 2) idx2++;
            if (res[i] == res[idx3] * 3) idx3++;
            if (res[i] == res[idx5] * 5) idx5++;
        }
        return res[n - 1];
    }
};