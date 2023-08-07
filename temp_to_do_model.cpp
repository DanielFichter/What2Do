#include "temp_to_do_model.h"
#include <algorithm>

TempToDoModel::ToDoContainer TempToDoModel::getTodoList() const noexcept
{
    return todos;
}

void TempToDoModel::pushBack(const ToDo &newToDo) noexcept
{
    todos.insert(todos.end(), newToDo);
}

ToDo *const TempToDoModel::getByName(const std::string &name) noexcept
{
    ToDoIterator todo{std::find_if(todos.begin(), todos.end(), [name](ToDo todo)
                                   { return todo.getName() == name; })};

    if (todo == todos.end())
    {
        return nullptr;
    }
    return &*todo;
}