//https://www.acmicpc.net/problem/17611
#include <bits/stdc++.h>
using namespace std;

int xpart[1000002];
int ypart[1000002];
int maxpart = 0;

vector<pair<int, int>> v;

int toin(int x)
{
    return x + 500000;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, y, px, py;
    cin >> n;

    memset(xpart, 0, sizeof(xpart));
    memset(ypart, 0, sizeof(ypart));

    for (int i=0; i < n; i++)
    {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    for (int i=0; i < n; i++)
    {
        pair<int, int> cur = v[i];
        pair<int, int> nxt = v[(i+1)%n];

        if (cur.first == nxt.first)
        {
            ypart[toin(min(cur.second, nxt.second))]++;
            ypart[toin(max(cur.second, nxt.second))]--;
        }
        else
        {
            xpart[toin(min(cur.first, nxt.first))]++;
            xpart[toin(max(cur.first, nxt.first))]--;
        }
    }
    for (int i=1; i < 1000002; i++)
    {
        xpart[i] += xpart[i-1];
        ypart[i] += ypart[i-1];
    }
    maxpart = max(*max_element(xpart, xpart + 1000002), *max_element(ypart, ypart + 1000002));
    cout << maxpart << '\n';
    return 0;
}