class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        
        ranges::sort(idx, [&](const int& a, const int& b) {
            return arr[a] < arr[b];
        });
        
        int rank = 0, pre = INT_MIN;
        for (int i : idx) {
            if (arr[i] != pre) ++rank;
            pre = arr[i];
            arr[i] = rank;
        }
        
        return arr;
    }
};