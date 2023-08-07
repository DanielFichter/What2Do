#include "cli.h"
#include <string>
#include <iostream>
#include <iomanip>

CLI::CLI(std::unique_ptr<ToDoModel> &&model) : todos{std::move(model)}, helpMessage{"n for new to-do\nl for list all to-dos\ne for exit\nh for help\nm for marking as done"}
{
}

void CLI::addToDo() noexcept
{
    std::cout << "enter name of to-do: " << std::endl;
    std::string name;
    std::getline(std::cin, name);
    std::getline(std::cin, name);
    todos->pushBack(ToDo(name));
    std::cout << "to-do with name " << std::quoted(name) << " was added " << std::endl;
}

void CLI::listToDos() const noexcept
{
    for (const ToDo &todo : todos->getTodoList())
    {
        std::cout << todo.getName() << "  " << std::boolalpha << todo.isDone() << std::endl;
    }
}

void CLI::displayHelp() const noexcept
{
    std::cout << helpMessage << std::endl;
}

/**
 * read-evaluate-print-loop
 */
void CLI::repl() noexcept
{
    std::string input;
    while (std::cin >> input)
    {
        if (input == "h")
        {
            displayHelp();
        }
        if (input == "n")
        {
            addToDo();
        }
        if (input == "l")
        {
            listToDos();
        }
        if (input == "m")
        {
            markToDoAsDone();
        }
        if (input == "e")
        {
            std::exit(EXIT_SUCCESS);
        }
    }
}

void CLI::markToDoAsDone() const noexcept
{
    std::cout << "enter name of todo:" << std::endl;
    std::string name;
    std::getline(std::cin, name);
    std::getline(std::cin, name);
    if (ToDo *const pToDo = todos->getByName(name); pToDo != nullptr)
    {
        if (pToDo->isDone())
        {
            std::cout << "todo " << std::quoted(name) << " is already marked as done!";
        }
        else
        {
            pToDo->setDone();
            std::cout << "todo " << std::quoted(name) << " is now marked as done!";
        }
    }
    else
    {
        std::cout << "no todo with name " << std::quoted(name) << " found!";
    }
    std::cout << std::endl;
}