#include <iostream>

#include <fstream>
#include <string>
#include <optional>

using namespace std;

int main() {
	cout << " AoC 2021 Day 01" << endl;

	ifstream input("Day01.txt");

	string line;

    optional<int> previous;

    int increments = 0;

	while (input) {
		getline(input, line);

		if (line.length() == 0)
            break;

        int depth = atoi(line.data());

        if (previous.has_value()) {
            if (depth > *previous)
                increments++;
        }

        previous = depth;
        
    }

    cout << "Increments: " << increments << endl;

    return 0;
}