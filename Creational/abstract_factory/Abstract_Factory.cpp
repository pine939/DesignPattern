//
// Created by kangdasol on 22. 10. 17.
//

#include <iostream>

enum CakeFlavor {
    CHOCOLATE,
    CHEESE,
    CREAM
};

/* INGREDIENT(PRODUCT) */
class Flour {
public:
    virtual void DescriptFlourName() = 0;
};

class Milk {
public:
    virtual void DescriptMilkName() = 0;
};

class Sugar {
public:
    virtual void DescriptSugarName() = 0;
};

class RedFlour : public Flour {
public:
    void DescriptFlourName() override {
        std::cout << "RedFlour" << std::endl;
    }
};

class BlueFlour : public Flour {
public:
    void DescriptFlourName() override {
        std::cout << "BlueFlour" << std::endl;
    }
};

class BananaMilk : public Milk {
public:
    void DescriptMilkName() override {
        std::cout << "BananaMilk" << std::endl;
    }
};

class CoffeeMilk : public Milk {
public:
    void DescriptMilkName() override {
        std::cout << "CoffeeMilk" << std::endl;
    }
};

class WhiteSugar : public Sugar{
public:
    void DescriptSugarName() override {
        std::cout << "WhiteSugar" << std::endl;
    }
};

class BlackSugar : public Sugar{
public:
    void DescriptSugarName() override {
        std::cout << "BlackSugar" << std::endl;
    }
};

/* INGREDIENT INTERFACE(ABSTRACT) FACTORY  */
class CakeIngredientFactory {
public:
    virtual Flour* CreateFlour() = 0;
    virtual Milk* CreateMilk() = 0;
    virtual Sugar* CreateSugar() = 0;
};

/* INGREDIENT CONCRETE FACTORY */
class SeoulCakeIngredientFactory : public CakeIngredientFactory {
public:
    Flour* CreateFlour() override {
        return new BlueFlour();
    }

    Milk* CreateMilk() override {
        return new BananaMilk();
    }

    Sugar* CreateSugar() override {
        return new WhiteSugar();
    }
};

class DaejeonCakeIngredientFactory : public CakeIngredientFactory {
public:
    Flour* CreateFlour() override {
        return new RedFlour();
    }

    Milk* CreateMilk() override {
        return new CoffeeMilk();
    }

    Sugar* CreateSugar() override {
        return new BlackSugar();
    }
};

/* CAKE */
class Cake {
public:
    virtual void PrePare() = 0;
};

class ChocolateCake : public Cake {
public:
    ChocolateCake(CakeIngredientFactory *ingredientFactory) {
        ingredientFactory1 = ingredientFactory;
    }
    void PrePare() override {
        ingredientFactory1->CreateFlour();
        ingredientFactory1->CreateMilk();
        ingredientFactory1->CreateSugar();
    }
private:
    CakeIngredientFactory *ingredientFactory1;
};

class CheeseCake : public Cake {
public:
    CheeseCake(CakeIngredientFactory *ingredientFactory) {
        ingredientFactory1 = ingredientFactory;
    }
    void PrePare() override {
        ingredientFactory1->CreateFlour()->DescriptFlourName();
        ingredientFactory1->CreateMilk()->DescriptMilkName();
        ingredientFactory1->CreateSugar()->DescriptSugarName();
    }
private:
    CakeIngredientFactory *ingredientFactory1;
};

class CreamCake : public Cake {
public:
    CreamCake(CakeIngredientFactory *ingredientFactory) {
        ingredientFactory1 = ingredientFactory;
    }
    void PrePare() override {
        ingredientFactory1->CreateFlour();
        ingredientFactory1->CreateMilk();
        ingredientFactory1->CreateSugar();
    }
private:
    CakeIngredientFactory *ingredientFactory1;
};

/* CAKE STORE */
class CakeStore {
private:
    virtual Cake* CreateCake(int CakeType) = 0;
public:
    void OrderCake(int CakeType) {
        Cake *cake = CreateCake(CakeType);
        cake->PrePare();
    }
};

class SeoulCakeStore : public CakeStore {
private:
    Cake* CreateCake(int CakeType) override {
        Cake *cake = nullptr;
        CakeIngredientFactory *ingredientFactory = new SeoulCakeIngredientFactory();

        switch (CakeType) {
            case CHOCOLATE:
                cake = new ChocolateCake(ingredientFactory);
                break;
            case CHEESE:
                cake = new CheeseCake(ingredientFactory);
                break;
            case CREAM:
                cake = new CreamCake(ingredientFactory);
                break;
            default:
                break;
        }
        return cake;
    }
};

class DaejeonCakeStore : public CakeStore {
private:
    Cake* CreateCake(int CakeType) override {
        Cake *cake = nullptr;
        CakeIngredientFactory *ingredientFactory = new DaejeonCakeIngredientFactory();

        switch (CakeType) {
            case CHOCOLATE:
                cake = new ChocolateCake(ingredientFactory);
                break;
            case CHEESE:
                cake = new CheeseCake(ingredientFactory);
                break;
            case CREAM:
                cake = new CreamCake(ingredientFactory);
                break;
            default:
                break;
        }
        return cake;
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