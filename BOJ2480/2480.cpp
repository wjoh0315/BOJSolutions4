#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int dice[3];
    cin >> dice[0] >> dice[1] >> dice[2];

    int reward, max;
    max = dice[0] > dice[1] ? dice[0] : dice[1];
    max = max > dice[2] ? max : dice[2];
    if (dice[0] == dice[1] && dice[1] == dice[2] 
        && dice[0] == dice[2])
        reward = 10000 + dice[0] * 1000;
    else if (dice[0] == dice[1] || dice[0] == dice[2])
        reward = 1000 + dice[0] * 100;
    else if (dice[1] == dice[2])
        reward = 1000 + dice[1] * 100;
    else
        reward = max * 100;
    cout << reward << '\n';
}