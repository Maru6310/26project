#include <stdio.h>
#include <Windows.h>
#include <locale.h>
#include <conio.h>
#include <time.h> // rand, time 함수용 헤더 추가

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
         printf("[ 게임 설명   %d / 2 ]          ", page);

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

// 보조 함수: 대기하면서 키 입력이 들어오면 즉시 1을 리턴(스킵 신호)
int sleep_or_skip(int ms)
{
   int interval = 50; // 50ms 단위로 쪼개서 체크
   int elapsed = 0;
   while (elapsed < ms)
   {
      if (_kbhit()) // 사용자가 아무 키나 눌렀다면
      {
         // 버퍼에 쌓인 키 값을 비워줌 (엔터 등)
         while (_kbhit()) _getch();
         return 1; // 스킵하라는 신호 반환
      }
      Sleep(interval);
      elapsed += interval;
   }
   return 0;
}

// [메뉴 1] 인트로 연출 및 전투 시스템 함수
void start_battle()
{
   // 난수 초기화 (확률 시스템용)
   srand((unsigned int)time(NULL));

   system("cls");

   int skipIntro = 0; // 스킵 플래그 변수

   // 인트로 연출 (괴물 김상민 등장)
   set_color(FONT_COLOR_RED);
   move_cursor(74, 15); printf("괴"); if (sleep_or_skip(500)) skipIntro = 1;
   if (!skipIntro) { move_cursor(76, 15); printf("물"); if (sleep_or_skip(1000)) skipIntro = 1; }
   if (!skipIntro) { move_cursor(79, 15); printf("김"); if (sleep_or_skip(500)) skipIntro = 1; }
   if (!skipIntro) { move_cursor(81, 15); printf("상"); if (sleep_or_skip(500)) skipIntro = 1; }
   if (!skipIntro) { move_cursor(83, 15); printf("민"); if (sleep_or_skip(1000)) skipIntro = 1; }

   // 2. 스토리 연출 (나레이션 및 대사)
   if (!skipIntro)
   {
      system("cls");
      set_color(FONT_COLOR_WHITE);

      move_cursor(62, 10);
      printf("오늘 동기들과 술자리가 있는 날..");
      if (sleep_or_skip(1500)) skipIntro = 1;
   }
   if (!skipIntro)
   {
      move_cursor(61, 12);
      printf("홍업사거리에서 김상민을 마주쳤다.");
      if (sleep_or_skip(2000)) skipIntro = 1;
   }
   if (!skipIntro)
   {
      move_cursor(60, 15);
      set_color(FONT_COLOR_RED);
      printf("김상민: \"민성아 어디가? 헬스장 가야지.\"");
      if (sleep_or_skip(2000)) skipIntro = 1;
   }
   if (!skipIntro)
   {
      move_cursor(46, 17);
      set_color(FONT_COLOR_GREEN);
      printf("김민성: \"오늘 술약속이 있어서 힘들 것 같습니다. 죄송합니다 선배님..\"");
      if (sleep_or_skip(2500)) skipIntro = 1;
   }
   if (!skipIntro)
   {
      move_cursor(60, 20);
      set_color(FONT_COLOR_RED);
      printf("김상민: \"? 그게 왜 헬스보다 중요해?\"");
      if (sleep_or_skip(2000)) skipIntro = 1;
   }
   if (!skipIntro)
   {
      move_cursor(58, 23);
      set_color(FONT_COLOR_WHITE);
      printf("아무래도 평범한 방법으로는 힘들 것 같다.");
      if (sleep_or_skip(1800)) skipIntro = 1;
   }
   if (!skipIntro)
   {
      move_cursor(68, 25);
      set_color(FONT_COLOR_BRIGHTYELLOW);
      printf("김상민을 죽여야겠다.");
      if (sleep_or_skip(1500)) skipIntro = 1;
   }

   if (!skipIntro)
   {
      move_cursor(61, 31);
      set_color(FONT_COLOR_GREEN);
      printf("-> 아무 키나 누르면 본 게임 시작.");
      _getch();
   }

   // 전투 시스템 변수 초기화
   int bossHP = 200;
   int playerHP = 100;
   int battleMenu = 1;
   int battleRunning = 1;
   int isFled = 0;
   int bossHealed = 0;

   // 가방 버프 관련 상태 변수
   int damageMultiplier = 1;
   int greenJuiceActive = 0;
   int moldJuiceActive = 0;

   while (battleRunning)
   {
      printf(COLOR_RESET);
      system("cls");

      // 1. 보스 체력 표시
      move_cursor(118, 3);
      set_color(FONT_COLOR_RED);
      printf("[BOSS] 김상민 선배   HP: %d / 200", bossHP >= 0 ? bossHP : 0);
      move_cursor(118, 4);
      printf("체력: ");
      for (int i = 0; i < (bossHP > 0 ? bossHP : 0) / 10; i++) printf("■");
      for (int i = 0; i < (200 - (bossHP > 0 ? bossHP : 0)) / 10; i++) printf("  ");

      move_cursor(5, 31);
      set_color(FONT_COLOR_GREEN);
      printf("[PLAYER] 김민성     HP: %d / 100", playerHP >= 0 ? playerHP : 0);

      move_cursor(5, 33);
      set_color(FONT_COLOR_GREEN);
      printf("체력: ");
      for (int i = 0; i < (playerHP > 0 ? playerHP : 0) / 10; i++) printf("■");
      for (int i = 0; i < (100 - (playerHP > 0 ? playerHP : 0)) / 10; i++) printf("  ");

      // 3. 전투 결과 판정
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

      if (damageMultiplier > 1)
      {
         move_cursor(5, 29); // 플레이어 체력 위쪽 안내
         set_color(FONT_COLOR_BRIGHTYELLOW);
         printf("다음 공격 데미지 %d배 증가!", damageMultiplier);
      }

      // 4. 행동 선택 메뉴 출력 (기존 33줄 -> 34줄로 한 칸 내림)
      move_cursor(69, 34);
      set_color(FONT_COLOR_WHITE);
      printf("행동을 선택하세요:");

      // 행동 종류 버튼 출력 (기존 37줄 -> 38줄로 한 칸 내림)
      if (battleMenu == 1) set_color(BG_COLOR_YELLOW), set_color(FONT_COLOR_BLACK);
      else set_color(BG_COLOR_BLACK), set_color(FONT_COLOR_WHITE);
      move_cursor(45, 38); printf(" 1. 공격하기 ");

      if (battleMenu == 2) set_color(BG_COLOR_YELLOW), set_color(FONT_COLOR_BLACK);
      else set_color(BG_COLOR_BLACK), set_color(FONT_COLOR_WHITE);
      move_cursor(62, 38); printf(" 2. 방어하기 ");

      if (battleMenu == 3) set_color(BG_COLOR_YELLOW), set_color(FONT_COLOR_BLACK);
      else set_color(BG_COLOR_BLACK), set_color(FONT_COLOR_WHITE);
      move_cursor(79, 38); printf(" 3. 회피하기 ");

      if (battleMenu == 4) set_color(BG_COLOR_YELLOW), set_color(FONT_COLOR_BLACK);
      else set_color(BG_COLOR_BLACK), set_color(FONT_COLOR_WHITE);
      move_cursor(96, 38); printf(" 4. 가방뒤지기 ");

      // 도망가기 버튼 출력 (기존 45줄 -> 46줄로 한 칸 내림)
      if (battleMenu == 5) set_color(BG_COLOR_RED), set_color(FONT_COLOR_WHITE);
      else set_color(BG_COLOR_BLACK), set_color(FONT_COLOR_MAGENTA);
      move_cursor(135, 46); printf(" 5. 도망가기... ");

      printf(COLOR_RESET);

      int battleKey = _getch();
      if (battleKey == 224 || battleKey == 0)
      {
         battleKey = _getch();
         if (battleKey == 75)
         {
            if (battleMenu == 1) battleMenu = 5;
            else battleMenu--;
         }
         else if (battleKey == 77)
         {
            if (battleMenu == 5) battleMenu = 1;
            else battleMenu++;
         }
      }
      else if (battleKey == 13) // 엔터 선택으로 턴 공방 시작
      {
         int skipBossTurn = 0;

         //이전 턴의 메시지 잔상 지우기 (24, 26, 28번 라인 청소)
         for (int row = 24; row <= 28; row++) {
            move_cursor(20, row);
            printf("                                                                                                                                                                                ");
         }

         // --- [STAGE 1] 플레이어 선택 행동 처리 (25층 -> 24층으로 이동) ---
         move_cursor(20, 24);

         if (battleMenu == 1) // 1. 공격하기
         {
            int rate = rand() % 100;
            set_color(FONT_COLOR_BRIGHTYELLOW);

            if (rate < 60) {
               int dmg = 20 * damageMultiplier;
               printf("-> [성공 60%%] 주먹으로 강력하게 타격! (보스 HP -%d)", dmg);
               bossHP -= dmg;
               if (damageMultiplier > 1) {
                  set_color(FONT_COLOR_RED);
                  printf(" (버프 적용!)");
               }
            }
            else if (rate < 75) {
               int dmg = 25 * damageMultiplier;
               printf("-> [성공 15%%] 바닥에 있는 돌을 들고 머리 가격! (보스 HP -%d)", dmg);
               bossHP -= dmg;
               if (damageMultiplier > 1) {
                  set_color(FONT_COLOR_RED);
                  printf(" (버프 적용!)");
               }
            }
            else if (rate < 90) {
               set_color(FONT_COLOR_RED);
               printf("-> [실패 15%%] 김상민에게 로우킥을 날렸으나 다리가 단단해 내 다리가 다침! (플레이어 HP -10)");
               playerHP -= 10;
               skipBossTurn = 1;
            }
            else if (rate < 95) {
               int dmg = 30 * damageMultiplier;
               printf("-> [성공 15%%] 바닥의 모래를 눈에 뿌리고 기습 공격! (보스 HP -%d)", dmg);
               bossHP -= dmg;
               if (damageMultiplier > 1) {
                  set_color(FONT_COLOR_RED);
                  printf(" (버프 적용!)");
               }
            }
            else {
               int dmg = 50 * damageMultiplier;
               printf("-> [성공 5%%] 킥보드로 도망치는 척 교란 후 핸들을 틀어 박치기! (보스 HP -%d)", dmg);
               bossHP -= dmg;
               if (damageMultiplier > 1) {
                  set_color(FONT_COLOR_RED);
                  printf(" (버프 적용!)");
               }
            }
            damageMultiplier = 1; // 공격을 마쳤으므로 버프 초기화
         }
         else if (battleMenu == 2) // 2. 방어하기
         {
            int defRate = rand() % 100;
            skipBossTurn = 1;

            if (defRate < 50) {
               set_color(FONT_COLOR_GREEN);
               printf("-> [방어 성공 50%%] 완벽한 타이밍으로 가드 성공! (플레이어 HP -0)");
            }
            else if (defRate < 65) {
               set_color(FONT_COLOR_BRIGHTYELLOW);
               printf("-> [방어 아쉬움 15%%] 가드했으나 아쉬운 타이밍으로 뚫렸습니다! (플레이어 HP -5)");
               playerHP -= 5;
            }
            else if (defRate < 80) {
               set_color(FONT_COLOR_RED);
               printf("-> [방어 파쇄 15%%] 완벽한 가드였으나 김상민이 후라이팬으로 가격했습니다! (플레이어 HP -5)");
               playerHP -= 5;
            }
            else {
               set_color(FONT_COLOR_RED);
               printf("-> [방어 실패 20%%] 허접한 타이밍으로 가드 아예 실패! (플레이어 HP -10)");
               playerHP -= 10;
            }
         }
         else if (battleMenu == 3) // 3. 회피하기
         {
            int evaRate = rand() % 100;

            if (evaRate < 20) {
               set_color(FONT_COLOR_BRIGHTYELLOW);
               printf("-> [회피 큰 성공 20%%] 날라오는 김상민의 주먹을 가볍게 피하고 카운터! (보스 HP -30)");
               bossHP -= 30;
               skipBossTurn = 1;
            }
            else if (evaRate < 50) {
               set_color(FONT_COLOR_GREEN);
               printf("-> [회피 성공 30%%] 김상민의 주먹을 아슬아슬하게 흘렸습니다! (데미지 없음)");
               skipBossTurn = 1;
            }
            else {
               set_color(FONT_COLOR_RED);
               printf("-> [회피 실패 50%%] 보스가 날리는 주먹에 심리전 실패로 얼굴 가격당함! (보스 턴 진행)");
               skipBossTurn = 0;
            }
         }
         else if (battleMenu == 4) // 4. 가방뒤지기
         {
            int bagRate = rand() % 100;

            if (bagRate < 15) {
               set_color(FONT_COLOR_BRIGHTYELLOW);
               printf("-> [가방 뒤지기 15%%] 이은석 교수님의 3년전 구매한 만년필 획득! (다음 공격력 2배!)");
               damageMultiplier = 2;
            }
            else if (bagRate < 25) {
               set_color(FONT_COLOR_BRIGHTYELLOW);
               printf("-> [가방 뒤지기 10%%] 이은석 교수님의 10년전 중고 구매한 다 낡아버린 모니터 획득! (다음 공격력 3배!)");
               damageMultiplier = 3;
            }
            else if (bagRate < 40) {
               set_color(FONT_COLOR_GREEN);
               printf("-> [가방 뒤지기 15%%] 이은석 교수님의 건강영양제 획득! (즉시 HP + 10)");
               playerHP += 10; if (playerHP > 100) playerHP = 100;
            }
            else if (bagRate < 50) {
               set_color(FONT_COLOR_GREEN);
               printf("-> [가방 뒤지기 10%%] 이은석 교수님의 어제 야식으로 먹다 남은 치킨 획득! (즉시 HP + 20)");
               playerHP += 20; if (playerHP > 100) playerHP = 100;
            }
            // 녹즙 획득 (조건 추가: 아직 안 뽑았을 때만)
            else if (bagRate < 60 && greenJuiceActive == 0) {
               set_color(FONT_COLOR_GREEN);
               printf("-> [가방 뒤지기 10%%] 이은석 교수님의 녹즙 획득! (이번 턴 종료시점부터 매 턴 피 5 지속 회복)");
               greenJuiceActive = 1;
            }
            // 곰팡이 녹즙 획득 (조건 추가: 아직 안 뽑았을 때만)
            else if (bagRate < 70 && moldJuiceActive == 0) {
               set_color(FONT_COLOR_MAGENTA);
               printf("-> [가방 뒤지기 10%%] 이은석 교수님의 곰팡이 녹즙 획득! (이번 턴 종료시점부터 보스 피 매 턴 5 감소)");
               moldJuiceActive = 1;
            }
            // 60~70 구간에 걸렸으나 이미 아이템을 보유 중이거나, 원래 30% 꽝 확률인 경우
            else {
               set_color(FONT_COLOR_WHITE);
               printf("-> [가방 뒤지기 30%%] 가방 안에서 아무것도 찾지 못했습니다..");
            }
         }
         else if (battleMenu == 5) // 5. 도망가기
         {
            system("cls");
            set_color(FONT_COLOR_WHITE);
            move_cursor(66, 12); printf("김상민을 뿌리치고 도망쳤다.."); Sleep(2000);
            move_cursor(61, 14); printf("비록 동기들과의 술자리는 가지 못했지만"); Sleep(2000);
            move_cursor(60, 16); printf("김상민과의 싸움을 이길 가능성도 희박하고"); Sleep(2000);
            move_cursor(60, 18); printf("만약 지면 끔찍한 지옥을 보았을 것이다..."); Sleep(2000);
            move_cursor(70, 20); set_color(FONT_COLOR_GREEN); printf("무사히 도망치길 잘했다.."); Sleep(2500);
            move_cursor(63, 23); set_color(FONT_COLOR_WHITE); printf("아니, 무사히 도망쳤다고 생각했었다."); Sleep(2500);
            move_cursor(69, 26); set_color(FONT_COLOR_RED); printf("김상민: \"민성아. 가야지?\""); Sleep(2500);
            move_cursor(65, 29); set_color(FONT_COLOR_WHITE); printf("..그에게서 벗어날 수는 없었다."); Sleep(2000);
            move_cursor(75, 32); set_color(FONT_COLOR_RED); printf("-BAD END-"); Sleep(2000);
            move_cursor(57, 35); set_color(FONT_COLOR_GREEN); printf("-> 아무 키나 누르면 타이틀 화면으로 이동합니다.");
            _getch();
            battleRunning = 0;
            break;
         }

         // 플레이어 행동 후 실시간 UI 갱신
         move_cursor(5, 31); set_color(FONT_COLOR_GREEN);
         printf("[PLAYER] 김민성     HP: %d / 100  ", playerHP >= 0 ? playerHP : 0);

         move_cursor(5, 33); printf("체력: ");
         for (int i = 0; i < (playerHP > 0 ? playerHP : 0) / 10; i++) printf("■");
         for (int i = 0; i < (100 - (playerHP > 0 ? playerHP : 0)) / 10; i++) printf("  ");

         move_cursor(118, 3); set_color(FONT_COLOR_RED);
         printf("[BOSS] 김상민 선배   HP: %d / 200  ", bossHP >= 0 ? bossHP : 0);
         move_cursor(118, 4); printf("체력: ");
         for (int i = 0; i < (bossHP > 0 ? bossHP : 0) / 10; i++) printf("■");
         for (int i = 0; i < (200 - (bossHP > 0 ? bossHP : 0)) / 10; i++) printf("  ");

         Sleep(1500); // 연출용 대기

         // 보스 체력 50 미만 시 부활 패턴 (25층 -> 24층으로 이동)
         if (bossHP > 0 && bossHP < 50 && bossHealed == 0)
         {
            move_cursor(20, 24);
            printf("                                                                                                                                                                                                                                ");
            move_cursor(20, 24);
            set_color(FONT_COLOR_RED);
            printf("-> [보스 각성] 이은석 교수님과의 삼겹살과 소주 먹방으로 체력이 회복됐다! (체력 120으로 회복)");
            bossHP = 120;
            bossHealed = 1;
            skipBossTurn = 1;

            move_cursor(118, 3); printf("[BOSS] 김상민 선배   HP: %d / 200  ", bossHP);
            move_cursor(118, 4); printf("체력: ");
            for (int i = 0; i < bossHP / 10; i++) printf("■");
            for (int i = 0; i < (200 - bossHP) / 10; i++) printf("  ");

            Sleep(1500);
         }

         // --- [STAGE 2] 보스의 반격 턴 (27층 -> 26층으로 이동) ---
         if (bossHP > 0 && !skipBossTurn)
         {
            move_cursor(20, 26);
            set_color(FONT_COLOR_RED);

            if (battleMenu == 3) {
               printf("-> [피격] 회피 실패의 대가! 김상민 선배의 강력한 안면 가격! (플레이어 HP -10)");
            }
            else {
               printf("-> [반격] 김상민 선배의 고강도 리프팅 공격! (플레이어 HP -10)");
            }
            playerHP -= 10;

            move_cursor(5, 31); set_color(FONT_COLOR_GREEN);
            printf("[PLAYER] 김민성     HP: %d / 100  ", playerHP >= 0 ? playerHP : 0);
            move_cursor(5, 33); printf("체력: ");
            for (int i = 0; i < (playerHP > 0 ? playerHP : 0) / 10; i++) printf("■");
            for (int i = 0; i < (100 - (playerHP > 0 ? playerHP : 0)) / 10; i++) printf("  ");

            Sleep(1500);
         }

         // --- [STAGE 3] 녹즙 및 곰팡이 정산 (29층 -> 28층으로 이동) ---
         if (greenJuiceActive || moldJuiceActive)
         {
            move_cursor(20, 28);
            if (greenJuiceActive)
            {
               playerHP += 5;
               if (playerHP > 100) playerHP = 100;
               set_color(FONT_COLOR_GREEN);
               printf("[녹즙 정산] 몸이 정화되며 HP가 5 회복됩니다! ");
            }
            if (moldJuiceActive)
            {
               bossHP -= 5;
               set_color(FONT_COLOR_MAGENTA);
               printf("[곰팡이 정산] 김상민이 식중독 증세로 HP가 5 감소합니다! ");
            }

            // 정산된 체력 실시간 재갱신
            move_cursor(5, 31); set_color(FONT_COLOR_GREEN);
            printf("[PLAYER] 김민성     HP: %d / 100  ", playerHP >= 0 ? playerHP : 0);
            move_cursor(118, 3); set_color(FONT_COLOR_RED);
            printf("[BOSS] 김상민 선배   HP: %d / 200  ", bossHP >= 0 ? bossHP : 0);

            Sleep(1500); // 녹즙 틱 이펙트를 인지할 수 있도록 대기
         }

         // 사용자의 키 입력이 들어올 때까지 대기
         _getch();
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

   setlocale(LC_ALL, "");
   printf("\033[2J\033[?25l");

   while (isRunning)
   {
      move_cursor(40, 1);
      set_color(BG_COLOR_BLACK);
      set_color(FONT_COLOR_RED);

      draw_title_logo();

      set_color(BG_COLOR_BLACK);
      set_color(FONT_COLOR_WHITE);
      move_cursor(70, 24); printf(" 1.  게임 시작   ");
      move_cursor(70, 26); printf(" 2.  게임 설명   ");
      move_cursor(70, 28); printf(" 3.  만든이       ");
      move_cursor(70, 30); printf(" 4.  게임 종료   ");

      set_color(BG_COLOR_YELLOW);
      set_color(FONT_COLOR_BLACK);

      if (posY == 1) { move_cursor(70, 24); printf(" 1.  게임 시작   "); }
      else if (posY == 2) { move_cursor(70, 26); printf(" 2.  게임 설명   "); }
      else if (posY == 3) { move_cursor(70, 28); printf(" 3.  만든이       "); }
      else if (posY == 4) { move_cursor(70, 30); printf(" 4.  게임 종료   "); }

      printf(COLOR_RESET);

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
            isRunning = 0;
         }
         else if (posY == 3)
         {
            show_maker_info();
         }
         else if (posY == 2)
         {
            show_game_desc();
         }
         else if (posY == 1)
         {
            start_battle();
         }
      }
   }

   set_color(0);
   system("cls");

   return 0;
}
