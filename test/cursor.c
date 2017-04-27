#include <mikeos.h>
#include <stdio.h>
#include <textio.h>

#define MODE_COUNT 11

struct cursor_pos {
	int row;
	int col;
};

struct cursor_pos os_cursor;
int currentMode = 0;
int altPage = 0;
char printBuffer[50];

char *modeName[MODE_COUNT] = {
	"Off-MOS", 
	"On-MOS", 
	"Off", 
	"Thin",
	"Block",
	"SBlock",
	"Rapid",
	"Slow",
	"Strike",
	"Over",
	"Random"
};

int main()
{
	int key;
	
	initScr();
	enterMode(currentMode);
	redraw();

	do {
		key = os_wait_for_key();
		if (key == RIGHT_KEY && currentMode < (MODE_COUNT - 1)) {
			enterMode(++currentMode);
		} else if (key == LEFT_KEY && currentMode > 0) {
			enterMode(--currentMode);
		}
		redraw();

	} while (key != ESC_KEY);
	exitScr();
	return 0;
}


void initScr()
{
	os_get_cursor_pos(&os_cursor.row, &os_cursor.col);
	textio_init();
	textcolour(BLACK_ON_LIGHTGREY);
	outpage(2);
}


void exitScr()
{
	viewpage(0);
	os_move_cursor(os_cursor.row, os_cursor.col);
	os_show_cursor();
}


void redraw()
{
	int i;

	textcolour(LIGHTGREY_ON_BLACK);
	clearscr();

	movecur(30, 0);
	strout("Cursor Mode Sampler");

	movecur(0, 1);

	for (i = 0; i < MODE_COUNT; i++) {
		if (i == currentMode) {
			textcolour(BLACK_ON_LIGHTGREY);
		} else {
			textcolour(LIGHTGREY_ON_BLACK);
		}

		snprintf(printBuffer, 50, "[ %s ]", modeName[i]);
		strout(printBuffer);
		textcolour(LIGHTGREY_ON_BLACK);
		strout("   ");
	}

	movecur(39, 4);
	textcolour(BLACK_ON_LIGHTGREY);
	strout(" A ");
	textcolour(LIGHTGREY_ON_BLACK);
	movecur(40, 4);

	if (altPage) {
		outpage(2);
		viewpage(4);
	} else {
		outpage(4);
		viewpage(2);
	}

	altPage = !altPage;
}

	
void enterMode(int modeNumber)
{
	switch (modeNumber) {
		case 0:
			os_hide_cursor();
			break;

		case 1:
			os_show_cursor();
			break;

		case 2:
			cursorMode(0x2000);
			break;

		case 3:
			cursorMode(0x0707);
			break;

		case 4:
			cursorMode(0x0007);
			break;

		case 5:
			cursorMode(0x0106);
			break;

		case 6:
			cursorMode(0x4607);
			break;

		case 7:
			cursorMode(0x6607);
			break;

		case 8:
			cursorMode(0x0304);
			break;

		case 9:
			cursorMode(0x0001);
			break;

		case 10:
			cursorMode(os_get_random(0, 255) * 256 + os_get_random(0, 255));
			break;

	}
}


void cursorMode(int code)
{
	asm("mov ah, 1\n mov cx, [bp + 4]\n int 0x10");
}

