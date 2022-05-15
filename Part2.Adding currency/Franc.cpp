#include "Franc.h"

Franc::Franc(int amount) :amount(amount)
{
}

Franc* Franc::times(int time)
{
	return new Franc(amount * time);
}

int Franc::getAmount()
{
	return amount;
}

bool Franc::equals(const Franc& other)
{
	return amount == other.amount;
}

