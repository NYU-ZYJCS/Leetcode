class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        istringstream ss(sentence);
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        
        string word;
        string result;
        bool isfind = false;
        while (getline(ss, word, ' ')) {
            for (int i = 1; i <= word.size(); ++i) {
                string root = word.substr(0, i);
                if (dict.count(root)) {
                    isfind = true;
                    result += root + " ";
                    break;
                }
            }
            if (!isfind) result += word + " ";        
            isfind = false;
        }
        
        result.pop_back();
        return result;
    }
};