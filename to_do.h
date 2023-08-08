#pragma once
#include <string>
#include <vector>
#include <chrono>

class ToDo
{

public:
    enum class Status
    {
        todo,
        done
    };
    static std::vector<std::string> statusNames;
    using TimePoint = std::chrono::time_point<std::chrono::system_clock>;

private:
    std::string name;
    Status status;
    long long unsigned id;
    static long long unsigned currentId;
    TimePoint timePoint;

public:
    ToDo(const std::string&, const TimePoint&);

    std::string getName() const;
    Status getStatus() const;
    long long unsigned getId() const;
    TimePoint getTimePoint() const;
    
    bool setStatus(Status);
    bool setTimePoint(const TimePoint&);
};