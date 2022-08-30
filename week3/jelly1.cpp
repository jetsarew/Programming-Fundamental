#include <iostream>
using namespace std;
int main()
{
    int arr[3], ans = 0;

    cin >> arr[0] >> arr[1] >> arr[2];

    for(int i = 0; i < 3; i++)
    {
        while(arr[i] > 1)
        {
            arr[i]/=2;
            ans++;
        }
    }

    cout << ans;

    return 0;
}

