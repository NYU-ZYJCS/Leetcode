const int MX = 1010;
vector<int> primes{0};

void get_primes() {
    vector<bool> is_prime(MX, true);
    
    for (int i = 2; i < MX; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i; j <= MX; j += i) {
                is_prime[j] = false;
            }
        }
    }
}


class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        get_primes();
        int pre = 0;
        for (auto x : nums) {
            if (x <= pre) return false;
            pre = x - *--lower_bound(primes.begin(), primes.end(), x - pre);
        }
        
        return true;
    }
};