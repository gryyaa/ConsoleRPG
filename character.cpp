#include "character.h"
#include <cmath>
#include <iostream>

using namespace std;

/// <summary>
/// Создает характеристики персонажа со стандартными значениями.
/// </summary>
Characteristics::Characteristics() : strength(15), dexterity(14), constitution(13),
	wisdom(12), intelligence(10), charisma(8), armorClass(12) {}

/// <summary>
/// Создает характеристики персонажа с указанными значениями.
/// </summary>
/// <param name="_strength">Сила персонажа.</param>
/// <param name="_dexterity">Ловкость персонажа.</param>
/// <param name="_constitution">Телосложение персонажа.</param>
/// <param name="_wisdom">Мудрость персонажа.</param>
/// <param name="_intelligence">Интеллект персонажа.</param>
/// <param name="_charisma">Харизма персонажа.</param>
/// <param name="_armorClass">Класс доспехов персонажа.</param>
Characteristics::Characteristics(int _strength, int _dexterity, int _constitution,
	int _wisdom, int _intelligence, int _charisma, int _armorClass)
{
	strength = _strength;
	dexterity = _dexterity;
	constitution = _constitution;
	wisdom = _wisdom;
	intelligence = _intelligence;
	charisma = _charisma;
	armorClass = _armorClass;
}

/// <summary>
/// Считает модификатор характеристики.
/// </summary>
/// <param name="characteristic">Значение характеристики.</param>
/// <returns>Модификатор характеристики.</returns>
int Characteristics::CountModificator(int characteristic)
{
	return floor((characteristic - 10) / 2);
}

/// <summary>
/// Выводит текущие характеристики персонажа.
/// </summary>
void Characteristics::PrintCharacteristics()
{
	cout << "---- Ваши текущие характеристики ----" << endl;
	cout << "Сила: " << strength << endl;
	cout << "Ловкость: " << dexterity << endl;
	cout << "Телосложение: " << constitution << endl;
	cout << "Интеллект: " << intelligence << endl;
	cout << "Мудрость: " << wisdom << endl;
	cout << "Харизма: " << charisma << endl;
	cout << "Класс доспехов: " << armorClass << endl;
}

/// <summary>
/// Создает персонажа со стандартными значениями.
/// </summary>
Character::Character()
{
	name = "Безымянный";
	health = 10;
	maxHealth = health;
	healthFlasks = 3;
	damageFace = 4;
	specialCooldown = 0;
	gold = 10;
	uniqueAbilityDifficulty = 10;
	minion = nullptr;
	minionSpawned = false;
	appearance.skinColor = "Не выбран";
	appearance.hairColor = "Не выбран";
}

/// <summary>
/// Создает персонажа с указанными значениями и миньоном.
/// </summary>
/// <param name="_name">Имя персонажа.</param>
/// <param name="_health">Здоровье персонажа.</param>
/// <param name="_damageFace">Количество граней кубика урона.</param>
/// <param name="_specialCooldown">Перезарядка специальной атаки.</param>
/// <param name="_startGold">Начальное золото персонажа.</param>
/// <param name="_minion">Миньон персонажа.</param>
/// <param name="_uniqueAbilityDifficulty">Сложность уникальной способности.</param>
Character::Character(string _name, int _health, int _damageFace, int _specialCooldown,
	int _startGold, Character& _minion, int _uniqueAbilityDifficulty)
{
	name = _name;
	health = _health;
	damageFace = _damageFace;
	maxHealth = health;
	healthFlasks = 3;
	specialCooldown = _specialCooldown;
	minion = &_minion;
	uniqueAbilityDifficulty = _uniqueAbilityDifficulty;
	gold = _startGold;
}

/// <summary>
/// Создает персонажа с указанными значениями без миньона.
/// </summary>
/// <param name="_name">Имя персонажа.</param>
/// <param name="_health">Здоровье персонажа.</param>
/// <param name="_damageFace">Количество граней кубика урона.</param>
/// <param name="_specialCooldown">Перезарядка специальной атаки.</param>
/// <param name="_startGold">Начальное золото персонажа.</param>
Character::Character(string _name, int _health, int _damageFace, int _specialCooldown,
	int _startGold)
{
	name = _name;
	health = _health;
	damageFace = _damageFace;
	maxHealth = health;
	healthFlasks = 3;
	specialCooldown = _specialCooldown;
	gold = _startGold;
}

/// <summary>
/// Возвращает имя персонажа.
/// </summary>
/// <returns>Имя персонажа.</returns>
string Character::GetName() const { return name; }

/// <summary>
/// Возвращает текущее здоровье персонажа.
/// </summary>
/// <returns>Текущее здоровье персонажа.</returns>
int Character::GetHealth() const { return health; }

