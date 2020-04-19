#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
#include<windows.h>

//全局变量定义
int place_x, place_y;//飞机初始坐标
int high, weith;//边界宽高
int balle_x, balle_y;//子弹位置
int enemy_x, enemy_y;//敌机位置
int score;//得分

void startup();//数据初始化
void show();//显示初始界面
void updateWithoutInput();//与用户输入无关的更新
void updateWithInput();//与用户输入有关的更新

int main(void) {

	startup();

	while (1) {

		show();

		updateWithoutInput();

		updateWithInput();
	}

	return 0;
}
void startup() {

	high = 20;
	weith = 40;

	place_x = weith / 2;
	place_y = high / 2;

	balle_x = place_x;
	balle_y = -1;

	enemy_x = weith / 2;
	enemy_y = 0;

	score = 0;

}

void show() {

	int i, j;

    system("cls");

	for (i = 0; i < high; i++) {
		for (j = 0; j < weith; j++) {
			if ((i == place_y) && (j == place_x)) {
				printf("*");
			}
			if ((i == enemy_y) && (j == enemy_x)) {
				printf("@");
			}
			if ((i == balle_y) && (j == balle_x)) {
				printf("|");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}

	printf("得分是：%d", score);

}

void updateWithoutInput() {
	char input;

	if (_kbhit()) {
		
		input = _getch();

		if (input == 'a') {
			place_x--;
		}
		if (input == 'd') {
			place_x++;
		}
		if (input == 'w') {
			place_y--;
		}
		if (input == 's') {
			place_y++;
		}
		if (input == ' ') {
			balle_y = place_y - 1;
		}
	}

}

void updateWithInput() {

	if ((balle_x == enemy_x) && (balle_y == enemy_y)) {
		score++;
		balle_y = -1;
		enemy_x = rand() % weith;
		enemy_y = 0;
	}

	balle_x = place_x;

	if ( balle_y > -1 ) {
		balle_y--;
	}

	static int speed = 0;

	if (speed < 10) {
		speed++;
	}
	else {
        if (enemy_y > high) {
			enemy_x = rand() % weith;
		    enemy_y = 0;
	    }
	    else {
            enemy_y++;
	    }
		speed = 0;
	}
	

}

