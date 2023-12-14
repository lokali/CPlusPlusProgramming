//完全背包：物品可以有无限个 
/*
INPUT:
5 
2 6
2 3
6 5 
5 4
4 6
10
OUTPUT:
30
*/ 

#include <iostream>

using namespace std;
int weight[20 + 1];
int value[20 + 1];
int f[500 + 1];

int main() {
    int n, m;
    cout << "请输入物品个数:";
    cin >> n;
    cout << "请分别输入" << n << "个物品的重量和价值:" << endl; 
    for (int i = 1; i <= n; i++) {
        cin >> weight[i] >> value[i];
    }
    cout << "请输入背包容量:";
    cin >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) { //顺序 
            if(weight[i]<=j)
                f[j] = max(f[j], f[j - weight[i]] + value[i]);
        }
    }
    cout << "背包能放的最大价值为:" << f[m] << endl;
}
