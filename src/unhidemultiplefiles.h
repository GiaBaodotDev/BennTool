#ifndef UNHIDEMULTIPLEFILES_H
#define UNHIDEMULTIPLEFILES_H

#include <vector>
#include <string>

class UnhideMultipleFiles {
public:
    UnhideMultipleFiles();
    void chooseFilePaths();
    bool unhideFiles();

private:
    std::vector<std::string> filePaths;
};

#endif // UNHIDEMULTIPLEFILES_H