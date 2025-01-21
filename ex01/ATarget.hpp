#ifndef C_HPP
#define C_HPP

#include <string>

class ASpell;

class ATarget
{
private:
	std::string _type;

public:
	ATarget(const std::string &type);
	~ATarget();
	ATarget(const ATarget &other);
	ATarget &operator=(const ATarget &other);
	const std::string &getType() const;
	virtual ATarget *clone() const = 0;
	void getHitBySpell(const ASpell &spell) const;
};

#endif