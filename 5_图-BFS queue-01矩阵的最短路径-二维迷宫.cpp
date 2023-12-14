//BFS + queue
/*1Ϊ���У�0Ϊ������
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
bool vis[N][N] = {0};   //���ʼ�¼
int path[N][N];   //��¼·�� 0��1��2��3�ֱ������������
int dx[4] = {-1,1,0,0};  //���������ƶ�
int dy[4] = {0,0,-1,1};
int m, n;  //����������

struct node {
	int x, y;
	int cnt;//��㵽�˵�����·������
	node():cnt(0) {}
	node(int xx, int yy, int c=0) :x(xx), y(yy), cnt(c) {}
};


//�����������
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
				continue;   //�±�Խ�� �� ���ʹ� �� �ϰ���
			q.push(node(nx, ny, now.cnt + 1));
			vis[nx][ny] = 1;
			path[nx][ny] = i;//��¼�Ա㻹ԭ·�� 
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
		cin >> map[i];//�����ͼ
	}

	node s, t;//��㡢�յ㣬 index start from 0. 
	cin >> s.x >> s.y >> t.x >> t.y;

	//dfs(s, t);
	int res = bfs(s,t);//ע�⣺����bfs����ε��ã���Ϊvisû�б����ã����Խ�����ܻ������⣬��Ϊ���������bfs�� 
	if(map[s.x][s.y]=='0')
		cout << "0, �׸����Ų�����" << endl;
	else{
		if(res==-1){
			cout << "1-, ��β����ͨ" << endl; 
		}
		else{
			cout << "��β��ͨ������·������Ϊ�� " << res << endl;//���·��
		}
	} 
	//	cout << bfs(s,t) << endl;
	printPath(s, t);//��ӡ·�� 
	return 0;
}
