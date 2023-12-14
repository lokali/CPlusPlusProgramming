#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int s;    //为了方面，直接declare 全局变量
int N;//点的个数
int init_point;
double x[20];    //城市的x坐标
double y[20];    //城市的y坐标
double dp[20][20];//两个城市的距离   一般不超过20个
double **dis;//2^20  表示出发点到S集合是否已经访问过  数组较大 在main函数中动态内存分配
bool visited[20];   //设置某点的坐标是否访问过 在main函数中初始化false


//时间复杂度是（n*2^n*n = n^2*2^n）  空间复杂度是（n*2^n）
double go(int s,int init)    //init 计数
{
    if (init == N)
    {
        return 0;
    }
    if(dis[s][init]!=-1) return dis[s][init];//去重
    
    double minlen=100000;
    
    for(int i=0;i<N;i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            double temp = dp[s][i] + go(i,init+1);
            if (temp<minlen)
            {
                minlen = temp;
            }
        }
    }
            dis[s][init] = minlen;
    return dis[s][init];
}
int main()
{
    for (int i = 0;i<N;i++)
    {
        visited[i] = false;
    }
    int test;
    cout<<"Please input the number of test instance:"<<endl;
    cin>>test;
    while(test--)//测试样例数
    {
        cout<<"Please input the number of the coordinate(less than 20 for some reason!):"<<endl;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            cout<<"Please input the coordinate of the "<<i+1<<"th x[i] and y[i]:";
            cin>>x[i]>>y[i];//读入城市的坐标
        }
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
            {
                dp[i][j]=sqrt(pow((x[i]-x[j]),2)+pow((y[i]-y[j]),2));
                //计算两个城市i与j的距离
            }
        
        int M = static_cast<int>(pow(2.0,N));
        
        dis = new double*[M];
        for (int i = 0;i<M;i++)
        {
            dis[i] = new double[N];
        }
        for(int i=0;i<pow(2.0,N);i++)
            for(int j=0;j<N;j++)
                dis[i][j]=-1;//去重数组初始化
        
        init_point=0;
        s=0;
        
        double distance=go(s,init_point);
        cout<<fixed<<setprecision(2)<<distance<<endl;
        
        //用完之后记得delete 防止内存泄漏
        for (int i = 0;i<M;i++)
        {
            delete [] dis[i];
        }
        delete [] dis;
    }      
    return 0;
}

