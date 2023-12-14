/*stack: ����ȳ� 
��ջ��������s.push(x);
��ջ��������s.pop();ע�⣬��ջ����ֻ��ɾ��ջ��Ԫ�أ��������ظ�Ԫ�ء�
����ջ����������s.top()
�ж�ջ�գ�������s.empty()����ջ��ʱ������true��
����ջ�е�Ԫ�ظ�����������s.size() 

Stack: First In Last Out
*/ 
#include<iostream> 
#include<stack> 
using namespace std;
int main(){
	stack<int> s; 
	
	for(int i=0;i<10;i++){
		s.push(i);
	}
	
	if(!s.empty()){
		cout<<"ջ���ǿյ�"<<endl; 
	}
	
	cout<<"ջ��Ԫ�صĸ���Ϊ��"<<s.size()<<endl;
	
	while(!s.empty()) {
		cout<<" "<<s.top(); //��ȡջ��Ԫ��
		s.pop(); //����ջ��Ԫ�� 
	}
	cout<<endl;
	return 0;
}
