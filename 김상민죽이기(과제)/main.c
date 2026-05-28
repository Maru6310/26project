#include <stdio.h>
#include <Windows.h>
#include <locale.h>
#include <conio.h>

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

// --- 그래픽 및 화면 제어 함수 ---

void set_color(int code)
{
	printf("\x1b[%dm", code);
}

int move_cursor(int x, int y)
{
	printf("\033[%d;%dH", y, x);
	return 0;
}

void print_colored_map(const wchar_t* map) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	WORD redText = FOREGROUND_RED | FOREGROUND_INTENSITY;
	WORD blackText = 0;
	WORD originalColor = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;

	for (int i = 0; map[i] != L'\0'; i++) {
		if (map[i] == L'□') {
			SetConsoleTextAttribute(hConsole, blackText);
			wprintf(L"□");
		}
		else if (map[i] == L'■') {
			SetConsoleTextAttribute(hConsole, redText);
			wprintf(L"■");
		}
		else {
			SetConsoleTextAttribute(hConsole, originalColor);
			wprintf(L"%c", map[i]);
		}
	}
	SetConsoleTextAttribute(hConsole, originalColor);
}

// 타이틀 대형 로고 출력
void draw_title_logo()
{
	move_cursor(40, 5);  print_colored_map(L"□■■■■■■□□□■□□□□■■□□□□■□□□□■■■■■■□□□■□□□□□■■■■■■■■■■□□□□□■■□□□□□■□□□□□□□□□□□□■\n");
	move_cursor(40, 6);  print_colored_map(L"□□□□□■■□□□■□□□□■■□□□□■□□□□■■■■■■□□□■□□□□□□□□□■■□□□□□□□■■■■■■□□□■□□□■■■■■■□□□■\n");
	move_cursor(40, 7);  print_colored_map(L"□□□□□■■□□□■□□□□■■□□□□■□□□□■□□□□■□□□■□□□□□□□□■■■■■□□□□□■■□□■■□□□■□□□□□□□□■□□□■\n");
	move_cursor(40, 8);  print_colored_map(L"□□□□■■□□□□■□□□□■■■□□□■■■□□■□□□□■□□□■□□□□□■■■■■□■■■■□□□■□□□□■□□□■□□□□□□□■■□□□■\n");
	move_cursor(40, 9);  print_colored_map(L"□□□■■□□□□□■□□□■■■■■□□■□□□□■□□□□■□□□■□□□□□■■□□□□□□□■□□□■□□□□■□□□■□□□□□□□■■□□□■\n");
	move_cursor(40, 10); print_colored_map(L"□□■■□□□□□□■□□■■□□■■■□■□□□□■■■■■■□□□■□□□□■■■■■■■■■■■■□□■□□□□■□□□■□□□□□□□■■□□□■\n");
	move_cursor(40, 11); print_colored_map(L"□■■□□□□□□□■□■■□□□□□□□■□□□□■■■■■■□□□■□□□□□□□□□■■□□□□□□□■■□□□■□□□■□□□□□□■■□□□□■\n");
	move_cursor(40, 12); print_colored_map(L"□□□■■■■■■■■□□□□■■■■■■■□□□□□□■□□□□□□■□□□□□□□□□■■□□□□□□□■■□□■■□□□■□□□□□■■□□□□□■\n");
	move_cursor(40, 13); print_colored_map(L"□□□■□□□□□□■□□□□■■□□□■■□□□□□□■□□□□□□■□□□□□■■■■■■■■■■□□□□■■■■□□□□■□□□□■■□□□□□□■\n");
	move_cursor(40, 14); print_colored_map(L"□□□■□□□□□□■□□□□■□□□□□■□□□□□□■□□□□□□□□□□□□□□□□□□□□■■□□□□□□□□□□□□■□□□■□□□□□□□□■\n");
	move_cursor(40, 15); print_colored_map(L"□□□■□□□□□□■□□□□■■□□□■■□□□□□□■□□□□□□□□□□□□□□□□□□□□■■□□□□□□□□□□□□■□□□□□□□□□□□□■\n");
	move_cursor(40, 16); print_colored_map(L"□□□■■■■■■■■□□□□■■■■■■■□□□□□□■■■■■■■■□□□□□□□□□□□□□■■□□□□□□□□□□□□■□□□□□□□□□□□□■\n");
}


// --- 각 메뉴 화면 함수 (서브 모듈) ---

// [메뉴 3] 만든이 정보 화면
void show_maker_info()
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

// [메뉴 2] 게임 설명 화면 (페이지 전환 포함)
void show_game_desc()
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

			// 내용 영역 초기화
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
			if (key == 75) // 왼쪽 화살표
			{
				if (page > 1) { page--; needRedraw = 1; }
			}
			else if (key == 77) // 오른쪽 화살표
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

