#ifndef UNHIDEMULTIPLEFOLDERS_H
#define UNHIDEMULTIPLEFOLDERS_H

#include <string>
#include <vector>

class UnhideMultipleFolders {
public:
    UnhideMultipleFolders();
    void chooseFolderPaths();
    bool unhideFolders();

private:
    std::vector<std::string> folderPaths;
};

#endif  // UNHIDEMULTIPLEFOLDERS_H