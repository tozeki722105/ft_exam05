#ifndef A_HPP
#define A_HPP

#include <string>

#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock
{
private:
	Warlock();
	Warlock(const Warlock &other);
	Warlock &operator=(const Warlock &other);
	std::string _name;
	std::string _title;
	SpellBook _book;

public:
	Warlock(const std::string &name, const std::string &title);
	~Warlock();
	const std::string &getName() const;
	const std::string &getTitle() const;
	void setTitle(const std::string &title);
	void introduce() const;
	void learnSpell(ASpell *spell);
	void forgetSpell(const std::string &spellName);
	void launchSpell(const std::string &spellName, ATarget &target);
};

#endif