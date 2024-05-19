class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return 0;
        
        queue<string> q;
        q.push(beginWord);
        int steps = 1;
        
        while (!q.empty()) {
            int size = q.size();
            
            while (size--) {
                auto curWord = q.front();
                q.pop();

                if (curWord == endWord) return steps;
                
                for (int i = 0; i < curWord.size(); ++i) {
                    char old = curWord[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (old == c) continue;
                        curWord[i] = c;
                        if (dict.find(curWord) != dict.end()) {
                            q.push(curWord);
                            dict.erase(curWord);
                        }
                        curWord[i] = old;
                    }
                }
            }
            ++steps;
        }
        
        return 0;
    }
};