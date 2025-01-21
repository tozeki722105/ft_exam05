#ifndef B_HPP
#define B_HPP

#include <string>

class ATarget;

class ASpell
{
private:
	ASpell();
	std::string _name;
	std::string _effects;

public:
	ASpell(const std::string &name, const std::string &effects);
	~ASpell();
	ASpell(const ASpell &other);
	ASpell &operator=(const ASpell &other);
	const std::string &getName() const;
	const std::string &getEffects() const;
	virtual ASpell *clone() const = 0;
	void launch(const ATarget &targ) const;
};

#endif