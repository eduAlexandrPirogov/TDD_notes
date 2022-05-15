# Добавление новой валюты

Для приложения "Конвертер валют" требуется, как ни странно :), наличие нескольких валют. Добавим новую валюту франк.

Но прежде, вернемся на минутку к доллару и...

## Паттерн Object Value

Данный паттерн указывает, что значения объекта должны устанавливаться в конструкторе и более не изменяться в этом же объекте. Это позволяет избежать изменения состояния объекта.

## Сравнение объектов

Сравнивая валюты, мы понимаем, что 10 долларов не равно 10 франкам. И зеленое яблоко не равно красному яблоку.
Мы сравниваем объекты по их классам, а затем по их характеристикам.

Воспользуемся паттерном `Object Value` и напишем тест на проверки равенства для класса `Dollar`.

Вспомним шаги TDD:
1) Пишем тест
```cpp
TEST(DollarTest, TestEquality)
{
	EXPECT_TRUE((new Dollar(5))->equals(*(new Dollar(5))));
	EXPECT_TRUE((new Dollar(0))->equals(*(new Dollar(0))));
	EXPECT_FALSE((new Dollar(5))->equals(*(new Dollar(15))));
	EXPECT_FALSE((new Dollar(0))->equals(*(new Dollar(5))));
}
```
2) Убеждаемся, что он не запустится
3) Пишем простейшую реализацию (если видим решением в лоб -- пишем решение, иначе -- заглушку)
bool Dollar::equals(const Dollar& other)
{
	return amount == other.amount;
}

4) Убеждаемся, что тест проходит
5) Рефакторим

_____

## Возвращаемся к франкам

Создадим класс...опять же по методике TDD, сначала создаем тесты :)

Если посмотреть на наш пример, то можно сказать, что `Franc` ничем не отличается от `Dollar`. Посему, смело скопируем все тесты для класса `Dollar`. 

**Лучше всего создавать каждый тест итеративно, но в данном случае нам повезло**

Тесты для класса `Franc`:

```cpp
TEST(FrancTest, Multiply)
{
	Franc* franc = new Franc{ 5 };
	franc = franc->times(2);
	EXPECT_EQ(franc->getAmount(), 10);
}

TEST(FrancTest, ReturnNewObject)
{
	Franc* franc = new Franc{ 5 };
	Franc* product = franc->times(2);
	EXPECT_EQ(product->getAmount(), 10);

	Franc* three_product = franc->times(3);
	EXPECT_EQ(three_product->getAmount(), 15);
}

TEST(FrancTest, TestEquality)
{
	EXPECT_TRUE((new Franc(5))->equals(*(new Franc(5))));
	EXPECT_TRUE((new Franc(0))->equals(*(new Franc(0))));
	EXPECT_FALSE((new Franc(5))->equals(*(new Franc(15))));
	EXPECT_FALSE((new Franc(0))->equals(*(new Franc(5))));
}
```

Тесты не сработали, поскольку мы не создали класс `Franc`. Будет он идентичен классу `Dollar`:

`Franc.h`
```cpp
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
```

`Franc.cpp`
```cpp
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

```

Да, у нас получилось огромное количество дублированного кода и в тестах, и в классах. Но рефакторинг в TDD стоит на последнем месте. Об этом поговорим далее в 3-ей части...
