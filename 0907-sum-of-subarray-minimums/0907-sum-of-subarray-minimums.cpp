class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> stk;
        long res = 0;

        for (int i = 0; i <= n; ++i) {
            int cur = (i == n) ? 0 : arr[i];

            // increasing monotonic stack
            while (!stk.empty() && cur <= arr[stk.top()]) {
                int midIndex = stk.top(); stk.pop();
                int preIndex = -1;
                if (!stk.empty()) preIndex = stk.top();
                res += (long)(arr[midIndex]) * (i - midIndex) * (midIndex - preIndex);
            }
            stk.push(i);
        }

        return res % 1000000007;
    }
};