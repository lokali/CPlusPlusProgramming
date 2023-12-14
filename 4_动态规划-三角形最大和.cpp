//动态规划：way[i][j] -> way[i+1][j] || way[i+1][j+1]. i-行 j-列 
//求最大的和 
/*
1.静态分配,即编译器在处理程序源代码时分配；动态分配:即程序执行时调用运行时刻函数来分配.
2.静态内存分配是在程序运行前进行,效率高.但缺少灵活性.
3.静态变量是有名字的变量,我们直接对其操作(int a[10]; memset(a,0,sizeof(a)));
  而动态内存是没有名字的变量,我们通过指针间接对其操作( int *a = new int[10]).
4.静态对象的分配与释放由编译器自动处理;动态对象的分配与释放必须由程序员管理(delete [] a).

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
	int **way = new int*[n+1];//动态申请二维数组的第一维，每一个元素都是一个一维数组的指针 
	
	for(int i=0; i <= n; i++){
		way[i] = new int[i+2];//why i+2 rather than i+1: because 考虑最边上的情况 way[i-1][j]可能会出界； 多一头一尾 
		for(int j=0; j<= i+1; j++)//动态的不能用memset初始化 只能逐一赋值 
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
			if(i==n){//在最后一群值中找最大值 
				max_weight = max(max_weight, way[i][j]);
			}
		}
	}
	cout << max_weight << endl; 
	delete[] way; 
	return 0;
} 
