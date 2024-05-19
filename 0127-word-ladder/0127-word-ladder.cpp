class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return 0;
        
        queue<string> q_start, q_end;
        unordered_set<string> dict_start, dict_end;
        
        q_start.push(beginWord);
        q_end.push(endWord);
        dict_start.insert(beginWord);
        dict_end.insert(endWord);
        dict.erase(endWord);
        
        int steps = 1;
        
        
        while (!q_start.empty() && !q_end.empty()) {
            if (q_start.size() > q_end.size()) {
                swap(q_start, q_end);
                swap(dict_start, dict_end);
            }
            
            int size = q_start.size();
            
            while (size--) {
                auto curWord = q_start.front();
                q_start.pop();

                // if (dict_end.find(curWord) != dict_end.end()) return steps + 1;
                
                for (int i = 0; i < curWord.size(); ++i) {
                    char old = curWord[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (old == c) continue;
                        curWord[i] = c;
                        if (dict_end.find(curWord) != dict_end.end()) return steps + 1;
                        if (dict.find(curWord) != dict.end()) {
                            q_start.push(curWord);
                            dict_start.insert(curWord);
                            dict.erase(curWord);
                        }
                    }
                    curWord[i] = old;
                }
            }
            ++steps;
        }
        
        return 0;
    }
};