class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // 1 0 0 
        if (n == 0) return true;
        for (int i = 0; i < flowerbed.size(); ++i) {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) 
                && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;
                if (--n == 0) break;
            }
        }
        return n == 0;
    }
};