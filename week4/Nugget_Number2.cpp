#include <iostream>
using namespace std;
bool mem[125];
bool vis[125];
int d[3] = {6, 9, 20};
bool solve(int num){
    //printf("visit %d\n",num);
    if(vis[num]){
        //printf("bangggg\n");
        return mem[num];
    }
    vis[num] = true;

    for(int i = 0; i < 3; i++){
        if(num - d[i] >= 6){
            if(solve(num - d[i])){
                mem[num] = true;
                break;
            }
        }
        else break;
    }
    return mem[num];
}
int main(){
    int n;

    cin >> n;

    if(n < 6){
        cout << "no";
        return 0;
    }

    mem[6] = true;
    vis[6] = true;
    mem[9] = true;
    vis[9] = true;
    mem[20] = true;
    vis[20] = true;
    for(int i = n; i >= 12; i--){
        if(!vis[i])
        {
            //printf("--------solve %d\n",i);
            solve(i);
        }
    }

    for(int i = 6; i <= n; i++){
        if(mem[i]) cout << i << "\n";
    }
    return 0;
}

