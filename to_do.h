#pragma once
#include <string>
#include <vector>

class ToDo
{

public:
    enum class Status
    {
        todo,
        done
    };
    static std::vector<std::string> statusNames;

private:
    std::string name;
    Status status;
    long long unsigned id;
    static long long unsigned currentId;

public:
    ToDo(const std::string&);

    std::string getName() const;
    Status getStatus() const;
    long long unsigned getId() const;

    bool setStatus(Status);
};