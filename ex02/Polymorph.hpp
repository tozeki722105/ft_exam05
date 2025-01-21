#ifndef PL_HPP
#define PL_HPP

#include "ASpell.hpp"

class Polymorph : public ASpell
{
private:
	/* data */
public:
	Polymorph();
	~Polymorph();
	Polymorph(const Polymorph &other);
	Polymorph &operator=(const Polymorph &other);
	Polymorph *clone() const;
};

#endif