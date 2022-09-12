#include <iostream>
using namespace std;

int n;
int ans;
int arr[105];
int l, r;
int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){

        l = arr[0];

        for(int j = 1, num; j <= i; j++){

            r = arr[j];
            cin >> num;
            arr[j] = num + max(l, r);
            l = r;
        }
    }

    for(int i = 1; i <= n; i++){
        ans = max(ans, arr[i]);
    }

    cout << ans;

    return 0;
}
/*
4
3
7 4
2 4 6
9 5 8 3

*/
