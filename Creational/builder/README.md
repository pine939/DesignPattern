## Builder Pattern

### 개념

![image](https://user-images.githubusercontent.com/5865308/196721648-d2857cba-b532-446d-8ad3-4f568930e8ab.png)

* 동일한 프로세스를 거쳐 다양한 구성의 인스턴스를 만들 때 사용하는 패턴이다.
* 생성자만으로 객체를 만들기 어려운 상황이 있을 수 있다. 이 때, 생성자에서 초기화 하는 부분과 그 외 객체 생성에 필요한 부분을 담당하는 부분을 클래스로(Builder) 분리하여 객체를 생성하는 복잡한 과정을 숨길 수 있다.
* 클라이언트가 불완전한 객체를 사용하지 못하도록 방지할 수 있다.

### 예제 코드 작성

다양한 장르의 영화를 제작하는 MovieDirector 클래스를 빌더 패턴을 사용하여 설계해 보자. 

MovieDirector는 MovieBuilder를 사용해 "Your Name", "Extraordinary Attorney Woo"라는 이름의 Movie를 만들어 낸다.

1. Movie는 다음과 같은 특징을 가지고 있다.
 * 영화 제목
 * 장르
 * 제작 기간
 * 주연 배우
 * 촬영 장소
 
 ```c++
 class Movie
{
public:
    Movie(std::string title, std::string genre, std::string period, std::vector<std::string>& actors, std::string place)
        : title_(title),
        genre_(genre),
        period_(period),
        actors_(actors),
        place_(place) {}
    virtual ~Movie() {}
    void PrintInfo() {
        std::cout << "Title: " << title_ << std::endl;
        std::cout << "Genre: " << genre_ << std::endl;
        std::cout << "Period: " << period_ << std::endl;
        std::cout << "Actors: " << "\n";
        for (auto item : actors_) {
            std::cout << "  " << item << ", ";
        }
        std::cout << "\n";
        std::cout << "Place: " << place_ << std::endl;
        std::cout << "-----------------------------------------------" << std::endl;
    }
private:
    std::string title_;
    std::string genre_;
    std::string period_;
    std::vector<std::string> actors_;
    std::string place_;
};
 ```
 
2. MovieBuilder 인터페이스는 다음과 같다. 
```c++
class MovieBuilder
{
public:
    virtual MovieBuilder* Title(std::string title) = 0;
    virtual MovieBuilder* Genre(std::string genre) = 0;
    virtual MovieBuilder* Period(std::string period) = 0;
    virtual MovieBuilder* Actors(std::vector<std::string> actors) = 0;
    virtual MovieBuilder* Place(std::string place) = 0;
    virtual Movie* GetMovie() = 0;
};
```

3. MovieBuilder를 구현한 ConcreteMovieBuilder. GetMovie 메서드에서 Movie를 생산해 낸다.
```c++
class ConcreteMovieBuilder : public MovieBuilder
{
public:
    MovieBuilder *Title(std::string title) override {
        title_ = title;
        return this;
    }

    MovieBuilder *Genre(std::string genre) override {
        genre_ = genre;
        return this;
    }

    MovieBuilder *Period(std::string period) override {
        period_ = period;
        return this;
    }

    MovieBuilder *Actors(std::vector<std::string> actors) override {
        actors_ = actors;
        return this;
    }

    MovieBuilder *Place(std::string place) override {
        place_ = place;
        return this;
    }

    Movie *GetMovie() override {
        return new Movie(title_, genre_, period_, actors_, place_);
    }

private:
    std::string title_;
    std::string genre_;
    std::string period_;
    std::vector<std::string> actors_;
    std::string place_;

};
```

4. MovieDirector에서는 MovieBuilder를 사용하여, YourName, Extraordinary_Attorney_Woo와 같이 Movie를 만들어 리턴하는 메서드를 제공함으로써 클라이언트가 완전한 객체를 만들어 낼 수 있도록 한다.
```c++
class MovieDirector
{
public:
    MovieDirector(MovieBuilder* movieBuilder) : movieBuilder_(movieBuilder) {}

    Movie* YourName() {
        return movieBuilder_->Title("Your Name")
                ->Genre("Animation")
                ->Period("1Year")
                ->GetMovie();
    }

    Movie* Extraordinary_Attorney_Woo() {
        return movieBuilder_->Title("Extraordinary Attorney Woo")
                ->Genre("Drama")
                ->Period("3Years")
                ->Actors({"parkeunbin, kangtaeoh, kangkiyoung"})
                ->Place("suwon")
                ->GetMovie();
    }

private:
    MovieBuilder* movieBuilder_;
};
```

5. Client
```c++
int main()
{
    MovieDirector* movieDirector = new MovieDirector(new ConcreteMovieBuilder());
    Movie* movie1 = movieDirector->Extraordinary_Attorney_Woo();
    Movie* movie2 = movieDirector->YourName();

    return 0;
}
```
