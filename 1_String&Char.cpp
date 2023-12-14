//
//  main.cpp
//  4
//
//  Created by Longkang Li on 2019/8/17.
//  Copyright © 2019年 李隆康. All rights reserved.
//

#include <iostream>
#include <cctype>
using namespace std;

//输入: "A man, a plan, a canal: Panama"
//输出: true
bool isPalindrome(string s) {
    int len = s.size();
    if(len == 1) return true;
    int i = 0,j = len - 1;
    while(i < j){
        if(s[i] >= '0' && s[i] <= '9' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z');
        else{
            i++;
            continue;
        }
        if(s[j] >= '0' && s[j] <= '9' || s[j] >= 'A' && s[j] <= 'Z' || s[j] >= 'a' && s[j] <= 'z');
        else{
            j--;
            continue;
        }
        
        if(s[i] >= 'a' || s[j] >= 'a'){
            if(abs(s[i] - s[j]) == 0 || abs(s[i] - s[j]) == 32){
                i++;
                j--;
            }
            else return false;
        }
        else if(abs(s[i] - s[j]) == 0){
            i++;
            j--;
        }
        else return false;
        
    }
    return true;
}

int main() {
    //string s + tolower/toupper
    string str;
    cin >> str;//abcde
    cout << "Length= " << str.size() << endl;//5
    for(int i = 0 ; i< str.size(); i++)
        str[i] = toupper(str[i]);//tolower/toupper
    cout << str << endl;
    while(1);
    
    //char*
    char st[100000];
    cin >> st;
    cout << strlen(st) << endl;
    
    //char*
    int n;
    cin>> n; //5
    char s[10000];
    for(int i=0;i<n; i++){
        cin >> s[i]; //abcde
    }
    s[n] = '\0';
    cout << "Lens= " << strlen(s) << endl;//5
    
    //char*
    char ss[n+1]; //n=5
    for(int i=0;i<n; i++){
        cin >> ss[i]; //abcde
    }
    ss[n] = '\0';
    cout << "Lens= " << strlen(ss) << endl;//6
    
    return 0;
}
