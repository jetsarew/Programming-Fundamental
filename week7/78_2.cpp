#include <iostream>
#define N 100
using namespace std;
int arr[N + 5][N + 5];
int row[N + 5];
int col[N + 5];
int n;
int target;
bool check(){
    for(int i = 1; i <= n; i++){
        if(row[i] != target) return false;
        if(col[i] != target) return false;
    }
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
            row[i] += arr[i][j];
            col[j] += arr[i][j];
        }
    }
    //print();
    target = (n * (n * n + 1)) / 2;

    if(check()) printf("Yes");
    else printf("No");

    return 0;
}

