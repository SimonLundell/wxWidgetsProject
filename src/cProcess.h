#ifndef CPROCESS_H
#define CPROCESS_H

#include "cParser.h"

#include <string>
#include <iostream>

class Process {
    public:
        Process(std::string id);

        std::string getProcessInformation() const;
    
    private:
        const std::string _id;
        const std::string _command = "/cmdline";
};
#endif