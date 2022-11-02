//
// Created by kangdasol on 22. 11. 2.
//

#include <string>
#include <iostream>
#include <map>

class Monster
{
public:
    Monster() {}
    Monster(const Monster& rhs) {}
    virtual ~Monster() {}
    void PrintName()
    {
        std::cout << "My Name is " << name_ << std::endl;
    }
    virtual Monster* Clone_Object() = 0;
protected:
    std::string name_;
};

class Poring : Monster
{
public:
    Poring() {}
    Poring(const Poring& rhs) {}
    virtual ~Poring() {}

    static Monster* CreateMonster()
    {
        Poring *poring = new Poring();
        poring->Initialize();
        return poring;
    }

    Monster* Clone_Object() override
    {
        return new Poring(*this);
    }
private:
    void Initialize()
    {
        // I/O Logic
        name_ = "Poring";
    }
};

class Lunatic : Monster
{
public:
    Lunatic() {}
    Lunatic(const Poring& rhs) {}
    virtual ~Lunatic() {}

    static Monster* CreateMonster()
    {
        Lunatic *lunatic = new Lunatic();
        lunatic->Initialize();
        return lunatic;
    }

    Monster* Clone_Object() override
    {
        return new Lunatic(*this);
    }
private:
    void Initialize()
    {
        // I/O Logic
        name_ = "Lunatic";
    }
};

class MonsterManager
{
public:
    void Add_Monster_Prototype(std::string type, Monster *monster_prototype)
    {
        monster_prototype_group_.insert({type.c_str(), monster_prototype});
    }

    Monster* Clone_Monster(std::string type)
    {
        Monster *monster = nullptr;
        std::map<std::string, Monster*>::iterator iter;
        iter = monster_prototype_group_.find(type.c_str());
        if (iter != monster_prototype_group_.end())
        {
            monster = iter->second->Clone_Object();
        }
        return monster;
    }
private:
    std::map<std::string, Monster*> monster_prototype_group_;
};

int main()
{
    MonsterManager monster_manager;
    monster_manager.Add_Monster_Prototype("Poring", Poring::CreateMonster());
    monster_manager.Add_Monster_Prototype("Lunatic", Lunatic::CreateMonster());

    Monster* Poring = monster_manager.Clone_Monster("Poring");
    Monster* Lunatic = monster_manager.Clone_Monster("Lunatic");

    Poring->PrintName();
    Lunatic->PrintName();
    return 0;
}