//
// Created by kangdasol on 22. 10. 6.
//

#include <iostream>
#include <utility>
#include <vector>
#include <memory>
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