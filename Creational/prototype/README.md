## ProtoType Pattern

![image](https://user-images.githubusercontent.com/5865308/197516815-315a9433-fe23-4ba7-bc8a-734bc4d50e6e.png)

### 개념 

프로토타입 패턴은 미리 원형 클래스를 생성해 놓고, 그 원형 클래스를 복사하는 형태로써 생성하는 패턴이다.   
예시로, 몬스터를 생성할 때 파일 I/O관련 로직이 들어간다면 그 몬스터를 생성할 때 마다 I/O 동작을 수행하므로 부하가 발생할 수 있다.   
따라서 몬스터 클래스를 미리 만들어 놓고, 필요할 때 해당 클래스를 복사하면 오버헤드를 줄일 수 있을 것이다.

### 예제 코드 작성

포링과 루나틱이라는 몬스터를 Monster클래스를 상속받아, Prototype으로 생성해 본다.

1. Prototype Interface

몬스터 클래스는 원형을 복사할 수 있는 Clone_Object()메서드를 가지고 있는 추상 클래스이다.

```c++
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
```

2. Concrete Prototype

포링과 루나틱은 몬스터 클래스를 상속받아 Clone_Object()메서드를 구현한 몬스터들이다. 각 몬스터들을 생성할 때, Initialize()함수에서 복잡한 I/O 동작을 한다고 가정하였다.   
CreateMonster()에서는 원형을 생성하고 초기화 메서드(Initialize())를 호출하며, Clone_Object()에서는 원형을 복사하여 리턴한다.

```c++
class Poring : Monster
{
public:
    Poring() {}
    Poring(const Poring& rhs) {}
    virtual ~Poring() {}

    static Monster* CreateMoster()
    {
        Poring *poring = new Poring();
        poring->Initialize();
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
    Lunatic() {}
    Lunatic(const Poring& rhs) {}
    virtual ~Lunatic() {}

    static Monster* CreateMoster()
    {
        Lunatic *lunatic = new Lunatic();
        lunatic->Initialize();
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
```

3. 몬스터 관리 클래스 

몬스터 프로토타입을 맵으로 가지고 있는 클래스이다.   
몬스터 프로토타입을 등록하고, 타입에 해당하는 몬스터의 복사본을 리턴하는 메서드로 구성되어 있다.

```c++
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
```

4. Client 

```c++
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
```
