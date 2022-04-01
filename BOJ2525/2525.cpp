#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int hour, minute, time;
    cin >> hour >> minute >> time;
    
    int added = minute + time;
    cout << (hour + int(added / 60)) % 24 << ' ' 
        << added % 60 << '\n';
}