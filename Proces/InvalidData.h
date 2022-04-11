#pragma once
#include <iostream>
#include <string>

class InvalidData : public std::exception
{

public:


    InvalidData() = default;

    const char *what() const noexcept override
    {
        return "nu ai pus numar cand am dorit sa am numar  ;)))))))))))))))) lol get gud";
    }
};
