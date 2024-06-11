class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> freq;
        for (auto num : arr1) freq[num]++;
        
        int idx = 0;
        int num;
        for (int i = 0; i < arr2.size(); ++i) {
            num = arr2[i];
            while (freq[num] > 0) {
                arr1[idx++] = num;
                freq[num]--;
            }
        }
        
        for (auto &[num, f] : freq) {
            while (f > 0) {
                arr1[idx++] = num;
                freq[num]--;
            }
        }
        
        return arr1;
    }
};