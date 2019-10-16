#include <iostream>
#include <string>
#include <vector>

using namespace std;

int[2] goAhead(int i, int y) {
	if (currentNode == '>')
		j++;
	else if (currentNode == 'v')
		i++;
	else if (currentNode == '<')
		j--;
	else if (currentNode == '^')
		i--;
	
	int[2] pos = {i, j};
	return pos;
}

int[2] goBack(int i, int j) {
	
}

int main(){
	int width, height;
	string line;
	vector<string> input;
	vector<vector<int> visited;
	vector<int> row;
	scanf("%d %d", &width, &height);
	
	row.assign(width, 0);
	for (int i=0; i < height; i++) {
		cin >> line;
		input.push_back(line);
		visited.push_back(row);
	}

	/*for (int i=0; i < height; i++) {
		cout << input.at(i) << endl;
	}*/

	bool findACycle = false;
	char currentNode = '.';
	int i = 0, j = 0;
	int[2] pos = {0, 0};

	while (!findACycle) {
		if (input.at(i).at(j) != '.'){
			if (visited.at(i).at(j) == 1){
				cout  << "!" << endl;
				findACycle = true;
			}
			else {
				currentNode = input.at(i).at(j);
				visited.at(i).at(j) = 1;
			}
		}

		if (i < height && j < width)
			pos = goAhead();
		else
			pos = goBack();

		i  = pos[0];
		j = pos[1];
		
		

	}
	return 0; 
}
