//#include <string>
//#include <fstream>
//#include <iostream>
#include <iostream>

#include "cParser.h"

Parser::Parser() {
    std::cout << "Parser constructor\n";
    getFolderContent(nProcessPath);
}

void Parser::getFolderContent(const char* path) {
    DIR* const dir = opendir(path);
    if (dir != nullptr) {
        // have to read dir in argument below to avoid infinite loop..
        struct dirent *diread;
        while ((diread = readdir(dir))!= nullptr) {
            if (diread->d_type == DT_DIR) {
                std::string processName = diread->d_name;
                if (std::all_of(processName.begin(), processName.end(), isdigit)) {  // Requires bits/stdc++ header
                    _processes.emplace_back(Process(processName));
                }
            }
        }
        closedir(dir);
    }
}

std::string Parser::readContent(std::string process) {

}

Parser::~Parser() {

}