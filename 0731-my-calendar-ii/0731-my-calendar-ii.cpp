class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        int res = 0;
        int maxBook = 0;
        cnt[start]++, cnt[end]--;
        
        for (auto &[_, freq] : cnt) {
            maxBook += freq;
            res = max(maxBook, res);
            
            if (maxBook > 2) {
                cnt[start]--;
                cnt[end]++;
                return false;
            }
        }
        
        return true;
    }
    
private:
    map<int, int> cnt;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */