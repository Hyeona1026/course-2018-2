#include<stdio.h>
#include"���.h"
#include"ChainHash.h"

typedef enum {
	TERMINATE,ADD,DLETE,SEARCH,CLEAR,DUMP
}Menu;

Menu SelectMenu(void)
{
	int ch;
	do {
		printf("(1)�߰� (2)���� (3)�˻� (4) ��� ���� (5) ���� (0) ���� : ");
		scnaf("%d, &ch");
	} while (ch < TERMINATE || ch > DUMP);
	return(Menu)ch;
}

int main(void)
{
	Menu menu;
	ChainHash hash;
	Initialize(&hash, 13);
	do {
		int result;
		Member x;
		Node *temp;
		switch(menu = SelectMenu()){
		case ADD :
			x = ScanMember("�߰�", MEMBER_NO | MEMBER_NAME);
			result = Add(&hash &x);
			if (result)
				printf("\a���� : �߰��� �����߽��ϴ�(%s).\n",
				(result == 1) ? "�̹� ��ϵ�" : "�޸𸮺���");
			break;

		case DLETE :
			x = ScanMember("����", MEMBER_NO);
			result = Remove(&hash, &x);
			if (result == 1)
				printf("\a���� : �� ��ȣ�� �����Ͱ� �������� �ʽ��ϴ�.\n");
			break;

		case SEARCH :
			x = ScanMember("�˻�", MEMBER_NO);
			temp = Search(&hash, &x);
			if (temp == NULL)
				printf("\a�˻��� �����߽��ϴ�.\n");
			else {
				printf("�˻��� �����߽��ϴ�. : ");
				PrintLnMember(&temp->date);
			}
			break;

		case CLEAR :
			Clear(&hash);
			break;

		case DUMP:
			Dump(&hash);
			break;
		}
	} while (menu != TERMINATE);
	Terminate(&hash);

	return 0;
}