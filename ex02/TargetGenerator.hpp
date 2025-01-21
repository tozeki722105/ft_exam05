#ifndef G_HPP
#define G_HPP

#include <map>
#include <string>

#include "ATarget.hpp"

class TargetGenerator
{
private:
	TargetGenerator(const TargetGenerator &other);
	TargetGenerator &operator=(const TargetGenerator &other);
	std::map<std::string, ATarget *> _map;

public:
	TargetGenerator();
	~TargetGenerator();
	void learnTargetType(ATarget *targ);
	void forgetTargetType(const std::string &type);
	ATarget *createTarget(const std::string &type);
};

#endif