#include "CreateEntityDialog.h"

CreateEntityDialog::CreateEntityDialog()
{
	result = CANCEL;
	
}

void CreateEntityDialog::Show()
{
	WX_CreateEntityDialog dialog(NULL);
	
	if(dialog.ShowModal() == wxID_OK)
	{
		wxTextCtrl * textBox = (wxTextCtrl*)dialog.FindWindowByName("txtName");
		name = textBox->GetValue().c_str();

		wxFilePickerCtrl * flpc = (wxFilePickerCtrl*)dialog.FindWindowByName("flpcFileName");
		filePath = flpc->GetTextCtrlValue().c_str();

		result = OK;
	}
	else 
	{
		result = CANCEL;
	}

	
}

DialogResult CreateEntityDialog::GetResult()
{
	return result;
}

std::string CreateEntityDialog::GetName()
{
	return name;
}

std::string CreateEntityDialog::GetFilePath()
{
	return filePath;
}



