class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int j = arr.size() - 1;
        while (j > 0 && arr[j - 1] <= arr[j]) --j;
        
        if (j == 0) return 0;
        
        int res = j;
        for (int i = 0; i == 0 || arr[i - 1] <= arr[i]; ++i) {
            while (j < arr.size() && arr[i] > arr[j]) ++j;
            res = min(res, j - i - 1);
        }
        
        return res;
    }
};