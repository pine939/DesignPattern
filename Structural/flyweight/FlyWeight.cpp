//
// Created by kangdasol on 22. 12. 4.
//

#include <string>
#include <utility>
#include <iostream>
#include <map>
#include <algorithm>
#include <memory>

class Tree
{
public:
    explicit Tree(std::string color) : color_(std::move(color)) {}

    void SetX(int x)
    {
        x_ = x;
    }

    void SetY(int y)
    {
        y_ = y;
    }

    void InstallTree()
    {
        std::cout << "Install Tree at x: " << x_ << ", y:" << y_ << ", And color: " << color_ << std::endl;
    }
private:
    std::string color_;
    int x_;
    int y_;
};

class TreeFactory
{
public:
    TreeFactory() : tree_map_(std::make_shared<std::map<std::string, Tree>>()) {}
    Tree GetTree(const std::string& TreeColor)
    {
        auto tree = tree_map_->find(TreeColor);
        if (tree_map_->count(TreeColor) <= 0)
        {
            Tree tree(TreeColor);
            tree_map_->insert(std::make_pair(TreeColor, tree));
            std::cout << "make new tree!" << std::endl;
            return tree;
        }
        return tree->second;
    }
private:
    std::shared_ptr<std::map<std::string, Tree>> tree_map_;
};

int main()
{
    std::cout << "please enter the color you want" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::string input;
        std::cin >> input;
        auto factory = std::make_shared<TreeFactory>();
        auto tree = factory->GetTree(input);
        tree.SetX((int)rand());
        tree.SetY((int)rand());
        tree.InstallTree();
    }
    return 0;
}