/*vector: 动态数组 
vector<int> vec;  //声明一个int型向量
vector<int> a(10);//声明一个初始大小为10的int向量,值默认为0
fill(a.begin(), a.end(), INF); //初始化最短距离矩阵，全部为INF
vector<int> b(10,1);//声明一个初始大小为10且值均为1的向量
vector<int> c = {1,2,3,4}; //
vector<int> d(c.begin(),c.end())); 

vec.begin();
vec.end();
vec.size();//返回向量大小（容量）
vec.max_size();//返回向量的最大容量
vec.capacity();//向量真实大小
vec.empty();//判断向量是否为空
vec.shrink_to_fit();//减少向量大小到满足所占存储空间的大小
vec.push_back();//向量末尾插入元素
vec.pop_back();//删除向量末尾元素
vec.insert(vec.begin()+i,a);//在第i+1个元素前面插入a，通过迭代器操作
vec.erase(vec.begin()+i);//删除第i+1个元素，通过迭代器操作
vec.clear();//清除向量中所有元素
vec[1];//下标法访问向量的第一个元素

//排序 逆序
#include<algorithm>
resverse(vec.begin(),vec,end());//元素反向排列
sort(vec.begin(),vec.end());//将元素从小到大排序 //int d[n]; sort(d,d+n)

//遍历元素（迭代器法）
vector<int>::iterator it;//定义int型向量的迭代器it
for(it=vec.begin();it!=vec.end();it++)
cout<<*it<<endl;

//vector或者数组的遍历都可以如下
for(int v : vec) cout << v << endl;

//从大到小排序
bool Comp(const int& a, const int& b) {
return a > b;
}
sort(vec.begin(), vec.end(), Comp);
*/ 
#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> v;
	
	for(int i=0;i<10;i++){
		v.push_back(i); 
	}
	
	for(int i=0;i<v.size();i++){
		cout<<" "<<v[i];
	}
	cout<<endl;
	
	//使用迭代器遍历数据 迭代器相当于指针
	vector<int>::iterator iter;
	for(iter = v.begin();iter != v.end();iter++){
		cout<<" "<<*iter;
	}
	cout<<endl;
	
	//删除数据
	for(vector<int>::iterator it=v.begin();it!=v.end();){
		v.erase(it);
	}
	
	if(v.empty()){
		cout<<"向量v为空"<<endl;
	}
	return 0;
}
