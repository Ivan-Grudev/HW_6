#include <boost/filesystem.hpp>
//#include <filesystem>
#include <fstream>
#include <iomanip>
#include <istream>
#include <locale>
#include <ostream>
#include <iostream>
#include <string>
#include <vector>

#include "json.hpp"

using nlohmann::json;
//using namespace boost::filesystem;
using namespace std;

struct Human {
    string name;
    unsigned int age;
    string address;
    double weight;

    friend istream& operator>> (std::istream &in, Human &human);
};

std::istream& operator>> (std::istream &in, Human &human)
{
    in >> human.name;
    in >> human.address;
    in >> human.age;
    in >> human.weight;

    return in;
}

int main(int argc, char ** argv)
{

    vector<Human> h(3);

    for (size_t i = 0; i < h.size(); i++) {
        cout << "Enter human #" << i + 1 << ": ";
        cin >> h[i];
    }

	json j;

//пытался создать новую директорию различными способами, но ни один не сработал: вылетает ошибка undefined reference to `boost::filesystem::path::codecvt()';
//чтобы довести задачу до конца, создал текстовые файлы с объектами json в папке проекта
//    boost::filesystem::path p = boost::filesystem::current_path();
//    boost::filesystem::create_directory(p / "directory_1");
//	  boost::filesystem::create_directories("C:\\Games\\New");

    std::string outFile;

    for (size_t i = 0; i < h.size(); i++) {
        outFile = "out" + to_string(i + 1) + ".dat";
        std::ofstream out_1(outFile);

        if (!out_1.is_open()) {
            std::cerr << "Can not open: " << outFile << std::endl;
            return EXIT_FAILURE;
        }

        j["name"] = h[i].name;
        j["address"] = h[i].address;
        j["age"] = h[i].age;
        j["weight"] = h[i].weight;

        for (auto iterator = j.begin(); iterator != j.end(); ++iterator) {
            out_1 << iterator.key() << ": " << iterator.value() << "\n";
        }

        out_1.close();
    }

	return EXIT_SUCCESS;
}
