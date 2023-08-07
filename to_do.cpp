#include <string>
#include "to_do.h"

long long unsigned ToDo::currentId{1};

std::vector<std::string> ToDo::statusNames {"todo", "done"};

ToDo::ToDo(const std::string &name) : name{name}, status{Status::todo}, id{currentId} { ++currentId; }

std::string ToDo::getName() const
{
    return name;
}

ToDo::Status ToDo::getStatus() const
{
    return status;
}

bool ToDo::setStatus(Status newStatus = Status::done)
{
    if (status != newStatus)
    {
        status = newStatus;
        return true;
    }
    return false;
}

long long unsigned ToDo::getId() const
{
    return id;
}