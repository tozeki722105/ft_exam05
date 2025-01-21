
#include "ASpell.hpp"

#include "ATarget.hpp"

ASpell::ASpell(const std::string &name, const std::string &effects) : _name(name), _effects(effects)
{
}

ASpell::~ASpell() {}

ASpell::ASpell(const ASpell &other)
{
	*this = other;
}

ASpell &ASpell::operator=(const ASpell &other)
{
	if (this == &other)
		return *this;
	_name = other._name;
	_effects = other._effects;
	return *this;
}

const std::string &ASpell::getName() const
{
	return _name;
}

const std::string &ASpell::getEffects() const
{
	return _effects;
}

void ASpell::launch(const ATarget &targ) const
{
	targ.getHitBySpell(*this);
}