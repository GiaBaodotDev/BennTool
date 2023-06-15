#include "hidemultiplefolders.h"
#include <iostream>
#include <sstream>
#include <Windows.h>

HideMultipleFolders::HideMultipleFolders() {};

void HideMultipleFolders::chooseFolderPaths() {
    std::cout << "Enter the paths of the folders you want to hide (separated by commas): ";
    std::string input;
    std::getline(std::cin, input);

    std::stringstream ss(input);
    std::string folderPath;

    while (std::getline(ss, folderPath, ',')) {
        folderPaths.push_back(folderPath);
    }
}

bool HideMultipleFolders::hideFolders() {
    bool allFoldersHidden = true;
    for (const auto& folderPath : folderPaths) {
        if (!SetFileAttributesA(folderPath.c_str(), FILE_ATTRIBUTE_HIDDEN)) {
            std::cerr << "Error: Failed to hide folder " << folderPath << std::endl;
            allFoldersHidden = false;
        }
    }

    if (allFoldersHidden) {
        std::cout << "All specified folders have been successfully hidden." << std::endl;
        return true;
    }
    else {
        return false;
    }
}