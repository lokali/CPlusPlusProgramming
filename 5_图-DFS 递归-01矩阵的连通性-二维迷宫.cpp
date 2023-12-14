//迷宫：1可行， 0不可行 
/*sample input:
M=4 N=6 
"100010"
"111111"
"011010"
"101011"
start: 1 1 //index start from 1
end: 4 6

sample output:
Yes
*/	
#include <iostream>
#include <cstdio> 
using namespace std; 

const int MAXN=10000;
int M,N;
char A[MAXN][MAXN];//index start from 0 
bool visited[MAXN][MAXN]={0};//index from 0
int dx[4] = {-1,1,0,0};  //上下左右移动
int dy[4] = {0,0,-1,1};

void dfs(int x,int y)
{
		visited[x][y] = 1;
		cout << x << " " << y << endl;
		for(int i=0; i < 4; i++){
			int nx=x+dx[i],ny=y+dy[i];
			if(nx>=0&&nx<M && ny>=0&&ny<N &&A[nx][ny]=='1'&& !visited[nx][ny])
				dfs(nx,ny); 
		}
}

int main()
{
	cin >> M >> N;
	for(int i=0;i<M;++i)
		//scanf("%s",A[i]);
		cin >> A[i];
	int sx,sy,ex,ey;//start position, end position.
	cin >> sx >> sy >> ex >> ey;//index start from 1.
		
	if(A[sx-1][sy-1]=='1')
		dfs(sx-1,sy-1);
	else{};
		
	if(visited[ex-1][ey-1])
		cout << "Yes" << endl;
	else
		cout << "No" << endl;	
	return 0;
}
