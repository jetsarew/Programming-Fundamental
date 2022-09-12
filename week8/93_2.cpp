#include <iostream>
#include <vector>
#define st first
#define nd second
using namespace std;

int n;
int ans;
int dis[5100];
int num;
int it1, it2;
vector<vector<pair<int,int> > > adj(5100);
void dfs(int u, int w){
    //printf("vis %d dis = %d\n", u, w);
    for(int i = 0; i < adj[u].size(); i++){
        int w1 = adj[u][i].st;
        int v = adj[u][i].nd;
        if(w + w1 > dis[v]){
            dis[v] = w + w1;
            dfs(v, dis[v]);
        }
    }
    ans = max(ans, dis[u]);
}
int main(){

    cin >> n;

    cin >> num;
    adj[0].push_back({num, 1});

    for(int i = 2; i <= n; i++){
        it1 = ((i - 1) * (i - 2)) / 2 + 1;
        it2 = (i * (i - 1)) / 2 + 1;

        cin >> num;

        adj[it1].push_back({num, it2++});
        //printf("it1 = %d it2 = %d\n", it1, it2 - 1);

        for(int j = 1, num; j < i; j++){
            cin >> num;
            //printf("it1 = %d it2 = %d\n", it1, it2);

            adj[it1++].push_back({num, it2});

            if(j < i - 1){
                //printf("it1 = %d it2 = %d\n", it1, it2);
                adj[it1].push_back({num, it2++});
            }

        }
    }

    dfs(0, 0);

    cout << ans;

    return 0;
}
/*
4
3
7 4
2 4 6
9 5 8 3

*/

