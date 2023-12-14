//BFS + queue
//一维数据：N个顶点
//判断从顶点1开始，整个有向图是否联通 

//sample input:
//N=5
//顶点信息： 
//1 -> 2
//2 -> 3
//3 -> 4
//4 -> 5
//5 -> 4 
//sample output: 
//从1开始de图 连通 
#include<iostream>
#include<queue>
using namespace std;

#define N 5
int maze[N][N]={//邻接矩阵-有向图  maze[0][1]=1 表示第1点指向第2点  index从0开始 
	{0,1,0,0,0},
	{0,0,1,0,0},
	{0,0,0,1,0},
	{0,0,0,0,1},
	{0,0,0,1,0},
}; 

int visited[N+1]={0}; //visited[i] 表示第i个节点 index从1开始 

void BFS(int start){
	queue<int> Q;
	Q.push(start);
	visited[start] = 1;
	while(!Q.empty()){
		int front=Q.front();
		cout << front << " ";// BFS遍历输出节点
		Q.pop();
		
		for(int i=1; i<=N; i++){
			if(!visited[i]&&maze[front-1][i-1]==1){
				visited[i] = 1;
				Q.push(i); 
			}
		} 
		
	}
}

int main(){
	BFS(1);
	
	int flag = 1;
	for(int i = 1; i <= N; i++){
		if(visited[i]==0)
			flag = 0;
	} 
	if(flag==0)
		cout << "从1开始的图 不连通" << endl;
	else
		cout << "从1开始的图 连通" << endl; 
	
	return 0;
} 
