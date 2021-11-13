#include <iostream>
#include <math.h>
#include <algorithm>
#include <array>

using namespace std;

void triangle_one(int side_one, int limiter) {
	int possible_triplets[16][3];
	int counter = 0;
	
	int sort_on[3];
	
	float side_three;
	
	for (int side_two = 0; side_two <= limiter; side_two++) {
		
		if (side_one > side_two) {
			side_three = sqrt(pow(side_one, 2) - pow(side_two, 2));
		}

		else {
			side_three = sqrt(pow(side_two, 2) - pow(side_one, 2));
		}

		bool side_three_is_int = ceil(side_three) == floor(side_three);

		if (!side_three_is_int) {
			side_three = sqrt(pow(side_two, 2) + pow(side_one, 2));

			side_three_is_int = ceil(side_three) == floor(side_three);
		}

		if (side_three_is_int) {

			sort_on[0] = side_one;
			sort_on[1] = side_two;
			sort_on[2] = side_three;

			sort(sort_on, sort_on + 3);

			bool in_limit = side_two > side_three;
			
			bool theorem_len = sort_on[2] < sort_on[1] + sort_on[0];

			bool theorem_pow = pow(sort_on[2], 2) == pow(sort_on[1], 2) + pow(sort_on[0], 2);

			if (theorem_len && theorem_pow && in_limit) {
				for (int g = 0; g < 3; g++) {

					possible_triplets[counter][g] = sort_on[g];
				}

				counter ++;		
			}
		}
		
	}

	if (counter == 0) {
		cout << "\n\nNo possible triplet with given side length or limiter" << endl;
	}

	else {
		cout << "\n\nAll possible triplet(s) generated from your known side length\n" << endl;

		for (int i = 0; i < counter; i++) {
			for (int g = 0; g < 3; g++) {
					
				if (g < 2) {
					cout << possible_triplets[i][g] << ", "; 
				}

				else {
					cout << possible_triplets[i][g] << endl;
				}
			}
		}
	}
}

void triangle_two(int side_one, int side_two) {
	float side_three;

	if (side_one > side_two) {
		side_three = sqrt(pow(side_one, 2) - pow(side_two, 2));
	}

	else{
		side_three = sqrt(pow(side_two, 2) - pow(side_one, 2));
	}

	bool side_three_is_int = ceil(side_three) == floor(side_three);

	if (!side_three_is_int) {
		side_three = sqrt(pow (side_two, 2) + pow(side_one, 2));
	}

	side_three_is_int = ceil(side_three) == floor(side_three);

	if (!side_three_is_int) {
		cout << "\n\nNo possible triplet with given side lengths" << endl;
	}
	
	else { 
		cout << "\n\nAll possible triplet(s) generated from your known side lengths\n" << endl;
		cout << side_one << ", " << side_two << ", " << side_three << endl;
	}
}

void triangle_three(int side_one, int side_two, int side_three) {
	int sort_on[3];

	sort_on[0] = side_one;
	sort_on[1] = side_two;
	sort_on[2] = side_three;

	sort(sort_on, sort_on + 3);

	bool theorem_len = sort_on[2] < sort_on[1] + sort_on[0];

	bool theorem_pow = pow(sort_on[2], 2) == pow(sort_on[1], 2) + pow(sort_on[0], 2);

	if (theorem_len && theorem_pow) {
		cout << "\n\nThe council has determined that\n" << endl;
		cout << " O ";
		cout << "{ " << side_one << " }";
		cout << "{ " << side_two << " }";
		cout << "{ " << side_three << " }";
		cout << " O ";
		cout << "\n\nare indeed sides of a pythagorean triangle." << endl;
	}

	else {
		cout << "\n\nThe council has determined that\n" << endl;
		cout << " X ";
		cout << "{ " << side_one << " }";
		cout << "{ " << side_two << " }";
		cout << "{ " << side_three << " }";
		cout << " X ";
		cout << "\n\nare indeed NOT sides of a pythagorean triangle." << endl;
	}

}

bool cin_type_error() {
	if (cin.fail()) {
		cin.clear();
		cin.ignore(10000, '\n');

		cout << "\n\n******************************" << endl;
		cout << "\n\n>>\tWrong input type\n\n" << endl;
		cout << "******************************\n\n";

		return true;
	}
	
	else{ 
		return false;
	}
}

