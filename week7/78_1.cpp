#include <iostream>
#define N 100
using namespace std;
int arr[N + 5][N + 5];
int n;
int target;
bool check(){
    /*
    for(int i = 1; i <= n; i++){
        cout << arr[i][n] - arr[i - 1][n] << " " <<
        arr[n][i] - arr[n][i - 1] << "\n";
    }
    */
    for(int i = 1; i <= n; i++){
        if(arr[i][n] - arr[i - 1][n] != target) return false;
        if(arr[n][i] - arr[n][i - 1] != target) return false;
    }
    return true;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &arr[i][j]);
            arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        }
    }

    target = (n * (n * n + 1)) / 2;

    if(check()) printf("Yes");
    else printf("No");

    return 0;
}
