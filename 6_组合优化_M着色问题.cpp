/* M着色问题:给定无向连通图G和M种不同的颜色，用这些颜色为图G的各顶点着色，每个顶点着一种颜色。如果有一种着色法使G中每条边的2个顶点着不同的颜色，则称这个图是M可着色的。图的M着色问题是对于给定图G和M种颜色，找出所有不同的着色法。 [如果结果为0，则说明m种颜色无法实现着色]
 
 sapmle input:
 n=5 k=8 m=4
 1 2
 1 3
 1 4
 2 3
 2 4
 2 5
 3 4
 4 5
 
 output:
 48
 */
#include<iostream>
using namespace std;
int n,k,m,ans;
int g[101][101],c[101];//g-graph, c[i] is the color of i-th vertex
void dfs(int deep)
{
    if (deep>n)
    {
        ans++;
    }
    else
    {
        int i,j;
        bool flag;
        for(i=1;i<=m;i++)
        {
            c[deep]=i;
            flag=true;
            j=1;
            while ((j<=n)&&(flag))
            {
                //条件分别代表 相连 同色 已染色
                if ((g[deep][j])&&(c[deep]==c[j])&&(c[deep]!=0))
                {
                    flag=false;
                }
                j++;
            }
            //回溯行为，取消染色
            if (flag)
            {
                dfs(deep+1);
            }
            c[deep]=0;
        }
    }
    
}
int main()
{
    int s,j,t1,t2;
    cin>>n>>k>>m;
    for(s=1;s<=n;s++)
    {
        for(j=1;j<=n;j++)
        {
            g[s][j]=false;
        }
    }
    for(s=1;s<=k;s++)
    {
        cin>>t1>>t2;
        g[t1][t2]=true;
        g[t2][t1]=true;
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}