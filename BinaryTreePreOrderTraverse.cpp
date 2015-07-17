#include"iostream"
#include"stack"
using namespace std;

struct BiTNode{
	int data;
	struct BiTNode *lchild, *rchild;
};

class Solution{
public:
	void preOrderTraverse(BiTNode *T)
	{
		if (T == NULL)
			return;
		stack<BiTNode*> assi;//���帨��ջ
		assi.push(T);//ѹջ
		cout << assi.top()->data;//��ջʱ�����

		while (!assi.empty())
		{
			while (assi.top()->lchild)
			{
				cout << assi.top()->lchild->data;
				BiTNode *temp = assi.top();//���ڶϿ��������� ��ֹ�ظ�����
				assi.push(assi.top()->lchild);
				temp->lchild = NULL;//�Ͽ���������
			}
			
			if (!assi.top()->rchild)//���Һ���Ϊ����ֱ�ӵ������ýڵ��Ѿ�����������ˡ�
				assi.pop();
			else
			{
				cout << assi.top()->rchild->data;
				BiTNode *temp = assi.top();
				assi.push(assi.top()->rchild);
				temp->rchild = NULL;
			}
		}
	}


	void preOrderTraverse2(BiTNode *T)
	{
		if (T == NULL)
			return;
		stack<BiTNode *> st;
		st.push(T);
		BiTNode *p = NULL;

		while (!st.empty())
		{
			p = st.top();
			cout << p->data;
			st.pop();

			if (p->rchild != NULL)
				st.push(p->rchild);
			if (p->lchild != NULL)
				st.push(p->lchild);
		}
	}
};