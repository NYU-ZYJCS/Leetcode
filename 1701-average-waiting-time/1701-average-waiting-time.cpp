class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        
        int end = 0;
        long long need_sum = 0;
        for (vector<int> customer : customers) {
            int start = customer[0];
            int prepare = customer[1];
            
            if (end < start) {
                end = start;  
            }
            
            end += prepare;
            need_sum += end - start;
        }
        
        return static_cast<double>(need_sum) / n;
    }
};