//多重背包：物品的数量有限制 
/*
input:
5
2 6 1
2 3 3
6 5 5
5 4 4
4 6 10
10
output:
18 
*/ 
#include <iostream>
using namespace std;

int weight[50 + 1];
int value[50 + 1];
int num[20 + 1];
int f[1000 + 1];

int main() {
    int n, m;
    cout << "请输入物品个数:";
    cin >> n;
    cout << "请分别输入" << n << "个物品的重量、价值和数量:" << endl; 
    for (int i = 1; i <= n; i++) {
        cin >> weight[i] >> value[i] >> num[i];
    }
    int k = n + 1;
    for (int i = 1; i <= n; i++) {//相当于把比1多的部分 补到了数组w v后面 
        while (num[i] != 1) {
            weight[k] = weight[i];
            value[k] = value[i];
            k++;
            num[i]--;
        }
    }
    cout << "请输入背包容量:";
    cin >> m;
    for (int i = 1; i <= k; i++) {
        for (int j = m; j >= 1; j--) {
            if (weight[i] <= j) 
				f[j] = max(f[j], f[j-weight[i]] + value[i]);
        }
    }
    cout << "背包能放的最大价值为:" << f[m] << endl;
}
