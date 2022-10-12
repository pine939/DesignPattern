//
// Created by kangdasol on 22. 10. 13.
//
#include <iostream>
#include <mutex>
#include <memory>


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