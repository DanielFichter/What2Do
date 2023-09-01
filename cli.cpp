#include "cli.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <chrono>

CLI::CLI(std::unique_ptr<ToDoModel> &&model) : todos{std::move(model)}, helpMessage{"n for new to-do\nl for list all to-dos\ne for exit\nh for help\nm for marking as done"}
{
}

void CLI::addToDo() noexcept
{
    std::cout << "enter name of to-do: " << std::endl;
    std::string name;
    std::getline(std::cin, name);
    std::getline(std::cin, name);
    std::cout << "enter timepoint of the todo: " << std::endl;
    std::tm time;
    std::cin >> std::get_time(&time, "%Y-%m-%d");

    std::chrono::days duration{std::chrono::days(time.tm_yday + 1)};
    duration += std::chrono::duration_cast<std::chrono::days>(std::chrono::years(time.tm_year - 70));
    ToDo::TimePoint timePoint{duration};
    todos->pushBack(ToDo(name, timePoint));
    std::cout << "to-do with name " << std::quoted(name) << " was added " << std::endl;
}

void CLI::listToDos() const noexcept
{
    for (const ToDo &todo : todos->getTodoList())
    {
        const std::time_t time = std::chrono::system_clock::to_time_t(todo.getTimePoint());
        std::cout << todo.getId() << " " << todo.getName() << " " << std::put_time(std::localtime(&time), "%d.%m.%Y") << " "
                  << ToDo::statusNames.at(static_cast<size_t>(todo.getStatus())) << std::endl;
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
        else if (input == "n")
        {
            addToDo();
        }
        else if (input == "l")
        {
            listToDos();
        }
        else if (input == "m")
        {
            markToDoAsDone();
        }
        else if (input == "e")
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
        if (pToDo->getStatus() == ToDo::Status::done)
        {
            std::cout << "todo " << std::quoted(name) << " is already marked as done!";
        }
        else
        {
            pToDo->setStatus(ToDo::Status::done);
            std::cout << "todo " << std::quoted(name) << " is now marked as done!";
        }
    }
    else
    {
        std::cout << "no todo with name " << std::quoted(name) << " found!";
    }
    std::cout << std::endl;
}