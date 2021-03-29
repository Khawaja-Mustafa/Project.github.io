#include <iostream>
#include <string>
#include "MovieManagement.h"
#include "Admin.h"
#include "Register_Users.h"
#include "MakePayment.h"
#include "BookTicket.h" 
#include <fstream> 
#include <ctime>
fstream file, file2;
using namespace std;
//Function of MovieManagement
MovieManagement::MovieManagement() //Default Constructor
{
	for (int i = 0; i < 5; i++)
	{
		Movie_Name[i] = "";
		Movie_Venue[i] = "";
		day[i] = 0;
		month[i] = 0;
		year[i] = 0;
	}
}
void MovieManagement::Adddetails(string iMovie_Name[], string iMovie_Venue[], int iday[], int imonth[], int iyear[]) //Adding New movie details
{
	//-------Made for Storing Movies-------
	//file2.open("Movie.txt", ios::out | ios::trunc);
	file.open("Movie.txt", ios::in | ios::out | ios::app);
	for (int i = 0; i < 5; i++)
	{
		file << endl << i << endl << iMovie_Name[i] << endl;
		file << iMovie_Venue[i] << endl;
		file << "Date of Movie :" << iday[i] << "/" << imonth[i] << "/20" << iyear[i] << endl;
		file << "**" << endl;
	}
	//file2.close();
	file.close();
	//-------Made for Storing Movie-------

	for (int i = 0; i < 5; i++)
	{
		Movie_Name[i] = iMovie_Name[i];
		Movie_Venue[i] = iMovie_Venue[i];
		day[i] = iday[i];
		month[i] = imonth[i];
		year[i] = iyear[i];
	}
}
void MovieManagement::Updatedetails(string uMovie_Name, string uMovie_Venue, int h, string iMovie_Name[], string iMovie_Venue[], int iday[], int imonth[], int iyear[]) //updating Movie Details
{
	int count = 0;
	string text;
	file.open("Movie.txt", ios::in | ios::out | ios::app); //Checks Movies
	for (int i = 0; i < 5; i++)
	{
		while (!file.eof())
		{
			getline(file, text); //Text Variable Movie.txt data store
			if (text == uMovie_Name || text == uMovie_Venue)//Flag If Statement 1
			{
			rUpdet:
				cout << endl << "Do you really want to update the movie " << uMovie_Name << " (Y/N) :"; 
				char upPoss;
				cin >> upPoss;
				if (upPoss == 'Y' || upPoss == 'y')
				{
					cout << "\nEnter New Name of the Movie :";
					cin.ignore();
					getline(cin, iMovie_Name[h]);
					cout << "\nEnter New Venue of the Movie :";
					cin.ignore();
					getline(cin, iMovie_Venue[h]);
					cout << "\nEnter New Date in Format (dd/mm/yy) :";
					cin >> iday[h] >> imonth[h] >> iyear[h];
					cout << "\n\n\t\t\t\t\t<<<< Movie Details Updated >>>>\n\n";
					system("ClS");
					count++;
					break;
				}
				else if (upPoss == 'N' || upPoss == 'n')
				{
					cout << "\n\n\t\t\t\t\t<<<< Movie Details NOT Updated >>>>\n\n";
					count++;
					break;
				}
				else
				{
					cout << "\n\n\t\t\t\t\t<<<< Wrong Input >>>>\n\n";
					goto rUpdet; //if choice is wrong then it would go back to choice
				}
				count++;
			}
		}
		if (count == 0)//Flag If Statement 2
		{
			cout << "\n\n\t\t\t\t\t<<<< Wrong details are Inputed >>>>\n\n";
			system("CLS");
			break;
		}
	}
	file.close();

	//-------Made for Storing updated Movies Movies-------
	file2.open("Movie.txt", ios::out | ios::trunc);
	file.open("Movie.txt", ios::in | ios::out | ios::app);
	for (int i = 0; i < 5; i++)
	{
		file << endl << i << endl << iMovie_Name[i] << endl;
		file << iMovie_Venue[i] << endl;
		file << "Date of Movie :" << iday[i] << "/" << imonth[i] << "/20" << iyear[i] << endl;
		file << "**" << endl;
	}
	MovieManagement::Adddetails(iMovie_Name, iMovie_Venue, iday, imonth, iyear);
	file2.close();
	file.close();
	//-------Made for Storing updated Movies Movies-------
}
void MovieManagement::Deletedetails(string DMovie_Name, string DMovie_Venue, int h, string iMovie_Name[], string iMovie_Venue[], int iday[], int imonth[], int iyear[]) //Delete Saved Movies
{
	int count = 0;
	string text;
	file.open("Movie.txt", ios::in | ios::out | ios::app);
	for (int i = 0; i < 5; i++)
	{
		while (!file.eof())
		{
			getline(file, text);
			if (text == DMovie_Name || text == DMovie_Venue)
			{
				cout << endl << "Do you really want to Delete the movie (Y/N) " << DMovie_Name << " :";
				char DpPoss;
				cin >> DpPoss;
				if (DpPoss == 'Y' || DpPoss == 'y')
				{
					iMovie_Name[h] = "0000";
					iMovie_Venue[h] = "0000";
					iday[h] = 0;
					imonth[h] = 0;
					iyear[h] = 0;
					cout << "\n\n\t\t\t\t\t<<<< Movie Details Deleted >>>>\n\n";
					count++;
					system("CLS");
					break;
				}
				else if (DpPoss == 'N' || DpPoss == 'n')
				{
					cout << "\n\n\t\t\t\t\t<<<< Movie Details NOT Deleted >>>>\n\n";
					count++;
					system("CLS");
					break;
				}
				else
				{
					cout << "\n\n\t\t\t\t\t<<<< Movie Details NOT Deleted >>>>\n\n";
					count++;
					system("CLS");
					break;
				}
				count++;
			}
		}
		if (count == 0)
		{
			cout << "\n\n\t\t\t\t\t<<<< Wrong details are Inputed >>>>\n\n";
			system("CLS");
			break;
		}
	}
	file.close();

	//-------Made for Storing updated Movies Movies-------
	file2.open("Movie.txt", ios::out | ios::trunc);
	file.open("Movie.txt", ios::in | ios::out | ios::app);
	for (int i = 0; i < 5; i++)
	{
		file << endl << i << endl << iMovie_Name[i] << endl;
		file << iMovie_Venue[i] << endl;
		file << "Date of Movie :" << iday[i] << "/" << imonth[i] << "/20" << iyear[i] << endl;
		file << "**" << endl;
	}
	MovieManagement::Adddetails(iMovie_Name, iMovie_Venue, iday, imonth, iyear);
	file2.close();
	file.close();
	//-------Made for Storing updated Movies Movies-------
}
void MovieManagement::view_Movies(string iMovie_Name[], string iMovie_Venue[], int iday[], int imonth[], int iyear[]) //View Saved Movies
{
	for (int i = 0; i < 5; i++)
	{
		cout << "\n\n\t\t\t <" << i << ">";
		cout << "\n\t\t\t" << "	Movie Name: " << iMovie_Name[i];
		cout << "\n\t\t\t" << "	Movie Venue: " << iMovie_Venue[i];
		cout << "\n\t\t\t" "	Movie Date: " << iday[i] << "/" << imonth[i] << "/" << iyear[i] << endl;
		cout << "\t\t\t\t***********" << endl;
	}
}

