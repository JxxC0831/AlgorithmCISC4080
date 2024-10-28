#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <stack>

using namespace std;

struct svpair {
	string state;
	string chars;
	bool flag;
	int rule;
};

svpair rules(string state, char v1, stack<char>& s) { //v is input letter, s is stack character.
	//vector<string> states = { "p","q","qa","qb","q$" };
	//vector<char> v = { 'e','a','b' };

	//check what rule you can do with provided, not all the time do we need to use v or s.

	svpair l;
	l.state = "";
	l.chars = "";
	l.flag = false;
	l.rule = 0;

	if (!s.empty()) {
		if (state == "p" && s.top() == 'e') {
			l.state = "q";
			l.chars = "S";
			s.pop();
			l.rule = 1;
			for (int i = l.chars.size() - 1;i >= 0;i--) {
				s.push(l.chars[i]);
			}
		}
		else if (state == "q" && v1 == 'a') {
			l.state = "qa";
			//l.chars = "";
			l.flag = true; //increment
			l.rule = 2;
		}
		else if (state == "qa" && s.top() == 'a') {
			l.state = "q";
			//l.chars = "";
			l.rule = 3;
			s.pop();
		}

		else if (state == "q" && v1 == 'b') {
			l.state = "qb";
			l.rule = 4;
			l.flag = true;
		}
		else if (state == "qb" && s.top() == 'b') {
			l.state = "q";
			l.rule = 5;
			s.pop();
		}

		else if (state == "q" && v1 == '$') {
			l.state = "q$";
			l.rule = 6;
			l.flag = true;
		}

		else if (state == "qa" && s.top() == 'S') {
			l.state = "qa";
			l.chars = "aSb";
			l.rule = 7;
			s.pop();
			for (int i = l.chars.size() - 1;i >= 0;i--) {
				s.push(l.chars[i]);
			}
		}
		else if (state == "qb" && s.top() == 'S') {
			l.state = "qb";
			l.chars = "e";
			l.rule = 8;
			s.pop();
		}
	}
	else {
		if (state == "q" && v1 == 'a') {
			l.state = "qa";
			//l.chars = "";
			l.flag = true; //increment
			l.rule = 2;
		}
		else if (state == "q" && v1 == 'b') {
			l.state = "qb";
			l.rule = 4;
			l.flag = true;
		}
		else if (state == "q" && v1 == '$') {
			l.state = "q$";
			l.rule = 6;
			l.flag = true;
		}

	}
	return l;

}
//rules should return what to add to stack and state.

void PDA(string input, int n) {
	
	//vector<
	int iterator = 0;
	int count = 1;
	stack<char> s;
	stack<char> p; //for printing out the stack;
	s.push('e');
	char v = 'e';
	string st = "p"; //state and starting state is p
	int rule = 0;// no rule used at begining;
	bool R = false; //will be a flag, if we used R, then we will include it.
	
	cout << left << setw(6) << "step" << "|" << setw(8) << "state" << "|" << setw(18) << "unread input"<< "|" << setw(13) << "stack" << "|" << setw(9) << "rule used" << "|" << "R used" << endl;
	svpair l;
	l.chars = "";
	l.state = "";
	l.rule = 0;
	l.flag = false;

	string uninput = "";//unread input;

	while (count<=5*n+4) {
		cout << setw(6) << count << "|";
		cout << setw(8) << st << "|";
		

		
		uninput = "";
		for (int i = iterator;i < input.size();i++) {
			uninput += input[i];
		}
		cout << setw(18)<<uninput << "|";
		p = s;
		uninput = "";
		while (!p.empty()) {
			uninput += p.top();
			p.pop();
		}
		cout << setw(13) << uninput << "|";
		cout << setw(9) << l.rule << "|";
		if (l.rule==7 || l.rule ==8) {
			cout << "S->" << l.chars;
		}

		count++;
		l = rules(st, v, s); //decide what rule to choose;
		
		if (l.flag == true) {
			iterator++;
		}
		if (iterator > input.size()) {
			cout << "We have went out of bounds, too much in our stack, too little in our input." << endl;
			break;
		}
		v = input[iterator];
		st = l.state;
		cout << endl;
	}

	if (!s.empty()) {
		cout << "Stack is not empty, not in the language." << endl;
	}
	else if (iterator <= input.size()-1) {
		cout << "Not all input has been read, not in the language." << endl;
	}
	else {
		cout << "As we can see, your input is in the language." << endl;
	}
	

}

string inputCreator(int n1, int n2) {
	string input = "";
	for (int i = 0;i < n1;i++) {
		input += 'a';
	}
	for (int i = 0;i < n2;i++) {
		input += 'b';
	}
	input += '$';
	return input;
}


int main() {
	string input;

	cout << "Enter an input in the form a^nb^n$ or ab$: ";
	cin >> input;
	int n = input.size();
	bool flag = false;
	bool flag2 = false;//if there is just regular ab$
	bool flag3 = false;//if there is an a
	bool flag4 = false;//if there is a b
	string s1 = "", s2 = "";
	
	for (int i = 0;i < n;i++) {
		if (input[i] == '0' || input[i] == '1' || input[i] == '2' || input[i] == '3' || input[i] == '4' || input[i] == '5' || input[i] == '6' || input[i] == '7' || input[i] == '8' || input[i] == '9') {
			if (flag) {
				s2 += input[i];
			}
			else {
				s1 += input[i];
				if (input[i+1] != '0' && input[i+1] != '1' && input[i+1] != '2' && input[i+1] != '3' && input[i+1] != '4' && input[i+1] != '5' && input[i+1] != '6' && input[i+1] != '7' && input[i+1] != '8' && input[i+1] != '9') {
					flag = true;
				}
			}
			flag2 = true;//use this to check if we have a normal ab$
		}
		else if (input[i] == 'a') {
			flag3 = true;
		}
		else if (input[i] == 'b') {
			flag4 = true;
		}
		else if (input[i] == '-') {
			cout << "In our grammar, exponent needs to be greater than or equal to zero." << endl;
			return 0;
		}
		else if (input[i] == '^') {
			//your good.
		}
		else if (input[i] == '$') {
			//your good
		}
		else {
			cout << "The word you entered is not in our language, please try again with correct alphabet." << endl;
			return 0;
		}
	}
	if (!flag3 || !flag4||(input[input.size()-1]!='$')) {
		cout << "Incorrect grammar"<<endl;
		return 0;
	}
	int n1, n2;
	if (s1 == "" && s2 == "") {
		n1 = 1;
		n2 = 1;
	}
	else if (s2 == "") {
		n1 = stoi(s1);
		n2 = 1;
	}
	else {
		n1 = stoi(s1);
		n2 = stoi(s2);
	}
	if (n1 != n2) {
		cout << "This word probably does not exist in this language, let us check via the rules." << endl;
	}
	else {
		cout << "This word probably exists in this language, let us check via the rules." << endl;
	}
	input = inputCreator(n1, n2);

	if (n1 > n2) {
		PDA(input, n2);
	}
	else {
		PDA(input, n1);
	}


	return 0;
}