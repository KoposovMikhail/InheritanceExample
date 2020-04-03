#include <iostream>
#include <string>
using namespace std;

class GameObject
{
private:
	string name;
protected:
	GameObject() : name("") {};
	GameObject(const GameObject& object) : name(object.name) {}
	GameObject(const string& _name) :name(_name) {}
	virtual ~GameObject() { cout << "Game object has been deleted" << endl; }
	virtual void  _print() const { cout << endl << "Name: " << name; }
public:
	void  print() const
	{
		 cout << typeid(*this).name() << ": ";
		_print(); cout << endl;
	}
	virtual void draw() = 0; // Чистая виртуальная функция
};

class Сharacters :public GameObject
{
private:
	int healthpoints;
	int manapoints;
	int X;
	int Y;
public:
	Сharacters() :GameObject() {};
	Сharacters(const string& _name, int _healthpoints, int _manapoints) : GameObject(_name), healthpoints(_healthpoints), manapoints(_manapoints),  X(0), Y(0) {}
	Сharacters(const Сharacters& obj) : GameObject(obj), healthpoints(obj.healthpoints), manapoints(obj.manapoints),  X(obj.X), Y(obj.Y) {}
	Сharacters(const string& _name, int _healthpoints, int _manapoints,  int _X, int _moveY) : GameObject(_name), healthpoints(_healthpoints), manapoints(_manapoints),  X(_X), Y(_moveY) {}
	void _move(int x, int y)
	{
		X += x;
		Y += y;
	} 
	int getX()  { return X; }
	int getY()  { return Y;}
	~Сharacters() { cout << "Character has been deleted" << endl; }
protected:
	virtual void move(int x, int y) = 0; // Чистая виртуальная функция
	void  _print() const override
	{
		GameObject::_print();
		cout << "\nHealthpoints: " << healthpoints << "\nManapoints: " << manapoints <<endl<<"x position: " << X <<endl<<"y position: " << Y;
	}
};

class MythCreation :public Сharacters
{
private:
	string type;
public:
	MythCreation() : Сharacters() {};
	MythCreation(const string& _name, int _healthpoints, int _manapoints,  string _type) :Сharacters(_name, _healthpoints, _manapoints), type(_type) {}
	MythCreation(const MythCreation& obj) : Сharacters(obj), type(obj.type) {}
	MythCreation(const string& _name, int _healthpoints, int _manapoints,  string _type, int _X, int _moveY) :
	Сharacters(_name, _healthpoints, _manapoints,  _X, _moveY), type(_type) {}
	~MythCreation() { cout << "MythCreation has been deleted" << endl; }
	void move(int x, int y) override
	{
		Сharacters::_move(x, y);
		cout << "MythCreation crossed to the coordinates: " << getX() << "," << getY() << endl;
	}
	void draw()
	{
		cout << "Position of MythCreation: " << getX() << "," << getY() << endl;
	}
protected:
	void _print()const override
	{
		Сharacters::_print();
		cout <<endl<<"MythCreation type: " << type;
	}
};

class HumanCharacter :public Сharacters
{
private:
	string weapon;
	int level;
public:
	HumanCharacter() : Сharacters() {};
	HumanCharacter(const string& _name, int _healthpoints, int _manapoints,  string _weapon, int _level) :Сharacters(_name, _healthpoints, _manapoints), weapon(_weapon), level(_level) {}
	HumanCharacter(const HumanCharacter& obj) : Сharacters(obj), weapon(obj.weapon), level(obj.level) {}
	HumanCharacter(const string& _name, int _healthpoints, int _manapoints, int X, int moveY, string _weapon, int _level) :
	Сharacters(_name, _healthpoints, _manapoints), weapon(_weapon), level(_level) {}
	~HumanCharacter() { cout << "Human Character has been deleted" << endl; }
	void move(int x, int y) override
	{
		Сharacters::_move(x, y);
		cout << "Human character crossed to the coordinates: " << getX() << "," << getY() << endl;
	}
	void draw() override { cout << "Human character position: " << getX() << "," << getY() << endl; }	
protected:

	void _print() const override
	{
		Сharacters::_print();
		cout <<endl<<"Human weapon: " << weapon <<endl<<"level: " << level;
	}
};

class MagicCharacter :public Сharacters
{
private:
	string nameMagic;
public:
	MagicCharacter() :Сharacters() {};
	MagicCharacter(const string& _name, int _healthpoints, int _manapoints, string _nameMagic) :Сharacters(_name, _healthpoints, _manapoints), nameMagic(_nameMagic) {}
	MagicCharacter(const MagicCharacter& obj) : Сharacters(obj), nameMagic(obj.nameMagic) {}
	MagicCharacter(const string& _name, int _healthpoints, int _manapoints,  int _X, int _moveY, string _nameMagic) :
	Сharacters(_name, _healthpoints, _manapoints, _X, _moveY), nameMagic(_nameMagic) {}
	~MagicCharacter() { cout << "Magic Character has been deleted" << endl; }
	void move(int x, int y) override
	{
		Сharacters::_move(x, y);
		cout << "Magic character crossed to the coordinates: " << getX() << "," << getY() << endl;
	}
	void draw() override { cout << "Magic Character position: " << getX() << "," << getY() << endl; }
protected:

	void _print()const override
	{
		Сharacters::_print();
		cout <<endl<<"Magic Character: " << nameMagic;
	}
};

class Weapon :public GameObject
{
private:
	int damage;
public:
	Weapon() : GameObject() {};
	Weapon(const string& _name, int _damage) :GameObject(_name), damage(_damage) {}
	Weapon(const Weapon& obj) :GameObject(obj), damage(obj.damage) {}
	~Weapon() { cout << "Weapon has been deleted" << endl; }
protected:
	void draw() override { cout << "Character with next weapon: "; }
	void _print()const override
	{
		GameObject::_print();
		cout <<endl<<"Damage: " << damage ;
	}
};

int main()
{
	MythCreation merveil("Merveil, the Siren", 200, 500, "Siren");
	MagicCharacter sin("Sin, Thief of Virtue", 150, 100, "None");
	Weapon lakishu("Lakishu's Blade", 15);
	merveil.draw();	
	merveil.move(20, 50);
	merveil.print(); cout << endl;
	sin.draw();
	sin.move(10, 35);
	sin.print(); cout << endl;
	lakishu.print();
}