//Function of Registered Users
Customer::Customer()//Constructor
{
	for (int i = 0; i < 5; i++)
	{
		ID[i] = 0000;
		Name[i] = "0000";
		Phone_Number[i] = "0000";
		User_Address[i] = "0000";
		Pass[i] = "0000";
	}
}
void Customer::set_Users(int iID[], string iName[], string iPhone_Number[], string iUser_Address[], string iPass[]) //Set New USers
{
	//-------Made for Storing Users-------
	//file2.open("Movie.txt", ios::out | ios::trunc);
	file.open("RegisterUser.txt", ios::in | ios::out | ios::app);
	for (int i = 0; i < 5; i++)
	{
		file << endl << iID[i] << endl;
		file << iName[i] << endl;
		file << iPhone_Number[i] << endl;
		file << iUser_Address[i] << endl;
		file << iPass[i] << endl;
		file << "**" << endl;
	}
	//file2.close();
	file.close();
	//-------Made for Storing USers-------

	for (int i = 0; i < 5; i++)//Class Variables Storing
	{
		ID[i] = iID[i];
		Name[i] = iName[i];
		Phone_Number[i] = iPhone_Number[i];
		User_Address[i] = iUser_Address[i];
		Name[i] = iName[i];
		Pass[i] = iPass[i];
	}

}
int Customer::Check_Users(int RiID, string RiName, string RiPass) //Checks Registered Users (Login)
{
	int count = 0;
	string text;
	file.open("RegisterUser.txt", ios::in | ios::out | ios::app); //Checks Users
	while (!file.eof())
	{
		getline(file, text);
		if (text == RiName || text == RiPass)
		{
			cout << "\n\n\t\t\t\t\t<<<< User Logged-IN >>>>\n\n";
			system("ClS");
			Reg_User = 1;
			count++;
			return Reg_User;
			break;
		}
		count++;
	}
	if (count == 0)
	{
		cout << "\n\n\t\t\t\t\t<<<< Wrong details are Inputed >>>>\n\n";
		system("CLS");
		Reg_User = 0;
		return Reg_User;
	}
	file.close();
	return 0;
}
void Customer::New_Users(int iID[], string iName[], string iPhone_Number[], string iUser_Address[], string iPass[])
{
	file.open("RegisterUser.txt", ios::in | ios::out | ios::app);
	for (int i = 0; i < 5; i++)
	{
		file << endl << iID[i] << endl;
		file << iName[i] << endl;
		file << iPhone_Number[i] << endl;
		file << iUser_Address[i] << endl;
		file << iPass[i] << endl;
		file << "**" << endl;
	}
}

