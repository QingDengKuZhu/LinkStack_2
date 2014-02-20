#include "Data_Base.h"

void Conversion_ten_to_n(unsigned int m, unsigned int n)
{
	char ch[16] = {'0', '1', '2', '3', 
				   '4', '5', '6', '7', 
				   '8', '9', 'A', 'B', 
				   'C', 'D', 'E', 'F'};
	
	PLINKSTACK pS = InitStack();

	while (m != 0)
	{
		Push(pS, m%n);
		m/=n;
	}

	printf("十进制数%d转换为%d进制数为: ", m, n);
	
	while (FALSE == StackEmpty(pS))
	{
		unsigned int temp;
		Pop(pS, &temp);
		printf("%c", ch[temp]);
	}

	DestroyStack(&pS);
	
	return;
}