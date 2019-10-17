#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

int width, height;

tuple<int, int> goAhead(char currentNode, int i, int j) {
	if (currentNode == '>')
		j++;
	else if (currentNode == 'v')
		i++;
	else if (currentNode == '<')
		j--;
	else if (currentNode == '^')
		i--;
	
	tuple<int, int> pos = make_tuple(i, j);
	return pos;
}

bool canGoAhead(char currentNode, int i, int j) {
	if (currentNode == '>')
		return j < width-1 and currentNode != '<';
	else if (currentNode == '<')
		return j > 0 and currentNode != '>';
	else if (currentNode == 'v')
		return i < height-1 and currentNode != '^';
	else
		return i > 0 and currentNode != 'v'; 
}

int main(){
	string line;
	vector<string> input;
	vector<vector<int>> visited;
	vector<int> row;
	scanf("%d %d", &width, &height);
	
	row.assign(width, 0);
	for (int i=0; i < height; i++) {
		cin >> line;
		input.push_back(line);
		visited.push_back(row);
	}

	bool findACycle = false;
	char currentNode = '.';
	int i = 0, j = 0;
	tuple<int, int> pos;

	while (!findACycle) {
		if (input.at(i).at(j) != '.'){
			if (visited.at(i).at(j) == 1){
				cout << "!" << endl;
				findACycle = true;
			}
			else {
				currentNode = input.at(i).at(j);
				visited.at(i).at(j) = 1;
			}
		}

		if(currentNode == '*') {
			cout << '*' << endl;
			findACycle = true;	
		}

		else if (canGoAhead(currentNode, i, j)) {
			pos = goAhead(currentNode, i, j);
			i  = get<0>(pos);
			j = get<1>(pos);
		}

		else if (!findACycle){
			cout << "!" << endl;
			break;
		}

	}
	return 0; 
}
