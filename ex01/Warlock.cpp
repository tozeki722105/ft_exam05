#include "Warlock.hpp"

#include <iostream>

Warlock::Warlock(const std::string &name, const std::string &title) : _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
	std::map<std::string, ASpell *>::iterator i = _map.begin();
	for (i; i != _map.end(); i++) {
		delete i->second;
	}
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
	_map = other._map;
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

void Warlock::learnSpell(ASpell *spell)
{
	if (!spell)
		return;
	_map.insert(make_pair(spell->getName(), spell->clone()));
}

void Warlock::forgetSpell(const std::string &spellName)
{
	std::map<std::string, ASpell *>::iterator it = _map.find(spellName);
	if (it == _map.end())
		return;
	delete it->second;
	_map.erase(it);
}

void Warlock::launchSpell(const std::string &spellName, ATarget &target)
{
	std::map<std::string, ASpell *>::iterator it = _map.find(spellName);
	if (it == _map.end())
		return;
	it->second->launch(target);
}