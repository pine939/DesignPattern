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

int main() {
    CakeStore cakeStore(new SimpleCakeFactory());
    cakeStore.OrderCake(CHOCOLATE);
    cakeStore.OrderCake(CHEESE);
    cakeStore.OrderCake(CREAM);
    return 0;
}