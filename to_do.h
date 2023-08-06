#pragma once
#include<string>

class ToDo {

    std::string name;
    bool done;

public:
    ToDo(std::string);
    std::string getName() const;
    bool isDone() const;

    bool setDone();
};