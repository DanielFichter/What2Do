#pragma once

#include "to_do_model.h"


class TempToDoModel: public ToDoModel 
{

    ToDoContainer todos;

public:
    virtual ToDoContainer getTodoList() const noexcept override;
    virtual void pushBack(const ToDo&) noexcept override;
};

