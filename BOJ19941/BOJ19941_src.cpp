//https://www.acmicpc.net/problem/19941
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    string pos;
    cin >> pos;

    int j = 0;
    int cnt = 0;
    for (int i=0; i < n; i++)
    {
        if (pos[i] == 'H') continue;
        for (j=max(j, i-k); j < min(n, i+k+1); j++)
        {
            if (pos[j] == 'P') continue;
            j++;
            cnt++;
            break;
        }
    }
    cout << cnt << '\n';
    return 0;
}