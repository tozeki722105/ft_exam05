#ifndef F_HPP
#define F_HPP

#include <map>
#include <string>

class ASpell;
class ATarget;

class SpellBook
{
private:
	std::map<std::string, ASpell *> _map;
	SpellBook(const SpellBook &other);
	SpellBook &operator=(const SpellBook &other);

public:
	SpellBook(/* args */);
	~SpellBook();
	void learnSpell(ASpell *spell);
	void forgetSpell(const std::string &spellName);
	ASpell *createSpell(const std::string &spellName);
};

#endif