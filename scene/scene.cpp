#include"scene.h"
#include"tool/output.h"

void SCENE::run()
{
	tm.run();
	bm.run();
	bum.run();
}

void SCENE::init()
{
	//						0 1 2 3 4 5 6 7
	//const char* tempTs = "  ¡¬¡ñ£½¡þ¡ï¡õ¨ˆ";
	g_op.addInfo("  ", "", 0);
	g_op.addInfo("¡¬", "\033[31m", 5);
	g_op.addInfo("¡ñ", "\033[32m", 5);
	g_op.addInfo("£½", "\033[31m", 5);
	g_op.addInfo("¡þ", "\033[33m", 5);
	g_op.addInfo("¡ï", "\033[31m", 5);
	g_op.addInfo("¡õ", "\033[34m", 5);
	g_op.addInfo("¨ˆ", "\033[32m", 5);
	g_op.SetClientWH(MAP_WIDTH, MAP_HEIGHT);
	g_op.SetClientPos(0, 0);

	bm.init();
	bum.init(&bm);
	tm.init(&bm,&bum);
}

void SCENE::end()
{
	tm.clear();
	bum.clear();
	bm.clear();
	g_op.Clear();
}

void SCENE_ONE::init()
{
	this->baseScene.init();
	this->baseScene.bm.buildBrick(3, 3, 15);
	this->baseScene.bm.buildBrick(9, 3, 15);
	this->baseScene.bm.buildBrick(15, 3, 12);
	this->baseScene.bm.buildBrick(21, 3, 12);
	this->baseScene.bm.buildBrick(18, 9, 3);
	this->baseScene.bm.buildBrick(27, 3, 15);
	this->baseScene.bm.buildBrick(33, 3, 15);

	this->baseScene.bm.buildBrick(0, 21, 2); 
	this->baseScene.bm.buildIron(0, 23, 1);
	this->baseScene.bm.buildBrick(6, 21, 3);
	this->baseScene.bm.buildBrick(9, 21, 3);

	this->baseScene.bm.buildBrick(15, 18, 3);
	this->baseScene.bm.buildBrick(21, 18, 3);

	this->baseScene.bm.buildBrick(27, 21, 3);
	this->baseScene.bm.buildBrick(30, 21, 3);
	this->baseScene.bm.buildBrick(36, 21, 2);
	this->baseScene.bm.buildIron(36, 23, 1);

	this->baseScene.bm.buildBrick(3, 27, 12);
	this->baseScene.bm.buildBrick(9, 27, 12);
	this->baseScene.bm.buildBrick(15, 24, 8);
	this->baseScene.bm.buildBrick(21, 24, 8);
	this->baseScene.bm.buildBrick(18, 25, 3);
	this->baseScene.bm.buildBrick(27, 27, 12);
	this->baseScene.bm.buildBrick(33, 27, 12);
}

void SCENE_TWO::init()
{
	this->baseScene.init();
	this->baseScene.bm.buildBrick(3, 3, 6);
	this->baseScene.bm.buildIron(9, 0, 6);
	this->baseScene.bm.buildBrick(9, 9, 6);
	this->baseScene.bm.buildBrick(18, 6, 3);
	this->baseScene.bm.buildBrick(21, 3, 6);
	this->baseScene.bm.buildIron(21, 0, 3);

	this->baseScene.bm.buildBrick(27, 3, 6);
	this->baseScene.bm.buildIron(30, 6, 3);
	this->baseScene.bm.buildBrick(33, 3, 6);


	this->baseScene.bm.buildIron(27, 9, 3);
	this->baseScene.bm.buildIron(18 , 12, 3);

	this->baseScene.bm.buildBrick(27, 12, 3);
	this->baseScene.bm.buildBrick(33, 12, 3);
	this->baseScene.bm.buildIron(36, 12, 3);

	this->baseScene.bm.buildBrick(15, 15, 3);
	this->baseScene.bm.buildIron(24, 15, 3);

	this->baseScene.bm.buildBrick(3, 18, 3);
	this->baseScene.bm.buildBrick(6, 18, 3);
	this->baseScene.bm.buildBrick(9, 18, 3);

	this->baseScene.bm.buildIron(21, 18, 3);
	this->baseScene.bm.buildBrick(33, 18, 12);

	this->baseScene.bm.buildIron(0, 24, 3);
	this->baseScene.bm.buildBrick(3, 24, 18);

	this->baseScene.bm.buildIron(9, 21,6);
	this->baseScene.bm.buildBrick(9, 27, 6);
	this->baseScene.bm.buildBrick(9, 36, 6);

	this->baseScene.bm.buildBrick(15, 21, 12);
	this->baseScene.bm.buildBrick(18, 27, 6);
	this->baseScene.bm.buildBrick(21, 21, 12);

	this->baseScene.bm.buildBrick(27, 21, 3);
	this->baseScene.bm.buildBrick(27, 27, 3);
	this->baseScene.bm.buildIron(30, 27, 3);

	this->baseScene.bm.buildBrick(27, 36, 6);
	this->baseScene.bm.buildBrick(30, 36, 3);
	this->baseScene.bm.buildBrick(33, 36, 6);


	this->baseScene.bm.buildTree(0,12,6);
	this->baseScene.bm.buildTree(3,15,3);

	this->baseScene.bm.buildTree(12, 18, 6);
	this->baseScene.bm.buildTree(15, 18, 3);
	this->baseScene.bm.buildTree(18, 18, 3);
	this->baseScene.bm.buildTree(30, 12, 9);

}
