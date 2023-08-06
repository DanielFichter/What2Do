#pragma once
#include <list>
#include "to_do.h"

class ToDoModel
{
    
public:
    using ToDoContainer = std::list<ToDo>;
    virtual ToDoContainer getTodoList() const noexcept = 0;
    virtual void pushBack(const ToDo&) noexcept = 0;
    virtual ~ToDoModel() = default;
};