#include <iostream>
#include <cstring>

/* ������ ���¹�ȣ�� �ߺ��� �ʴ´ٴ� ����.
   �Ա� �� ��ݱݾ��� ������ 0���� ũ�ٴ� ����
   ������ ���������� ���¹�ȣ(accountNum), �����̸�(name), ������ �ܾ�(money), �̷��� �������� ���� �� �����Ѵ�.
   �� �̻��� ���� ���� ������ ���ؼ� �迭�� ����Ѵ�.(10���� ����)
   ���¹�ȣ�� ������ �����̴�.
*/

void menu();
void printMenu();
void accountOpen();
void deposit();
void withdraw();
void allAccountInfo();

int client_count = 0;

typedef struct _client
{
	char name[10];
	int accountNum;
	int money;
}client;

client clientNum[10];

int main(void)
{
	menu();
}

void menu()
{
	int choice;
	while(1)
	{
		system("cls");
		printMenu();
		scanf("%d", &choice);
		if(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5)
		{
			switch(choice)
			{
			case 1:
				accountOpen();
				break;
			case 2:
				deposit();
				break;
			case 3:
				withdraw();
				break;
			case 4:
				allAccountInfo();
				break;
			case 5:
				exit(1);
				break;
			}
		}

	}

}

void printMenu()
{
	printf("-------Menu--------\n");
	printf("1. ���°���\n");
	printf("2. �� ��\n");
	printf("3. �� ��\n");
	printf("4. �������� ��ü ���\n");
	printf("5. ���α׷� ����\n");
}

void accountOpen()
{
	if(client_count == 10)
	{
		printf("���ο� ���¸� ���� �� �����ϴ�.\n");
	}
	else
	{
		printf("���� ���� ������ ��ȣ�� �Է��ϼ���.\n");
		scanf("%d", &clientNum[client_count].accountNum);
		printf("�̸��� �Է��ϼ���.\n");
		scanf("%s", &clientNum[client_count].name);
		printf("���� �ݾ��� �Է��ϼ���. (������ ������ �����ø� 0�� �Է��ϼ���.)\n");
		scanf("%d", &clientNum[client_count].money);
		printf("%s���� �����Ͻ� ������ ��ȣ�� %d�̸�, ���� ��ġ���� %d�� �Դϴ�.", clientNum[client_count].name, clientNum[client_count].accountNum,
			clientNum[client_count].money);
		client_count++;
	}
	getchar();
	getchar();
}

void deposit()
{
	int accNum, i, deposit;
	printf("���� �� ���¹�ȣ�� �Է��ϼ���\n");
	scanf("%d", &accNum);
	for(i = 0; i < 10; i++)
	{
		if(clientNum[i].accountNum == accNum)
		{
			printf("%s���� ���¿� �Ա��Ͻ� �ݾ��� �Է��ϼ���\n", clientNum[i].name);
			scanf("%d", &deposit);
			clientNum[i].money += deposit;
			printf("%s���� ���¿� %d���� �ԱݵǾ� %d���� �ֽ��ϴ�.\n", clientNum[i].name, deposit, clientNum[i].money);
			break;
		}
		else
		{
			printf("%d�� ���¹�ȣ�� �������� �ʴ� ��ȣ�Դϴ�.\n", accNum);
		}
	}
	getchar();
	getchar();
}

void withdraw()
{
	int accNum, i, withdraw;
	printf("��� �� ���¹�ȣ�� �Է��ϼ���\n");
	scanf("%d", &accNum);
	for(i = 0; i < 10; i++)
	{
		if(clientNum[i].accountNum == accNum)
		{
			printf("%s���� ���¿� ����Ͻ� �ݾ��� �Է��ϼ���\n", clientNum[i].name);
			scanf("%d", &withdraw);
			clientNum[i].money -= withdraw;
			printf("%s���� ���¿� %d���� ��ݵǾ� %d���� �ֽ��ϴ�.\n", clientNum[i].name, withdraw, clientNum[i].money);
			break;
		}
		else
		{
			printf("%d�� ���¹�ȣ�� �������� �ʴ� ��ȣ�Դϴ�.\n", accNum);
		}
	}
	getchar();
	getchar();
}

void allAccountInfo()
{
	int i;
	for(i = 0; i < client_count; i++)
	{
		printf("-----------��� ������ ����------------\n");
		printf("���¹�ȣ : %d\n", clientNum[i].accountNum);
		printf("�����̸� : %s\n", clientNum[i].name);
		printf("�����ܾ� : %d\n", clientNum[i].money);
	}
	getchar();
	getchar();
}