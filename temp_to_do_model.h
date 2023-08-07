#pragma once
#include <optional>
#include "to_do_model.h"


class TempToDoModel: public ToDoModel 
{

    ToDoContainer todos;
    using ToDoIterator = ToDoContainer::iterator;
    using ToDoConstIterator = ToDoContainer::const_iterator;

public:
    virtual ToDoContainer getTodoList() const noexcept override;
    virtual ToDo* const getByName(const std::string&) noexcept override;
    virtual void pushBack(const ToDo&) noexcept override;
};

