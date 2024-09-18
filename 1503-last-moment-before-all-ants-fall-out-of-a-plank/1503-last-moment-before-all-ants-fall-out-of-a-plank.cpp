class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int lastMoment = 0;
        for (auto num : left) lastMoment = max(lastMoment, num);
        for (auto num : right) lastMoment = max(lastMoment, n - num);

        return lastMoment;
    }
};