//Function of Admin
Admin::Admin() //Admin Credentials
{
	Admin_ID = 123;
	Admin_Name = "Khawaja";
	Admin_Pass = "Khawaja172";
}
int Admin::Check(int iAdmin_ID, string iAdmin_Name, string iAdmin_Pass)
{
	Admin_ID = iAdmin_ID;
	Admin_Name = iAdmin_Name;
	Admin_Pass = iAdmin_Pass;
	if (Admin_ID == 123 && Admin_Name == "Khawaja" && Admin_Pass == "Khawaja172")
	{
		cout << "\nOkay Admin\n\n";
		system("cls");
		admin_C = 1;
		return admin_C;
	}
	else
	{
		cout << "\t\nINVALID ADMIN CREDENTIALS!!!\n\n";
		admin_C = 0;
		return admin_C;
	}
}

//BookTickets
BookTicket::BookTicket()//Default Constructor
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			Av_Tickets[i][j] = 0;
		}
	}
	Show_No = 0;
}
void BookTicket::Setseats(int iAv_Tickets[][7])
{
	for (int i = 0; i < 7; i++)//Values Pass
	{
		for (int j = 0; j < 7; j++)
		{
			Av_Tickets[i][j] = iAv_Tickets[i][j];
		}
	}
}
void BookTicket::UpdateAvailableSeats()
{
	cout << "\t\t\t******************************************************\n";
	cout << "\t\t\t\t\tMovie Management System\n";
	cout << "\t\t\t******************************************************\n\n";
	cout << "\t\t\t\t\t<<<<<< Seat Left >>>>>>\n\n";
	for (int i = 0; i < 7; i++)//Determines Seat booking
	{
		for (int j = 0; j < 7; j++)
		{
			if (Av_Tickets[i][j] == 0)
			{
				cout << "\t| " << i << j << " |\t";
			}
			else
			{
				cout << "\t| " << "XX" << " |\t";
			}
		}
		cout << endl << endl;
	}

	cout << endl << endl;
	MK.ConfirmTransaction(Av_Tickets);
}

