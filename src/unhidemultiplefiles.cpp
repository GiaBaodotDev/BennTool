#include "unhidemultiplefiles.h"
#include <iostream>
#include <Windows.h>
#include <Commdlg.h>

UnhideMultipleFiles::UnhideMultipleFiles() {}

void UnhideMultipleFiles::chooseFilePaths() {
    OPENFILENAMEA ofn;
    char* fileNames = new char[MAX_PATH * 100]{};
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFile = fileNames;
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = MAX_PATH * 100;
    ofn.lpstrFilter = "All Files\0*.*\0";
    ofn.nFilterIndex = 1;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_ALLOWMULTISELECT;

    if (GetOpenFileNameA(&ofn) != FALSE) {
        char* p = fileNames;
        std::string folderPath = p;
        p += folderPath.length() + 1;

        while (*p) {
            std::string filePath = folderPath + "\\" + p;
            filePaths.push_back(filePath);
            p += strlen(p) + 1;
        }
    }

    delete[] fileNames;
}

bool UnhideMultipleFiles::unhideFiles() {
    bool allFilesUnhidden = true;
    for (const auto& filePath : filePaths) {
        if (!SetFileAttributesA(filePath.c_str(), FILE_ATTRIBUTE_NORMAL)) {
            std::cerr << "Error: Failed to unhide file " << filePath << std::endl;
            allFilesUnhidden = false;
        }
    }

    if (allFilesUnhidden) {
        std::cout << "All selected files have been successfully unhidden." << std::endl;
        return true;
    }
    else {
        return false;
    }
}