#ifndef CPARSER_H
#define CPARSER_H

#include "cProcess.h"

#include <string>
#include <dirent.h>
#include <bits/stdc++.h>
#include <vector>

class Process;

class Parser {
    public:
        Parser();
        ~Parser();

        // Getter
        std::vector<Process> getProcesses() { return _processes; }

        void getFolderContent(const char* path);
        std::string readContent(std::string process);
        // Should implement generic function to query directory with flag if int/string and flag for keyword.
    
    private:
        const char* nProcessPath{"/proc/"};
        std::vector<Process> _processes;
};
#endif