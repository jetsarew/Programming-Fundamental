#include <iostream>
#include <string>
#include <vector>
#define Max_n 1005
#define st first
#define nd second

using namespace std;

int mem[Max_n];
bool vis[Max_n];
int n, start;
string path[Max_n];
vector<vector<pair<int,int> > > adj(Max_n);
string tmp_str;

void print(){
    for(auto n : tmp_str){
        cout << n << " ";
    }
    cout << "\n";
}

string toString(int num){

    //printf("convert %d to ",num);
    string str = "";
    string tmp_str = " ";

    do{
        int tmp_num = num % 10;
        num /= 10;
        tmp_str[0] = tmp_num + '0';
        str = tmp_str + str;
    }while(num > 0);

    //cout << str << "\n";
    return str;
}

void popBack(int num){
    do{
        num /= 10;
        tmp_str.pop_back();
    }while(num > 0);
    tmp_str.pop_back();
    tmp_str.pop_back();
}

void dfs(int u, int w){

    if(mem[u] != w) return ;
    //printf("visited %d dis = %d path = ", u, w);
    path[u] = tmp_str;
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i].first;
        int w1 = adj[u][i].nd;
        if((mem[v] == 0 || w + w1 < mem[v]) && !vis[v]){
            mem[v] = w + w1;
            tmp_str += "-<" + toString(u);
            vis[v] = true;
            dfs(v, w + w1);
            vis[v] = false;
            popBack(v);
        }
    }
}

int main(){
   printf("Enter no. of vertices:");
    scanf("%d", &n);


    //vector<vector<int> > path(n + 5);
    printf("\nEnter the adjacency matrix:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0, dis; j < n; j++){
            scanf("%d", &dis);
            if(dis > 0)
            adj[i].push_back({j, dis});
        }
    }

    printf("\nEnter the starting node:\n");
    scanf("%d", &start);
    tmp_str.push_back(start);
    vis[start] = true;
    dfs(start, 0);
    for(int i = 0; i < n; i++){
        if(i != start){
            cout << "\nDistance of node" << i << "=" << mem[i];
            cout << "\nPath=" << i << "<-";
            for(int j = path[i].length() - 1; j > 2; j--){
                cout << path[i][j];
            }
        }
    }
    return 0;
}
