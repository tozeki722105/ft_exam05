#ifndef E_HPP
#define E_HPP

#include "ATarget.hpp"

class Dummy : public ATarget
{
private:
	/* data */
public:
	Dummy(/* args */);
	~Dummy();
	Dummy(const Dummy &other);
	Dummy &operator=(const Dummy &other);
	Dummy *clone() const;
};

#endif