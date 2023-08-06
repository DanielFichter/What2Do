#include "temp_to_do_model.h"

TempToDoModel::ToDoContainer TempToDoModel::getTodoList() const noexcept
{
    return todos;
}

void TempToDoModel::pushBack(const ToDo& newToDo) noexcept
{
    todos.insert(todos.end(), newToDo);
}