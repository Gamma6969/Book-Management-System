#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

class book
{
private:
	char *name_of_authour, *title_of_the_book, *publisher;
	float *cost;
	int *total_stock;

public:
	book()
	{
		name_of_authour = new char[20];
		title_of_the_book = new char[20];
		publisher = new char[20];
		cost = new float;
		total_stock = new int;
	}
	void feeddata();
	void editdata();
	void showdata();
	int search(char[], char[]);
	void buybook();
	void intro();
};
void intro()
{
	system("cls");
	cout << "\n\n\n\t       BOOK "
	     << "\n\t      ------";
	cout << "\n\n\t MANAGEMENT SYSTEM"
	     << "\n\t-------------------";
	cout << "\n\n\t      PROJECT"
	     << "\n\t     ---------";
	cout << "\n\n\nMADE BY :";
	cout << "\n\nCO21321 HARMANPREET SINGH";
	cout << "\n\nCO21324 HUZAIFA ALI";
	cout << "\n\n\nPress Enter To Start The Project....\n\n";
	cin.get();
	system("cls");
}
void book::feeddata()
{
	system("cls");
	cin.ignore();
	cout << "\n\tEntry of New Book";
	cout << "\n\n\nEnter Name of The Author: ";
	cin.getline(name_of_authour, 20);
	cout << "Enter Title of The Book: ";
	cin.getline(title_of_the_book, 20);
	cout << "Enter Publisher's Name: ";
	cin.getline(publisher, 20);
	cout << "Enter Price Tag: ";
	cin >> *cost;
	cout << "Enter Stock Position: ";
	cin >> *total_stock;
}

void book::editdata()
{
	system("cls");
	cout << "\n\tEnter New Data";
	cout << "\n\n\nEnter Name Of The Author: ";
	cin.getline(name_of_authour, 20);
	cout << "Enter Title Of The Book: ";
	cin.getline(title_of_the_book, 20);
	cout << "Enter Publisher's Name: ";
	cin.getline(publisher, 20);
	cout << "Enter Price tag: ";
	cin >> *cost;
	cout << "Enter Stock Position: ";
	cin >> *total_stock;
}

void book::showdata()
{
	cout << "\n\n\n\tDetails OF The Book";
	cout << "\n\n\nName Of The Author: " << name_of_authour;
	cout << "\nTitle Of the Book: " << title_of_the_book;
	cout << "\nPublisher's Name: " << publisher;
	cout << "\nPrice Tag: " << *cost;
	cout << "\nStock Position: " << *total_stock;
	cout << "\n\nPress Enter To Continue..";
	cin.ignore();
	system("cls");
}

int book::search(char tbuy[20], char abuy[20])
{
	
	if (strcmp(tbuy, title_of_the_book) == 0 && strcmp(abuy, name_of_authour) == 0)
		return 1;
		
	else
		return 0;
}

void book::buybook()
{
	
	int count;
	cout << "\nEnter Number Of Books to buy: ";
	cin >> count;
	if (count <= *total_stock)
	{
		*total_stock = *total_stock - count;
		cout << "\nBooks Bought Sucessfully";
		cout << "\nAmount: Rs. " << (*cost) * count;
	}
	else
		cout << "\nRequired Number of Copies not in  the Stock\n";
}

int main()
{
	system("cls");
	book *B[20];
	int i = 0, r, t, choice;
	intro();
	char titlebuy[20], authorbuy[20];
	while (1)
	{
		cout << "\n\n\t\tMENU"
			 << "\n1. Entry of New Book"
			 << "\n2. Buy a Book"
			 << "\n3. Search Any Book"
			 << "\n4. Edit Details"
			 << "\n5. Exit Program"
			 << "\n\nEnter Choice: ";
		cin >> choice;
		system("cls");

		switch (choice)
		{
		case 1:
			B[i] = new book;
			B[i]->feeddata();
			i++;
			break;

		case 2:
			cin.ignore();
            system("cls");
			cout << "\n\tBuy The Book";
			cout << "\n\n\nEnter Name of the Author Of the Book: ";
			cin.getline(authorbuy, 20);
			cout << "Enter Title Of the Book: ";
			cin.getline(titlebuy, 20);
			
			for (t = 0; t < i; t++)
			{
				if (B[t]->search(titlebuy, authorbuy))
				{
					B[t]->buybook();
					break;
				}
				
			}
			if (t == 1)
				cout << "\nThis Book is Not in Stock";

			break;
		case 3:
			cin.ignore();
			cout << "\n\tSearch Any Book";
			cout << "\n\n\nEnter Title Of the Book: ";
			cin.getline(titlebuy, 20);
			cout << "Enter Name of the Author Of the Book: ";
			cin.getline(authorbuy, 20);

			for (t = 0; t < i; t++)
			{
				if (B[t]->search(titlebuy, authorbuy))
				{
					cout << "\nBook Found Successfully";
					B[t]->showdata();
					break;
				}
			}
			if (t == i)
				cout << "\nThis Book is Not in Stock";
			break;

		case 4:
			cin.ignore();
			cout << "\n\tEdit Data";
			cout << "\n\n\nEnter Title Of the Book: ";
			cin.getline(titlebuy, 20);
			cout << "Enter Name of the Author Of the Book: ";
			cin.getline(authorbuy, 20);

			for (t = 0; t < i; t++)
			{
				if (B[t]->search(titlebuy, authorbuy))
				{
					cout << "\nBook Found Successfully";
					B[t]->editdata();
					break;
				}
			}
			if (t == i)
				cout << "\nThis Book is Not in Stock";
			break;

		case 5:
			exit(0);
		default:
			cout << "\nInvalid Choice Entered";
		}
	}
	return 0;
}