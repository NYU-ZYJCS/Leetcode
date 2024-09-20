class RandomizedCollection {
public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        nums.push_back(val);
        mp[val].insert(nums.size() - 1);
        return mp[val].size() == 1;
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end()) return false;
        
        int lastVal = nums.back();
        int index_of_val = *mp[val].begin();
        
        nums[index_of_val] = lastVal;
        mp[val].erase(index_of_val);
        mp[lastVal].insert(index_of_val);
        mp[lastVal].erase(nums.size() - 1);
        nums.pop_back();
        
        if (mp[val].size() == 0) mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
    
private:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> mp;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */