struct node
{
	int value;
	node* next;
};


/* 链表尾加入新元素*/
node* addNode(node*head ,int addValue)
{
	 node* newNode=new node();
	 newNode->next=NULL;
	 newNode->value=addValue;
	 node* p=new node();
	 p=head; //list的头结点
	 if(head==NULL)
	 {
	   head=newNode; //新节点为链表头节点
	 }else
	 {
		while(p->next!=NULL)//找到尾节点
			p=p->next;
		p->next=newNode; //在尾节点后面加入新节点
	 }
	 return head;
}


/*从头到尾遍历链表*/
void travelList(node*head)
{
	node* pNode=head;
	if(head==NULL)
		return ;
	else
	{
	  cout<<pNode->value<<'\t';
	  while(pNode->next!=NULL)
	  {
		  pNode=pNode->next; 
          cout<<pNode->value<<'\t';
	  }
	}  
}

/*在链表中找到某个值，删除它*/
node* removeNode(node* head,int value)
{
	node* pNode=head;
	node* deleteNode=NULL;
	if(head==NULL)
	{
	   cout<<"链表为空"<<endl;
	   return NULL;
	}else if(head->value==value)//头节点为目标节点
	{
		deleteNode=head;
		head=head->next;
	}else
	{
	   while(pNode->next!=NULL&&pNode->next->value!=value)//找出目标节点的上一个节点
		 	pNode=pNode->next;
	   		if(pNode->next!=NULL&&pNode->next->value==value)
	   		{
	   			deleteNode=pNode->next;
	   			pNode->next=pNode->next->next;//删除目标节点
	   		}
	}
	 if(deleteNode!=NULL)
	   {
		   delete deleteNode;
		   deleteNode=NULL;
	   }
	return head;
}