//MakePayement
void MakePayment::ConfirmTransaction(int Av_Tickets[][7])
{
	//Transaction Operation
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (Av_Tickets[i][j] == 1)
			{
				Payment++;
			}
			else
			{
				continue;
			}
		}
	}
}
void MakePayment::Display(int choice, string Movie_Name[], string Movie_Venue[], int day[], int month[], int year[], char Student, string institute_N, string program)
{
	if (Student == 'y' || Student == 'Y')
	{
		TicketPrice = 300;
		cout << "\n\t\t\t\t" << "Movie Name : " << Movie_Name[choice] << endl;
		cout << "\n\t\t\t\t" << "Movie Venue : " << Movie_Venue[choice] << endl;
		cout << "\n\t\t\t\t" << "Movie Date : " << day[choice] << "/" << month[choice] << "/" << year[choice] << endl;
		totalPayment = Payment * TicketPrice;
		cout << "\n\t\t\t\t" << "Price of Tickets : " << TicketPrice << endl;
		cout << "\n\t\t\t\t" << "Amount of Tickets : " << Payment << endl;
		cout << "\n\t\t\t\t" << "The Total Bill : " << totalPayment << endl;
		Payment = 0;
	}
	else
	{
		cout << "\n\t\t\t\t" << "Movie Name : " << Movie_Name[choice] << endl;
		cout << "\n\t\t\t\t" << "Movie Venue : " << Movie_Venue[choice] << endl;
		cout << "\n\t\t\t\t" << "Movie Date : " << day[choice] << "/" << month[choice] << "/" << year[choice] << endl;
		totalPayment = Payment * TicketPrice;
		cout << "\n\t\t\t\t" << "Price of Tickets : " << TicketPrice << endl;
		cout << "\n\t\t\t\t" << "Amount of Tickets : " << Payment << endl;
		cout << "\n\t\t\t\t" << "The Total Bill : " << totalPayment << endl;
		Payment = 0;
	}
}
void MakePayment::dateAndTime()
{
	struct tm newtime;
	time_t t = time(0);
	localtime_s(&newtime, &t);
	int Month = 1 + newtime.tm_mon;
	int Day = newtime.tm_mday;
	int Year = newtime.tm_year + 1900;
	int hour = newtime.tm_hour;
	int minuts = newtime.tm_min;
	int sec = newtime.tm_sec;
	cout << "\n\t\t\t\t" << "Current time : " << hour << ":" << minuts << ":" << sec << endl;
	cout << "\n\t\t\t\t" << "Current date : " << Day << "/" << Month << "/" << Year << endl;
}
int main()
{
	int choice = 0;
	char Possibility;
	int AdminMovie = 0;
	int RiID = 123;
	string RiName = "0000";
	string RiPass = "0000";
	int h = 0;
	int Admin_C = 0;
	string iMovie_Name[5] = { "Batman Beyond", "Avengers", "Dhoom 3", "Toy Story 3", "Dead Pool" };
	string iMovie_Venue[5] = { "Room 1", "Room 2" , "Room 3" , "Room 4" , "Room 5" };
	int MainMovie = 0;
	int iday[5] = { 01, 02, 03, 04, 05 }, imonth[5] = { 01, 02, 03, 04, 05 }, iyear[5] = { 21, 21, 21, 21, 21 };
	int iID[5] = { 123, 123, 123, 123, 123 };
	string iName[5] = { "Khawaja Mustafa","Tehreem Ijaz", "Armaghan Bin Zahid", "Haris Naveed", "Abdullah Arshad" };
	string iPhone_Number[5] = { "03244871082","032300000", "032300000", "032300000", "032300000" };
	string iUser_Address[5] = { "Nishtar Block, Allama Iqbal Town, LHR","Bahria Town", "Nizam Block", "Johar Town", "Mustafa Town, LHR" };
	string iPass[5] = { "Khawaja172","Tehreem123", "Armaghan123", "Haris123", "Abdullah123" };
	fstream file, file2;
	int vistorSelec;
	int iAv_Ticket[7][7];
MainPage:
	int Mainlogin;
	cout << "\t\t\t******************************************************\n";
	cout << "\t\t\t\t\tMovie Management System\n";
	cout << "\t\t\t******************************************************\n\n";
	cout << "\t\t\t\t\t<<<<<< Welcome >>>>>>\n\n";
	cout << "\t\t\t1) Admin Login\n";
	cout << "\t\t\t2) Registered Customers\n";
	cout << "\t\t\t3) New Registration\n";
	cout << "\t\t\t4) Walk-In-Customer\n";
	cout << "\t\t\t5) Exit\n\n";
	cout << "\t\t\tYour Selection: ";
	cin >> Mainlogin;
	system("cls");

	if (Mainlogin == 1)
	{
	main_page:
		int iAdmin_ID;
		string iAdmin_Name, iAdmin_Pass;
		cout << "\t\t\t******************************************************\n"; //Admin Block
		cout << "\t\t\t\t\tMovie Management System\n";
		cout << "\t\t\t******************************************************\n\n";
		cout << "\t\t\t\t\t<<<<<< Admin-Login >>>>>>\n\n";
		cout << "\t\t\tAdmin ID: ";
		cin >> iAdmin_ID;
		cout << "\t\t\tAdmin Name: ";
		cin >> iAdmin_Name;
		cout << "\t\t\tAdmin Password: ";
		cin >> iAdmin_Pass;
		cout << endl;
		AD.Check(iAdmin_ID, iAdmin_Name, iAdmin_Pass);
		if (AD.admin_C == 1)
		{
			goto Movie_Add;
		}
		else
		{
			system("CLS");
			goto main_page;
		}
	}
	else if (Mainlogin == 2)
	{
		cout << "\t\t\t******************************************************\n";
		cout << "\t\t\t\t\tMovie Management System\n";
		cout << "\t\t\t******************************************************\n\n";
		cout << "\t\t\t\t\t<<<<<< Customer-Login >>>>>>\n\n";
		cout << "\t\t\tCustomer ID: ";
		cin.ignore();
		cin >> RiID;
		cout << "\t\t\tCustomer Name: ";
		cin.ignore();
		getline(cin, RiName);
		cout << "\t\t\tCustomer Password: ";
		cin.ignore();
		getline(cin, RiPass);
		SU.Check_Users(RiID, RiName, RiPass);
		if (SU.Reg_User == 1)
		{
			system("CLS");
			goto Regblock;
		}
		else
		{
			system("CLS");
			goto MainPage;
		}
	}
	else if (Mainlogin == 3)
	{
	registration:
		cout << "\t\t\t******************************************************\n";
		cout << "\t\t\t\t\tMovie Management System\n";
		cout << "\t\t\t******************************************************\n\n";
		cout << "\t\t\t\t\t<<<<<< New_Registration >>>>>>\n\n";
		{
			for (int i = 0; i < 5; i++)
			{
			new_reg_1:
				cout << "\t\t\tEnter New ID: ";
				cin >> iID[i];
				cout << "\t\t\tEnter Your Name: ";
				cin.ignore();
				getline(cin, iName[i]);
				cout << "\t\t\tEnter Your Phone-Number: ";
				cin.ignore();
				getline(cin, iPhone_Number[i]);
				cout << "\t\t\tEnter Your Address: ";
				cin.ignore();
				getline(cin, iUser_Address[i]);
				cout << "\t\t\tEnter Your Password: ";
				cin.ignore();
				getline(cin, iPass[i]);
			poss_1:
				cout << endl << endl;
				cout << "\t\t\tDo you want conduct more registrations?, Press 'Y' for Yes! OR 'N' for NO!: ";
				cin >> Possibility;
				if (Possibility == 'Y' || Possibility == 'y')
				{
					i++;
					goto new_reg_1;
				}
				else if (Possibility == 'N' || Possibility == 'n')
				{
					SU.New_Users(iID, iName, iPhone_Number, iUser_Address, iPass);
					cout << "\t\t\t\nPress Enter For MainPage\n\n";
					system("cls");
					goto MainPage;
				}
				else
				{
					cout << "\n\nWrong Input, try again\n";
					goto poss_1;
				}

			}
		}
	}
	else if (Mainlogin == 4)
	{
	vSelect:
		cout << "\t\t\t******************************************************\n";
		cout << "\t\t\t\t\tMovie Management System\n";
		cout << "\t\t\t******************************************************\n\n";
		cout << "\t\t\t\t    <<<<<< Walk-In-Customer >>>>>>\n";
		cout << "\t\t\t\t\t<<<<<< Welcome >>>>>>\n\n";
		cout << "\t\t\t1) Get Registered\n";
		cout << "\t\t\t2) View Movies\n";
		cout << "\t\t\t3) Main Page\n";
		cout << "\t\t\tYour Selection: ";
		cin >> vistorSelec;
		if (vistorSelec == 1)
		{
			system("cls");
			goto registration;
		}
		else if (vistorSelec == 2)
		{
			system("CLS");
			goto View;
		}
		else if (vistorSelec == 3)
		{
			system("cls");
			goto MainPage;
		}
		else
		{
			cout << "\t\t\tWrong Input Made\n\n";
			system("CLS");
			goto vSelect;
		}
	}
	else if (Mainlogin == 5)
	{
		system("cls");
		cout << "\t\t\t******************************************************\n"; //Admin Function Block
		cout << "\t\t\t\t\tMovie Management System\n";
		cout << "\t\t\t******************************************************\n\n";
		cout << "\t\t\t\t\t<<<<<< Program Exiting >>>>>>\n\n";
		system("pause");
		system("cls");
		goto logout;
	}
	else
	{
		cout << "\t\t\tWrong Input\n\n";
		goto main_page;
	}

	//----------Admin Block Starts----------//
Movie_Add:
	cout << "\t\t\t******************************************************\n";
	cout << "\t\t\t\t\tMovie Management System\n";
	cout << "\t\t\t******************************************************\n\n";
	cout << "\t\t\t\t\t<<<<<< Admin-LoggedIn >>>>>>\n\n";
	cout << "\t\t\t1) Add Movies Records\n";
	cout << "\t\t\t2) Update Movie Records\n";
	cout << "\t\t\t3) Delete Movie Records\n";
	cout << "\t\t\t4) View Movie Records\n";
	cout << "\t\t\t5) Book Tickets for customers\n";
	cout << "\t\t\t6) Make Payment for customers\n";
	cout << "\t\t\t7) Logout\n\n";
	cout << "\t\t\tYour Selection: ";
	cin >> AdminMovie;
	if (AdminMovie == 1)							//Add Movies
	{
		for (int i = 0; i < 5; i++)
		{
		AgainInput:
			cout << "\nEnter Name of the Movie :";
			cin.ignore();
			getline(cin, iMovie_Name[i]);
			cout << "\nEnter Venue of the Movie :";
			cin.ignore();
			getline(cin, iMovie_Venue[i]);
			cout << "\nEnter Date in Format (dd/mm/yy) :";
			cin >> iday[i] >> imonth[i] >> iyear[i];
			cout << "\n\n";
		Poss:
			cout << "\n\tDo you want to add more Movies Yes/No (Y/N) :";
			cin >> Possibility;
			if (Possibility == 'Y' || Possibility == 'y')
			{
				i++;
				goto AgainInput;
			}
			else if (Possibility == 'N' || Possibility == 'n')
			{
				//-------Made for Adding new movies in the beggining-------
				file.open("Movie.txt", ios::in | ios::out | ios::beg);
				for (int i = 0; i < 5; i++)
				{
					file << endl << i << endl << iMovie_Name[i] << endl;
					file << iMovie_Venue[i] << endl;
					file << "Date of Movie :" << iday[i] << "/" << imonth[i] << "/20" << iyear[i] << endl;
					file << "**" << endl;
				}
				file.close();
				i = 5; //Break or we would add a goto mainpage function
				system("cls");
				goto Movie_Add;
			}
			else
			{
				cout << "Wrong Choice Made, Please Enter again\n";
				goto Poss;
			}
		}
		AD.Adddetails(iMovie_Name, iMovie_Venue, iday, imonth, iyear);
	}
	else if (AdminMovie == 2) //Update Movies
	{
		string uMovie_Name;
		string uMovie_Venue;
		cout << "\nEnter the Number of the Movie you want to update :";
		cin >> h; //Serial Number :P
		cout << "\nEnter Name of the Movie you want to update :";
		cin.ignore();
		getline(cin, uMovie_Name);
		cout << "\nEnter Venue of the Movie you want to update :";
		cin.ignore();
		getline(cin, uMovie_Venue);
		cout << "\n\n";
		AD.Updatedetails(uMovie_Name, uMovie_Venue, h, iMovie_Name, iMovie_Venue, iday, imonth, iyear);
		goto Movie_Add;
	}
	else if (AdminMovie == 3) //Delete Movies
	{
		string DMovie_Name, DMovie_Venue;
		for (int i = 0; i < 3; i++)
		{
			cout << "\nEnter the Number of the Movie you want to delete :";
			cin >> h; //Serial Number :P
			cout << "\nEnter the Name of the Movie you want to delete :";
			cin.ignore();
			getline(cin, DMovie_Name);
			cout << "\nEnter the Venue of the Movie you want to delete :";
			cin.ignore();
			getline(cin, DMovie_Venue);
			AD.Deletedetails(DMovie_Name, DMovie_Venue, h, iMovie_Name, iMovie_Venue, iday, imonth, iyear);
			goto Movie_Add;
		}
	}
	else if (AdminMovie == 4)//ViewMovie Admin
	{
		goto View;
	}
	else if (AdminMovie == 5) //BOOK Ticket
	{
		//BOOKTICKET
		system("cls");
		cout << "\t\t\t******************************************************\n";
		cout << "\t\t\t\t\tMovie Management System\n";
		cout << "\t\t\t******************************************************\n\n";
		cout << "\t\t\t\t\t<<<<<< Book Your Seats >>>>>>\n\n";

		cout << "\t\t\tEnter the following details :-" << endl;
		cout << "\t\t\tUser ID: ";
		cin.ignore();
		cin >> RiID;
		cout << "\t\t\tUser Name: ";
		cin.ignore();
		getline(cin, RiName);
		cout << endl;

		cout << "\t\t\tWhich Moviue You want to see? :-" << endl << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << "\t\t\t>" << i << "< Movie Name :" << iMovie_Name[i] << endl;
			cout << "\t\t\tMovie Venue :" << iMovie_Venue[i] << endl;
			cout << "\t\t\tDate (10 05 21) :" << iday[i] << "/" << imonth[i] << "/" << iyear[i] << endl << endl;
		}
		cout << "You have Selected :";
		cin >> choice;
		cout << endl << endl;
		system("ClS");
		cout << "\t\t\t******************************************************\n";
		cout << "\t\t\t\t\tMovie Management System\n";
		cout << "\t\t\t******************************************************\n\n";
		cout << "\t\t\t\t\t<<<<<< Book Your Seats >>>>>>\n\n";
		char choice_B;
		for (int i = 0; i < 7; i++) //Initializing 2D array == 0
		{
			for (int j = 0; j < 7; j++)
			{
				iAv_Ticket[i][j] = 0; //initialize 2day array to '0'
			}
		}

		for (int i = 0; i < 7; i++) //49 Table outputs
		{
			for (int j = 0; j < 7; j++)
			{
				cout << "\t| " << i << j << " |\t";
			}
			cout << endl << endl;
		}
		for (int i = 0; i < 7; i++)//Booking
		{
			for (int j = 0; j < 7; j++)
			{
				cout << "Do you want to book a Seat/ticket? (Y/N):";
				cin >> choice_B;
				if (choice_B == 'Y' || choice_B == 'y')
				{
					cout << "Select Row and Column (0 1) :";
					cin >> i >> j;
					iAv_Ticket[i][j] = 1;
					i = 0; // i = 0, j = 0 for running program on i = 6, j = 6.
					j = 0;
				}
				else if (choice_B == 'N' || choice_B == 'n')
				{
					i = 6;
					j = 6;
					system("cls");
					break;//breaks the loop
				}
				else
				{
					cout << "\n\nWrong Input!\n\n";
				}
			}
		}
		BT.Setseats(iAv_Ticket);
		BT.UpdateAvailableSeats();
		system("pause");
		system("CLS");
		goto Movie_Add;
	}
	else if (AdminMovie == 6)  //Payment Function
	{
		char Student = 'n';
		string institute_N;
		string program;
		system("cls");
		cout << "\t\t\t******************************************************\n";
		cout << "\t\t\t\t\tMovie Management System\n";
		cout << "\t\t\t******************************************************\n";
		cout << "\t\t\t\t\t<<<<<< Payment >>>>>>\n\n";
		cout << "\t\t\t\t" << "User ID :" << RiID << "\n";
		cout << "\n\t\t\t\t" << "User Name :" << RiName << "\n";
	AgainBill:
		cout << "\n\t\t\t\t" << "Are you a student? :";
		cin >> Student;
		if (Student == 'Y' || Student == 'y')
		{
			cout << "\n\t\t\t\tEnter your institute name :";
			cin.ignore();
			getline(cin, institute_N);
			cout << "\n\t\t\t\tEnter your program :";
			cin.ignore();
			getline(cin, program);
			system("pause");
			system("cls");
			cout << "\t\t\t******************************************************\n";
			cout << "\t\t\t\t\tMovie Management System\n";
			cout << "\t\t\t******************************************************\n";
			cout << "\t\t\t\t\t<<<<<< Payment >>>>>>\n\n";
			cout << "\t\t\t\t" << "User ID :" << RiID << "\n";
			cout << "\n\t\t\t\t" << "User Name :" << RiName << "\n";
			cout << "\n\t\t\t\t" << "Student @ :" << institute_N << "\n";
			cout << "\n\t\t\t\t" << "Studying Program :" << program << "\n";
			cout << "\n\t\t\t\t" << "Student Discount provided //50% OFF//" << "\n";
			system("pause");
			system("CLS");
		}
		else if (Student == 'N' || Student == 'n')
		{
			system("pause");
			system("cls");
			cout << "\t\t\t******************************************************\n";
			cout << "\t\t\t\t\tMovie Management System\n";
			cout << "\t\t\t******************************************************\n";
			cout << "\t\t\t\t\t<<<<<< Payment >>>>>>\n\n";
			cout << "\t\t\t\t" << "User ID :" << RiID << "\n";
			cout << "\n\t\t\t\t" << "User Name :" << RiName << "\n";
			system("pause");
			system("CLS");
		}
		else
		{
			cout << "\t\t\t\t\t<<<<<< Wrong input >>>>>>\n\n";
			goto AgainBill;
		}
		cout << "\t\t\t******************************************************\n";
		cout << "\t\t\t\t\tMovie Management System\n";
		cout << "\t\t\t******************************************************\n";
		cout << "\n\t\t\t\t\t<<<<<< Bill >>>>>>\n\n";
		cout << "\t\t\t\t" << "User ID :" << RiID << "\n";
		cout << "\n\t\t\t\t" << "User Name :" << RiName << "\n";
		MK.dateAndTime();
		MK.Display(choice, iMovie_Name, iMovie_Venue, iday, imonth, iyear, Student, institute_N, program);
		system("pause");
		system("CLS");
		goto Movie_Add;
	}
	else if (AdminMovie == 7)//LogoutAdmin
	{
		system("cls");
		cout << "\t\t\t******************************************************\n";
		cout << "\t\t\t\t\tMovie Management System\n";
		cout << "\t\t\t******************************************************\n\n";
		cout << "\t\t\t\t\t<<<<<< Admin-LoggedOut >>>>>>\n\n";
		system("pause");
		system("cls");
		goto MainPage;
	}

	//-------------Admin Block Ends-------------------//
