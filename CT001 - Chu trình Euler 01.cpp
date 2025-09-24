#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;

int vh[105][105];
int dk, n, c, u;
int check[105] = {0};
vector<int> CE;

void dfs(){
    stack<int> a;
    a.push(1);
    check[1] = 1;
    while(!a.empty()){
        int s = a.top();
        a.pop();
        for(int i = 1; i <= n; i++){
            if(!check[i] && vh[s][i]){
                check[i] = 1;
                a.push(s);
                a.push(i);
                break;
            }
        }
    }
}

bool check_lien_thong(){
    dfs();
    for(int i = 1; i <= n; i++)
        if(!check[i])
            return 0;
    return 1;
}

void check_el(){
    int dg = 0;
    if(check_lien_thong()){
        dg = 1;
        int bacle = 0;
        for(int i = 1; i <= n; i++){
          int bac = 0;
            for(int j = 1; j <= n; j++){
              if(vh[i][j])
              bac++;
            }
            if(bac % 2 != 0){
              bacle++;
            }
        }
        if(bacle == 2){
          dg = 2;
        }else if(bacle == 0){
          dg = 1;
        }else{
          dg = 0;
        }
    }
    cout << dg;
}
void find_el(){
    stack<int> s;
    s.push(u);
    while(!s.empty()){
        int a = s.top();
        int dg = 0;
        for(int i = 1; i <= n; i++){
            if(vh[a][i]){
                dg = 1;
                s.push(i);
                vh[a][i] = 0;
                vh[i][a] = 0;
                break;
            }
        }
        if(!dg){
            s.pop();
            CE.push_back(a);
        }
    }
    for(auto it = CE.rbegin(); it != CE.rend(); it++)
        cout << *it << " ";
}
int main(){
    cin >> dk >> n >> c;
    if(dk == 2) cin >> u;
    for(int i = 0; i < c; i++){
      int x, y;
      cin >> x >> y;
      vh[x][y] = 1;
      vh[y][x] = 1;
    }
    if(dk == 1) check_el();
    else if(dk == 2) find_el();
}
