#ifndef D_HPP
#define D_HPP

#include "ASpell.hpp"

class Fwoosh : public ASpell
{
private:
	/* data */
public:
	Fwoosh();
	~Fwoosh();
	Fwoosh(const Fwoosh &other);
	Fwoosh &operator=(const Fwoosh &other);
	Fwoosh *clone() const;
};

#endif