class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        ranges::sort(intervals);
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (auto i : intervals) {
            if (!pq.empty() && i[0] > pq.top()) pq.pop();
            pq.push(i[1]);
        }
        
        return pq.size();
    }
};