#include <iostream>
#include <list>
#include "to_do.h"
#include <string>
#include <iomanip>
#include "cli.h"
#include "temp_to_do_model.h"

int main()
{
    std::cout << "welcome to the to-do-list, enter h to see help\n";
    std::unique_ptr<ToDoModel> toDoModel{std::make_unique<TempToDoModel>()};
    CLI cli{std::move(toDoModel)};
    cli.repl();

    return 0;
}
