BSTNode  *BSTDelete(BSTNode *bt,KeyType k)
{//1.寻找待删除节点在链表中的位置,如果不存在该结点，p指针会一直向后移动直到最后一位
	BSTNode  *p,*f,*s,*q;
	p=bt;f=NULL;
	while(p)
	{
		if(p->key==k)   break;
		f=p;//f为p的双亲结点
		if(p->key>k)
			p=p->lchild;
		else
		p=p->rchild;
	}
	//2.判断该点在二叉树中是否存在
	if(p==NULL) return bt;
	//3.单分支结构
	if(p->lchild==NULL)//p无左子树
	{
		if(f==NULL)
			bt=p->rchild;
		else  if(f->lchild==p)
			f->lchild=p->rchild;
		else 
			f->rchild=p->rchild;
		free(p);
	}
	else//双分支结点
	{
		q=p;s=p->lchild;//此时将p赋值为q，s为p的左子树，则q为s的双亲
		while(s->rchild)//查找p的左子树中查找最右下结点——最大结点
			{
				q=s;
				s=s->rchild;//s为左子树最大结点，q为左子树最大节点的父母结点
			}
	if(q==p)//用来判断p结点的左子树是否有右子树的
		 q->lchild=s->lchild;//s为p左子树的最右子树，所以它没有右子树了
	else     
		q->rchild=s->lchild;
		p->key=s->key;
		free(s);
	}
	return  bt;
}

