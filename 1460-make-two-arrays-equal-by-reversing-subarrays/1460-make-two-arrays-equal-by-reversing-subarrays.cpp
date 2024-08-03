class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> v(1001, 0);
        for(int i = 0; i < target.size(); i++) {
            v[target[i]]++;
            v[arr[i]]--;
        }
        for(int i = 1; i <= 1000; i++) {
            if(v[i] != 0)
                return false;
        }
        return true;
    }
};