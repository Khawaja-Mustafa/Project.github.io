using namespace std;
class MovieManagement //ParentClass
{
protected: //Private
	string Movie_Name[5];
	int day[5], month[5], year[5];
	string Movie_Venue[5];
public:
	MovieManagement();
	void Adddetails(string iMovie_Name[], string iMovie_Venue[], int iday[], int imonth[], int iyear[]);
	void Updatedetails(string uMovie_Name, string uMovie_Venue, int h, string iMovie_Name[], string iMovie_Venue[], int iday[], int imonth[], int iyear[]); //updating Movie Details
	void Deletedetails(string DMovie_Name, string DMovie_Venue, int h, string iMovie_Name[], string iMovie_Venue[], int iday[], int imonth[], int iyear[]); //Delete Saved Movies
	void view_Movies(string iMovie_Name[], string iMovie_Venue[], int iday[], int imonth[], int iyear[]); //View Saved Movies
}MP;
