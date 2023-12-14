//��̬�滮��way[i][j] -> way[i+1][j] || way[i+1][j+1]. i-�� j-�� 
//�����ĺ� 
/*
1.��̬����,���������ڴ������Դ����ʱ���䣻��̬����:������ִ��ʱ��������ʱ�̺���������.
2.��̬�ڴ�������ڳ�������ǰ����,Ч�ʸ�.��ȱ�������.
3.��̬�����������ֵı���,����ֱ�Ӷ������(int a[10]; memset(a,0,sizeof(a)));
  ����̬�ڴ���û�����ֵı���,����ͨ��ָ���Ӷ������( int *a = new int[10]).
4.��̬����ķ������ͷ��ɱ������Զ�����;��̬����ķ������ͷű����ɳ���Ա����(delete [] a).

sample input:
5
         7
        3 8
       8 1 0
      2 7 4 4
     4 5 2 6 5
output:
30 
(7+3+8+7+5=30)
*/
#include<iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int **way = new int*[n+1];//��̬�����ά����ĵ�һά��ÿһ��Ԫ�ض���һ��һά�����ָ�� 
	
	for(int i=0; i <= n; i++){
		way[i] = new int[i+2];//why i+2 rather than i+1: because ��������ϵ���� way[i-1][j]���ܻ���磻 ��һͷһβ 
		for(int j=0; j<= i+1; j++)//��̬�Ĳ�����memset��ʼ�� ֻ����һ��ֵ 
			way[i][j] = 0;
		
		if(i!=0){
			for(int j=1; j<=i; j++){
				cin >> way[i][j];
			}
		}  
	}
	
	int max_weight = 0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			way[i][j] += max(way[i-1][j-1], way[i-1][j]);
			if(i==n){//�����һȺֵ�������ֵ 
				max_weight = max(max_weight, way[i][j]);
			}
		}
	}
	cout << max_weight << endl; 
	delete[] way; 
	return 0;
} 
