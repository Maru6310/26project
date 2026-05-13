#include <stdio.h>
#include <Windows.h>

#define COLOR_RESET "\x1b[0m"
#define KEY_ESC 27
#define FONT_COLOR_BLACK 30
#define BG_COLOR_BLACK 40
#define FONT_COLOR_RED 31
#define BG_COLOR_RED 41
#define FONT_COLOR_GREEN 32
#define BG_COLOR_GREEN 42
#define BG_COLOR_YELLOW 43
#define FONT_COLOR_BLUE 34
#define BG_COLOR_BLUE 44
#define FONT_COLOR_MAGENTA 35
#define BG_COLOR_MAGENTA 45
#define FONT_COLOR_BRIGHTMAGENTA 95
#define BG_COLOR_BRIGHTMAGENTA 105
#define FONT_COLOR_WHITE 37
#define BG_COLOR_WHITE 47
#define FONT_COLOR_BRIGHTYELLOW 93


	void set_color(int code)
{
	printf("\x1b[%dm", code);
}

int move_cursor(int x, int y)
{
	printf("\033[%d;%dH", y, x);
	return 0;
}

int main()
{
	int posY = 1;
	char input = 0;
	int isRunning = 1;

	while (isRunning)
	{
		move_cursor(40, 1);
		set_color(BG_COLOR_BLACK);
		set_color(FONT_COLOR_RED);
		move_cursor(40, 5);
		printf("□■■■■■■□□□■□□□□■■□□□□■□□□■■■■■■□□□■□□□□□■■■■■■■■■■□□□□□■■□□□□□■□□□□□□□□□□□□■\n");
		move_cursor(40, 6);
		printf("□□□□□■■□□□■□□□□■■□□□□■□□□■■■■■■□□□■□□□□□□□□□■■□□□□□□□■■■■■■□□□■□□□■■■■■■□□□■\n");
		move_cursor(40, 7);
		printf("□□□□□■■□□□■□□□□■■□□□□■□□□■□□□□■□□□■□□□□□□□□■■■■■□□□□□■■□□■■□□□■□□□□□□□□■□□□■\n");
		move_cursor(40, 8);
		printf("□□□□■■□□□□■□□□□■■■□□□■■■□■□□□□■□□□■□□□□□■■■■■□■■■■□□□■□□□□■□□□■□□□□□□□■■□□□■\n");
		move_cursor(40, 9);
		printf("□□□■■□□□□□■□□□■■■■■□□■□□□■□□□□■□□□■□□□□□■■□□□□□□□■□□□■□□□□■□□□■□□□□□□□■■□□□■\n");
		move_cursor(40, 10);
		printf("□□■■□□□□□□■□□■■□□■■■□■□□□■■■■■■□□□■□□□□■■■■■■■■■■■■□□■□□□□■□□□■□□□□□□□■■□□□■\n");
		move_cursor(40, 11);
		printf("□■■□□□□□□□■□■■□□□□□□□■□□□■■■■■■□□□■□□□□□□□□□■■□□□□□□□■■□□□■□□□■□□□□□□■■□□□□■\n");
		move_cursor(40, 12);
		printf("□□□■■■■■■■■□□□□■■■■■■■□□□□□■□□□□□□■□□□□□□□□□■■□□□□□□□■■□□■■□□□■□□□□□■■□□□□□■\n");
		move_cursor(40, 13);
		printf("□□□■□□□□□□■□□□□■■□□□■■□□□□□■□□□□□□■□□□□□■■■■■■■■■■□□□□■■■■□□□□■□□□□■■□□□□□□■\n");
		move_cursor(40, 14);
		printf("□□□■□□□□□□■□□□□■□□□□□■□□□□□■□□□□□□□□□□□□□□□□□□□□■■□□□□□□□□□□□□■□□□■□□□□□□□□■\n");
		move_cursor(40, 15);
		printf("□□□■□□□□□□■□□□□■■□□□■■□□□□□■□□□□□□□□□□□□□□□□□□□□■■□□□□□□□□□□□□■□□□□□□□□□□□□■\n");
		move_cursor(40, 16);
		printf("□□□■■■■■■■■□□□□■■■■■■■□□□□□■■■■■■■■□□□□□□□□□□□□□■■□□□□□□□□□□□□■□□□□□□□□□□□□■\n");
		

		set_color(BG_COLOR_BLACK);
		set_color(FONT_COLOR_WHITE);
		move_cursor(70, 24);
		printf(" 1.  게임 시작  ");
		move_cursor(70, 26);
		printf(" 2.  게임 설명  ");
		move_cursor(70, 28);
		printf(" 3.  만든이     ");
		move_cursor(70, 30);
		printf(" 4.  게임 종료  ");

		set_color(BG_COLOR_YELLOW);
		set_color(FONT_COLOR_BLACK);

		if (posY == 1) 
		{
			move_cursor(70, 24);
			printf(" 1.  게임 시작  ");
		}
		else if (posY == 2) 
		{
			move_cursor(70, 26);
			printf(" 2.  게임 설명  ");
		}
		else if (posY == 3) 
		{
			move_cursor(70, 28);
			printf(" 3.  만든이     ");
		}
		else if (posY == 4)
		{
			move_cursor(70, 30);
			printf(" 4.  게임 종료  ");
		}

		printf(COLOR_RESET);
		
		input = _getch();

		if (input == 72)
		{
			if (posY == 4)      posY = 3;
			else if (posY == 3) posY = 2;
			else if (posY == 2) posY = 1;
			else if (posY == 1) posY = 4;
		}
		if (input == 80)
		{
			if (posY == 1)      posY = 2;
			else if (posY == 2) posY = 3;
			else if (posY == 3) posY = 4;
			else if (posY == 4) posY = 1;
		}
		if (input == 13)
		{
			if (posY == 4)
			{
				isRunning = 0;
			}
			else if (posY == 3)
			{
				system("cls"); 
				move_cursor(72, 8);
				set_color(FONT_COLOR_BRIGHTMAGENTA);
				printf("[ 만든이 정보 ]");

				move_cursor(68, 12);
				set_color(FONT_COLOR_WHITE);
				printf(" 기획 김민성 202618128 ");
				set_color(FONT_COLOR_BRIGHTYELLOW);
				move_cursor(60, 13);
				printf(" 게임 아이디어, 규칙 설계, 전체 진행 구성 ");

				move_cursor(67, 16);
				set_color(FONT_COLOR_WHITE);
				printf(" 디자인 김성회 202618654 ");
				set_color(FONT_COLOR_BRIGHTYELLOW);
				move_cursor(59, 17);
				printf(" 캐릭터, 배경, 메뉴 화면, 인터페이스 디자인 ");

				move_cursor(62, 20);
				set_color(FONT_COLOR_WHITE);
				printf(" 테스트 및 디버깅 박영찬 202618543 ");
				set_color(FONT_COLOR_BRIGHTYELLOW);
				move_cursor(61, 21);
				printf(" 오류 찾기, 플레이 테스트, 밸런스 확인 ");

				move_cursor(68, 24);
				set_color(FONT_COLOR_WHITE);
				printf(" 개발 이원재 202617919 ");
				set_color(FONT_COLOR_BRIGHTYELLOW);
				move_cursor(60, 25);
				printf(" C언어 코드 작성, 기능 구현, 시스템 제작 ");

				move_cursor(61, 28);
				set_color(FONT_COLOR_GREEN);
				printf("메뉴로 돌아가려면 아무 키나 누르세요...");

				_getch(); 
				system("cls"); 
			}
			else if (posY == 2)
			{
				int page = 1;      
				int inRunning = 1;
				int needRedraw = 1;

				system("cls"); 

				while (inRunning)
				{
					if (needRedraw)
					{
						move_cursor(1, 1);

						move_cursor(70, 5);
						set_color(FONT_COLOR_BRIGHTMAGENTA);
						printf("[ 게임 설명  %d / 2 ]          ", page); 

						for (int i = 10; i < 25; i++) {
							move_cursor(50, i);
							printf("                                                                  ");
						}

						if (page == 1)
						{
							move_cursor(72, 10);
							set_color(FONT_COLOR_BRIGHTYELLOW);
							printf("■ 캐릭터 설정 ■");
							move_cursor(55, 13);
							set_color(FONT_COLOR_WHITE);
							printf("보스: AI콘텐츠공학과 헬창선배 김상민 (HP 100)");
							move_cursor(55, 15);
							printf("플레이어: 헬창 호소인 김민성 (HP 100)");
							move_cursor(55, 20);
							set_color(FONT_COLOR_GREEN);
							printf("헬스 하자며 붙잡는 보스에게서 도망가기 위한 턴제 게임입니다.");
							move_cursor(55, 22);
							printf("플레이어는 매 턴마다 두 가지 선택지를 고릅니다.");
						}
						else if (page == 2)
						{
							move_cursor(73, 10);
							set_color(FONT_COLOR_BRIGHTYELLOW);
							printf("■ 게임 규칙 ■");
							move_cursor(55, 13);
							set_color(FONT_COLOR_WHITE);
							printf("1. 공격하기: 보스 HP -10 / 반격 시 플레이어 HP -20");
							move_cursor(55, 15);
							printf("2. 도망가기: 즉시 패배 (게임 종료)");
							move_cursor(55, 19);
							set_color(FONT_COLOR_GREEN);
							printf("[승리] 보스 HP 0: 단계동에서 동기들과 즐거운 술자리!");
							move_cursor(55, 21);
							set_color(FONT_COLOR_RED);
							printf("[패배] 내 HP 0: 헬스장으로 끌려가 고강도 웨이트 고문...");
						}

						move_cursor(68, 28);
						set_color(FONT_COLOR_WHITE);
						printf("<- (왼쪽)  |  (오른쪽) ->");
						move_cursor(60, 30);
						printf("메뉴로 돌아가려면 아무키나 누르세요...");

						needRedraw = 0; 
					}

					int key = _getch();

					if (key == 224 || key == 0)
					{
						key = _getch();
						if (key == 75) 
						{
							if (page > 1) { page--; needRedraw = 1; }
						}
						else if (key == 77) 
						{
							if (page < 2) { page++; needRedraw = 1; }
						}
					}
					else 
					{
						inRunning = 0;
					}
				}
				system("cls");
			}
			else if (posY == 1)
			{
				system("cls");

				move_cursor(68, 20);
				printf("괴");
				Sleep(700);
				move_cursor(70, 20);
				printf("물");
				Sleep(1500);
				move_cursor(73, 20);
				printf("김");
				Sleep(700);
				move_cursor(75, 20);
				printf("상");
				Sleep(700);
				move_cursor(77, 20);
				printf("민");

				_getch();
				system("cls");
			}
		}
	}
	set_color (0);
	system("cls");

	return 0;
} 
