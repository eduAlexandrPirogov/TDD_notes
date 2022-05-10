# Написание первых тестов по TDD

Имеется задача создать конвертер валют.

Программа должна иметь возможность конвертировать одну валюту в другую с учет количества и курса.

Прежде чем писать код, попробуем написать тест. Изначально, написать единый тест, который будет подтверждать верную работу для всех валют с учетом соответствующего курса задача довольно сложная. Разобъем задачу на более простые.

Попробуем реализовать умножение валюты на количество.

Методика TDD говорит -- 
1) Пишем тест, который не исполняется
2) Если не видем прямого решения, заполняем заглушками
3) Как только тест проходит -- рефакторим.

Напишем первый тест умножения:

```cpp
TEST(DollarTest, Multiply)
{
	Dollar* dollar = new Dollar{ 5 };
	dollar = dollar->times(2);
	EXPECT_EQ(dollar->getAmount(), 10);
}
```

Тест не запуститься, поскольку отсутствует класс `Dollar`. Создадим интерфейс для него:

`Dolar.h`
```cpp
#pragma once
class Dollar
{
	int amount;
public:

	Dollar() = default;
	Dollar(int amount);

	void times(int time);
	int getAmount();
};
```

И создадим опреления-заглушки для данного класса:

`Dollar.cpp v1`
```cpp
#include "Dollar.h"

Dollar::Dollar(int amount) :amount(amount)
{
}

void Dollar::times(int time)
{
	
}

int Dollar::getAmount()
{
	return 0;
}

```

Запустив тест, ожидаемо он не пройдет, но уже подскажет, что результаты, который он ожидал и который получил -- отличаются.
Дополним реализацией в лоб, так как данный пример простой.

`Dollar.cpp v2`
```cpp
#include "Dollar.h"

Dollar::Dollar(int amount) :amount(amount)
{
}

void Dollar::times(int time)
{
	 amount = amount * time;
}

int Dollar::getAmount()
{
	return amount;
}
```

Теперь тест проходит. Небольшой рефакторинг в методе `void times(int time)` не повредит.
```cpp
amount *= time;
```
-----
