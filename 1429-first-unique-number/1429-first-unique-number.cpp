class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        idx = 0;
        for (int num : nums) {
            this->nums.push_back(num);
            freq[num]++;
        }
    }
    
    int showFirstUnique() {
        int n = nums.size();
        while (idx < n) {
            if (freq[nums[idx]] == 1) return nums[idx];
            else ++idx;
        }
        return -1;
    }
    
    void add(int value) {
        nums.push_back(value);
        freq[value]++;
    }
    
private:
    unordered_map<int, int> freq;
    vector<int> nums;
    int idx;
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */