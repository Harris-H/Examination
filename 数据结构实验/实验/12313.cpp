BSTNode  *BSTDelete(BSTNode *bt,KeyType k)
{//1.Ѱ�Ҵ�ɾ���ڵ��������е�λ��,��������ڸý�㣬pָ���һֱ����ƶ�ֱ�����һλ
	BSTNode  *p,*f,*s,*q;
	p=bt;f=NULL;
	while(p)
	{
		if(p->key==k)   break;
		f=p;//fΪp��˫�׽��
		if(p->key>k)
			p=p->lchild;
		else
		p=p->rchild;
	}
	//2.�жϸõ��ڶ��������Ƿ����
	if(p==NULL) return bt;
	//3.����֧�ṹ
	if(p->lchild==NULL)//p��������
	{
		if(f==NULL)
			bt=p->rchild;
		else  if(f->lchild==p)
			f->lchild=p->rchild;
		else 
			f->rchild=p->rchild;
		free(p);
	}
	else//˫��֧���
	{
		q=p;s=p->lchild;//��ʱ��p��ֵΪq��sΪp������������qΪs��˫��
		while(s->rchild)//����p���������в��������½�㡪�������
			{
				q=s;
				s=s->rchild;//sΪ����������㣬qΪ���������ڵ�ĸ�ĸ���
			}
	if(q==p)//�����ж�p�����������Ƿ�����������
		 q->lchild=s->lchild;//sΪp������������������������û����������
	else     
		q->rchild=s->lchild;
		p->key=s->key;
		free(s);
	}
	return  bt;
}

