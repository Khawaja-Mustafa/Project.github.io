using namespace std;
class Customer : public Admin
{
protected:
	int ID[5];	//Registered Users ID
	string Name[5];	//Registered Users Name
	string Phone_Number[5];	//Registered Users Phone Number
	string User_Address[5]; //Registered Users Address
	string Pass[5]; //Regisered Users Password
public:
	int Reg_User = 0;
	Customer();
	void set_Users(int iID[], string iName[], string iPhone_Number[], string iUser_Address[], string iPass[]); //Set New USers
	int Check_Users(int RiID, string RiName, string RiPass); //Checks Registered Users (Login)
	void New_Users(int iID[], string iName[], string iPhone_Number[], string iUser_Address[], string iPass[]);
	
}SU;
