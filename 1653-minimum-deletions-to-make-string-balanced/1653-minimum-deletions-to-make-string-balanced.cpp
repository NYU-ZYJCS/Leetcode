class Solution {
public:
    int minimumDeletions(string s) {
        int countb = 0, counta = 0;
        for (auto c : s) counta += (c == 'a');
        
        int res = counta;
        for (auto c : s) {
            countb += (c == 'b');
            counta -= (c == 'a');
            res = min(res, counta + countb);
        }
        return res;
    }
};