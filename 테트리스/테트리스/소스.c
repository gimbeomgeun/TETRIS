#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define AREA_ROW 20 
#define AREA_COL 10
#define BLOCK_ROW 4
#define BLOCK_COL 4


char area[AREA_ROW + 1][AREA_COL + 2];

char block1[BLOCK_ROW][BLOCK_COL] = {
	{'1','0','0','0'},
	{'1','0','0','0'},
	{'1','0','0','0'},
	{'1','0','0','0'},
};
char block2[BLOCK_ROW][BLOCK_COL] = {
	{'1','1','0','0'},
	{'1','1','0','0'},
	{'0','0','0','0'},
	{'0','0','0','0'},
};
char block3[BLOCK_ROW][BLOCK_COL] = {
	{'1','1','0','0'},
	{'0','1','1','0'},
	{'0','0','0','0'},
	{'0','0','0','0'},
};
char block4[BLOCK_ROW][BLOCK_COL] = {
	{'0','1','1','0'},
	{'1','1','0','0'},
	{'0','0','0','0'},
	{'0','0','0','0'},
};
char block5[BLOCK_ROW][BLOCK_COL] = {
	{'0','1','0','0'},
	{'0','1','0','0'},
	{'1','1','0','0'},
	{'0','0','0','0'},
};
char block6[BLOCK_ROW][BLOCK_COL] = {
	{'1','0','0','0'},
	{'1','0','0','0'},
	{'1','1','0','0'},
	{'0','0','0','0'},
};
char block7[BLOCK_ROW][BLOCK_COL] = {
	{'1','1','1','0'},
	{'0','1','0','0'},
	{'0','0','0','0'},
	{'0','0','0','0'},
};

char block_rotation();		//블록 회전
char is_crash();			//충돌판별
char is_FullLine();		//한줄완성판별
char block_down();		//블록내리기
char left();		//왼쪽이동
char right();		//오른쪽이동
char input();		//사용자입력
char print();
char create_block();		//랜덤으로 블록생성
char print_block(int r);		//화면에 블록생성
char print_area();		//화면출력


char print_area()
{
	printf("\n\n\n\n");
	for (int i = 0; i < AREA_ROW; i++)
	{
		for (int j = 1; j < AREA_COL + 1; j++)
		{
			printf("%c", area[i][j]);
		}
		printf("\n");
	}
}

char create_area()
{
	for (int i = 0; i < AREA_ROW + 1;i++)
	{
		for (int j = 0; j < AREA_COL + 2; j++)
		{
			if (j == 0 || j == AREA_COL+1)		//양옆 맨 끝 9로설정
			{
				area[i][j] = '9';
			}
			else if (i == AREA_ROW)		//맨 밑 1로설정 - 충돌판정
			{
				area[i][j] = '1';
			}
			else		//나머지 0
			{
				area[i][j] = '0';
			}
		}
	}


	print_area();
}
char create_block()
{
	int r = (rand() % 7)+1;
	return print_block(r);
}

char print_block(int r)
{
	if (r == 1)
	{
		for (int i = 0; i < BLOCK_ROW; i++)
		{
			for (int j = 0; j < BLOCK_COL; j++)
			{
				area[i][j + 4] = block1[i][j];
			}
		}
	}
	else if (r == 2)
	{
		for (int i = 0; i < BLOCK_ROW; i++)
		{
			for (int j = 0; j < BLOCK_COL; j++)
			{
				area[i][j + 4] = block2[i][j];
			}
		}
	}
	else if (r == 3)
	{
		for (int i = 0; i < BLOCK_ROW; i++)
		{
			for (int j = 0; j < BLOCK_COL; j++)
			{
				area[i][j + 4] = block3[i][j];
			}
		}
	}
	else if (r == 4)
	{
		for (int i = 0; i < BLOCK_ROW; i++)
		{
			for (int j = 0; j < BLOCK_COL; j++)
			{
				area[i][j + 4] = block4[i][j];
			}
		}
	}
	else if (r == 5)
	{
		for (int i = 0; i < BLOCK_ROW; i++)
		{
			for (int j = 0; j < BLOCK_COL; j++)
			{
				area[i][j + 4] = block5[i][j];
			}
		}
	}
	else if (r == 6)
	{
		for (int i = 0; i < BLOCK_ROW; i++)
		{
			for (int j = 0; j < BLOCK_COL; j++)
			{
				area[i][j + 4] = block6[i][j];
			}
		}
	}
	else if (r == 7)
	{
		for (int i = 0; i < BLOCK_ROW; i++)
		{
			for (int j = 0; j < BLOCK_COL; j++)
			{
				area[i][j + 4] = block7[i][j];
			}
		}
	}
	return print_area();
}
int main()
{
	srand(time(NULL));
	/*for (int i = 0; i < BLOCK_ROW; i++)
	{
		for (int j = 0; j < BLOCK_COL; j++)
		{
			printf("%c", block7[i][j]);
		}
		printf("\n");
	}*/
	create_area();
	create_block();
}