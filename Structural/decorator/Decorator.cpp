//
// Created by kangdasol on 22. 11. 3.
//

#include <iostream>

class Item
{
public:
    virtual void DoubleSpeed() = 0;
};

class DefaultItem : public Item
{
public:
    void DoubleSpeed() override
    {
        std::cout << "double speed!!!" << std::endl;
    }
};

class DecorateItem : public Item
{
public:
    explicit DecorateItem(Item *item) : item_(item) {}
    void DoubleSpeed() override
    {
        item_->DoubleSpeed();
    }

private:
    Item *item_;
};

class UpgradeDamageDecorateItem : public DecorateItem
{
public:
    explicit UpgradeDamageDecorateItem(Item *item)
    : DecorateItem(item) {}
    void DoubleSpeed() override
    {
        DecorateItem::DoubleSpeed();
        UpgradeDamage();
    }

    static void UpgradeDamage()
    {
        std::cout << "upgrade 10% damage!!!" << std::endl;
    }
};

class UpgradeDefenseDecorateItem : public DecorateItem
{
public:
    explicit UpgradeDefenseDecorateItem(Item *item)
    : DecorateItem(item) {}
    void DoubleSpeed() override
    {
        DecorateItem::DoubleSpeed();
        UpgradeDefense();
    }

    static void UpgradeDefense()
    {
        std::cout << "upgrade 20% defense!!!" << std::endl;
    }
};

class Goblin
{
public:
    explicit Goblin(Item *item)
    : item_(item){}

    void SetStatusWithItem()
    {
        item_->DoubleSpeed();
    }
private:
    Item *item_;
};

int main()
{
    std::cout << "=== Default ===" << std::endl;
    Item *item = new DefaultItem();
    Goblin *goblin = new Goblin(item);
    goblin->SetStatusWithItem();

    std::cout << "=== Default + Upgrade Damage ===" << std::endl;
    item = new UpgradeDamageDecorateItem(item);
    goblin = new Goblin(item);
    goblin->SetStatusWithItem();

    std::cout << "=== Default + Upgrade Damage + Upgrade Defense ===" << std::endl;
    item = new UpgradeDefenseDecorateItem(item);
    goblin = new Goblin(item);
    goblin->SetStatusWithItem();
    return 0;
}