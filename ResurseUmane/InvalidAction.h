#pragma once

class InvalidAction : public std::exception
{
public:
    InvalidAction() = default;

    const char *what() const noexcept override 
    {
        return "cxc";
    }
};
