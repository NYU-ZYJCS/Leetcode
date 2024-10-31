class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        using ii = pair<int, int>;
        int target_in = times[targetFriend][0];
        ranges::sort(times);
        
        priority_queue<ii, vector<ii>, greater<ii>> leave;
        priority_queue<int, vector<int>, greater<int>> chair;
        
        for (int i = 0; i < times.size(); ++i) chair.push(i);

        for (auto& t : times) {
            while (!leave.empty() && t[0] >= leave.top().first) {
                chair.push(leave.top().second);
                leave.pop();
            }
            
            leave.push({t[1], chair.top()});
            
            if (target_in == t[0]) {
                return chair.top();
            }
            
            chair.pop();
        }
        
        return 0; 
    }
};