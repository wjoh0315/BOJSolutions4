//https://www.acmicpc.net/problem/1006
#include <bits/stdc++.h>
using namespace std;

/*
dp[x][0]: 1층만 연결
dp[x][1]: 2층만 연결
dp[x][2]: 1, 2층 모두 연결
dp[x][3]: 1, 2층 모두 연결 X
dp[x][4]: x번째 dp의 최소 개수

dp[x][0] = min(dp[x-1][1], dp[x-1][3]) + 1
dp[x][1] = min(dp[x-1][0], dp[x-1][3]) + 1
dp[x][2] = min(dp[x-1][3], dp[x-1][4] + 1)
dp[x][3] = dp[x-1][4] + 2
dp[x][4] = min(dp[x][0], dp[x][1], dp[x][2], dp[x][3])
*/
int solve(int N, int W, 
const vector<int> area1, const vector<int> area2, vector<vector<int>> &dp)
{
    dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = dp[0][4] = 2;
    if (area1[0] + area2[0] <= W)
        dp[0][2] = dp[0][4] = 1;

    for(int i=1; i < 3*N; i++)
    {
        // 1층 연결 가능 여부
        bool isAble1 = area1[i%N] + area1[(i-1)%N] <= W;
        // 2층 연결 가능 여부
        bool isAble2 = area2[i%N] + area2[(i-1)%N] <= W;
        // 1층-2층 서로 연결 가능 여부
        bool eachAble = area1[i%N] + area2[i%N] <= W;

        dp[i][0] = dp[i][1] = dp[i][2] = dp[i][3] = dp[i-1][4] + 2;

        if (isAble1)
            dp[i][0] = min(dp[i][0], min(dp[i-1][1], dp[i-1][3]) + 1);

        if (isAble2)
            dp[i][1] = min(dp[i][1], min(dp[i-1][0], dp[i-1][3]) + 1);

        if (isAble1 && isAble2)
            dp[i][2] = min(dp[i][2], dp[i-1][3]);
        if (eachAble)
            dp[i][2] = min(dp[i][2], dp[i-1][4] + 1);

        dp[i][4] = min(min(dp[i][0], dp[i][1]), min(dp[i][2], dp[i][3]));
    }
    return dp[3*N-1][4] - dp[2*N-1][4];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int i=0; i < T; i++)
    {
        int N, W;
        cin >> N >> W;

        // 1층 (안쪽 원)
        vector<int> area1(N);
        // 2층 (바깥쪽 원)
        vector<int> area2(N);
        for (int j=0; j < N; j++)
            cin >> area1[j];
        for (int j=0; j < N; j++)
            cin >> area2[j];

        vector<vector<int>> dp(3*N, vector<int>(5, 0));
        std::cout << solve(N, W, area1, area2, dp) << '\n';
    }

    return 0;
}