#pragma once
#include "to_do_model.h"
#include <list>
#include "to_do.h"
#include <memory>

class CLI
{
    std::unique_ptr<ToDoModel> todos;
    std::string helpMessage;

public:
    CLI(std::unique_ptr<ToDoModel>&&);
    void repl() noexcept;
private:
    void addToDo() noexcept;
    void listToDos() const noexcept;
    void displayHelp() const noexcept;
    void markToDoAsDone() const noexcept;
};