## Abstract Factory Pattern 

### 개념

![image](https://user-images.githubusercontent.com/5865308/196193425-ce1c0f6f-960a-4fee-941c-38d366ecb148.png)

서로 연관 있는 여러 객체를 만들어주는 인터페이스이다.   
구체적으로 어떤 클래스의 인스턴스를(concrete product)를 사용하는지 감출 수 있다.


### 예제 코드 작성

CakeStore의 서울지점과 대전지점에서 Cake를 만들 때 중복되는 재료가 있다.   
두 가게 모두 케익을 만드는 스타일은 다르지만 같은 종류의 밀가루, 우유, 설탕이 필요하다.   
이러한 부분을 묶어서 팩토리화 하는 것이 추상 팩토리 패턴이다.

구체적인 재료들은 어떤 팩토리를 쓰는지에 따라 달라진다.

* Cake Type 
```c++
enum CakeFlavor {
    CHOCOLATE,
    CHEESE,
    CREAM
};
```
* Cake Ingredient
```c++
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
//// Concrete 
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
```
* Cake Ingredient Factory
```c++
class CakeIngredientFactory {
public:
    virtual Flour* CreateFlour() = 0;
    virtual Milk* CreateMilk() = 0;
    virtual Sugar* CreateSugar() = 0;
};
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
```
* Cake
```c++
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
```
* Cake Store
```c++
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
```
* Client
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
BlueFlour
BananaMilk
WhiteSugar
RedFlour
CoffeeMilk
BlackSugar
```