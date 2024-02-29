#include <iostream>
using namespace std;
#include <fstream>
int main() {
	string choice = "";
	for (int i = 0; ; i++) {
		cout << "Would you like to lodge a complaint: ";
		cin >> choice;
		cin.ignore();
		if (choice == "yes") {
			ofstream out("out.txt", ios::app);
			ifstream read("compNum.txt");
			char arr[1000];
			char* ptr = nullptr;
			ptr = new char[50];
			cout << "Enter your email: ";
			cin.getline(ptr, 50);
			cout << "Lodge your complaint: ";
			cin.getline(arr, 1000);
			int number;
			read >> number;
			read.close();
			cout << "Thank you for lodging your complaint, your time is very valuable to us. We will get back to you as soon as possible on " << ptr << "\nRegards, \nyour complaint id is " << number << endl;
			delete[] ptr;
			ptr = nullptr;
			out << number << ". " << arr << endl;
			ofstream write("compNum.txt");
			write << number + 1;
			write.close();
			out.close();
		}
		else if (choice == "no") {
			return 0;
		}
			else if (choice == "Admin") {
	ifstream read("out.txt");
	ifstream readNum("compNum.txt");
	cout << "num of All complaints: ";
	int num = 0;
	readNum >> num;
	cout << num << endl;
	readNum.close();
	int nums[1000];
	int i = 0;
	while (!read.eof()) {
		read >> nums[i++];
		char arr[1000];
		read.getline(arr, 1000);
		cout << arr << endl;
	}
	read.close();
	
}
		else {
			cout << "I couldnt Understand, please answer in yes or no: ";
			cin >> choice;
		}
	}
}
