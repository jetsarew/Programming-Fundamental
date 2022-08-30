#include <iostream>
using namespace std;
int w, h, n;
int main(){
    cin >> w >> h >> n;

    int arr[w + 5] = {};
    int ans100 = 0, ans50 = 0;

    for(int i = 1, a, x; i <= n; i++){
        cin >> x >> a;
        arr[x + 1]++;
        if(x + a < w)
        arr[x + a + 1]--;
    }

    for(int i = 1; i <= w; i++){
        arr[i] += arr[i-1];
        if(arr[i] == 0) ans100++;
        else if(arr[i] == 1) ans50++;
    }

    cout << ans100 * h << " " << ans50 * h;
    return 0;
}

