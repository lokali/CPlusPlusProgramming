//BFS + queue
/*1为可行，0为不可行
sample input:
4 5
11101
10111
10010
11110
0 0  //index start from 0
3 3
sample output:
6
*/ 
#include <iostream>  
//#include <vector>
#include <queue>
#include <stack>
using namespace std;

const int N = 10000;
char map[N][N];
bool vis[N][N] = {0};   //访问记录
int path[N][N];   //记录路径 0、1、2、3分别代表上下左右
int dx[4] = {-1,1,0,0};  //上下左右移动
int dy[4] = {0,0,-1,1};
int m, n;  //行数、列数

struct node {
	int x, y;
	int cnt;//起点到此点的最短路径长度
	node():cnt(0) {}
	node(int xx, int yy, int c=0) :x(xx), y(yy), cnt(c) {}
};


//广度优先搜索
int bfs(node s, node t) {
	queue<node> q;
	q.push(s);
	vis[s.x][s.y] = 1;

	while(!q.empty()) {
		node now = q.front();
		q.pop();
		if (now.x == t.x && now.y == t.y)
			return now.cnt;
		for (int i = 0; i < 4; ++i) {
			int nx=now.x+dx[i], ny=now.y+dy[i];
			if (nx<0 || nx>=m || ny<0 || ny>=n || map[nx][ny]=='0' || vis[nx][ny]==1)
				continue;   //下标越界 或 访问过 或 障碍物
			q.push(node(nx, ny, now.cnt + 1));
			vis[nx][ny] = 1;
			path[nx][ny] = i;//记录以便还原路径 
		}
	}
	return -1;
}

void printPath(node s, node t) {
	stack<node> tmp;
	tmp.push(t);
	int x = t.x, y = t.y;  
	while (!(x == s.x && y == s.y)) {		
		int i = path[x][y];
		x = x - dx[i];
		y = y - dy[i];
		tmp.push(node(x,y));
	}

	tmp.pop(); 
	cout << "(" << s.x << "," << s.y << ")";
	while (!tmp.empty()) {
		node k = tmp.top();
		tmp.pop();
		cout << "-->" << "(" << k.x << "," << k.y << ")";
	}
	cout << endl;
}

int main()
{
	cin >> m >> n;
	for(int i = 0; i < m; ++i){
		cin >> map[i];//输入地图
	}

	node s, t;//起点、终点， index start from 0. 
	cin >> s.x >> s.y >> t.x >> t.y;

	//dfs(s, t);
	int res = bfs(s,t);//注意：避免bfs被多次调用，因为vis没有被重置，所以结果可能会有问题，因为计算过两次bfs。 
	if(map[s.x][s.y]=='0')
		cout << "0, 首个符号不可行" << endl;
	else{
		if(res==-1){
			cout << "1-, 首尾不连通" << endl; 
		}
		else{
			cout << "首尾连通，并且路径长度为： " << res << endl;//最短路径
		}
	} 
	//	cout << bfs(s,t) << endl;
	printPath(s, t);//打印路径 
	return 0;
}
