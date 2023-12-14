//DFS + �ݹ� ��Ҳ������stack�ķǵݹ鷽����
//һά���ݣ�N������
//�жϴӶ���1��ʼ����������ͼ�Ƿ���ͨ 
 
//sample input:
//N=5
//������Ϣ�� 
//1 -> 2
//2 -> 3
//3 -> 4
//4 -> 5
//5 -> 4 
//sample output: 
//��1��ʼdeͼ ����ͨ 
#include<iostream>
#include<stack>
using namespace std;

#define N 5
int maze[N][N]={//�ڽӾ���-����ͼ  maze[0][1]=1 ��ʾ��1��ָ���2��  index��0��ʼ 
	{0,1,0,0,0},
	{0,0,1,0,0},
	{0,0,0,1,0},
	{0,0,0,0,1},
	{0,0,0,1,0},
}; 
int visited[N+1]={0}; //visited[i] ��ʾ��i���ڵ� index��1��ʼ 

void DFS(int start){
	visited[start] = 1;
	cout << start << " ";//output 
	for(int i = 1; i<=N; i++){
		if(!visited[i] && maze[start-1][i-1]==1)
			DFS(i); 
	}
}

int main(){
	DFS(1);
	
	int flag = 1;
	for(int i = 1; i <= N; i++){
		if(visited[i]==0)
			flag = 0;
	} 
	if(flag==0)
		cout << "��1��ʼ��ͼ ����ͨ" << endl;
	else
		cout << "��1��ʼ��ͼ ��ͨ" << endl; 
	return 0;
} 
