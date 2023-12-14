//���ر�������Ʒ������������ 
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
    cout << "��������Ʒ����:";
    cin >> n;
    cout << "��ֱ�����" << n << "����Ʒ����������ֵ������:" << endl; 
    for (int i = 1; i <= n; i++) {
        cin >> weight[i] >> value[i] >> num[i];
    }
    int k = n + 1;
    for (int i = 1; i <= n; i++) {//�൱�ڰѱ�1��Ĳ��� ����������w v���� 
        while (num[i] != 1) {
            weight[k] = weight[i];
            value[k] = value[i];
            k++;
            num[i]--;
        }
    }
    cout << "�����뱳������:";
    cin >> m;
    for (int i = 1; i <= k; i++) {
        for (int j = m; j >= 1; j--) {
            if (weight[i] <= j) 
				f[j] = max(f[j], f[j-weight[i]] + value[i]);
        }
    }
    cout << "�����ܷŵ�����ֵΪ:" << f[m] << endl;
}
