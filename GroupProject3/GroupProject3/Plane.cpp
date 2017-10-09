#include <iostream>
#include <iomanip>
#include "Plane.h"
using namespace std;



plane::plane()
{
	int f_row, f_col, e_row, e_col;

	cout << "Enter the row for the First Class: ";
	cin >> f_row;
	cout << "Enter the col for the First Class: ";
	cin >> f_col;

	cout << "Enter the row for the Econ Class: ";
	cin >> e_row;
	cout << "Enter the col for the Econ Class: ";
	cin >> e_col;
	cout << endl;

	first_class_rows_ = f_row;
	first_class_cols_ = f_col;
	econ_rows_ = e_row;
	econ_cols_ = e_col;

	first_class_ = new seat*[f_row];

	for(int i = 0; i < f_row; i++)
	{
		first_class_[i] = new seat[first_class_cols_];
	}

	for(int i =0; i < first_class_rows_; i++)
	{
		for(int j=0; j < first_class_cols_; j++)
		{
			first_class_[i][j].status = '-';
			first_class_[i][j].is_booked = false;
		}

	}

	economy_ = new seat*[econ_rows_];
	for (int i = 0; i < econ_rows_;i++)
	{
		economy_[i] = new seat[econ_cols_];
	}

	for(int i=0; i < econ_rows_; i++)
	{
		for(int j=0; j < econ_cols_; j++)
		{
			economy_[i][j].status = '-';
			economy_[i][j].is_booked = false;
		}
	}
}

plane::plane(int f_row, int f_col, int e_row, int e_col)
{
	first_class_rows_ = f_row;
	first_class_cols_ = f_col;
	econ_rows_ = e_row;
	econ_cols_ = e_col;

	first_class_ = new seat*[f_row];

	for(int i = 0; i < f_row; i++)
	{
		first_class_[i] = new seat[first_class_cols_];
	}

	for(int i =0; i < first_class_rows_; i++)
	{
		for(int j=0; j < first_class_cols_; j++)
		{
			first_class_[i][j].status = '-';
			first_class_[i][j].is_booked = false;
		}

	}

	economy_ = new seat*[econ_rows_];
	for (int i = 0; i < econ_rows_;i++)
	{
		economy_[i] = new seat[econ_cols_];
	}

	for(int i=0; i < econ_rows_; i++)
	{
		for(int j=0; j < econ_cols_; j++)
		{
			economy_[i][j].status = '-';
			economy_[i][j].is_booked = false;
		}
	}
}


void plane::display_seats()
{
	cout << "COSC1430 PLANE SEATING MAP" << endl;
	cout << endl;

	cout << "First Class" << endl;
	cout << "-----------" << endl;

	for(int i=0; i< first_class_rows_; i++)
	{
		for(int j=0; j <first_class_cols_; j++)
		{
			cout << first_class_[i][j].status << " ";
		}
		cout << endl;
	}

	cout << endl;

	cout << "Economy" << endl;
	cout << "-------" << endl;

	for(int i=0; i <econ_rows_; i++)
	{
		for(int j=0; j <econ_cols_; j++)
		{
			cout << economy_[i][j].status << " ";
		}
		cout << endl;
	}
	cout << endl;


}

void plane::book_seat()
{	
	/*bool booked = false;*/
	int user_class;
	cout << "Which section 1.First Class or 2.Economy" << endl;
	cin >> user_class;

	/*while(!booked)
	{*/
		int row, col;
		cout << "Enter the row: ";
		cin >> row;
		cout << "Enter the column: ";
		cin >> col;

		switch (user_class)
		{
		case 1:
			if (first_class_[row - 1][col - 1].is_booked == false)
			{
				first_class_[row - 1][col - 1].status = '*';
				first_class_[row - 1][col - 1].is_booked = true;
				cout << "The seat is booked";
				/*booked = true;*/
				break;
			}
			else
			{
				cout << "The seat is unavilable.Please choose another seat." << endl;
				/*booked = false;*/
				break;
			}
		case 2:
				if(economy_[row-1][col-1].is_booked==false)
				{
					economy_[row - 1][col - 1].status = '*';
					economy_[row - 1][col - 1].is_booked = true;
					cout << "The seat is booked"<< endl;
					/*booked = true;*/
					break;
				}
				else
				{
					cout << "The seat is unavilable.Please choose another seat." << endl;
					/*booked = false;*/
					break;
				}
		default: 
			cout<< "Wrong Choice." << endl;
			break;
		}
		cout << endl;
		}

	/*}*/
	
void plane::check_seat()
{
	int user_class;
	cout << "Which section 1.First Class or 2.Economy" << endl;
	cin >> user_class;
	int row, col;
	cout << "Enter the row: ";
	cin >> row;
	cout << "Enter the column: ";
	cin >> col;

	switch (user_class)
	{
	case 1:
		if(first_class_[row-1][col-1].is_booked==true)
		{
			cout << "The seat is unavaliable." << endl;
			break;
		}else
		{
			cout << "The seat is avalible." << endl;
			break;
		}
	case 2:

		if (economy_[row - 1][col - 1].is_booked == true)
		{
			cout << "The seat is avaliable." << endl;
			break;
		}
		else
		{
			cout << "The seat is unavalible." << endl;
			break;
		}
	default:
		cout << "Wrong choice." << endl;
		break;
	}
	cout << endl;
}

void plane::clear_seat()
{
	int user_class;
	cout << "Which section 1.First Class or 2.Economy" << endl;
	cin >> user_class;
	int row, col;
	cout << "Enter the row: ";
	cin >> row;
	cout << "Enter the column: ";
	cin >> col;

	switch (user_class)
	{
	case 1:
		cout << "Cleared seat.";
		first_class_[row - 1][col - 1].status = '-';
		first_class_[row - 1][col - 1].is_booked = false;
		break;
	case 2:
		cout << "Cleared seat.";
		economy_[row - 1][col - 1].status = '-';
		economy_[row - 1][col - 1].is_booked = false;
		break;
	default:
		cout << "Wrong choice." << endl;
	}
	cout << endl;
}

void plane::clear_all_seats()
{
	for(int i=0; i < first_class_rows_; i++)
	{
		for (int j=0; j < first_class_cols_; j++)
		{
			first_class_[i][j].status = '-';
			first_class_[i][j].is_booked = false;
		}
	}

	for (int i = 0; i < econ_rows_; i++)
	{
		for (int j = 0; j < econ_cols_; j++)
		{
			economy_[i][j].status = '-';
			economy_[i][j].is_booked = false;
		}
	}
}


plane::~plane()
{
	delete first_class_;
	delete economy_;
}


