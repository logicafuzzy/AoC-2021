#include <iostream>

#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	cout << " AoC 2021 Day 03 part1" << endl;

	ifstream input("Day03.txt");

    int count = 0;
    vector<int> bitcount;

    bool init = true;

	while (input) {
        string line;
		
        getline(input, line);

		if (line.length() == 0)
            break;

        if (init) {
            bitcount.resize(line.length(), 0);
            init = false;
        }

        int i = 0;
        for( auto& c : line)
            bitcount[i++] += c == '1' ? 1 : 0;   

        count++;
    }

    int shift = bitcount.size() - 1;
    
    int gamma = 0;
    int epsilon = 0;

    for(auto b : bitcount)
    {
        if (b > count / 2)
            gamma += 1 << (shift--);
        else if (b < count / 2)
            epsilon += 1 << (shift--);

        assert (b != count / 2);
    }

    cout << "Gamma: " << gamma << endl;
    cout << "Epsilon: " << epsilon << endl;
    cout << "Power consumption: " << gamma*epsilon << endl;

    return 0;
}