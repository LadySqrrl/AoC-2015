#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
	string path;
	int x, y, currX, currY, uniqueStops;
	bool repeats;
	vector<int> coords;
	coords.push_back(0);
	coords.push_back(0);

	path = ">^^v^<>v<<<v<v^>>v";
	x = 0;
	y = 0;

	//For each direction, push back into end of coords vector
	for (int i = 0; i < path.size(); i++) {
		if (path[i] == '>') {
			x += 1;
			coords.push_back(x);
			coords.push_back(y);
		}
		else if (path[i] == '<') {
			x -= 1;
			coords.push_back(x);
			coords.push_back(y);
		}
		else if (path[i] == '^') {
			y += 1;
			coords.push_back(x);
			coords.push_back(y);
		}
		else if (path[i] == 'v') {
			y -= 1;
			coords.push_back(x);
			coords.push_back(y);
		}
	}


	//idenfity each set of coordinates and whether they appear anywhere else in the vector
	//assign a set of x,y based on location in the vector
	for (int i = 0; i < (coords.size() - 2); i += 2) {
		currX = coords[i];
		currY = coords[i + 1];
		//iterate through the vector and determine if it repeats later in the list
		for (int step = 2; step < coords.size(); step += 2) {
			if (currX == coords[step] && currY == coords[step + 1]) {
				repeats = true;
			}
			else
				repeats = false;
		}
		//delete the two coordinates we were iterating with
		if (repeats = true) {
			currX = 0;
			currY = 0;
			coords.erase(coords.begin() + i);
			coords.erase(coords.begin() + (i + 1));
		}
	}

	for (int i = 0; i < coords.size(); i++)
		cout << coords[i] << endl;

	cout << coords.size() << endl;

	//count up the unique stops made (total coordinates left in vector / 2)
	uniqueStops = coords.size() / 2;

	cout << uniqueStops << endl;

	return 0;
}
