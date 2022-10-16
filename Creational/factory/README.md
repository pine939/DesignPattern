## Factory Pattern

### 개념

![image](https://user-images.githubusercontent.com/5865308/195593009-cbdfe7e4-a36e-4617-8f7d-bdd18b592d56.png)

* 객체의 생성 처리를 서브 클래스로 분리하여 캡슐화하는 패턴이다. (즉, 객체 생성 부분을 팩토리 클래스에 위임한다.)
* 특정 기능의 구현은 개별 클래스를 통해 제공 되어야 한다. 

### 예제 코드 작성

1. ***심플 팩토리 패턴***

![image](https://user-images.githubusercontent.com/5865308/196029078-ca333531-0744-41a8-ba7c-b340fc00fea9.png)

Cake를 만들어내는 CakeStore객체를 설계해 보자.
이 CakeStore는 공장(SimpleCakeFactory)을 가지고 있어서 가게에서 직접 다양한 종류의 Cake를 생산할 수 있다.

* Cake Type
```c++
enum CakeFlavor {
    CHOCOLATE,
    CHEESE,
    CREAM
};
```

* Product인 Cake의 Interface와 Concrete Class
```c++
class Cake {
public:
    virtual void DescriptCakeName() = 0;
};

// concrete
class ChocolateCake : public Cake {
public:
    void DescriptCakeName() {
        std::cout << "Chocolate Cake" << std::endl;
    }
};

class CheeseCake : public Cake {
public:
    void DescriptCakeName() {
        std::cout << "Cheese Cake" << std::endl;
    }
};

class CreamCake : public Cake {
public:
    void DescriptCakeName() {
        std::cout << "Cream Cake" << std::endl;
    }
};
```

* Creator
```c++
class SimpleCakeFactory {
public:
    Cake* CreateCake(int CakeType) {
        switch (CakeType) {
            case CHOCOLATE:
                return new ChocolateCake();
            case CHEESE:
                return new CheeseCake();
            case CREAM:
                return new CreamCake();
            default:
                return nullptr;
        }
    }
};
```

* Cake Store
```c++
class CakeStore {
public:
    explicit CakeStore(SimpleCakeFactory *CakeFactory) {
        simpleCakeFactory = CakeFactory;
    }

    void OrderCake(int CakeType) {
        Cake *cake;
        cake = simpleCakeFactory->CreateCake(CakeType);
        if (!cake) {
            std::cout << "Undefined Cake Type" << std::endl;
            return;
        }
        cake->DescriptCakeName();
    }
private:
    SimpleCakeFactory *simpleCakeFactory;
};
```

* Client (main)
```c++
int main() {
    CakeStore cakeStore(new SimpleCakeFactory());
    cakeStore.OrderCake(CHOCOLATE);
    cakeStore.OrderCake(CHEESE);
    cakeStore.OrderCake(CREAM);
    return 0;
}
```

* Result
```text
Chocolate Cake
Cheese Cake
Cream Cake
```

2. ***팩토리 메소드 패턴***

![image](https://user-images.githubusercontent.com/5865308/196029405-d04b2c5e-3051-4652-a52f-e00a4707e8a6.png)

CakeStore가 가게를 확장하여 분점을 냈다!  
분점마다 고유 스타일의 Cake를 만든다고 한다.

CakeStore의 CreateCake 메서드를 추상 메서드로 선언한다.   
그리고, CakeStore를 상속받은 ConcreteCake Class들에서 CreateCake메서드를 구현하여 필요한 객체를 생산한다. 

* Product (Cake, Concrete Cake Class)
```c++
enum CakeFlavor {
    CHOCOLATE,
    CHEESE,
    CREAM
};

class Cake {
public:
    virtual void DescriptCakeName() = 0;
};

// concrete
class SeoulStyleChocolateCake : public Cake {
public:
    void DescriptCakeName() {
        std::cout << "SeoulStyle Chocolate Cake" << std::endl;
    }
};

class SeoulStyleCheeseCake : public Cake {
public:
    void DescriptCakeName() {
        std::cout << "SeoulStyle Cheese Cake" << std::endl;
    }
};

class SeoulStyleCreamCake : public Cake {
public:
    void DescriptCakeName() {
        std::cout << "SeoulStyle Cream Cake" << std::endl;
    }
};

class DaejeonStyleChocolateCake : public Cake {
public:
    void DescriptCakeName() {
        std::cout << "DaejeonStyle Chocolate Cake" << std::endl;
    }
};

class DaejeonStyleCheeseCake : public Cake {
public:
    void DescriptCakeName() {
        std::cout << "DaejeonStyle Cheese Cake" << std::endl;
    }
};

class DaejeonStyleCreamCake : public Cake {
public:
    void DescriptCakeName() {
        std::cout << "DaejeonStyle Cream Cake" << std::endl;
    }
};
```

* Creator (CakeStore, Concrete CakeStore Class)
```c++
class CakeStore {
private:
    virtual Cake *CreateCake(int CakeType) = 0;
public:
    void OrderCake(int CakeType) {
        Cake *cake;
        cake = CreateCake(CakeType);
        if (!cake) {
            std::cout << "Undefined Cake Type" << std::endl;
            return;
        }
        cake->DescriptCakeName();
    }
};

class SeoulCakeStore : public CakeStore{
private:
    Cake* CreateCake(int CakeType) {
        switch (CakeType) {
            case CHOCOLATE:
                return new SeoulStyleChocolateCake();
            case CHEESE:
                return new SeoulStyleCheeseCake();
            case CREAM:
                return new SeoulStyleCreamCake();
            default:
                return nullptr;
        }
    }
};

class DaejeonCakeStore : public CakeStore{
private:
    Cake* CreateCake(int CakeType) {
        switch (CakeType) {
            case CHOCOLATE:
                return new DaejeonStyleChocolateCake();
            case CHEESE:
                return new DaejeonStyleCheeseCake();
            case CREAM:
                return new DaejeonStyleCreamCake();
            default:
                return nullptr;
        }
    }
};
```

* Client (main)
```c++
int main() {
    CakeStore *cakeStore = new SeoulCakeStore();
    cakeStore->OrderCake(CHOCOLATE);
    cakeStore->OrderCake(CHEESE);
    cakeStore->OrderCake(CREAM);

    cakeStore = new DaejeonCakeStore();
    cakeStore->OrderCake(CHOCOLATE);
    cakeStore->OrderCake(CHEESE);
    cakeStore->OrderCake(CREAM);
    return 0;
}
```

* Result
```text
SeoulStyle Chocolate Cake
SeoulStyle Cheese Cake
SeoulStyle Cream Cake
DaejeonStyle Chocolate Cake
DaejeonStyle Cheese Cake
DaejeonStyle Cream Cake
```