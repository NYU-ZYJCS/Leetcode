class Solution {
public:
    int findTheWinner(int n, int k) {
        return winnerHelper(n, k) + 1;
    }
    
    int winnerHelper(int n, int k) {
        if (n == 1) return 0;
        return (winnerHelper(n - 1, k) + k) % n;
    }
};