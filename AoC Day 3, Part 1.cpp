#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
	string path;
	int x, y, currX, currY, stops, uniqueStops, repeats;
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
	uniqueStops = (coords.size() /2);
	repeats = 0;

	//idenfity each set of coordinates and whether they appear anywhere else in the vector
	//assign a set of x,y based on location in the vector
	for (int i = 0; i < coords.size(); i += 2) {
		currX = coords[i];
		currY = coords[i + 1];
		stops = 0;
		//iterate through the vector and identify how many times that set appears
		for (int step = 0; step < coords.size(); step += 2) {
			if (currX == coords[step] && coords[step + 1])
				stops++;
		}
		//remove repeats from the list of total stops made
		uniqueStops -= stops - 1; 
	}

	cout << uniqueStops << endl;
	cout << repeats << endl;
	return 0;
}
