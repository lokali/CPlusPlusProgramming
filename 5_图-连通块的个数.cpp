/*上下左右斜 都是连通 
sample input:
5 5 
10000
11100
11100
00001
11111

output:
2 
*/ 

#include <iostream>
using namespace std;

char c[1001][1001];//Graph
int n, m;
int cnt=0;
int idx[1001][1001];
//idx连通分量编号,若有值，则表示idx[i][j]表示第i行 第j列是否访问过；具体的数值为第idx个连通块
int dir[8][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}, {-1,1}, {1,-1}, {1,1}, {-1,-1}};

void Dfs(int x, int y, int id) {
    if(x < 1 || x > n || y < 1 || y > m) return;  //坐标越界
    if(c[x][y] != '1' || idx[x][y] != 0) return;  //不是1 或 已经访问
    idx[x][y] = id;
    for(int d=0; d<8; d++)
        Dfs(x+dir[d][0], y+dir[d][1], id);
}

int main() {
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> c[i][j];   //从1开始读入

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(idx[i][j] == 0 && c[i][j] == '1')
                Dfs(i, j, ++cnt);
    
    cout << cnt << endl;
    return 0;
}

