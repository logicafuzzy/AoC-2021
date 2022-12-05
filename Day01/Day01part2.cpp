#include <iostream>

#include <fstream>
#include <string>
#include <optional>
#include <deque>
#include <numeric>

using namespace std;

int main() {
	cout << " AoC 2021 Day 01" << endl;

	ifstream input("Day01.txt");

    optional<int> previous;

    deque<int> depth;

    int window_size = 3;

    int increments = 0;

	while (input) {
        string line;
		getline(input, line);

		if (line.length() == 0)
            break;

        depth.push_back(atoi(line.data()));

        if (depth.size() < window_size)
            continue;

        assert(depth.size() == 3);

        int sum = accumulate(depth.begin(), depth.end(), 0);

        cout << "window: " << sum << " ";

        if (previous.has_value()) {
            if (sum > *previous) {
                increments++;
                cout << "+ ";
            }
        }

        for (int i : depth)
            cout << i << " ";

        cout << endl;

        depth.pop_front();

        previous = sum;
        
    }

    cout << "Increments: " << increments << endl;

    return 0;
}