#include "SpellBook.hpp"

#include "ASpell.hpp"
#include "ATarget.hpp"

SpellBook::SpellBook(/* args */) {}

SpellBook::~SpellBook()
{
	std::map<std::string, ASpell *>::iterator i = _map.begin();
	for (i; i != _map.end(); i++) {
		delete i->second;
	}
}

void SpellBook::learnSpell(ASpell *spell)
{
	if (!spell)
		return;
	_map.insert(make_pair(spell->getName(), spell->clone()));
}

void SpellBook::forgetSpell(const std::string &spellName)
{
	std::map<std::string, ASpell *>::iterator it = _map.find(spellName);
	if (it == _map.end())
		return;
	delete it->second;
	_map.erase(it);
}

ASpell *SpellBook::createSpell(const std::string &spellName)
{
	std::map<std::string, ASpell *>::iterator it = _map.find(spellName);
	if (it == _map.end())
		return NULL;
	return it->second->clone();
}