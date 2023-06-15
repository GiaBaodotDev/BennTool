#ifndef UNHIDESINGLEFILE_H
#define UNHIDESINGLEFILE_H

#include <string>

class UnhideSingleFile {
public:
    UnhideSingleFile();
    void chooseFilePath();
    bool unhideFile();

private:
    std::string filePath;
};

#endif  // UNHIDESINGLEFILE_H