int main() {
	float any_number_one, any_number_two, any_number_three;
	int int_number_one, int_number_two, int_number_three;

	bool is_wrong_type;
	
	while (true) {

		while (true) {
			cout << "\nPick a function..." << endl;
			cout << "\tFunction (1): Find all possible triplets from one known side length." << endl;
			cout << "\tFunction (2): Find the third side length from 2 known sides." << endl;
			cout << "\tFunction (3): Check if a triplets of numbers are sides of a pythagorian triangle." << endl;
			cout << "\tFunction (4): About this program." << endl;
			cout << "\tFunction (5): Exit program." << endl;

			cout << "\n\tLet's go with >>  ";
			cin >> any_number_one;

			is_wrong_type = cin_type_error();
			
			if (!is_wrong_type) {
				cout << "\n\t-----------------------------" << endl;;
				break;
			}
		}

		int_number_one = floor(any_number_one);

		if (3 >= int_number_one >=1) {
			cout << "\n\nNOTE: Select { -1 } in any field to go back to function selection screen." << endl; 
			is_wrong_type = true;
		}

		switch (int_number_one) {

			case 1: 

				while (true) {

					do {
						cout << "\nEnter your known side length" << endl;
						cout << "\n\tKnown side length >>  ";

						cin >> any_number_one;
						
						is_wrong_type = cin_type_error();

					} while (is_wrong_type);

					int_number_one = floor(any_number_one);

					if (int_number_one < 1) {
						break;
					}
					
					do{
						cout << "\nEnter the limiting size of side lengths" << endl;
						cout << "\n\tLenght to not exceed >>  ";

						cin >> any_number_two;

						is_wrong_type = cin_type_error();

					} while (is_wrong_type);

					int_number_two = floor(any_number_two);

					if (int_number_two < 1) {
						break;
					}

					triangle_one(int_number_one, int_number_two);	
					cout << "\n\t-----------------------------" << endl;
				}
				cout << "\n\t-----------------------------" << endl;
			break;

			case 2:
				while(true) {

					do{
						cout << "\nEnter your known side length" << endl;
						cout << "\n\tKnown side length >>  ";

						cin >> any_number_one;
						
						is_wrong_type = cin_type_error();

					} while (is_wrong_type);
					
					int_number_one = floor(any_number_one);

					if (int_number_one < 1) {
						break;
					}
					
					do{
						cout << "\nEnter your other known side length" << endl;
						cout << "\n\tThe other known side length >>  ";

						cin >> any_number_two;

						is_wrong_type = cin_type_error();
						
					} while (is_wrong_type);
					
					int_number_two = floor(any_number_two);

					if (int_number_two < 1) {
						break;
					}

					triangle_two(int_number_one, int_number_two);
					cout << "\n\t-----------------------------" << endl;
				}
				cout << "\n\t-----------------------------" << endl;
			break;

			case 3:
				while (true){

					do{
						cout << "\nEnter your known side length" << endl;
						cout << "\n\tKnown side length >>  ";
						cin >> any_number_one;
						
						is_wrong_type = cin_type_error();

					} while (is_wrong_type);

					int_number_one = floor(any_number_one);

					if (int_number_one < 1) {
							break;
						}
				
					do{
						cout << "\nEnter your other known side length" << endl;
						cout << "\n\tOther known side length >>  ";
						cin >> any_number_two;

						is_wrong_type = cin_type_error();

					} while (is_wrong_type);

					int_number_two = floor(any_number_two);

					if (int_number_two < 1) {
							break;
						}

					do{
						cout << "\nEnter your other other known side length" << endl;
						cout << "\n\tOther other known side length >>  ";
						cin >> any_number_three;
						
						is_wrong_type = cin_type_error();

					} while (is_wrong_type);

					int_number_three = floor(any_number_three);

					if (int_number_three < 1) {
						break;
					}

					triangle_three(int_number_one, int_number_two, int_number_three);
					cout << "\n\t-----------------------------" << endl;
				}
				cout << "\n\t-----------------------------" << endl;
			break;

			case 4:

				cout << "\n\nNotes from the developer..." << endl;
				cout << "\n\t>>\tThis program is designed to only work with positive integers." << endl;
				cout << "\n\t>>\tIn Function { 1 } and { 2 }, this program will NOT output decimal side lengths." << endl;
				cout << "\n\t\tOnly integers." << endl;
				cout << "\n\t>>\tAny floating point number given as an input will be rounded down." << endl;
				cout << "\n\t>>\tSide lengths given to this program do not need to be in an order!" << endl;
				cout << "\n\t>>\tNo, characters are not valid inputs." << endl;
				cout << "\n\t-----------------------------" << endl;;

			break;

			case 5:

				cout << "\n\n\n\n\t\t\t\t:'(" << endl;;
				exit(0);

			break;

			default:

				cout << "\n\n******************************" << endl;
				cout << "\n\n>>\tIndex choice out of range\n\n" << endl;
				cout << "******************************\n\n";

			break;
			
		}
	}
	
	return 0;
}
