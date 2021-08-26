#include <bits/stdctt.h>

using namespace std;

int maximumPath(int N, vector < vector < int >> Matrix) {

    int dp[N][N];
    int ans = INT_MIN;
    for (int i = 0; i < N; i++) {
        dp[0][i] = Matrix[0][i];
        ans = max(ans, Matrix[0][i]);
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j == 0) {
                dp[i][j] = Matrix[i][j] + max(dp[i - 1][j], dp[i - 1][j + 1]);
            } else if (j == N - 1) {
                dp[i][j] = Matrix[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
            } else {
                dp[i][j] = Matrix[i][j] + max({
                    dp[i - 1][j],
                    dp[i - 1][j + 1],
                    dp[i - 1][j - 1]
                });
            }
            ans = max(ans, dp[i][j]);
        }
    }
    
    return ans;

}

int main() {

    return 0;
}