/// <summary>
/// Возвращает максимальное здоровье персонажа.
/// </summary>
/// <returns>Максимальное здоровье персонажа.</returns>
int Character::GetMaxHealth() const { return maxHealth; }

/// <summary>
/// Возвращает количество золота персонажа.
/// </summary>
/// <returns>Количество золота персонажа.</returns>
int Character::GetGold() const { return gold; }

/// <summary>
/// Устанавливает здоровье персонажа.
/// </summary>
/// <param name="value">Новое значение здоровья.</param>
void Character::SetHealth(int value) { health = value; }

/// <summary>
/// Устанавливает количество золота персонажа.
/// </summary>
/// <param name="value">Новое количество золота.</param>
void Character::SetGold(int value) { gold = value; }

/// <summary>
/// Выводит состояние персонажа.
/// </summary>
void Character::PrintStatus()
{
	cout << name << " — HP: " << health << "/" << maxHealth;
	cout << " | Золото: " << gold << endl;
	cout << "На данный момент у " << name << " " << healthFlasks << " зелий лечения" << endl;
}

/// <summary>
/// Добавляет золото персонажу.
/// </summary>
/// <param name="amount">Количество золота.</param>
void Character::AddGold(int amount)
{
	gold += amount;
	cout << name << " получает " << amount << " золота!" << endl;
}

/// <summary>
/// Убирает золото у персонажа.
/// </summary>
/// <param name="amount">Количество золота.</param>
void Character::RemoveGold(int amount)
{
	gold -= amount;
}

/// <summary>
/// Покупает предмет, если хватает золота.
/// </summary>
/// <param name="cost">Цена предмета.</param>
/// <returns>True, если покупка прошла успешно, иначе false.</returns>
bool Character::BuyItem(int cost)
{
	if (gold >= cost)
	{
		gold -= cost;
		cout << name << " купил предмет за " << cost << " золота!" << endl;
		return true;
	}
	else
	{
		cout << "Недостаточно золота! Нужно: " << cost << ", есть: " << gold << endl;
		return false;
	}
}

/// <summary>
/// Увеличивает здоровье персонажа.
/// </summary>
/// <param name="amount">Количество здоровья.</param>
void Character::IncreaseHealth(int amount)
{
	health += amount;
	if (health > maxHealth) health = maxHealth;
}

/// <summary>
/// Уменьшает здоровье персонажа.
/// </summary>
/// <param name="amount">Количество урона.</param>
void Character::DecreaseHealth(int amount)
{
	health -= amount;
	if (health < 0) health = 0;
}

/// <summary>
/// Выполняет обычную атаку по другому персонажу.
/// </summary>
/// <param name="other">Персонаж, которого атакуют.</param>
void Character::BasicAttack(Character& other)
{
	cout << name << " атакует " << other.GetName() << "..." << endl;
	int damageRoll = RollDice(damageFace);
	other.DecreaseHealth(damageRoll);
	cout << other.GetName() << " получает " << damageRoll << " урона!" << endl;
}

/// <summary>
/// Выполняет специальную атаку персонажа.
/// </summary>
void Character::SpecialAttack()
{
	
	cout << name << " использует специальную атаку!" << endl;
}

/// <summary>
/// Показывает инвентарь персонажа.
/// </summary>
void Character::ShowInventory()
{
	if (inventory.empty())
	{
		cout << "В инвентаре нет предметов!" << endl;
		return;
	}

	for (size_t i = 0; i < inventory.size(); i++)
	{
		cout << i + 1 << ". " << inventory[i].name << endl;
	}
}

/// <summary>
/// Лечит персонажа с помощью зелья лечения.
/// </summary>
/// <param name="difficulty">Сложность лечения.</param>
void Character::Heal(int difficulty)
{
	if (healthFlasks <= 0)
	{
		cout << "У " << name << " нет зелий лечения!" << endl;
		return;
	}
	healthFlasks--;
	IncreaseHealth(maxHealth / 3);
	cout << name << " восстанавливает здоровье!" << endl;
}

/// <summary>
/// Пытается убежать от другого персонажа.
/// </summary>
/// <param name="other">Персонаж, от которого нужно убежать.</param>
/// <returns>True, если побег получился, иначе false.</returns>
bool Character::Flee(Character& other)
{
	int healthPercent = int((double(other.GetHealth()) / double(other.GetMaxHealth())) * 100);
	cout << name << " пытается убежать от " << other.GetName() << "..." << endl;
	return healthPercent < 50; // простой пример
}

/// <summary>
/// Проверяет, получилось ли убежать.
/// </summary>
/// <param name="difficulty">Сложность побега.</param>
/// <returns>True, если побег успешен, иначе false.</returns>
bool Character::CheckFleeSuccess(int difficulty)
{
	
	return true;
}
