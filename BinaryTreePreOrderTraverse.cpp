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
		stack<BiTNode*> assi;//定义辅助栈
		assi.push(T);//压栈
		cout << assi.top()->data;//入栈时候访问

		while (!assi.empty())
		{
			while (assi.top()->lchild)
			{
				cout << assi.top()->lchild->data;
				BiTNode *temp = assi.top();//用于断开父子连接 防止重复访问
				assi.push(assi.top()->lchild);
				temp->lchild = NULL;//断开父子连接
			}
			
			if (!assi.top()->rchild)//若右孩子为空则直接弹出，该节点已经访问输出过了。
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