/**********************
**������йص�����
***********************/
#ifndef TEST_H
#define TEST_H

#include <stddef.h>

/*ϵͳ���˵�����,��ʾϵͳ�����˵�����,��ʾ�û�������Ӧ�Ĳ���*/
void Menu(void);


/*��궨λ*/
void gotoxy(const short x, const short y);


/*�����λ��*/
size_t InputPos(const char notice[]);


/*����������*/
int InputValue(const char notice[]);


#endif