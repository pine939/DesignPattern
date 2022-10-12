## Singleton Pattern

### 개념

* 단 하나의 인스턴스를 생성하도록 보장하고, 이에 대한 전역적인 접근점을 제공하는 패턴이다.
* 사용자 코드에서 Instance를 여러 번 생성하려 해도 단 한개의 Instance만 제공되기 때문에, 불필요한 new 연산에 의한 메모리 낭비가 없다는 것과 여러 사용자들이 동일한 Instance를 사용한다는 장점이 있지만 기본적으로 static변수가 갖는 Thread Safe하지 않은 문제가 있어 무분별한 사용은 자제해야 하는 패턴이다.
* C++ 11 부터는 call_once()를 사용하여 편리하게 Singleton을 사용할 수 있다. std::call_once()는 std::once_flag와 함께 사용하여 Thread-Safe하게 구현 가능하다.

### 예제 코드 작성

```c++
class singleton {
public:
    static singleton* GetInstance() {
        std::call_once(once_flag_, []() {
           instance_.reset(new singleton);
           std::cout << "singleton instance is created..." << std::endl;
        });
        return instance_.get();
    }
    void print() {
        std::cout << "print log..." << std::endl;
    }
    ~singleton() = default;
private:
    static std::unique_ptr<singleton> instance_;
    static std::once_flag once_flag_;

    singleton() = default;
    singleton(const singleton&) = delete;
    singleton &operator=(const singleton&) = delete;

};
std::unique_ptr<singleton> singleton::instance_ = nullptr;
std::once_flag singleton::once_flag_;

int main() {
    singleton::GetInstance()->print();
    singleton::GetInstance()->print();
    return 0;
}
```