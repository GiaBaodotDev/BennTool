#ifndef HIDESINGLEFILE_H
#define HIDESINGLEFILE_H

#include <string>

class HideSingleFile {
public:
    HideSingleFile();
    void chooseFilePath();
    bool hideFile();

private:
    std::string filePath;
};

#endif  // HIDESINGLEFILE_H