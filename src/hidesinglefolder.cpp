#include "hidesinglefolder.h"
#include <iostream>
#include <Windows.h>
#include <Shlobj.h>
#include <string>

HideSingleFolder::HideSingleFolder() {}

void HideSingleFolder::chooseFolderPath() {
    BROWSEINFOA bi;
    ZeroMemory(&bi, sizeof(bi));

    char folderPath[MAX_PATH] = { 0 };
    bi.hwndOwner = NULL;
    bi.pszDisplayName = folderPath;
    bi.pidlRoot = NULL;
    bi.lpszTitle = "Select a folder";
    bi.ulFlags = BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE;

    LPITEMIDLIST pFolder = SHBrowseForFolderA(&bi);
    if (pFolder != NULL) {
        SHGetPathFromIDListA(pFolder, folderPath);
        this->folderPath = folderPath;
        CoTaskMemFree(pFolder);
    }
}

bool HideSingleFolder::hideFolder() {
    if (SetFileAttributesA(folderPath.c_str(), FILE_ATTRIBUTE_HIDDEN)) {
        std::cout << "Folder " << folderPath << " has been successfully hidden." << std::endl;
        return true;
    }
    else {
        std::cerr << "Error: Failed to hide folder " << folderPath << std::endl;
        return false;
    }
}