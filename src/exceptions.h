#pragma once

#include <stdexcept>
#include <string>

class InvalidCoordinatesError : public std::out_of_range
{
public:
    explicit InvalidCoordinatesError(const std::string &message)
        : std::out_of_range("Invalid coordinates: " + message) {}
};

class EmptyNodeError : public std::logic_error
{
public:
    explicit EmptyNodeError(const std::string &message)
        : std::logic_error("Node error:" + message) {}
};