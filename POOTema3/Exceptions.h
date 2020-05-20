#pragma once
#include <iostream>
#include <exception>

class NoClassFound : public std::exception {
public:
    NoClassFound() noexcept {}
    NoClassFound(const NoClassFound&) noexcept = default;
    NoClassFound& operator= (const NoClassFound&) noexcept = default;
    virtual ~NoClassFound() noexcept = default;
    const char* what() const throw() {
        return "The Factory could not locate a class type for the given input";
    }
};

class CarNotFound : public std::exception {
public:
    CarNotFound() noexcept {}
    CarNotFound(const CarNotFound&) noexcept = default;
    CarNotFound& operator= (const CarNotFound&) noexcept = default;
    virtual ~CarNotFound() noexcept = default;
    const char* what() const throw() {
        return "No car found with the given details";
    }
};