#ifndef __CANFLY_H
#define __CANFLY_H
class Canfly
{
protected:
	int speedOfFlyt;

public:

	Canfly(int sof);
	virtual void fly() const = 0 ;
	int getSpeed() { return speedOfFlyt; }
	void setSpeed(int s) { speedOfFlyt = s; }
	
};
#endif
