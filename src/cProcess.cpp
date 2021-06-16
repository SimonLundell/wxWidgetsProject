#include "cProcess.h"
#include <string>

Process::Process(std::string id) : _id(id){
}

std::string Process::getProcessInformation() const { return _id; }