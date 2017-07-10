#include <bits/stdc++.h>

using namespace std;

// ini problem unbounded knapsack

int unboundedKnapsack(int W, int wt[], int val[], int n)
{
    int dp[W + 1];
    memset(dp, 0, sizeof(dp));
    int ans = 0;

    for (int i = 0; i <= W; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (wt[j] <= i)
            {
                dp[i] = max(dp[i], dp[i - wt[j]] + val[j]);
            }
        }
    }

    return dp[W];
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    int wt[N], val[N];
    for (int i = 0; i < N; i++)
        scanf("%d %d", &wt[i], &val[i]);
    printf("%d\n", unboundedKnapsack(M, wt, val, N));
    return 0;
}
