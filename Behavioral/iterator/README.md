## Iterator Pattern

* [참고](https://orcacode.tistory.com/entry/%EC%9D%B4%ED%84%B0%EB%A0%88%EC%9D%B4%ED%84%B0-%ED%8C%A8%ED%84%B4-Iterator-%EC%88%9C%EC%84%9C%EB%8C%80%EB%A1%9C-%EC%B2%98%EB%A6%AC%ED%95%98%EC%9E%90)

### 개념 

![image](https://user-images.githubusercontent.com/5865308/208037515-fac040e2-1d4a-447f-b0d1-209672e4dbf2.png)

![image](https://user-images.githubusercontent.com/5865308/208392068-19660ded-81a6-4663-88e4-1e259c6224e0.png)

* 복잡한 데이터 구조 세부 정보(list, vector, ...)를 노출시키지 않고, 해당 구조를 차례대로 순회할 수 있도록 하는 행동 디자인 패턴이다.   
클라이언트들은 단일 iterator interface를 통해 서로 다른 컬렉션들의 요소를 탐색할 수 있다. 
* 구성 요소
    * Client
    * Iterator<Interface> : 어떻게 순회할지에 대한 방법을 가지고 있는 인터페이스
    * ConcreteIterator : Iterator를 구현
    * Aggregate<Interface> : 있을 수도 있고, 없을 수도 있다.
    * ConcreteAggregate : 얘도 있을 수도 있고, 없을 수도 있다. 

### 예제 코드 작성

* [출처](https://refactoring.guru/ko/design-patterns/iterator/cpp/example#lang-features)

C++ STL vector의 iterator를 Wrapping한 소스코드를 참고해 보았다.

1. Aggregate(템플릿 U) 포인터를 가지고 있으며, vector의 iterator를 Wrapping한 Iterator 클래스이다.
```c++
template<typename T, typename U>
class Iterator
{
public:
    typedef typename std::vector<T>::iterator iter_type_;
    explicit Iterator(U *iter_data) : iter_data_(iter_data) {
        it_ = iter_data_->data_.begin();
    }
    void First()
    {
        it_ = iter_data_->data_.begin();
    }
    void Next()
    {
        it_++;
    }
    bool IsDone()
    {
        return (it_ == iter_data_->data_.end());
    }
    iter_type_ Current()
    {
        return it_;
    }
private:
    U *iter_data_;
    iter_type_ it_;
};
```

2. Aggregate에 해당하는 Container 클래스이다. Iterator 클래스를 friend선언 함으로써, Iterator가 해당 클래스를 순회할 수 있도록 멤버를 공개하며 CreateIterator메서드를 제공한다. 
```c++
template<class T>
class Container
{
friend class Iterator<T, Container>;
public:
    void Add(T data)
    {
        data_.push_back(data);
    }
    Iterator<T, Container> *CreateIterator()
    {
        return new Iterator<T, Container>(this);
    }
private:
    std::vector<T> data_;
};
```

3. 위 Container 템플릿 클래스의 데이터로써의 동작하는 클래스이다. 템플릿 예시를 보이기 위해 작성하였다. 
```c++
class Data
{
public:
    explicit  Data(int data = 0) : data_(data) {}
    void SetData(int data)
    {
        data_ = data;
    }
    [[nodiscard]] int GetData() const
    {
        return data_;
    }
private:
    int data_;
};
```

4. Client Code.
```c++
int main()
{
    Container<int> container;
    for (int i = 0; i < 10; i++)
    {
        container.Add(i);
    }
    Iterator<int, Container<int>> *iter = container.CreateIterator();
    for (iter->First(); !iter->IsDone(); iter->Next())
    {
        std::cout << *iter->Current() << std::endl;
    }



   Container<Data> data_container;
    Data data1(10), data2(20), data3(30);
    data_container.Add(data1);
    data_container.Add(data2);
    data_container.Add(data3);
    Iterator<Data, Container<Data>> *data_iter = data_container.CreateIterator();
    for (data_iter->First(); !data_iter->IsDone(); data_iter->Next())
    {
        std::cout << data_iter->Current()->GetData() << std::endl;
    }
    return 0;
}
```
