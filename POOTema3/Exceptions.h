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