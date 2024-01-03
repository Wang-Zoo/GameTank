#pragma once

#define GAME_FPS 80 //��Ϸ�����ٶ�

#define TANK_WIDTH 3
#define TANK_HEIGHT 3

#define MAP_WIDTH (TANK_WIDTH * 13)
#define MAP_HEIGHT (TANK_HEIGHT * 14)

#define TANK_DIR_UP 0
#define TANK_DIR_DOWN 1
#define TANK_DIR_LEFT 2
#define TANK_DIR_RIGHT 3

#define TANK_PIC_UP "TANK_UP"
#define TANK_PIC_DOWN "TANK_DOWN"
#define TANK_PIC_LEFT "TANK_LEFT"
#define TANK_PIC_RIGHT "TANK_RIGHT"

#define BARRIES_BRICK "B_BRICK" //ש�飬�ɴݻ�
#define BULLET_TYPE "BULLET" //�ӵ�

#define BULLET_STEP  2 //�ӵ���������
#define OUR_ATTACK_TIME_INTERVAL 500
#define ENEMY_ATTACK_TIME_INTERVAL 3000