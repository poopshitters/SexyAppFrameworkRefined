#include "AttributeDialog.h"
#include "FileDialog.h"
#include "resource.h"
#include "ProjectDialog.h"

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
AttributeDialog::AttributeDialog()
{
    mDialogId = IDD_PROJECT_ATTRIBUTES;
    mPatokeSystem = false;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void AttributeDialog::GetDataFromWindows()
{
    mName = GetWindowTextItem(IDC_PROJECT_NAME);
    mXMLPath = GetWindowTextItem(IDC_RESOURCE_XML);
    mCodePath = GetWindowTextItem(IDC_RESOURCE_CODE);
    mFunctionPrefix = GetWindowTextItem(IDC_FUNCTION_PREFIX);
    mPatokeSystem = GetWindowCheckBox(IDC_USEPATOKE);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void AttributeDialog::SetDataToWindows()
{
    SetWindowText(GetDlgItem(IDC_PROJECT_NAME), mName.c_str());
    SetWindowText(GetDlgItem(IDC_RESOURCE_XML), mXMLPath.c_str());
    SetWindowText(GetDlgItem(IDC_RESOURCE_CODE), mCodePath.c_str());
    SetWindowText(GetDlgItem(IDC_FUNCTION_PREFIX), mFunctionPrefix.c_str());
    SetWindowCheckBox(IDC_USEPATOKE, mPatokeSystem);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void AttributeDialog::OnBrowseXML()
{
    FileDialog aDialog(false);
    aDialog.SetTitle("Locate Resource XML");
    aDialog.AddFilter("*.xml", "XML Files (*.xml)");
    aDialog.AddFilter("*.*", "All Files (*.*)");
    aDialog.SetNoChangeDir(true);
    if (!aDialog.DoDialog(mHWND))
        return;

    SetWindowText(GetDlgItem(IDC_RESOURCE_XML), aDialog.GetFile().c_str());
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void AttributeDialog::OnBrowseCode()
{
    FileDialog aDialog(true);
    aDialog.SetTitle("Locate Resource XML");
    // aDialog.SetGetDir(true);
    aDialog.SetNoChangeDir(true);
    if (!aDialog.DoDialog(mHWND))
        return;

    SetWindowText(GetDlgItem(IDC_RESOURCE_CODE), aDialog.GetFile().c_str());
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
INT_PTR AttributeDialog::DialogProc(UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg) {
    case WM_COMMAND:
        if (HIWORD(wParam) == BN_CLICKED) {
            switch (LOWORD(wParam)) {
            case IDOK:
                mPatokeSystem = GetWindowCheckBox(IDC_USEPATOKE);
            case IDCANCEL:
                EndDialog(LOWORD(wParam));
                return TRUE;

            case IDC_BROWSE_XML:
                OnBrowseXML();
                return TRUE;

            case IDC_BROWSE_CODE:
                OnBrowseCode();
                return TRUE;
            }
        }
        break;
    }

    return FALSE;
}
