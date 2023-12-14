／*
思路：第一个值分别与后面的每一个值交换
sample output:
abc
acb
bac
bca
cba
cab
*／
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//递归实现permutation
void allRange(string s, int k, int m)
{
    if (k == m){
        cout << s << endl;
    }
    else{
        for (int i = k; i <= m; i++){
            swap(s[i], s[k]);
            allRange(s, k + 1, m);
            swap(s[i], s[k]);
        }
    }
}

int main() {
    string s = "abc";
    allRange(s, 0, s.length() - 1);
    return 0;
}