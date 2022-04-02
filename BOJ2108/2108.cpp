#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int *nums = new int[n];

    int sum, min, max;
    sum = 0;
    min = 4000;
    max = -4000;
    for (int i=0; i < n; i++)
    {
        cin >> nums[i];
        sum += nums[i];
        min = nums[i] < min ? nums[i] : min;
        max = nums[i] > max ? nums[i] : max;
    }

    sort(nums, nums + n);

    int count, maxcount, before, cur;
    bool first = true;
    count = 1;
    maxcount = 1;
    before = nums[0];
    cur = n > 1 ? nums[1] : nums[0];
    for (int i=1; i < n; i++)
    {
        if (nums[i] == before)
        {
            count++;
            if (count == maxcount && first)
            {
                first = !first;
                cur = nums[i];
            }
            else if (count > maxcount)
            {
                maxcount = count;
                cur = nums[i];
                first = true;
            }
        }
        else
            count = 1;
        before = nums[i];
    }
    
    cout << int(round(double(sum) / n)) << '\n';
    cout << nums[n / 2] << '\n';
    cout << cur << '\n';
    cout << max - min << '\n';
}