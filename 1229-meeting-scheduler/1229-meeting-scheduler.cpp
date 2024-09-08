class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        int index1 = 0, index2 = 0;
        ranges::sort(slots1);
        ranges::sort(slots2);
        
        while (index1 < slots1.size() && index2 < slots2.size()) {
            int max_start = max(slots1[index1][0], slots2[index2][0]);
            int min_end = min(slots1[index1][1], slots2[index2][1]);
            bool intersection = max_start <= min_end;
            int range = min_end - max_start;
            
            if (intersection && range >= duration) {
                return {max_start, max_start + duration};
            } else {
                if (slots1[index1][1] > slots2[index2][1]) index2++;
                else index1++;
            }
        }
        
        return {};
    }
};