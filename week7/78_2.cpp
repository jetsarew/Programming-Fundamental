#include <iostream>
#define N 100
using namespace std;
int arr[N + 5][N + 5];
int row[N + 5];
int col[N + 5];
bool chk[(N + 5) * (N + 5)];
int tmp1, tmp2;
int n;
int target;
bool check(){

    for(int i = 1; i <= n * n; i++){
        if(!chk[i]) return false;
    }

    for(int i = 1; i <= n; i++){
        if(row[i] != target) return false;
        if(col[i] != target) return false;
    }
    if(tmp1 != target) return false;
    if(tmp2 != target) return false;

    return true;
}
void print(){
    for(int i = 1; i <= n; i++){
        printf("%d %d\n", row[i], col[i]);
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &arr[i][j]);
            chk[arr[i][j]] = true;
            row[i] += arr[i][j];
            col[j] += arr[i][j];
            if(i == j) tmp1 += arr[i][j];
            if(i + j == n + 1) tmp2 += arr[i][j];
        }
    }
    //print();
    target = (n * (n * n + 1)) / 2;

    if(check()) printf("Yes");
    else printf("No");
    //printf("\n %d %d",tmp1, tmp2);

    return 0;
}

