#ifndef HIDEMULTIPLEFILES_H
#define HIDEMULTIPLEFILES_H

#include <vector>
#include <string>

class HideMultipleFiles {
public:
    HideMultipleFiles();
    void chooseFilePaths();
    bool hideFiles();

private:
    std::vector<std::string> filePaths;
};

#endif // HIDEMULTIPLEFILES_H