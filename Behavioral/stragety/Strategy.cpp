//
// Created by kangdasol on 22. 10. 9.
//

#include <iostream>

// Speed (Interface)
class Speed {
public:
    virtual void BlueLight() = 0;
    virtual void RedLight() = 0;
};

// Context
class BlueLightRedLight {
public:
    explicit BlueLightRedLight(Speed *speed1) : speed(speed1) {}
    void BlueLight() {
        speed->BlueLight();
    }

    void RedLight() {
        speed->RedLight();
    }

private:
    Speed *speed;
};

// Concrete Strategy
class Normal : public Speed {
public:
    virtual void BlueLight() {
        std::cout << "무궁화     꽃     이" << std::endl;
    }

    virtual void RedLight() {
        std::cout << "피었   습 니  다" << std::endl;
    }
};

class Faster : public Speed {
public:
    virtual void BlueLight() {
        std::cout << "무궁화꽃이" << std::endl;
    }

    virtual void RedLight() {
        std::cout << "피었습니다" << std::endl;
    }
};

// Client
int main() {
    BlueLightRedLight *game = new BlueLightRedLight(new Normal());
    game->BlueLight();
    game->RedLight();

    BlueLightRedLight *game2 = new BlueLightRedLight(new Faster());
    game2->BlueLight();
    game2->RedLight();
    return 0;
}