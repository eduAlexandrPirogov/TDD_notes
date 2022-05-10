#include "Dollar.h"

Dollar::Dollar(int amount) :amount(amount)
{
}

Dollar* Dollar::times(int time)
{
	return new Dollar(amount * time);
}

int Dollar::getAmount()
{
	return amount;
}
