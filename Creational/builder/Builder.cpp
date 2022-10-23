//
// Created by kangdasol on 22. 10. 23.
//

#include <string>
#include <vector>
#include <iostream>

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


int main()
{
    MovieDirector* movieDirector = new MovieDirector(new ConcreteMovieBuilder());
    Movie* movie1 = movieDirector->Extraordinary_Attorney_Woo();
    Movie* movie2 = movieDirector->YourName();

    return 0;
}