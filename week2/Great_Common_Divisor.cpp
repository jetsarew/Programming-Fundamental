#include <iostream>
using namespace std;
int main(){
    int a, b;
    cin >> a >> b;
    if(b < a)
    {
        a += b;
        b = a - b;
        a = a - b;
    }
    for(int i = a; i >= 1; i--){
        if(a % i || b % i) continue;
        cout << i;
        break;
    }
    return 0;
}
