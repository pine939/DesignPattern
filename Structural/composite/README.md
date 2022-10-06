## Composite Pattern

## 개념

![image](https://user-images.githubusercontent.com/5865308/194349293-c9e3bd13-360d-4169-8e34-d01311682997.png)

* 구성요소
    * Client
    * Component (Interface)
    * Leaf
    * Composite
* 그룹 전체와 개별 객체를 동일하게 처리할 수 있는 패턴이다.
* 클라이언트는 전체나 부분이 모두 동일한 컴포넌트로 인식할 수 있도록 계층구조를 만드는 것. 즉, 클라이언트는 컴포넌트에게만 위임한다.
* 컴포넌트?
* Leaf, Composite의 공통된 Operation을 컴포넌트 인터페이스에 작성한다.
* Leaf?
* Leaf를 참조하는 것이 아니라 Component를 참조한다.
* 예를 들어, Bag에 들어있는 Item들의 가격을 알아내는 어플리케이션을 개발할 때,
    * Item(Leaf), Bag(Composite)의 계층 구조를 Component로 추상화 하여 클라이언트는 Component 객체를 통해 Item의 가격을 알아낼 수 있다.
    * 물론 Item의 가격은 Item이 알고 있고, 계산은 Bag 객체가 책임지도록 한다.

## 예제 코드 작성

```c++
// FileSystem(Component)
class FileSystem {
public:
    virtual void Print() = 0;
    virtual void Add(std::shared_ptr<FileSystem>) {}
};

// File(Leaf)
class File : public FileSystem {
public:
    explicit File(std::string filename) : filename(std::move(filename)) {}
    void Print() override {
        std::cout << "FILE Name is " << filename << std::endl;
    }

private:
    std::string filename;
};

// Directory(Composite)
class Directory : public FileSystem {
public:
    void Print() override {
        for (auto & item : fs) {
            item->Print();
        }
        std::cout << "There are " << fs.size() << " files..." << std::endl;
    }

    void Add(std::shared_ptr<FileSystem> fileSystem) override {
        fs.push_back(fileSystem);
    }

public:
    std::vector<std::shared_ptr<FileSystem>> fs;
};

int main() {
    FileSystem *fileSystem = new Directory();
    fileSystem->Add(std::make_shared<File>("clean code"));
    fileSystem->Add(std::make_shared<File>("docker and k8s"));
    fileSystem->Add(std::make_shared<File>("algorithm"));

    fileSystem->Print();
    return 0;
}
```