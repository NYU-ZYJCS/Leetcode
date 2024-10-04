class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        int totalSkill = 0;
        unordered_map<int, int> skillMap;
        
        for (auto s : skill) {
            totalSkill += s;
            skillMap[s]++;
        }
        
        if (totalSkill % (n / 2) != 0) return -1;
        
        int targetSkill = totalSkill / (n / 2);
        long long result = 0;
        
        for (auto& [curSkill, curFreq] : skillMap) {
            int partnerSkill = targetSkill - curSkill;
            if (!skillMap.contains(partnerSkill) 
                || curFreq != skillMap[partnerSkill]) 
                return -1;
            
            result += (long long) curSkill * (long long) partnerSkill * curFreq;
        }
        return result / 2;
    }
};