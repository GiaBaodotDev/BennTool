#include "unhidemultiplefolders.h"
#include <iostream>
#include <sstream>
#include <Windows.h>

UnhideMultipleFolders::UnhideMultipleFolders() {};

void UnhideMultipleFolders::chooseFolderPaths() {
    std::cout << "Enter the paths of the folders you want to unhide (separated by commas): ";
    std::string input;
    std::getline(std::cin, input);

    std::stringstream ss(input);
    std::string folderPath;

    while (std::getline(ss, folderPath, ',')) {
        folderPaths.push_back(folderPath);
    }
}

bool UnhideMultipleFolders::unhideFolders() {
    bool allFoldersUnhidden = true;
    for (const auto& folderPath : folderPaths) {
        if (!SetFileAttributesA(folderPath.c_str(), FILE_ATTRIBUTE_NORMAL)) {
            std::cerr << "Error: Failed to unhide folder " << folderPath << std::endl;
            allFoldersUnhidden = false;
        }
    }

    if (allFoldersUnhidden) {
        std::cout << "All specified folders have been successfully unhidden." << std::endl;
        return true;
    }
    else {
        return false;
    }
}