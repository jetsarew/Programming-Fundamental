#include <iostream>
using namespace std;
bool mem[125];
int d[3] = {6, 9, 20};
int main(){
    int n;

    cin >> n;

    if(n < 6){
        cout << "no";
        return 0;
    }

    mem[6] = true;
    mem[9] = true;
    mem[20] = true;

    for(int i = 6; i <= n; i++){
        if(mem[i]){
            cout << i << "\n";
            for(int j = 0; j < 3; j ++){
                mem[i + d[j]] = true;
            }
        }
    }
    return 0;
}
