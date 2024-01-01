#include"scene.h"

void SCENE::run()
{
	tm.run();
	bm.run();
	bum.run();
}

void SCENE::init()
{
	bm.init();
	bum.init();
	tm.init(&bm,&bum);
}

void SCENE::end()
{
	tm.clear();
	bm.clear();
	bum.clear();
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

	this->baseScene.bm.buildBrick(0, 21, 3);
	this->baseScene.bm.buildBrick(6, 21, 3);
	this->baseScene.bm.buildBrick(9, 21, 3);

	this->baseScene.bm.buildBrick(15, 18, 3);
	this->baseScene.bm.buildBrick(21, 18, 3);

	this->baseScene.bm.buildBrick(27, 21, 3);
	this->baseScene.bm.buildBrick(30, 21, 3);
	this->baseScene.bm.buildBrick(36, 21, 3);

	this->baseScene.bm.buildBrick(3, 27, 12);
	this->baseScene.bm.buildBrick(9, 27, 12);
	this->baseScene.bm.buildBrick(15, 24, 8);
	this->baseScene.bm.buildBrick(21, 24, 8);
	this->baseScene.bm.buildBrick(18, 25, 3);
	this->baseScene.bm.buildBrick(27, 27, 12);
	this->baseScene.bm.buildBrick(33, 27, 12);
}