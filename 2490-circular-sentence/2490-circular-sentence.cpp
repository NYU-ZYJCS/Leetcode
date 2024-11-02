class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> parts = split(sentence);
        
        if (parts.size() == 1) return parts[0][0] == parts[0].back();
        
        for (int i = 1; i < parts.size(); ++i) {
            if (parts[i][0] != parts[i - 1].back()) return false;
        }
        
        return parts.back().back() == parts[0][0];
    }

    vector<string> split(string sentence) {
        stringstream ss(sentence);
        string part;
        
        vector<string> parts;
        
        while (getline(ss, part, ' ')) {
            parts.push_back(part);
        }
        
        return parts;
    }
};