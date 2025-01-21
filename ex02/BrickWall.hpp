#ifndef BW_HPP
#define BW_HPP

#include "ATarget.hpp"

class BrickWall : public ATarget
{
private:
	/* data */
public:
	BrickWall(/* args */);
	~BrickWall();
	BrickWall(const BrickWall &other);
	BrickWall &operator=(const BrickWall &other);
	BrickWall *clone() const;
};

#endif