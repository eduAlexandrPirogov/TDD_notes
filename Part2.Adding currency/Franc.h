#pragma once
class Franc
{
	int amount;
public:

	Franc() = default;
	Franc(int amount);

	Franc* times(int time);
	int getAmount();

	bool equals(const Franc& other);
};



