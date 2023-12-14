/*
01������ ��һά��������� 
input: 
5
2 6 
2 3
6 5
5 4
4 6
10
output:
15
*/

#include <iostream>
using namespace std;

int weight[20 + 1];
int value[20 + 1];
int f[500 + 1];
int main() {
    int n, m;
    cout << "��������Ʒ����:";
    cin >> n;
    cout << "��ֱ�����" << n << "����Ʒ�������ͼ�ֵ:" << endl; 
    for (int i = 1; i <= n; i++) {
        cin >> weight[i] >> value[i];
    }
    cout << "�����뱳������:";
    cin >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) { // ע������ 
            if (weight[i] <= j) {
                f[j] = max(f[j], f[j-weight[i]] + value[i]);
            }
        }
    }
    cout << "�����ܷŵ�����ֵΪ:" << f[m] << endl;
}
