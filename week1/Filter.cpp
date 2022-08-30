#include <iostream>
using namespace std;
int w, h, n;
int main(){
    cin >> w >> h >> n;

    int arr[w + 5] = {};
    int ans100 = 0, ans50 = 0;

    for(int i = 1, a, x; i <= n; i++){
        cin >> x >> a;
        int j = 0;
        while(j < a && x + j < w){
           arr[x + j++] += 1;
        }
    }

    for(int i = 0; i < w; i++){
        if(arr[i] == 1) ans50++;
        else if(arr[i] == 0) ans100++;
    }

    cout << ans100 * h << " " << ans50 * h;
    return 0;
}
