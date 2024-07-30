class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        if(n < 3) return 0;
        int ans = 0;
        
        for (int j = 1; j < n - 1; ++j) {
            int smaller_cnt_l = 0;
            int bigger_cnt_l = 0;
            int smaller_cnt_r = 0;
            int bigger_cnt_r = 0;

            for (int i = 0; i < j; ++i) {
                if (rating[i] < rating[j]) {
                    smaller_cnt_l++;
                } else {
                    bigger_cnt_l++;
                }    
            }
            
            for (int k = j + 1; k < n; ++k) {
                if (rating[k] < rating[j]) {
                    smaller_cnt_r++;
                } else {
                    bigger_cnt_r++;
                }    
            }
            ans += smaller_cnt_l * bigger_cnt_r + bigger_cnt_l * smaller_cnt_r;
        }
        
        return ans;
    }
};