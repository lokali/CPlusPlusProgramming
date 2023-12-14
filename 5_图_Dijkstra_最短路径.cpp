 /*Dijkstra算法：求最小路径 （要求图中无负权边）
思路：每次找到离源点最近的点
 
Dijkstra算法解决的是单源最短路径问题
给定无向图G(V,E)和起点s(起点又称为源点),
求从起点s到达其它顶点的最短距离
并将最短距离存储在矩阵d中
d就是输出的最短距离
*/
const int INF = 1000000000;
void Dijkstra(int n, int s, vector<vector<int>> G, vector<bool>& vis, vector<int>& d)
{
       /*
       n：           顶点个数
       s：           源点
       G：           图的邻接矩阵
       vis：         标记顶点是否已被访问
       d：           存储源点s到达其它顶点的最短距离
       */
       fill(d.begin(), d.end(), INF);                         //初始化最短距离矩阵，全部为INF
       d[s] = 0;                                              //起点s到达自身的距离为0
       for (int i = 0; i < n; ++i) //需要放n次 每一次找到一个最小距离的点
       {
              int u = -1;                                     //找到d[u]最小的u
              int MIN = INF;                                  //记录最小的d[u]
              for (int j = 0; j < n; ++j)//index: [0,n-1]     //开始寻找最小的d[u]
              {
                     if (vis[j] == false && d[j] < MIN)
                     {
                           u = j;//u记录[0,n-1]的顶点值
                           MIN = d[j];
                     }
              }
              //找不到小于INF的d[u]，说明剩下的顶点和起点s不连通
              if (u == -1)
                     return;                 
              vis[u] = true;
                                                //标记u已被访问
              for (int v = 0; v < n; ++v)
              {//遍历所有顶点，如果v未被访问 && u能够到达v && 以u为中介点可以使d[v]更优
                     if (vis[v] == false && G[v][u] + d[u] < d[v])
                           d[v] = G[v][u] + d[u];//更新d[v]
              }
       }
}