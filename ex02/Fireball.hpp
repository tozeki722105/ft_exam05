#ifndef FB_HPP
#define FB_HPP

#include "ASpell.hpp"

class Fireball : public ASpell
{
private:
	/* data */
public:
	Fireball();
	~Fireball();
	Fireball(const Fireball &other);
	Fireball &operator=(const Fireball &other);
	Fireball *clone() const;
};

#endif