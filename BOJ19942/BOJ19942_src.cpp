//https://www.acmicpc.net/problem/19942
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> info;
int mins[4];

void check(int cur[5], int& mincost, vector<int>& temp, vector<int>& arr)
{
    for (int i=0; i < 4; i++)
        if (cur[i] < mins[i]) return;
    if (cur[4] < mincost)
    {
        mincost = cur[4];
        arr = temp;
    }
}

void solve(int index, int sum[5], vector<int>& temp, int& mincost, vector<int>& arr)
{
    if (index >= info.size())
        return;

    check(sum, mincost, temp, arr);
    solve(index+1, sum, temp, mincost, arr);

    int newsum[5];
    for (int i=0; i < 5; i++)
        newsum[i] = sum[i] + info[index][i];
    temp.push_back(index);
    check(newsum, mincost, temp, arr);
    solve(index+1, newsum, temp, mincost, arr);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i=0; i < 4; i++)
        cin >> mins[i];

    int in;
    for (int i=0; i < n; i++)
    {
        info.push_back(vector<int>());
        for (int j=0; j < 5; j++)
        {
            cin >> in;
            info[i].push_back(in);
        }
    }

    int mincost = numeric_limits<int>::max();
    vector<int> arr;
    vector<int> temp;
    solve(0, { 0, }, temp, mincost, arr);

    sort(arr.begin(), arr.end());
    cout << mincost << '\n';
    for (int i=0; i < arr.size(); i++)
        cout << arr[i] + 1 << ' ';
    cout << '\n';

    return 0;
}