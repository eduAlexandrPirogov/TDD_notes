#pragma once
class Dollar
{
	int amount;
public:

	Dollar() = default;
	Dollar(int amount);

	Dollar* times(int time);
	int getAmount();

	bool equals(const Dollar& other);
};

