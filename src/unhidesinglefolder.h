#ifndef UNHIDESINGLEFOLDER_H
#define UNHIDESINGLEFOLDER_H

#include <string>

class UnhideSingleFolder {
public:
    UnhideSingleFolder();
    void chooseFolderPath();
    bool unhideFolder();

private:
    std::string folderPath;
};

#endif // UNHIDESINGLEFOLDER_H