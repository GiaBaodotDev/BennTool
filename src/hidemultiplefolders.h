#ifndef HIDEMULTIPLEFOLDERS_H
#define HIDEMULTIPLEFOLDERS_H

#include <string>
#include <vector>

class HideMultipleFolders {
public:
    HideMultipleFolders();
    void chooseFolderPaths();
    bool hideFolders();

private:
    std::vector<std::string> folderPaths;
};

#endif  // HIDEMULTIPLEFOLDERS_H