#include <iostream>
#define N 100
using namespace std;
int arr[N + 5][N + 5];
bool chk[(N + 5) * (N + 5)];
int tmp1 = 0, tmp2 = 0;
int n;
int target;
bool check(){
    for(int i = 1; i <= n * n; i++){
        if(!chk[i]) return false;
    }

    for(int i = 1; i <= n; i++){
        if(arr[i][n] - arr[i - 1][n] != target) return false;
        if(arr[n][i] - arr[n][i - 1] != target) return false;
    }

    if(tmp1 != target) return false;
    if(tmp2 != target) return false;
    return true;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &arr[i][j]);
            chk[arr[i][j]] = true;
            if(i == j) tmp1 += arr[i][j];
            if(i + j == n + 1) tmp2 += arr[i][j];
            arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        }

    }

    target = (n * (n * n + 1)) / 2;

    if(check()) printf("Yes");
    else printf("No");

    //printf("\n%d %d",tmp1, tmp2);

    return 0;
}
