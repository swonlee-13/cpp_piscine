#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void	replaceString(std::string &buffer, std::string &s1, std::string &s2) {

	size_t pos = buffer.find(s1);
	while (pos != std::string::npos) {
		buffer = buffer.substr(0, pos) + s2 + buffer.substr(pos + s2.length());
		pos = buffer.find(s1);
	}
}

int main(int ac, char **av)
{
    if (ac < 4) {
        std::cerr << "<file_path> [target_string] [replace_stirng]" << std::endl;
        return (1);
    }
    std::string infileString = av[1];
    std::string outfileString = infileString + ".replace";

    std::ifstream infile(infileString);
    std::ofstream outfile(outfileString);

    std::string s1 = av[2];
    std::string s2 = av[3];
    if(!infile.is_open() || !outfile.is_open()){
        std::cerr << "failed to open file" << std::endl;
        return (1);
    }
    std::stringstream ss;
    ss << infile.rdbuf();
    std::string buffer = ss.str();
    replaceString(buffer, s1, s2);
	outfile << buffer << std::endl;
}