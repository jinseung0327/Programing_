#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct Person
{
	char name[14];
	char league[14];
	unsigned short int age;
	unsigned int goal;
	float height;
	float weight;
}SoccerPlayer;
int AddPlayer(Person* p_player, int count)
{
	if (count < 5)
	{
		p_player = p_player + count;
		printf("\n새로운 선수 정보를 입력하세요\n");
		printf("1. 리그 : ");
		scanf("%s", p_player->league);
		printf("2. 이름 : ");
		scanf("%s", p_player->name);
		printf("3. 나이 : ");
		scanf("%hu", &p_player->age);
		printf("4. 키 : ");
		scanf("%f", &p_player->height);
		printf("5. 몸무게 : ");
		scanf("%f", &p_player->weight);
		printf("6. 골 횟수 : ");
		scanf("%d", &p_player->goal);
		printf("입력을 완료했습니다.\n\n");
		return 1;
	}
	else
	{
		printf("최대 인원을 초과하여 입력을 할 수 없습니다. \n");
		printf("최대 %d명까지만 관리 가능합니다. \n\n", 5);
	}
	return 0;
}
int ShowPlayerList(Person* p_player, int count)
{
	int i;
	if (count > 0)
	{
		printf("\n등록된 선수 스택\n");
		printf("=================================================\n");
		for (i = 0; i < count; i++)
		{
			printf("리그 : %s\n 이름 : %-6s\n 나이 : %3d\n 키 : %6.2f\n 몸무게 : %6.2f\n 골 횟수 : %d\n", p_player->league, p_player->name, p_player->age, p_player->height, p_player->weight, p_player->goal);
			p_player++;
		}
		printf("=================================================\n\n");
	}
	else
	{
		printf("\n등록된 선수가 없습니다.\n\n");
	}
	return 1;
}

int main()
{
	Person player[5];
	int count = 0, num;

	while (1)
	{
		printf("	[메뉴]		\n");
		printf("1. 선수추가			\n");
		printf("2. 선수 스택 보기 \n");
		printf("3. 종료				\n");
		printf("=================================================\n");
		printf("번호 선택 : ");
		scanf("%d", &num);
		if (num == 1)
		{
			if (1 == AddPlayer(player, count))count++;
		}
		else if (num == 2)
		{
			ShowPlayerList(player, count);
		}
		else if (num == 3)
		{
			break;
		}
		else
		{
			printf("1~3 번호만 선택할 수 있습니다\n\n");
		}
	}
}
