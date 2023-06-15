#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include "hidesinglefile.h"
#include "unhidesinglefile.h"
#include "hidesinglefolder.h"
#include "unhidesinglefolder.h"
#include "hidemultiplefiles.h"
#include "unhidemultiplefiles.h"
#include "hidemultiplefolders.h"
#include "unhidemultiplefolders.h"

int main() {
    char choice;

    do {
        std::cout << "BennTool v1.0" << std::endl;
        std::cout << "Press 'Q' to hide single file" << std::endl;
        std::cout << "Press 'A' to unhide single file" << std::endl;
        std::cout << "Press 'W' to hide single folder" << std::endl;
        std::cout << "Press 'S' to unhide single folder" << std::endl;
        std::cout << "Press 'E' to hide multiple files" << std::endl;
        std::cout << "Press 'D' to unhide multiple files" << std::endl;
        std::cout << "Press 'R' to hide multiple folders" << std::endl;
        std::cout << "Press 'F' to unhide multiple folders" << std::endl;
        std::cout << "Press 'X' to exit the program" << std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 'q': {
            HideSingleFile hideSingleFile;
            hideSingleFile.chooseFilePath();
            hideSingleFile.hideFile();
            Sleep(1500);
            system("cls");
            break;
        }
        case 'a': {
            UnhideSingleFile unhideSingleFile;
            unhideSingleFile.chooseFilePath();
            unhideSingleFile.unhideFile();
            Sleep(1500);
            system("cls");
            break;
        }
        case 'w': {
            HideSingleFolder hideSingleFolder;
            hideSingleFolder.chooseFolderPath();
            hideSingleFolder.hideFolder();
            Sleep(1500);
            system("cls");
            break;
        }
        case 's': {
            UnhideSingleFolder unhideSingleFolder;
            unhideSingleFolder.chooseFolderPath();
            unhideSingleFolder.unhideFolder();
            Sleep(1500);
            system("cls");
            break;
        }
        case 'e': {
            HideMultipleFiles hideMultipleFiles;
            hideMultipleFiles.chooseFilePaths();
            hideMultipleFiles.hideFiles();
            Sleep(1500);
            system("cls");
            break;
        }
        case 'd': {
            UnhideMultipleFiles unhideMultipleFiles;
            unhideMultipleFiles.chooseFilePaths();
            unhideMultipleFiles.unhideFiles();
            Sleep(1500);
            system("cls");
            break;
        }
        case 'r': {
            HideMultipleFolders hideMultipleFolders;
            hideMultipleFolders.chooseFolderPaths();
            hideMultipleFolders.hideFolders();
            Sleep(1500);
            system("cls");
            break;
        }
        case 'f': {
            UnhideMultipleFolders unhideMultipleFolders;
            unhideMultipleFolders.chooseFolderPaths();
            unhideMultipleFolders.unhideFolders();
            Sleep(1500);
            system("cls");
            break;
        }
        case 'x': {
            // Exit the program
            return 0;
        }
        default: {
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
        }

        std::cout << std::endl;

    } while (true);

    return 0;
}