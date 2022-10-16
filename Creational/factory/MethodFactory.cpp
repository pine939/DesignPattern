//
// Created by kangdasol on 22. 10. 13.
//

#include <string>
#include <iostream>

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