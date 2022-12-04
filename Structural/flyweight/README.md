### 개념

![image](https://user-images.githubusercontent.com/5865308/199248303-edae9d98-7ef3-48d5-afec-5ab83658809f.png)

* 객체를 가볍게 만들어 메모리 사용을 줄이는 패턴이다.
* 자주 변하는 속성(비본질)과 변하지 않는 속성(본질)을 분리하여 재사용 한다.
* 변하는 속성에서 변하지 않는 속성을 셋팅해 준다.

### 예제 코드 작성

* [예제 출처](https://velog.io/@hoit_98/%EB%94%94%EC%9E%90%EC%9D%B8-%ED%8C%A8%ED%84%B4-Flyweight-%ED%8C%A8%ED%84%B4)

* flywieght는 인스턴스를 가능한 한 공유해서 사용함으로써 메모리를 절약하는 패턴입니다. 
* Tree
```c++
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
```
* TreeFactory
```c++
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
```
* main
```c++
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
```
