#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <memory>
#include <algorithm>

class Mediator
{
public:
    virtual void SendMessage(std::string msg, std::shared_ptr<class Colleague> user) = 0;
    virtual void AddUser(std::shared_ptr<Colleague> user) = 0;
    virtual void DeleteUser(std::shared_ptr<Colleague> user) = 0;
};

class Colleague
{
public:
    explicit Colleague(std::shared_ptr<Mediator> mediator, std::string name)
    : mediator_(std::move(mediator)), name_(std::move(name)) {}
    virtual void Send(std::string msg) = 0;
    virtual void Receive(std::string msg) = 0;
protected:
    std::shared_ptr<Mediator> mediator_;
    std::string name_;
};

class ConcreteMediator : public Mediator
{
public:
    void SendMessage(std::string msg, std::shared_ptr<class Colleague> user) override
    {
        for (auto &item : user_)
        {
            if (user != item)
            {
                item->Receive(msg);
            }
        }
    }
    void AddUser(std::shared_ptr<Colleague> user) override
    {
        user_.push_back(std::move(user));
    }
    void DeleteUser(std::shared_ptr<Colleague> user) override
    {
    }
private:
    std::vector<std::shared_ptr<Colleague>> user_;
};

class ConcreteColleague : public Colleague, public std::enable_shared_from_this<ConcreteColleague>
{
public:
    explicit ConcreteColleague(std::shared_ptr<Mediator> mediator, std::string name)
    : Colleague(std::move(mediator), std::move(name)) {}
    void Send(std::string msg) override
    {
        mediator_->SendMessage(msg, shared_from_this());
    }
    void Receive(std::string msg) override
    {
        std::cout << "'" << name_ << "' Received Msg: " << msg << std::endl;
    }
};

int main()
{
    std::shared_ptr<Mediator> mediator = std::make_shared<ConcreteMediator>();
    std::shared_ptr<Colleague> user1 = std::make_shared<ConcreteColleague>(mediator, "kang");
    std::shared_ptr<Colleague> user2 = std::make_shared<ConcreteColleague>(mediator, "kim");
    std::shared_ptr<Colleague> user3 = std::make_shared<ConcreteColleague>(mediator, "kwon");
    mediator->AddUser(user1);
    mediator->AddUser(user2);
    mediator->AddUser(user3);



   user1->Send("hello");
    
    return 0;
}
