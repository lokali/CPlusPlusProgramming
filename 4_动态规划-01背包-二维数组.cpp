/*
0-1背包：每个物品只能使用一次
完全背包：每个物品可以无限次使用
多重背包：每个物品的使用次数有规定 
sample input:  
n=5
2 6
2 3
6 5
5 4
4 6
c=10 
sample output:
15
1 1 0 0 1
*/
#include<iostream>
#include<cstring>
using namespace std;
int V[200][200]={0}; 
int x[100]={0};

int knapsack(int n, int w[], int v[], int c){ 
 	for(int i=1; i<= n; i++){
 		for(int j=1; j<=c; j++){
 			if(j<w[i]){
			 	V[i][j] = V[i-1][j];
			}
			else{
				V[i][j] = max(V[i-1][j], V[i-1][j-w[i]]+v[i]);
			}
		 }
	}
	return V[n][c];
}

void traceback(int n, int w[], int v[], int c){
	int j=c;
	for(int i=n; i>0; i--){
		if(V[i][j]>V[i-1][j]){
			x[i] = 1;
			j -= w[i]; 
		}
		else{
			x[i] = 0;
		}
	}
}

int main(){
	int n;//number of item
	cin >> n;
	
	int w[100];
	int v[100];
	memset(w,0,sizeof(w)); // in head file: cstring
	memset(v,0,sizeof(v));
	
	for(int i=1; i <= n; i++){ // start index is 1.
		cin >> w[i] >> v[i];
	}
	
	int c;//max weight required
	cin >> c;
	
	int s;//max value
	s = knapsack(n,w,v,c);
	cout << "Max value is: " << s << endl;
	
	traceback(n,w,v,c); 
	for(int i=1; i<=n; i++){
		cout << x[i] << " ";
	}
	return 0;
}
 
