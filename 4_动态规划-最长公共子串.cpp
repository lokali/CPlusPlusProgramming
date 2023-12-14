//最长公共子序列：不一定连续 
//最长公共子串：一定要连续 
/*
input: 
abc abcd

output:
abc 
*/
#include<iostream>
using namespace std;

string longestSubstring(string x, string y) {
    int max = 0;
    string str = "";
    string res = "";
    for (int i = 0; i < x.size(); i++) {
        int len = 0;
        int j = i;
        while (j < x.size()) {
            str += x[j];
            if (y.find(str) == y.npos) break;//若没有在y中找到子串str 则break； y.find(x)是找x在y的position index 
            len++;
            j++;
            
            if(len>max){
			max = len;
            res = str;} 
        }
        str = "";
    }
    //cout << "the maximun length is " << max << endl;
    return res;   
}

int main(){
	string x,y;
	cin >> x >> y; 
	cout << longestSubstring(x,y) << endl;
	return 0;
}