// [메뉴 1] 인트로 연출 및 전투 시스템 함수
// [메뉴 1] 인트로 연출 및 전투 시스템 함수
// [메뉴 1] 인트로 연출 및 전투 시스템 함수
// [메뉴 1] 인트로 연출 및 전투 시스템 함수
// [메뉴 1] 인트로 연출 및 전투 시스템 함수
void start_battle()
{
	// 난수 초기화 (확률 시스템용)
	srand((unsigned int)time(NULL));

	system("cls");

	// 인트로 연출
	set_color(FONT_COLOR_RED);
	move_cursor(72, 15); printf("괴"); Sleep(500);
	move_cursor(74, 15); printf("물"); Sleep(1000);
	move_cursor(77, 15); printf("김"); Sleep(500);
	move_cursor(79, 15); printf("상"); Sleep(500);
	move_cursor(81, 15); printf("민"); Sleep(1000);

	// 전투 시스템 변수 초기화
	int bossHP = 200;
	int playerHP = 100;
	int battleMenu = 1;
	int battleRunning = 1;
	int isFled = 0;

	while (battleRunning)
	{
		printf(COLOR_RESET);
		system("cls");

		// 1. 보스 체력 표시
		move_cursor(115, 5);
		set_color(FONT_COLOR_RED);
		printf("[BOSS] 김상민 선배  HP: %d / 200", bossHP);
		move_cursor(115, 6);
		printf("체력: ");
		for (int i = 0; i < bossHP / 20; i++) printf("■");
		for (int i = 0; i < (200 - bossHP) / 20; i++) printf("  ");

		// 2. 플레이어 체력 표시
		move_cursor(5, 22);
		set_color(FONT_COLOR_GREEN);
		printf("[PLAYER] 김민성     HP: %d / 100", playerHP);
		move_cursor(5, 23);
		printf("체력: ");
		for (int i = 0; i < playerHP / 10; i++) printf("■");
		for (int i = 0; i < (100 - playerHP) / 10; i++) printf("  ");

		// 3. 전투 결과 판정 (턴 시작 시 체크)
		if (bossHP <= 0)
		{
			system("cls");
			move_cursor(50, 14);
			set_color(FONT_COLOR_BRIGHTYELLOW);
			printf("★ 승리! ★ 보스를 물리쳤습니다!");
			move_cursor(50, 16);
			set_color(FONT_COLOR_GREEN);
			printf("단계동에서 동기들과 즐거운 술자리를 가집니다! 🍻");
			move_cursor(50, 20);
			set_color(FONT_COLOR_WHITE);
			printf("아무 키나 누르면 메뉴로 돌아갑니다.");
			_getch();
			battleRunning = 0;
			break;
		}
		if (playerHP <= 0)
		{
			system("cls");
			move_cursor(50, 14);
			set_color(FONT_COLOR_RED);

			if (isFled) printf("🏃 도망치기에 실패했습니다! 🏃");
			else        printf("💀 패배... 💀 체력이 다했습니다.");

			move_cursor(50, 16);
			printf("헬스장으로 끌려가 고강도 웨이트 고문을 당합니다... 💪");
			move_cursor(50, 20);
			set_color(FONT_COLOR_WHITE);
			printf("아무 키나 누르면 메뉴로 돌아갑니다.");
			_getch();
			battleRunning = 0;
			break;
		}

		// 4. 행동 선택 메뉴 출력
		move_cursor(68, 26);
		set_color(FONT_COLOR_WHITE);
		printf("행동을 선택하세요:");

		if (battleMenu == 1) set_color(BG_COLOR_YELLOW), set_color(FONT_COLOR_BLACK);
		else set_color(BG_COLOR_BLACK), set_color(FONT_COLOR_WHITE);
		move_cursor(63, 28); printf(" 1. 공격하기 ");

		if (battleMenu == 2) set_color(BG_COLOR_YELLOW), set_color(FONT_COLOR_BLACK);
		else set_color(BG_COLOR_BLACK), set_color(FONT_COLOR_WHITE);
		move_cursor(78, 28); printf(" 2. 도망가기 ");

		printf(COLOR_RESET);

		// 5. 키 입력 처리
		int battleKey = _getch();
		if (battleKey == 224 || battleKey == 0)
		{
			battleKey = _getch();
			if (battleKey == 75)      battleMenu = 1;
			else if (battleKey == 77) battleMenu = 2;
		}
		else if (battleKey == 13) // 엔터 입력 시 실행
		{
			if (battleMenu == 1)
			{
				int rate = rand() % 100;

				// --- [STAGE 1] 플레이어의 선제 공격 턴 ---
				move_cursor(20, 16);
				set_color(FONT_COLOR_BRIGHTYELLOW);

				if (rate < 60) { // 60%
					printf("-> [성공 60%%] 주먹으로 강력하게 타격! (보스 HP -20)");
					bossHP -= 20;
				}
				else if (rate < 75) { // 15%
					printf("-> [성공 15%%] 바닥에 있는 돌을 들고 머리 가격! (보스 HP -25)");
					bossHP -= 25;
				}
				else if (rate < 90) { // 15% (로우킥 자해)
					set_color(FONT_COLOR_RED);
					printf("-> [실패 15%%] 김상민에게 로우킥을 날렸으나 다리가 단단해 내 다리가 다침! (플레이어 HP -10)");
					playerHP -= 10;
				}
				else if (rate < 95) { // 5%
					printf("-> [성공 5%%] 바닥의 모래를 눈에 뿌리고 기습 공격! (보스 HP -25)");
					bossHP -= 25;
				}
				else { // 5%
					printf("-> [성공 5%%] 킥보드로 도망치는 척 교란 후 핸들을 틀어 박치기! (보스 HP -30)");
					bossHP -= 30;
				}

				// 플레이어가 보스 체력을 깎았으므로 상단 보스 체력바 실시간 리프레시
				move_cursor(115, 5);
				set_color(FONT_COLOR_RED);
				printf("[BOSS] 김상민 선배  HP: %d / 200  ", bossHP >= 0 ? bossHP : 0);
				move_cursor(115, 6);
				printf("체력: ");
				for (int i = 0; i < (bossHP > 0 ? bossHP : 0) / 20; i++) printf("■");
				for (int i = 0; i < (200 - (bossHP > 0 ? bossHP : 0)) / 20; i++) printf("  ");

				// 플레이어 공격 후 연출을 위해 1.2초 대기
				Sleep(1200);

				// --- [STAGE 2] 보스의 반격 턴 ---
				// 보스가 살아있고, 내가 로우킥 자해를 한 상황이 아니라면 반격 개시
				if (bossHP > 0 && rate != (rate >= 75 && rate < 90 ? rate : -1))
				{
					// (정확히 rate가 75~89 사이가 아닐 때만 반격하도록 조건 설정)
					if (!(rate >= 75 && rate < 90))
					{
						move_cursor(20, 18);
						set_color(FONT_COLOR_RED);
						printf("-> [반격] 김상민 선배의 고강도 리프팅 공격! (플레이어 HP -10)");
						playerHP -= 10;

						// 하단 플레이어 체력바 실시간 리프레시
						move_cursor(5, 22);
						set_color(FONT_COLOR_GREEN);
						printf("[PLAYER] 김민성     HP: %d / 100  ", playerHP >= 0 ? playerHP : 0);
						move_cursor(5, 23);
						printf("체력: ");
						for (int i = 0; i < (playerHP > 0 ? playerHP : 0) / 10; i++) printf("■");
						for (int i = 0; i < (100 - (playerHP > 0 ? playerHP : 0)) / 10; i++) printf("  ");

						
						_getch();
					}
				}
			}
			else if (battleMenu == 2)
			{
				isFled = 1;
				playerHP = 0;
			}
		}
	}
	printf(COLOR_RESET);
	system("cls");
}

