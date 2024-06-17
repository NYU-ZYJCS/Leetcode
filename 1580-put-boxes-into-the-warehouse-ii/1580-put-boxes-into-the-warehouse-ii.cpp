class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int size = warehouse.size();
        vector<int> maxHeight(size, 0);
        
        // scan from the left
        int pre = warehouse[0];
        for (int i = 0; i < size; ++i) {
            pre = min(pre, warehouse[i]);
            maxHeight[i] = pre;
        }
        
        int back = warehouse[size - 1];
        for (int i = size - 1; i >= 0; --i) {
            back = min(back, warehouse[i]);
            maxHeight[i] = max(maxHeight[i], back);
        }
        
        ranges::sort(maxHeight);
        ranges::sort(boxes);
        
        int count = 0;
        int boxIndex = 0;
        for (int i = 0; i < size; ++i) {
            if (boxIndex < boxes.size() &&
                boxes[boxIndex] <= maxHeight[i]) {
                ++count;
                ++boxIndex;
            }
        }
        
        return count;
    }
};