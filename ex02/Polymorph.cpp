#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter") {}

Polymorph::~Polymorph() {}

Polymorph::Polymorph(const Polymorph &other) : ASpell(other) {}

Polymorph &Polymorph::operator=(const Polymorph &other)
{
	if (this == &other)
		return *this;
	ASpell::operator=(other);
	return *this;
}

Polymorph *Polymorph::clone() const
{
	return new Polymorph();
}