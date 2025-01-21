#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") {}

Fwoosh::~Fwoosh() {}

Fwoosh::Fwoosh(const Fwoosh &other) : ASpell(other) {}

Fwoosh &Fwoosh::operator=(const Fwoosh &other)
{
	if (this == &other)
		return *this;
	ASpell::operator=(other);
	return *this;
}

Fwoosh *Fwoosh::clone() const
{
	return new Fwoosh();
}