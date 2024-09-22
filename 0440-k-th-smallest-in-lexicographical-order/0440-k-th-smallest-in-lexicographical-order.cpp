class Solution {
public:
    typedef long long ll;
    
    ll get_count(ll prefix, ll n) {
        ll start = prefix, end = prefix + 1;
        ll count = 0;
        
        while (start <= n) {
            count += min(n + 1, end) - start;
            start *= 10, end *= 10;
        }
        
        return count;
    }
    
    
    int findKthNumber(int n, int k) {
        ll prefix = 1, pos = 1;
        while (pos < k) {
            ll count = get_count(prefix, n);
            
            if (pos + count > k) {
                prefix *= 10;
                ++pos;
            } else {
                prefix++;
                pos += count;
            }
        }
        return prefix;
    }
    
    
};