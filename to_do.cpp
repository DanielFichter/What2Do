#include <string>
#include "to_do.h"

ToDo::ToDo(std::string name) : name{name}, done{false} {}

std::string ToDo::getName() const {
    return name;
}

bool ToDo::isDone() const {
    return done;
}

bool ToDo::setDone() {
    bool hasChanged {!done};
    done = true;
    return hasChanged;
}