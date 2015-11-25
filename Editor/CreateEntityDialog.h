#pragma once 
#include "WX_CreateEntityDialog.h"
#include <string>
#include "DialogResult.h"


class CreateEntityDialog 
{
	DialogResult result;


	std::string name;
	std::string filePath;


public:
	CreateEntityDialog();


	void Show();

	DialogResult GetResult();

	std::string GetName();
	std::string GetFilePath();

};