//https://www.acmicpc.net/problem/17610
#include <bits/stdc++.h>
using namespace std;

void check(bool *arr, int num, int& cur)
{
    if (num <= 0)
        return;
    if (!arr[num])
    {
        arr[num] = true;
        cur++;
    }
}

void solve(bool *nums, int *chu, int k, int sum, int index, int& re)
{
    if (index == k)
        return;
    
    int ret = sum;
    ret += chu[index];
    check(nums, abs(ret), re);
    solve(nums, chu, k, ret, index+1, re);
    
    ret = sum;
    ret -= chu[index];
    check(nums, abs(ret), re);
    solve(nums, chu, k, ret, index+1, re);

    ret = sum;
    check(nums, abs(ret), re);
    solve(nums, chu, k, ret, index+1, re);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, s;
    cin >> k;
    s = 0;
    int *chu = new int[k];
    for (int i=0; i < k; i++)
    {
        cin >> chu[i];
        s += chu[i];
    }

    bool *nums = new bool[s+1];
    memset(nums, false, sizeof(nums));
    int count = 0;
    solve(nums, chu, k, 0, 0, count);
    cout << s - count << '\n';
    return 0;
}