#include "unhidesinglefile.h"
#include <iostream>
#include <Windows.h>
#include <Commdlg.h>

UnhideSingleFile::UnhideSingleFile() {}

void UnhideSingleFile::chooseFilePath() {
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

bool UnhideSingleFile::unhideFile() {
    if (SetFileAttributesA(filePath.c_str(), FILE_ATTRIBUTE_NORMAL)) {
        std::cout << "File " << filePath << " has been successfully unhidden." << std::endl;
        return true;
    }
    else {
        std::cerr << "Error: Failed to unhide file " << filePath << std::endl;
        return false;
    }
}