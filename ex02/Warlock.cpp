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
	_book.learnSpell(spell);
}

void Warlock::forgetSpell(const std::string &spellName)
{
	_book.forgetSpell(spellName);
}

void Warlock::launchSpell(const std::string &spellName, ATarget &target)
{
	ASpell *spell = _book.createSpell(spellName);
	if (!spell)
		return;
	spell->launch(target);
	delete spell;
}