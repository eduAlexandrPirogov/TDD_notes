# Написание первых тестов по TDD

Имеется задача создать конвертер валют.

Программа должна иметь возможность конвертировать одну валюту в другую с учет количества и курса.

Прежде чем писать код, попробуем написать тест. Изначально, написать единый тест, который будет подтверждать верную работу для всех валют с учетом соответствующего курса задача довольно сложная. Разобъем задачу на более простые.

Попробуем реализовать умножение валюты на количество.

Методика TDD говорит -- 
1) Пишем тест
2) Убеждаемся, что тест не запускается/не исполняется
3) Пишем реализацию (если имеется решение "в лоб", пишем это решение, иначе -- создаем заглушки)
4) Убеждаемся, что тест запускается и проходит
5) Рефакторинг

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

Теперь, предположим, что нам нужно возвращать каждый раз новые объект `Dollar` при умножение валют. То есть наш тест будет выглядеть следующим образом:

```cpp
TEST(DollarTest, ReturnNewObject)
{
	Dollar* dollar = new Dollar{ 5 };
	Dollar* product = dollar->times(2);
	EXPECT_EQ(product->getAmount(), 10);
	
	Dollar* three_product = dollar->times(3);
	EXPECT_EQ(three_product->getAmount(), 15);
}
```

Чтобы данные тест работал, изменим метод `void times(int time)` на `Dollar* times(int time)`:

```cpp
Dollar* Dollar::times(int time)
{
	return null; //Заглушка
}
```

Тест запускается, но не проходит.

Изменим на код на следующее:

```cpp
Dollar* Dollar::times(int time)
{
	return new Dollar(amount * time);
}
```
Тест проходит, но не забываем про первый написанный нами тест, который тоже стоит исправить:

```cpp
TEST(DollarTest, Multiply)
{
	Dollar* dollar = new Dollar{ 5 };
	dollar = dollar->times(2);
	EXPECT_EQ(dollar->getAmount(), 10);
}

```

Следующий шаг -- рефакторинг, но поскольку подзадача на этот раз была простой, данный шаг можно пропустить. Но всегда желательно приводить код в опрятный вид.
