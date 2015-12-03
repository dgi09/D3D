#include "MainScene.h"

Scene * MainScene::ptr = nullptr;

Scene * MainScene::Get()
{
	return ptr;
}
void MainScene::Set(Scene * scene)
{
	ptr = scene;
}