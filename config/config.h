#pragma once

#define GAME_FPS 30 //游戏运行速度

#define TANK_WIDTH 3
#define TANK_HEIGHT 3

#define BOX_WIDTH 3
#define BOX_HEIGHT 3

#define BRICK_UNIT_WIDTH 1
#define BRICK_UNIT_HEIGHT 1

#define MAP_WIDTH (TANK_WIDTH * 13)
#define MAP_HEIGHT (TANK_HEIGHT * 14)

#define UI_WIDTH 30
#define UI_HEIGHT 30

#define TANK_DIR_UP 0
#define TANK_DIR_DOWN 1
#define TANK_DIR_LEFT 2
#define TANK_DIR_RIGHT 3

#define TANK_PIC_UP "TANK_UP"
#define TANK_PIC_DOWN "TANK_DOWN"
#define TANK_PIC_LEFT "TANK_LEFT"
#define TANK_PIC_RIGHT "TANK_RIGHT"

#define TANK_DESTORY "TANK_DESTORY"

#define BARRIES_BRICK "B_BRICK" //砖块，可摧毁
#define BARRIES_IRON "B_IRON" //铁块，不可摧毁
#define BARRIES_TREE "B_TREE" //树丛，不可摧毁，可通过，被隐藏
#define ENEMY_BULLET_TYPE "ENNEMY_BULLET" //子弹
#define OUR_BULLET_TYPE "OUR_BULLET" //子弹

#define BOX_ALL_DESTORY "BOX_ALL_DESTORY"
#define BOX_ALL_DESTORY_TYPE 0
#define BOX_NONE -1

#define BULLET_STEP  2 //子弹步进距离
#define OUR_ATTACK_TIME_INTERVAL 500
#define ENEMY_ATTACK_TIME_INTERVAL 1000

#define ACTION_NEXT 1
#define ACTION_EXIT 2
#define ACTION_NONE 0