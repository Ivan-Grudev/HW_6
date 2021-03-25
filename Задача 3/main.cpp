#include <filesystem>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <chrono>

void view_directory(const std::filesystem::path & path)
{
	if (std::filesystem::exists(path) &&
        std::filesystem::is_directory(path))
	{
		for (const auto & entry : std::filesystem::directory_iterator(path))
		{
			auto file_name = entry.path().filename().string();
            auto ftime = std::filesystem::last_write_time(path);
            std::time_t cftime = decltype(ftime)::clock::to_time_t(ftime);

			std::cout << "filename() = " << file_name << "\t" << std::endl;
            std::cout << "extension() = " << path.extension().string() << std::endl;
            std::cout << "last write time() = " <<
                std::asctime(std::localtime(&cftime)) << "\t" << std::endl;

		}
	}
}


int main(int argc, char ** argv)
{
    setlocale(LC_ALL, "Russian");
	std::string st;
    std::cout << "¬ведите путь к файлу: ";
    std::cin >> st;
	std::filesystem::path file = st;

    if (!std::filesystem::exists(file))
	{
		std::cerr << "Path " << file << " does not exist.\n";

		return EXIT_FAILURE;
	}
	else
	{
		std::cout << "Path " << file.string() << " exists." << std::endl;
	}

    view_directory(file);

    return EXIT_SUCCESS;
}