// --- 메인 함수 (전체 흐름 관리) ---

int main()
{
	int posY = 1;
	char input = 0;
	int isRunning = 1;

	// 로케일 설정 및 초기 화면 초기화 (커서 숨기기)
	setlocale(LC_ALL, "");
	printf("\033[2J\033[?25l");

	while (isRunning)
	{
		move_cursor(40, 1);
		set_color(BG_COLOR_BLACK);
		set_color(FONT_COLOR_RED);

		// 상단 큰 타이틀 맵 그리기
		draw_title_logo();

		// 기본 메뉴 UI 출력
		set_color(BG_COLOR_BLACK);
		set_color(FONT_COLOR_WHITE);
		move_cursor(70, 24); printf(" 1.  게임 시작  ");
		move_cursor(70, 26); printf(" 2.  게임 설명  ");
		move_cursor(70, 28); printf(" 3.  만든이      ");
		move_cursor(70, 30); printf(" 4.  게임 종료  ");

		// 현재 선택된 메뉴 하이라이트 효과 적용
		set_color(BG_COLOR_YELLOW);
		set_color(FONT_COLOR_BLACK);

		if (posY == 1) { move_cursor(70, 24); printf(" 1.  게임 시작  "); }
		else if (posY == 2) { move_cursor(70, 26); printf(" 2.  게임 설명  "); }
		else if (posY == 3) { move_cursor(70, 28); printf(" 3.  만든이      "); }
		else if (posY == 4) { move_cursor(70, 30); printf(" 4.  게임 종료  "); }

		printf(COLOR_RESET);

		// 사용자 키 입력 처리 (메인 메뉴)
		input = _getch();

		if (input == 72) // 위쪽 화살표
		{
			if (posY == 4)      posY = 3;
			else if (posY == 3) posY = 2;
			else if (posY == 2) posY = 1;
			else if (posY == 1) posY = 4;
		}
		if (input == 80) // 아래쪽 화살표
		{
			if (posY == 1)      posY = 2;
			else if (posY == 2) posY = 3;
			else if (posY == 3) posY = 4;
			else if (posY == 4) posY = 1;
		}
		if (input == 13) // Enter 키
		{
			if (posY == 4)
			{
				isRunning = 0; // 종료
			}
			else if (posY == 3)
			{
				show_maker_info(); // 만든이 정보 호출
			}
			else if (posY == 2)
			{
				show_game_desc(); // 게임 설명 호출
			}
			else if (posY == 1)
			{
				start_battle(); // 게임 시작 호출
			}
		}
	}

	// 게임 완전 종료 전 화면 리셋
	set_color(0);
	system("cls");

	return 0;
}
