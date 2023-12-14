//
//  main.cpp
//  Cexamples
//
//  Created by Aaron_Lawrence on 2019/8/8.
//  Copyright © 2019年 李隆康. All rights reserved.
//
#include<iostream>
#include<algorithm>

using namespace std;

//sort according to the x value.
// class: private
// struct: public

class Clo{
public:
    int x;
    int y;
};

struct cl{
    int x;
    int y;
};

bool compare(cl a, cl b){
    if(a.x==b.x) return a.y<b.y; //优先比较x
    else return a.x < b.x;  //若x相同 则比较y值
}


int main(){
    int n;
    cin >> n;
    cl clo[100];
    for(int i = 0; i < n; i++){
        cin >> clo[i].x >> clo[i].y;
    }
    sort(clo,clo+n,compare);
    
    for(int i = 0; i < n; i++){
        cout << clo[i].x << "  " << clo[i].y << endl;
    }
    
    return 0;
}
