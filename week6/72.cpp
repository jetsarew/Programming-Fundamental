#include <iostream>
#include <vector>
#include <queue>
#include <string>

#define st first
#define nd second

using namespace std;
struct box{
    int cur_node;
    int dis;
    string tmp;
    bool operator<(const box &a) const{
        return a.dis < dis;
    }
};
int n;
int start;
int cnt;

priority_queue<box> pq;

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
int main(){

    printf("Enter no. of vertices:");
    scanf("%d", &n);

    int mem[n + 5] = {};
    bool vis[n + 5] = {};
    vector<vector<pair<int,int> > > adj(n + 5);
    //vector<vector<int> > path(n + 5);
    string path[n + 5] = {};
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

    pq.push({start, 0, ""});
    //vis[st] = true;

    while(!pq.empty()){
        int cn = pq.top().cur_node;
        int dd = pq.top().dis;
        string tt = pq.top().tmp;
        pq.pop();

        //printf("1 -> visited node %d dis = %d\n", cn, dd);
        if(mem[cn] != dd){
           continue;
        }
        if(vis[cn]) continue;
        vis[cn] = true;
        cnt++;
        path[cn] = tt + "-<" + toString(cn);

        if(cnt >= n){
            break;
        }





        //printf("2 -> visited node %d dis = %d\n", cn, dd);
        for(int i = 0; i < adj[cn].size(); i++){
            int n1 = adj[cn][i].st;
            int d1 = adj[cn][i].nd;

            if((mem[n1] == 0 || dd + d1 < mem[n1]) && !vis[n1] && n1 != start){

                mem[n1] = dd + d1;

                //printf("go to node %d dis = %d\n",n1,mem[n1]);
                pq.push({n1, mem[n1], path[cn]});
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(i != start){
            cout << "\nDistance of node" << i << "=" << mem[i] << "\n";
            cout << "Path=";
            for(int j = path[i].length() - 1; j > 1; j--){
                cout << path[i][j];
            }
        }

    }
}
/*

5
0 10 0 30 100
10 0 50 0 0
0 50 0 20 10
30 0 20 0 60
100 0 10 60 0
0

*/
