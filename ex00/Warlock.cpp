#include "Warlock.hpp"

#include <iostream>

Warlock::Warlock(const std::string &name, const std::string &title) : _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!\n";
}

Warlock::Warlock(const Warlock &other)
{
	*this = other;
}

Warlock &Warlock::operator=(const Warlock &other)
{
	if (this == &other)
		return *this;
	_name = other._name;
	_title = other._title;
	return *this;
}

const std::string &Warlock::getTitle() const
{
	return _title;
}

const std::string &Warlock::getName() const
{
	return _name;
}

void Warlock::setTitle(const std::string &title)
{
	_title = title;
}

void Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!\n";
}