Regblock:
	//Registered User Function Block
	cout << "\t\t\t******************************************************\n";
	cout << "\t\t\t\t\tMovie Management System\n";
	cout << "\t\t\t******************************************************\n\n";
	cout << "\t\t\t\t\t<<<<<< Movies >>>>>>\n\n";
	cout << "\t\t\t1) View Movies\n";
	cout << "\t\t\t2) Logout\n\n";
	cout << "\t\t\tYour Selection: ";
	cin >> MainMovie;
	if (MainMovie == 1) //View Movies
	{
	View:
		if (AdminMovie == 4)//View Movies For ADMIN
		{
			system("CLS");
			cout << "\t\t\t******************************************************\n";
			cout << "\t\t\t\t\tMovie Management System\n";
			cout << "\t\t\t******************************************************\n\n";
			cout << "\t\t\t\t\t<<<<<< View Movies >>>>>>\n\n";
			AD.view_Movies(iMovie_Name, iMovie_Venue, iday, imonth, iyear);
			system("pause");
			system("CLS");
			goto Movie_Add;
		}
		else if (MainMovie == 1)//View Movies For Registered User
		{
			system("CLS");
			cout << "\t\t\t******************************************************\n";
			cout << "\t\t\t\t\tMovie Management System\n";
			cout << "\t\t\t******************************************************\n\n";
			cout << "\t\t\t\t\t<<<<<< View Movies >>>>>>\n\n";
			SU.view_Movies(iMovie_Name, iMovie_Venue, iday, imonth, iyear);
			system("pause");
			system("CLS");
			goto Regblock;
		}
		else //View Movies For Visitors
		{
			system("CLS");
			cout << "\t\t\t******************************************************\n";
			cout << "\t\t\t\t\tMovie Management System\n";
			cout << "\t\t\t******************************************************\n\n";
			cout << "\t\t\t\t\t<<<<<< View Movies >>>>>>\n\n";
			MP.view_Movies(iMovie_Name, iMovie_Venue, iday, imonth, iyear);
			system("pause");
			system("CLS");
			goto vSelect;
		}
	}
	else if (MainMovie == 2)//LogoutRegUser
	{
		system("cls");
		cout << "\t\t\t******************************************************\n";
		cout << "\t\t\t\t\tMovie Management System\n";
		cout << "\t\t\t******************************************************\n\n";
		cout << "\t\t\t\t\t<<<<<< User-LoggedOut >>>>>>\n\n";
		system("pause");
		system("cls");
		goto MainPage;
	}
	else
	{
		cout << "\n\t\t\tWrong Input!\n";
	}
	//ViewMovies Function
logout:
	system("pause");
	return 0;
}