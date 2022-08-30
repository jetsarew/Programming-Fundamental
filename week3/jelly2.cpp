#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int a, b, c, ans;

    cin >> a >> b >> c;

    ans = floor(log10(a) / log10(2)) + floor(log10(b) / log10(2)) + floor(log10(c) / log10(2));

    cout << ans;

    return 0;
}


