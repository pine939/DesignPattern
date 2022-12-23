//
// Created by kangdasol on 22. 10. 9.
//
class Subscriber
{
public:
    virtual void GetNotifyFromPublisher(std::string msg) = 0;
};



class Publisher
{
public:
    explicit Publisher(std::list<std::unique_ptr<Subscriber>> subscriber) : subscribers_(std::move(subscriber)) {}
    virtual void NotifyToSubscribers() = 0;
    virtual void UpdateState(std::string state) = 0;
protected:
    std::list<std::unique_ptr<Subscriber>> subscribers_;
};



class IdolP : public Publisher
{
public:
    explicit IdolP(std::list<std::unique_ptr<Subscriber>> subscriber)
    : Publisher(std::move(subscriber)) {}
    void NotifyToSubscribers() override
    {
        for (auto &s : subscribers_)
        {
            s->GetNotifyFromPublisher(msg_);
        }
    }
    void UpdateState(std::string state) override
    {
        if (state == "Instagram")
        {
            UpdateInstagram();
        } else if (state == "VLive")
        {
            UpdateVLive();
        } else
        {
            UpdateYoutube();
        }
    }
private:
    std::string msg_;
    void UpdateInstagram()
    {
        msg_ = "P updates instagram!";
    }
    void UpdateVLive()
    {
        msg_ = "P updates vlive!";
    }
    void UpdateYoutube()
    {
        msg_ = "P updates youtube!";
    }
};



class Fan : public Subscriber
{
public:
    explicit Fan(std::string name) : name_(std::move(name)) {}
    void GetNotifyFromPublisher(std::string msg) override
    {
        std::cout << name_ << " received the update msg(" << msg << ")" << std::endl;
    }
private:
    std::string name_;
};



int main()
{
    std::list<std::unique_ptr<Subscriber>> fan;
    fan.push_back(std::make_unique<Fan>("Tiger"));
    fan.push_back(std::make_unique<Fan>("Cat"));
    fan.push_back(std::make_unique<Fan>("Dog"));



   std::unique_ptr<Publisher> p = std::make_unique<IdolP>(std::move(fan));
    p->UpdateState("Instagram");
    p->NotifyToSubscribers();
    return 0;
}
