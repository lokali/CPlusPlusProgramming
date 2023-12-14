/* 最佳调度问题
 Description: 假设有n个任务由k个可并行工作的机器完成。
 完成任务i需要的时间为ti。
 试设计一个算法找出完成这n个任务的最佳调度，使得完成全部任务的时间最早。
 
 Sample Input
 7 3
 2 14 4 16 6 5 3
 
 Sample Output
 17
 
 */
#include <iostream>
using namespace std;
int n,k;
int a[100086],s[100086];//a is time, s is bottom
int minn=1000000;
bool comp(int x,int y){
    return x>y;}

void dfs(int b,int c){
    if(c>=minn) return;//剪枝1号
    if(b>n){
        minn = min(minn, c);
        return;
    }
    for(int i=1;i<=k;i++){
        if(s[i]+a[b]<=minn){//剪枝2号
            s[i]+=a[b];
            dfs(b+1,max(c,s[i]));
            s[i]-=a[b];
        }
    }
    return;
}
int main() {
    cin>>n>>k;
    memset(s,0,sizeof(s));
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1,comp);//从大到小排序可以更快接近最优解
    dfs(1,0);
    cout<<minn<<endl;
    return 0;
}