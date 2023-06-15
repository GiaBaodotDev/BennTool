#ifndef HIDESINGLEFOLDER_H
#define HIDESINGLEFOLDER_H

#include <string>

class HideSingleFolder {
public:
    HideSingleFolder();
    void chooseFolderPath();
    bool hideFolder();

private:
    std::string folderPath;
};

#endif  // HIDESINGLEFOLDER_H