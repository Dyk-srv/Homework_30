#include <iostream>
#include <string>
#include <fstream>

void show_file(const std::string& path);
bool overwrite(const std::string& path, const std::string& str);

int main() {
	std::ifstream in;
	std::ofstream out;
	
	// 30.1 Endless writing to a file
	std::cout << "\t30.1 Endless writing to a file\n";
	std::string path1 = "File1.txt";
	out.open(path1, std::ios::app);
	if (out.is_open()) {
		std::cout << "File \"" << path1 << "\" is opened for writing.\n";
		std::string input;
		std::cout << "Add strings to append to the file (to stop enter: end):\n";
		do {
			std::cout << "-> ";
			std::getline(std::cin, input);
			if (input == "end")
				break;
			out << input << '\n';
		} while (input != "end");
		std::cout << "\nWriting terminated by user.\n\n";
	}
	else
		std::cout << "Error while opening file \"" << path1 << "\"!\n\n";
	out.close();

	show_file(path1);

	if(remove(path1.c_str()) == 0)
		std::cout << "\nFile \"" << path1 << "\" deleted.\n";
	else
		std::cout << "\nError while deleting file \"" << path1 << "\"!\n";


	// 30.2 File overwriting
	std::cout << "\n\n\t30.2 File overwriting\n";
	std::string path2 = "File2.txt";
	out.open(path2);
	if (out.is_open()) {
		std::cout << "File \"" << path2 << "\" is opened for writing. Add any string:\n-> ";
		std::string input;
		std::getline(std::cin, input);
		out << input << '\n';
		std::cout << std::endl;
	}
	else
		std::cout << "Error while opening file \"" << path2 << "\"!\n\n";
	out.close();

	show_file(path2);

	std::string new_str;
	std::cout << "\nEnter a new string to overwrite file \"" << path2 << "\":\n-> "; 
	std::getline(std::cin, new_str);
	std::cout << std::endl;

	if (overwrite(path2, new_str)) {
		std::cout << "File \"" << path2 << "\" has been overwritten successfully.\n\n";
		show_file(path2);
	}
	else
		std::cout << "Error! File \"" << path2 << "\" does not exist or cannot be opened.\n\n";

	return 0;
}

void show_file(const std::string& path) {
	std::ifstream in;
	in.open(path);
	if (in.is_open()) {
		std::cout << "File \"" << path << "\" is opened for reading.\n\n";
		std::string file;
		std::string str;
		while (std::getline(in, str))
			file += str + '\n';
		std::cout << file;
	}
	else
		std::cout << "Error while opening file \"" << path << "\"!\n\n";
	in.close();
}

bool overwrite(const std::string& path, const std::string& str) {
	std::ifstream in;
	in.open(path);
	if (!in.is_open()) {
		in.close();
		return false;
	}
	in.close();
	std::ofstream out;
	out.open(path);
	if (!out.is_open()) {
		out.close();
		return false;
	}
	out << str << '\n';
	out.close();
	return true;
}
