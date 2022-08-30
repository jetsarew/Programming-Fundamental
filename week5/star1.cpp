#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n, st1, st2;
    int row, col;

    cin >> n;

    char arr[n + 5][n + 5];

    st1 = (n + 1) / 2;
    st2 = st1 + (n % 2 == 0);
    row = n;
    col = n - (n % 2 == 0);

    for(int i = 1; i <= row; i++)
    {
        for(int j = 1; j <= col; j++)
        {
            arr[i][j] = '-';
        }
    }

    for(int i = 1; st1 > 0 ; i++)
    {
        arr[st1][i] = '*';
        arr[st1][col - i + 1] = '*';
        arr[st2][i] = '*';
        arr[st2][col - i + 1] = '*';
        st1--;
        st2++;
    }

    for(int i = 1; i <= row; i++)
    {
        for(int j = 1; j <= col; j++)
        {
            cout << arr[i][j];
        }
        cout << "\n";
    }

    return 0;
}
