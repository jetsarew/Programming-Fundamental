#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;

    cin >> n;

    int y = (n - 1) / 2;
    int x = (n - 1) / 2;

    for(int i = y; i >= -y; i--)
    {
        for(int j = -x; j <= x; j++)
        {
            if(abs(i) + abs(j) == x)
                cout << '*';
            else cout << '-';
        }
        cout << "\n";

        if(i == 0 && n % 2 == 0)
        {
            cout << '*';

            for(int j = -x + 1; j < x; j++)
                cout << '-';

            if(n > 2)
            cout << '*';

            cout << "\n";
        }
    }
    return 0;
}
