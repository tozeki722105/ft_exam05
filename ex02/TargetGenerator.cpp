#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(/* args */) {}

TargetGenerator::~TargetGenerator()
{
	std::map<std::string, ATarget *>::iterator i = _map.begin();
	for (; i != _map.end(); i++) {
		delete i->second;
	}
}

void TargetGenerator::learnTargetType(ATarget *targ)
{
	if (!targ)
		return;
	_map.insert(make_pair(targ->getType(), targ->clone()));
}
void TargetGenerator::forgetTargetType(const std::string &type)
{
	std::map<std::string, ATarget *>::iterator it = _map.find(type);
	if (it == _map.end())
		return;
	delete it->second;
	_map.erase(it);
}

ATarget *TargetGenerator::createTarget(const std::string &type)
{
	std::map<std::string, ATarget *>::iterator it = _map.find(type);
	if (it == _map.end())
		return NULL;
	return it->second->clone();
}