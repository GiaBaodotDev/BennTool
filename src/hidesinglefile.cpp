#include "hidesinglefile.h"
#include <iostream>
#include <Windows.h>
#include <Commdlg.h>

HideSingleFile::HideSingleFile() {}

void HideSingleFile::chooseFilePath() {
    OPENFILENAMEA ofn;
    CHAR szFile[MAX_PATH] = { 0 };

    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFilter = "All Files (*.*)\0*.*\0";
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = sizeof(szFile);
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;

    if (GetOpenFileNameA(&ofn)) {
        filePath = szFile;
    }
}

bool HideSingleFile::hideFile() {
    if (SetFileAttributesA(filePath.c_str(), FILE_ATTRIBUTE_HIDDEN)) {
        std::cout << "File " << filePath << " has been successfully hidden." << std::endl;
        return true;
    }
    else {
        std::cerr << "Error: Failed to hide file " << filePath << std::endl;
        return false;
    }
}