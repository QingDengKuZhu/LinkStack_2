#include "Data.h"
#include "Main_First.h"
#include "Data_Base.h"

/*
pS为指向栈的指针,且pS不为NULL.该种链式栈是单链表的特殊情况.
*/

PLINKSTACK InitStack(void)
{
	
	PNODE pTop = (PNODE)malloc(sizeof(NODE));	/*生成一个栈顶指针.*/
	if (!pTop)
	{
		printf("动态内存分配错误!\n");
		exit(ERROR);
	}
	
	pTop->pNext = NULL;	/*初始时,单链表为空,头结点指针域为空.*/
	
	return pTop;
}



void DestroyStack(PLINKSTACK *ppS)
{
	PNODE q = NULL;
	
	while (*ppS)
	{
		q = (*ppS)->pNext;
		free(*ppS);
		*ppS = q;
	}/*退出while()循环时, *ppS一定为NULL.*/
	
	/*不需要再设定(*ppS)为空,因为此时*ppS已经为NULL,这是与ClearList()的区别.*/
	
	return;
}

void ClearStack(PLINKSTACK pS)
{
	PNODE p = pS->pNext;	
	PNODE q = NULL;
	
	while (p)
	{
		q = p->pNext;
		free(p);
		p = q;
	}
	
	pS->pNext = NULL;	

	return;
}

BOOL StackEmpty(PLINKSTACK pS)
{
	if (!(pS->pNext))	
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}	

}

size_t StackLength(PLINKSTACK pS)
{
	PNODE p = pS->pNext;
	size_t length = 0;
	
	while (p)
	{
		++length;
		p = p->pNext;
	}
	
	return length;

}

STATUS GetTop(PLINKSTACK pS, Elem *e)
{
	if (TRUE == StackEmpty(pS))
	{
		return FAILE;
	}
	else
	{
		*e = pS->pNext->data;
	
		return OK;
	}
}

void Push(PLINKSTACK pS, const Elem v)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (!pNew)
	{
		printf("入栈失败\n");
		exit(ERROR);
	}
	
	pNew->data = v;
	pNew->pNext = pS->pNext;
	pS->pNext = pNew;
	
	return;
}

STATUS Pop(PLINKSTACK pS, Elem *e)
{
	if (TRUE == StackEmpty(pS))
	{
		return FAILE;
	}
	else
	{
		PNODE p = pS->pNext->pNext;
		*e = pS->pNext->data;
		free(pS->pNext);
		pS->pNext = p;
		
		return OK;

	}
}

void TraveStack(PLINKSTACK pS)
{
	PNODE p = pS->pNext;
	
	while (p)
	{
		printf("%d ", p->data);
		p = p->pNext;
	}
	
	return;
}
