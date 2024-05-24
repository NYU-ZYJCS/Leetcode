class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        for (auto c : letters) remains[c - 'a']++;
        
        for (auto it = words.begin(); it != words.end(); ) {
            if (!check(*it, score)) it = words.erase(it);
            else ++it;
        }

        int n = words.size();
        function<void(int, int)> helper = [&] (int pos, int sum) {
            result = max(result, sum);
            if (pos == n) return;
            
            for (int i = pos; i < n; ++i) {
                int contribution = check(words[i], score);
                for (char c : words[i]) remains[c - 'a']--;
                if (contribution) {
                    helper(i + 1, sum + contribution);
                }
                for (char c : words[i]) remains[c - 'a']++;
            }
        };
        
        helper(0, 0);
        return result;
    }
    
    
    
    int check(string word, vector<int>& score) {
        int freq[26] {0};
        int sum = 0;
        for (char c : word) {
            sum += score[c - 'a'];
            freq[c - 'a']++;
        }
        
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > remains[i]) return 0;
        }
        return sum;
    }
        
private:
    int remains[26] {0};
    int result = 0;
};