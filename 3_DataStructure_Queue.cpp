/*Queue ���У� �Ƚ��ȳ�
empty() �ж϶����Ƿ�Ϊ�գ���������Ϊbool
size() ���ض�����Ԫ�صĸ���
front() ���ض��ж���Ԫ��
back() ���ض��ж�βԪ��
push(ele) ��Ԫ��ele���뵽��β
pop ����Ԫ�س���, �����ؾ���ֵ 

Queue: First in First Out

*/ 
#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> q;
    for(int i=0;i<10;i++){
      	q.push(i);
  	}
  	
	if(!q.empty()){
    	cout<<"���в��ǿյ�"<<endl;
  	}
  	
  	int num=q.size();
  	cout<<"����q�ĳ���Ϊ��"<<num<<endl;
  	
  	int last=q.back();
  	cout<<"����q���һ��Ԫ�أ�"<<last<<endl;
  	
  	int ele;
  	while(!q.empty()){  
    	ele=q.front();
    	cout<<ele<<" ";
    	q.pop();
  	}
  	cout<<endl;
  	return 0;
} 
