#include <iostream>

#include <fstream>
#include <string>
#include <sstream>
#include <optional>

using namespace std;

int main() {
	cout << " AoC 2021 Day 02" << endl;

	ifstream input("Day02.txt");

    int depth = 0;
    int forward = 0;
    int aim = 0;

	while (input) {
        string line;
		getline(input, line);

		if (line.length() == 0)
            break;
        
        istringstream sline(line);
        string command;
        getline(sline, command, ' ');

        string sval;
        getline(sline, sval);

        int value = atoi(sval.data());

        if (command.compare("forward") == 0){
            forward += value;
            depth += aim * value;
        } else if(command.compare("down") == 0)
            aim += value;
        else if(command.compare("up") == 0)
            aim -= value;

    }

    cout << "forward: " << forward << endl;
    cout << "depth: " << depth << endl;
    cout << "product: " << (forward*depth) << endl;

    return 0;
}