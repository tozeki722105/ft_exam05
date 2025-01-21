#include "Fireball.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp") {}

Fireball::~Fireball() {}

Fireball::Fireball(const Fireball &other) : ASpell(other) {}

Fireball &Fireball::operator=(const Fireball &other)
{
	if (this == &other)
		return *this;
	ASpell::operator=(other);
	return *this;
}

Fireball *Fireball::clone() const
{
	return new Fireball();
}