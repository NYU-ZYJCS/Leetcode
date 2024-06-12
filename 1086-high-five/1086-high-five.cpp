class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        int k = 5;
        map<int, priority_queue<int, vector<int>, greater<int>>> allScores;
        
        for (auto item : items) {
            int id = item[0];
            int score = item[1];
            
            allScores[id].push(score);
            if (allScores[id].size() > k) {
                allScores[id].pop();
            }
        }
        
        vector<vector<int>> result;
        for (auto [id, top_scores] : allScores) {
            int total_score = 0;
            for (int i = 0; i < k; ++i) {
                total_score += top_scores.top();
                top_scores.pop();
            }
            result.push_back({ id, total_score / k });
        }
        return result;
    }
};