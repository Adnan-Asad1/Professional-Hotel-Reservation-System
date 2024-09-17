#include<iostream>
#include<string>
#include<fstream>
#include <vector>
#include <unordered_map>
#include <stack>                // Include the stack header
#include<conio.h>
#include<thread>
#include<chrono>
#include<Vector>
#include<windows.h>
#include<string.h>
#include<iomanip>
#include <sstream>
#include <cstdlib>               // For rand() and srand()
#include <ctime>                 // For time()

using namespace std;

void main_menu();
void animation();
void centerText(const string& text, int color) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

	stringstream ss(text);
	string line;
	vector<string> lines;
	int maxLineLength = 0;

	while (getline(ss, line)) {
		int lineLength = static_cast<int>(line.length());
		if (lineLength > maxLineLength) {
			maxLineLength = lineLength;
		}
		lines.push_back(line);
	}

	for (const auto& line : lines) {
		int padding = (consoleWidth - maxLineLength) / 2;
		for (int j = 0; j < padding; j++) {
			cout << " ";
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		cout << line << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // Reset to default color
	}
}
void clearScreen() {
	// A simple way to clear the console screen
	std::cout << "\033[2J\033[1;1H";
}
void blink(const string& text, int color, int blinkCount) {
	for (int i = 0; i < blinkCount; i++) {
		system("cls");
		centerText(text, color);
		this_thread::sleep_for(chrono::milliseconds(300));
		system("cls");
		this_thread::sleep_for(chrono::milliseconds(300));
	}
}

//                                         -----------------------------------
												   //Admin Funtionality
class text_delay {
public:

	static void slow(const string& text, int delay) {
		for (char c : text) {
			cout << c << flush;
			this_thread::sleep_for(chrono::milliseconds(delay));
		}
	}

};
class utility {
public:

	static  int Getpassword(int len)
	{

		//                                          VIP

		//validation fucntion    that restrict the user to enter only integer or char values 

		char strNum[11];
		char ch;
		int i = 0;
		while (i < len)
		{
			ch = _getch();

			if (ch >= '0' && ch <= '9')
			{
				cout << "*";
				strNum[i] = ch;
				i++;
			}

			if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') {
				cout << endl;
				cout << "\nCharacters are not allowed use digits from 0-9 only" << endl;
				cout << endl;
				system("pause");
				system("cls");
				cout << endl;
				cout << "Enter a number :";
				for (int j = 0; j < i; j++)
				{
					cout << "*";
				}


			}

			if (ch == '\b')
			{
				cout << "\b \b";

				i--;
			}

		}

		cout << "\n";
		strNum[i] = '\0';
		//cout << strNum;

		return atoi(strNum);

	}


	static int GetNumberFromUser(int len)
	{
		char strNum[11];
		if (len > 10)
			len = 10;

		char ch;
		int i = 0;

		while (i < len)
		{
			ch = _getch();

			if (ch >= '0' && ch <= '9')
			{
				cout << ch;
				strNum[i] = ch;
				i++;
			}

			if (ch == '\r')
			{
				break;
			}

			if (ch == '\b')
			{
				cout << "\b \b";

				i--;
			}
		}

		cout << "\n";
		strNum[i] = '\0';

		return atoi(strNum);

	}


	static string GetStringFromUser(int len)
	{
		char strNum[100];

		if (len > 30) len = 25;

		char ch;
		int i = 0;

		while (i < len)
		{
			ch = _getch();

			if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch == ' ')
			{
				cout << ch;
				strNum[i] = ch;
				i++;
			}

			if (ch == '\r')
			{
				break;
			}

			if (ch == '\b')
			{
				cout << "\b \b";

				i--;
			}

		}

		cout << "\n";
		strNum[i] = '\0';
		string str = strNum;
		return str;

	}

};
class date {

public:
	int dd;
	int mm;
	int yyyy;

	date() {

		dd = 00;
		mm = 00;
		yyyy = 0000;

	}

	date(int x, int y, int z) {

		dd = x;
		mm = y;
		yyyy = z;

	}


	void date_display() {

		cout << "Date is: " << dd << "/" << mm << "/" << yyyy << endl;

	}


	~date() {


	}

};
class color {

public:

	void display(int color) {

		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, color);

	}

};

class person {

protected:



public:

	string name;
	string gender;
	string email;


	person() {

		name = "NO Name";
		gender = "Sigma Male";
		email = "Dani777@gamil.com";

	}


	virtual void display() {

		cout << "Name is " << name << endl;
		cout << "Gender is " << gender << endl;
		cout << "Email is " << email << endl;

	}

	~person() {


	}

};
class staff :public person {

public:

	int staff_ID;
	int salary;


	void Add_staff()
	{}
	void Delet_staff()
	{}
	void Update_staff()
	{}
	void Search_staff()
	{}
	void toatl_salary()
	{}


	staff() {

		name = "NO Name";
		email = "Dani777@gamil.com";
		salary = 000;
		staff_ID = 007;
		gender = "Sigma Male";
	}

	staff(string a, string b, int c, int d, string e) {
		name = a;
		email = b;
		salary = c;
		staff_ID = d;
		gender = e;

	}

	staff(const staff& bb) {
		name = bb.name;
		email = bb.email;
		salary = bb.salary;
		staff_ID = bb.staff_ID;
		gender = bb.gender;

	}
	void display() {
		cout << "Name of staff member is:   " << name << endl;
		cout << "Email of staff memeber is: " << email << endl;
		cout << "Salary is:                 " << salary << endl;
		cout << "Staff ID is:               " << staff_ID << endl;
		cout << "Gender is:                 " << gender << endl;
	}
	static void stafff() {

		cout << "\n\n\n\n\n\n" << endl;
		cout << "\t\t\t\t\t\t\t|===================================|" << endl;
		cout << "\t\t\t\t\t\t\t|***********************************|" << endl;
		cout << "\t\t\t\t\t\t\t|" << "____________: (Sub Menu) :_________|" << endl;
		cout << "\t\t\t\t\t\t\t|" << "\t\t" << "\t" << "\t" << "    |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "   Press 1 To Add Staff            |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "   Press 2 To List Staff           |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "   Press 3 To Search Staff         |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "   Press 4 To Update Staff         |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "   Press 5 To Delete Staff         |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "   Press 6 Return to Main Menu     |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "\t\t" << "\t" << "\t" << "    |" << endl;
		cout << "\t\t\t\t\t\t\t|***********************************|" << endl;
		cout << "\t\t\t\t\t\t\t|===================================|" << endl;
	}

	void staff_display() {

		cout << "\n";
		cout << "Name of staff member is:    " << name << endl;
		cout << "Email of staff memeber is : " << email << endl;
		cout << "Salary is:                  " << salary << endl;
		cout << "Staff ID is:                " << staff_ID << endl;

	}

	void pasevalue(string str)
	{
		//name, email, salary, staff ID, 67
		string delimiter = ",";
		size_t pos;
		string token;

		pos = str.find(delimiter);
		token = str.substr(0, pos);
		name = token;
		str.erase(0, pos + delimiter.length());


		pos = str.find(delimiter);
		token = str.substr(0, pos);
		email = token;
		str.erase(0, pos + delimiter.length());

		pos = str.find(delimiter);
		token = str.substr(0, pos);
		salary = atoi(token.c_str());
		str.erase(0, pos + delimiter.length());

		pos = str.find(delimiter);
		token = str.substr(0, pos);
		staff_ID = atoi(token.c_str());
		str.erase(0, pos + delimiter.length());

	}

};
class staff_helper {

	staff* staff_arrray = new staff[50];

public:

	int staff_count = 0;


	void helper_staff() {

		system("cls");

		//system("color 8F");

		int choice = 0;

		do {

			staff::stafff();

			cout << "\n";
			cout << "                                                                  ' Enter choice '     " << endl;
			choice = utility::GetNumberFromUser(8);

			switch (choice)
			{

			case 1:
			{
				if (choice < 100) {


					string n;
					int x, y;

					cout << "\n";
					cout << "----------- New Staff ---------\n";

					cout << "Enter Name:" << endl;
					n = utility::GetStringFromUser(20);
					staff_arrray[staff_count].name = n;

					cout << "Enter email" << endl;
					cin >> staff_arrray[staff_count].email;

					cout << "Enter salary" << endl;
					x = utility::GetNumberFromUser(10);
					staff_arrray[staff_count].salary = x;

					cout << "Enter Staff ID" << endl;
					y = utility::GetNumberFromUser(10);
					staff_arrray[staff_count].staff_ID = y;

					cout << "------- Succesfully Saved -------\n";

					staff_count++;


				}

				break;

			}

			case 2:
			{

				system("cls");
				if (staff_count >= 0) {

					cout << "\n" << endl;
					cout << "============ List of Staff ============" << endl;

					for (int i = 0; i < staff_count; i++)
					{
						staff_arrray[i].staff_display();
					}

					cout << "\n";
					cout << "=======================================" << endl;
				}

				else {


					cout << "\n" << endl;
					cout << "============ List is Empty ==============" << endl;
					cout << "\n";

				}


				break;
			}

			case 3:
			{

				int num = -1;
				cout << "Enter Staff ID to be searched: " << endl;
				num = utility::GetNumberFromUser(10);


				int index = search_staff(num);
				if (index >= 0) {

					cout << "\n";
					cout << "------------- Staff ID Found -------------  " << endl;
					staff_arrray[index].staff_display();
					cout << "\n";
					cout << "------------------------------------------  " << endl;
					cout << "\n";

				}
				else {

					cout << "\n" << endl;
					cout << "------ Staff not Found ------" << endl;
				}

				break;

			}

			case 4: {

				int num = -1;
				cout << "Enter Staff ID to be Updated: " << endl;
				num = utility::GetNumberFromUser(10);

				int index = search_staff(num);
				if (index >= 0) {

					cout << "\n";
					cout << "--------------- Update Staff ID ---------------" << endl;
					cout << "\n";


					string n;
					int x, y;


					cout << "Enter Name:" << endl;
					n = utility::GetStringFromUser(10);
					staff_arrray[index].name = n;

					cout << "Enter email" << endl;
					cin >> staff_arrray[index].email;

					cout << "Enter salary" << endl;
					x = utility::GetNumberFromUser(10);
					staff_arrray[index].salary = x;

					cout << "Enter Staff ID" << endl;
					y = utility::GetNumberFromUser(10);
					staff_arrray[index].staff_ID = y;

					cout << "\n";
					cout << "------------- Sucessfully Updated -------------" << endl;
					cout << "\n";

				}
				else {

					cout << "\n" << endl;
					cout << "------ Staff ID not Found ------" << endl;
				}

				break;

			}
			case 5: {


				int num = -1;
				cout << "Enter Staff ID to be Deleted: " << endl;
				num = utility::GetNumberFromUser(10);

				int index = search_staff(num);
				if (index >= 0) {

					cout << "\n";
					cout << "--------------- Delete Staff ID ---------------" << endl;
					cout << "\n";


					for (int i = index; i < staff_count - 1; i++) {

						staff_arrray[i] = staff_arrray[i + 1];

					}
					staff_count--;

					cout << "\n";
					cout << "------------- Sucessfully Deleted -------------" << endl;
					cout << "\n";

				}
				else {

					cout << "\n" << endl;
					cout << "------ Staff ID not Found ------" << endl;
				}


				break;
			}

			default:


				break;
			}

		} while (choice != 6);


		system("cls");

		color* p = new color;
		p->display(9);
		delete p;

		main_menu();

	}


	void Read_Events_From_File(const char* filepath)
	{

		ifstream Reader;
		Reader.open(filepath, ios::in);
		if (!Reader)
		{
			cout << "File Openning Error...!!!" << endl;

		}

		// File reading!!!

		while (1)
		{
			string str;
			if (getline(Reader, str))
			{
				staff_arrray[staff_count].pasevalue(str);
				staff_count++;
			}
			else
			{
				break;
			}

		}
		Reader.close();




		/*
		staff_count = 0;
		fstream e;
		e.open(filePath);



		while (!e.eof()) {

			e.read((char*)& staff_array[staff_count], sizeof(staff));

			room_count++;
		}

		e.close();
		*/

	}


	void Save_Event_To_File(const char* filepath)
	{

		ofstream Filewriter;
		Filewriter.open(filepath, ios::out);
		if (!Filewriter)
		{
			cout << "File opening Error...!!!" << endl;
		}
		//File writing
		for (int i = 0; i < staff_count; i++)
		{
			Filewriter << staff_arrray[i].name << "," << staff_arrray[i].email << "," << staff_arrray[i].salary << "," << staff_arrray[i].staff_ID << endl;
		}

		Filewriter.close();


		/*
		if (staff_count > 0) {

			fstream h;
			h.open(filePath);

			for (int i = 0; i < staff_count; i++) {

				h.write((const char*)&staff_array[i], sizeof(staff));

			}

			h.close();

		}

		*/

	}



	int search_staff(int num) {


		for (int i = 0; i < staff_count; i++) {

			if (staff_arrray[i].staff_ID == num) {

				return i;
				break;

			}

		}
		cout << "\n";
		return -1;

	}



	~staff_helper() {

		delete[] staff_arrray;

	}

};

class customer : public person

{

public:

	string Adress;
	long long phone;
	double ID_card;

	void Add_customer()
	{}
	void Delet_customer()
	{}
	void search_customer()
	{}
	void Update_customer()
	{}
	void customer_history()
	{}

	customer() {

		name = "Asad";
		email = "Dani777@gamil.com";
		Adress = "Gujranwala";
		phone = 031145663366;
		ID_card = 869695;

	}

	customer(string a, string b, string c, int d, int e) {

		name = a;
		email = b;
		Adress = c;
		phone = d;
		ID_card = e;

	}
	customer(const customer& rr) {

		name = rr.name;
		email = rr.email;
		Adress = rr.Adress;
		phone = rr.phone;
		ID_card = rr.ID_card;

	}
	void display() {

		cout << "Name is:                 " << name << endl;
		cout << "Email  is:               " << email << endl;
		cout << "Phone is:                " << phone << endl;
		cout << "Adress is:               " << Adress << endl;
		cout << "ID Card is:              " << ID_card << endl;
	}
	static void prowny() {


		cout << "\n\n\n\n\n\n" << endl;
		cout << "\t\t\t\t\t\t\t|===================================|" << endl;
		cout << "\t\t\t\t\t\t\t|***********************************|" << endl;
		cout << "\t\t\t\t\t\t\t|" << "____________: (Sub Menu) :_________|" << endl;
		cout << "\t\t\t\t\t\t\t|" << "\t\t" << "\t" << "\t" << "    |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "   Press 1 To Add Customer         |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "   Press 2 To List Customer        |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "   Press 3 To Search Customer      |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "   Press 4 To Update Customer      |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "   Press 5 To Delete Customer      |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "   Press 6 Return to Main Menu     |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "\t\t" << "\t" << "\t" << "    |" << endl;
		cout << "\t\t\t\t\t\t\t|***********************************|" << endl;
		cout << "\t\t\t\t\t\t\t|===================================|" << endl;

	}


	void guest_display() {

		cout << "\n";
		cout << "Customer's name is:    " << name << endl;
		cout << "Customer's email is:   " << email << endl;
		cout << "Customer's phone is:   " << phone << endl;
		cout << "Customer's Adress is:   " << Adress << endl;
		cout << "Customer's ID card is:  " << ID_card << endl;

	}

	void pasevalue(string str)
	{
		//name, email, salary, staff ID, 67
		string delimiter = ",";
		size_t pos;
		string token;

		pos = str.find(delimiter);
		token = str.substr(0, pos);
		name = token;
		str.erase(0, pos + delimiter.length());

		pos = str.find(delimiter);
		token = str.substr(0, pos);
		email = token;
		str.erase(0, pos + delimiter.length());

		pos = str.find(delimiter);
		token = str.substr(0, pos);
		phone = atoi(token.c_str());
		str.erase(0, pos + delimiter.length());

		pos = str.find(delimiter);
		token = str.substr(0, pos);
		Adress = token;
		str.erase(0, pos + delimiter.length());

		pos = str.find(delimiter);
		token = str.substr(0, pos);
		ID_card = atoi(token.c_str());
		str.erase(0, pos + delimiter.length());

	}


};
class customer_helper {

	customer* guest_array = new customer[50];

public:

	int guest_count = 0;

	void helper_customer() {

		system("cls");

		//system("color 8F");

		int choice = 0;

		do {

			customer::prowny();

			cout << "\n";
			cout << "                                                                  ' Enter choice '     " << endl;
			choice = utility::GetNumberFromUser(8);

			switch (choice) {

			case 1: {

				if (choice < 100) {


					string n;
					int id, p;

					cout << "\n";
					cout << "----------- New Customer ---------\n";

					cout << "Enter Name:" << endl;
					n = utility::GetStringFromUser(20);
					guest_array[guest_count].name = n;

					cout << "Enter email" << endl;
					cin >> guest_array[guest_count].email;

					cout << "Enter Phone" << endl;
					p = utility::GetNumberFromUser(15);
					guest_array[guest_count].phone = p;

					cout << "Enter Adress" << endl;
					cin >> guest_array[guest_count].Adress;

					cout << "Enter Customer ID" << endl;
					id = utility::GetNumberFromUser(10);
					guest_array[guest_count].ID_card = id;

					cout << "------- Succesfully Saved -------\n";

					guest_count++;


				}

				break;

			}

			case 2: {


				system("cls");

				if (guest_count >= 0) {

					cout << "\n" << endl;
					cout << "============ List of Customers ============" << endl;

					for (int i = 0; i < guest_count; i++)
					{
						guest_array[i].guest_display();
					}

					cout << "\n";
					cout << "===========================================" << endl;
				}

				else {


					cout << "\n" << endl;
					cout << "============ List is Empty =================" << endl;
					cout << "\n";

				}

				break;

			}

			case 3:
			{

				int num = -1;
				cout << "Enter Customer ID to be searched: " << endl;
				num = utility::GetNumberFromUser(10);

				int index = search_guest(num);
				if (index >= 0) {

					cout << "\n";
					cout << "------------- Customer ID Found -------------  " << endl;
					guest_array[index].guest_display();
					cout << "\n";
					cout << "---------------------------------------------  " << endl;
					cout << "\n";

				}
				else {

					cout << "\n" << endl;
					cout << "------ Customer not Found ------" << endl;
				}

				break;

			}

			case 4: {

				int num = -1;
				cout << "Enter Customer ID to be Updated: " << endl;
				num = utility::GetNumberFromUser(10);

				int index = search_guest(num);
				if (index >= 0) {

					cout << "\n";
					cout << "--------------- Update Customer ID ---------------" << endl;
					cout << "\n";

					string n;
					int id, p;

					cout << "Enter Name:" << endl;
					n = utility::GetStringFromUser(20);
					guest_array[index].name = n;

					cout << "Enter email" << endl;
					cin >> guest_array[index].email;

					cout << "Enter Phone" << endl;
					p = utility::GetNumberFromUser(15);
					guest_array[index].phone = p;

					cout << "Enter Adress" << endl;
					cin >> guest_array[index].Adress;

					cout << "Enter Customer ID" << endl;
					id = utility::GetNumberFromUser(10);
					guest_array[index].ID_card = id;


					cout << "\n";
					cout << "------------- Sucessfully Updated -------------" << endl;
					cout << "\n";

				}
				else {

					cout << "\n" << endl;
					cout << "------ Customer ID not Found ------" << endl;
				}


				break;
			}
			case 5: {


				int num = -1;
				cout << "Enter Customer ID to be Deleted: " << endl;
				num = utility::GetNumberFromUser(10);

				int index = search_guest(num);
				if (index >= 0) {

					cout << "\n";
					cout << "--------------- Delete Customer ID ---------------" << endl;
					cout << "\n";


					for (int i = index; i < guest_count - 1; i++) {

						guest_array[i] = guest_array[i + 1];

					}
					guest_count--;

					cout << "\n";
					cout << "--------------- Sucessfully Deleted ---------------" << endl;
					cout << "\n";

				}
				else {

					cout << "\n" << endl;
					cout << "------ Customer ID not Found ------" << endl;
				}


				break;
			}

			default:
				break;

			}

		} while (choice != 6);

		system("cls");

		color* pp = new color;
		pp->display(9);
		delete pp;

		main_menu();


	}


	void Read_Events_From_File(const char* filepath)
	{

		ifstream Reader;
		Reader.open(filepath, ios::in);
		if (!Reader)
		{
			cout << "File Openning Error...!!!" << endl;

		}

		// File reading!!!

		while (1)
		{
			string str;
			if (getline(Reader, str))
			{
				guest_array[guest_count].pasevalue(str);
				guest_count++;
			}
			else
			{
				break;
			}

		}

		Reader.close();

	}



	void Save_Event_To_File(const char* filepath)
	{

		ofstream Filewriter;
		Filewriter.open(filepath, ios::out);
		if (!Filewriter)
		{
			cout << "File opening Error...!!!" << endl;
		}
		//File writing
		for (int i = 0; i < guest_count; i++)
		{
			Filewriter << guest_array[i].name << "," << guest_array[i].email << "," << guest_array[i].phone << "," << guest_array[i].Adress << "," << guest_array[i].ID_card << endl;
		}

		Filewriter.close();

	}



	int search_guest(int ID) {

		for (int i = 0; i < guest_count; i++) {

			if (guest_array[i].ID_card == ID) {

				return i;
				break;
			}


		}

		return -1;

	}


	~customer_helper() {

		delete[] guest_array;

	}

};

class room_specification {
	//room has specifications
public:

	string lightining;
	int windows;
	int doors;
	string furniture;

	room_specification() {
		lightining = "White Shade";
		windows = 2;
		doors = 1;
		furniture = "Well Furnished";

	}


	~room_specification() {


	}


};
class room {

public:

	int room_num;
	string room_available;
	string room_capacity;
	string room_type;
	string room_floor;
	int room_price;
	int num_of_days;


	room_specification  r;
	//composition class of room
	void room_speciii() {

		r.windows;
		r.doors;

	}


	void Add_room()
	{}
	void Delet_room()
	{}
	void Search_room()
	{}
	void Update_room()
	{}
	void room_history()
	{}

	room() {

		room_num = 0;
		room_available = "Null";
		room_capacity = "Extra large and luxerious";
		room_type = "High Class";
		room_floor = "3rd";

		r.windows = 2;
		r.doors = 1;
		room_price = 00;
		num_of_days = 00;

	}
	room(int a, string b, string c, string d, string e) {

		room_num = a;
		room_available = b;
		room_capacity = c;
		room_type = d;
		room_floor = e;

	}

	room(const room& ee) {

		room_num = ee.room_num;
		room_available = ee.room_available;
		room_capacity = ee.room_capacity;
		room_type = ee.room_type;
		room_floor = ee.room_floor;
	}

	void display() {

		cout << "Room Number is:          " << room_num << endl;
		cout << "Room Availibility:       " << room_available << endl;
		cout << "Room Capacity is:        " << room_capacity << endl;
		cout << "Room Type is:            " << room_type << endl;
		cout << "Room Floor is:           " << room_floor << endl;

		cout << "Room Doors are:          " << r.doors << endl;
		cout << "Room windows are:        " << r.windows << endl;

	}

	static void roomm() {

		cout << "\n\n\n\n\n\n" << endl;
		cout << "\t\t\t\t\t\t\t|===================================|" << endl;
		cout << "\t\t\t\t\t\t\t|***********************************|" << endl;
		cout << "\t\t\t\t\t\t\t|" << "____________: (Sub Menu) :_________|" << endl;
		cout << "\t\t\t\t\t\t\t|" << "\t\t" << "\t" << "\t" << "    |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "   Press 1 To Add Room             |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "   Press 2 To List Room            |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "   Press 3 To Search Room          |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "   Press 4 To Update Room          |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "   Press 5 To Delete Room          |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "   Press 6 Return to Main Menu     |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "\t\t" << "\t" << "\t" << "    |" << endl;
		cout << "\t\t\t\t\t\t\t|***********************************|" << endl;
		cout << "\t\t\t\t\t\t\t|===================================|" << endl;

	}

	void room_display() {

		cout << "\n";
		cout << "Room number is:    " << room_num << endl;
		cout << "Room status is:    " << room_available << endl;
		cout << "Room type is:      " << room_type << endl;
		cout << "Room Price is:     " << room_price << endl;
		cout << "Room floor is:     " << room_floor << endl;
		cout << "Num of days  is:   " << num_of_days << endl;

	}

	void pasevalue(string str)
	{
		//name, email, salary, staff ID, 67
		string delimiter = ",";
		size_t pos;
		string token;

		pos = str.find(delimiter);
		token = str.substr(0, pos);
		room_num = atoi(token.c_str());
		str.erase(0, pos + delimiter.length());

		pos = str.find(delimiter);
		token = str.substr(0, pos);
		room_available = token;
		str.erase(0, pos + delimiter.length());

		pos = str.find(delimiter);
		token = str.substr(0, pos);
		room_type = token;
		str.erase(0, pos + delimiter.length());

		pos = str.find(delimiter);
		token = str.substr(0, pos);
		room_price = atoi(token.c_str());
		str.erase(0, pos + delimiter.length());

		pos = str.find(delimiter);
		token = str.substr(0, pos);
		room_floor = token;
		str.erase(0, pos + delimiter.length());

		pos = str.find(delimiter);
		token = str.substr(0, pos);
		num_of_days = atoi(token.c_str());
		str.erase(0, pos + delimiter.length());

	}


};
class room_helper {

	room* room_array = new room[50];

public:

	int room_count = 0;

	void helper_room() {

		system("cls");

		//system("color 8F");

		int choice = 0;

		do {

			room::roomm();

			cout << "\n";
			cout << "                                                                  ' Enter choice '     " << endl;
			choice = utility::GetNumberFromUser(8);

			switch (choice) {
			case 1:
			{

				if (choice < 100) {

					cout << "\n";
					cout << "----------- New Room ---------\n";

					int n, d;
					string a;

					cout << "Enter Room Number:" << endl;
					n = utility::GetNumberFromUser(10);
					room_array[room_count].room_num = n;

					cout << "Enter Room Availablity" << endl;
					a = utility::GetStringFromUser(20);
					room_array[room_count].room_available = a;

					cout << endl;
					cout << "Room Type" << endl;
					room_type_setter();

					cout << "Room Price " << endl;
					room_price_setter();

					cout << "Enter Room Floor" << endl;
					cin >> room_array[room_count].room_floor;

					cout << "Enter Num of days" << endl;
					d = utility::GetNumberFromUser(10);
					room_array[room_count].num_of_days = d;

					cout << "------- Succesfully Saved -------\n";

					room_count++;


				}

				break;

			}

			case 2:
			{

				system("cls");

				if (room_count >= 0) {

					cout << "\n" << endl;
					cout << "============ List of Rooms ============" << endl;

					for (int i = 0; i < room_count; i++)
					{
						room_array[i].room_display();
					}

					cout << "\n";
					cout << "=======================================" << endl;
				}

				else {


					cout << "\n" << endl;
					cout << "============ List is Empty =============" << endl;
					cout << "\n";

				}


				break;

			}

			case 3:
			{

				int num = -1;
				cout << "Enter Room Number to be Searched: " << endl;
				num = utility::GetNumberFromUser(10);

				int index = search_room(num);
				if (index >= 0) {

					cout << "\n";
					cout << "------------- Room Number Found -------------" << endl;
					room_array[index].room_display();
					cout << "\n";
					cout << "---------------------------------------------" << endl;
					cout << "\n";

				}
				else {

					cout << "\n" << endl;
					cout << "------ Room not Found ------" << endl;
				}

				break;
			}
			case 4: {

				int num = -1;
				cout << "Enter Room Number to be Updated: " << endl;
				num = utility::GetNumberFromUser(10);

				int index = search_room(num);
				if (index >= 0) {

					cout << "\n";
					cout << "--------------- Update Room Num ---------------" << endl;
					cout << "\n";


					int n, d;
					string a;

					cout << "Enter Room Number:" << endl;
					n = utility::GetNumberFromUser(10);
					room_array[room_count].room_num = n;

					cout << "Enter Room Availablity" << endl;
					a = utility::GetStringFromUser(20);
					room_array[room_count].room_available = a;

					cout << endl;
					cout << "Room Type" << endl;
					room_type_setter();

					cout << "Room Price " << endl;
					room_price_setter();

					cout << "Enter Room Floor" << endl;
					cin >> room_array[room_count].room_floor;

					cout << "Enter Num of days" << endl;
					d = utility::GetNumberFromUser(10);
					room_array[room_count].num_of_days = d;

					cout << "\n";
					cout << "------------- Sucessfully Updated -------------" << endl;
					cout << "\n";

				}
				else {

					cout << "\n" << endl;
					cout << "------ Room Num not Found ------" << endl;
				}

				break;

			}
			case 5: {


				int num = -1;
				cout << "Enter Room Number to be Deleted: " << endl;
				num = utility::GetNumberFromUser(10);

				int index = search_room(num);
				if (index >= 0) {

					cout << "\n";
					cout << "--------------- Delete Room Num ---------------" << endl;
					cout << "\n";


					for (int i = index; i < room_count - 1; i++) {

						room_array[i] = room_array[i + 1];

					}
					room_count--;

					cout << "\n";
					cout << "-------------- Sucessfully Deleted --------------" << endl;
					cout << "\n";

				}
				else {

					cout << "\n" << endl;
					cout << "------ Room Num not Found ------" << endl;
				}



				break;
			}

			default:

				break;

			}


		} while (choice != 6);

		system("cls");

		color* ppp = new color;
		ppp->display(9);
		delete ppp;

		main_menu();

	}



	void Read_Events_From_File(const char* filepath)
	{

		ifstream Reader;
		Reader.open(filepath, ios::in);
		if (!Reader)
		{
			cout << "File Openning Error...!!!" << endl;

		}

		// File reading!!!

		while (1)
		{
			string str;
			if (getline(Reader, str))
			{
				room_array[room_count].pasevalue(str);
				room_count++;
			}
			else
			{
				break;
			}

		}

		Reader.close();

	}



	void Save_Event_To_File(const char* filepath)
	{

		ofstream Filewriter;
		Filewriter.open(filepath, ios::out);
		if (!Filewriter)
		{
			cout << "File opening Error...!!!" << endl;
		}
		//File writing
		for (int i = 0; i < room_count; i++)
		{
			Filewriter << room_array[i].room_num << "," << room_array[i].room_available << "," << room_array[i].room_type << "," << room_array[i].room_price << "," << room_array[i].room_floor << "," << room_array[i].num_of_days << endl;
		}

		Filewriter.close();

	}


	int search_room(int num) {

		for (int i = 0; i < room_count; i++) {

			if (room_array[i].room_num == num) {

				return i;
				break;

			}
		}

		return -1;
	}


	void room_type_setter() {

		cout << "\n";
		int n = 0;
		cout << "     1.For Luxury Room            Rs.(70000)" << endl;
		cout << "     2.For Bussines Class Room    Rs.(50000)" << endl;
		cout << "     3.For Local Room             Rs.(30000)" << endl;
		cout << "\n";

		n = utility::GetNumberFromUser(5);

		if (n == 1) {

			room_array[room_count].room_type = "Luxury";
			cout << "Room is Luxury" << endl;

		}

		else if (n == 2) {

			room_array[room_count].room_type = "Bussines Class";
			cout << "Room is Bussines Class" << endl;

		}

		else if (n == 3) {

			room_array[room_count].room_type = "Local";
			cout << "Room is Local" << endl;

		}

		else {

			cout << "You have entered invalid option" << endl;

		}

		cout << "\n";
	}



	void room_price_setter() {

		if (room_array[room_count].room_type == "Luxury") {

			room_array[room_count].room_price = 70000;
			cout << 70000 << endl;
			cout << "\n";

		}

		else if (room_array[room_count].room_type == "Bussines Class") {

			room_array[room_count].room_price = 50000;

			cout << 70000 << endl;
			cout << "\n";

		}

		else if (room_array[room_count].room_type == "Local") {

			room_array[room_count].room_price = 30000;

			cout << 30000 << endl;
			cout << "\n";

		}


	}


	void room_days() {

		cin >> room_array[room_count].num_of_days;

	}


	~room_helper() {


		delete[] room_array;

	}


};

class payment_status {
public:            //Composition class   payment 'has a' payment status

	string payment_sts;
	string Discount;
	int system_tax;


	payment_status() {

		payment_sts = "PENDING";
		Discount = "NON";
		system_tax = 0;

	}

	void pay_sts(string x, string y, int z) {

		payment_sts = x;

		Discount = y;

		system_tax = z;

	}


	void display() {

		cout << "\n";
		cout << " ----------- Payment Status ------------ " << endl;
		cout << "\n";

		cout << "Payment Status is:    " << payment_sts << endl;
		cout << "Discount is:          " << Discount << endl;
		cout << "system_tax is:        " << system_tax << endl;

	}

	~payment_status() {

	}

};    // not in use
class Payment {
public:
	string payment_method;
	string payment_date;
	int amount;
	string payment_time;
	int transection_ID;

	payment_status v;    //Composition class

	void p_display() {

		cout << "\n";
		v.display();

	}

	void pp_display(string x, string y, int z) {

		cout << "\n";

		v.pay_sts(x, y, z);
		v.display();

	}


	void add_payment()
	{}
	void delet_payment()
	{}
	void update_payment()
	{}
	void refund_payment()
	{}
	void search_payment()
	{}
	Payment() {
		payment_method = " Defual Credit Card";
		payment_date = "23/12/2017";
		amount = 0;
		payment_time = "10:35 AM";
		transection_ID = 57718;
	}
	Payment(string a, string b, int c, string d, int e) {

		payment_method = a;
		payment_date = b;
		amount = c;
		payment_time = d;
		transection_ID = e;
	}
	void display() {
		cout << "Payment Method is:       " << payment_method << endl;
		cout << "Payment Date is:         " << payment_date << endl;
		cout << "Amount is:               " << amount << endl;
		cout << "Payment Time is:         " << payment_time << endl;
		cout << "Transection ID is:       " << transection_ID << endl;
	}
	Payment(const Payment& hh) {

		payment_method = hh.payment_method;
		payment_date = hh.payment_date;
		amount = hh.amount;
		payment_time = hh.payment_time;
		transection_ID = hh.transection_ID;
	}
	static void payit() {

		cout << "\n\n\n\n\n\n" << endl;
		cout << "\t\t\t\t\t\t\t|===================================|" << endl;
		cout << "\t\t\t\t\t\t\t|***********************************|" << endl;
		cout << "\t\t\t\t\t\t\t|" << "____________: (Sub Menu) :_________|" << endl;
		cout << "\t\t\t\t\t\t\t|" << "\t\t" << "\t" << "\t" << "    |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "   Press 1 To Add Payment          |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "   Press 2 To List Payment         |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "   Press 3 To Search Payment       |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "   Press 4 To Update Payment       |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "   Press 5 To Delete Payment       |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "   Press 6 Return to Main Menu     |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "\t\t" << "\t" << "\t" << "    |" << endl;
		cout << "\t\t\t\t\t\t\t|***********************************|" << endl;
		cout << "\t\t\t\t\t\t\t|===================================|" << endl;

	}

	void pay_display() {

		cout << "\n";
		cout << " payment Method is:  " << payment_method << endl;
		cout << " payment Amount is:  " << amount << endl;
		cout << " payment Date is:    " << payment_date << endl;
		cout << " payment Time is:    " << payment_time << endl;
		cout << " Patment ID is:      " << transection_ID << endl;

	}



	void pasevalue(string str)
	{
		//jazzcash, 33333, 56000, 24:45, 67
		string delimiter = ",";
		size_t pos;
		string token;

		pos = str.find(delimiter);
		token = str.substr(0, pos);
		payment_method = token;
		str.erase(0, pos + delimiter.length());


		pos = str.find(delimiter);
		token = str.substr(0, pos);
		payment_date = token;
		str.erase(0, pos + delimiter.length());

		pos = str.find(delimiter);
		token = str.substr(0, pos);
		amount = atoi(token.c_str());
		str.erase(0, pos + delimiter.length());

		pos = str.find(delimiter);
		token = str.substr(0, pos);
		payment_time = token;
		str.erase(0, pos + delimiter.length());

		pos = str.find(delimiter);
		token = str.substr(0, pos);
		transection_ID = atoi(token.c_str());
		str.erase(0, pos + delimiter.length());

	}




};
class payment_helper
{

	Payment* payArray = new Payment[50];

public:


	int payment_count = 0;

	void helper_payment()
	{
		//                 Unique
		payArray->amount;
		payArray[2].amount;

		system("cls");
		//system("color 8F");


		Payment c;
		c.p_display();

		string x, y;
		int z;

		cout << "\n";
		cout << "Enter your payament status" << endl;
		x = utility::GetStringFromUser(20);
		cout << "Enter special Discount" << endl;
		cin >> y;
		cout << "Enter system tax" << endl;
		z = utility::GetNumberFromUser(10);

		system("cls");


		c.pp_display(x, y, z);
		cout << "\n";


		int choice = 0;
		do {
			Payment::payit();
			cout << "\n";
			cout << "                                                                  ' Enter choice '     " << endl;
			choice = utility::GetNumberFromUser(8);


			switch (choice)
			{
			case 1:
			{

				cout << "\n";
				cout << "----------- New Payment ---------\n";

				string m;
				int a, id;

				cout << "Enter Payment Method" << endl;
				m = utility::GetStringFromUser(20);
				payArray[payment_count].payment_method = m;

				cout << "Enter Payment Date:" << endl;
				cin >> payArray[payment_count].payment_date;

				cout << "Enter Payment amount:" << endl;
				a = utility::GetNumberFromUser(10);
				payArray[payment_count].amount = a;

				cout << "Enter Payment Time" << endl;
				cin >> payArray[payment_count].payment_time;

				cout << "Enter Payment ID" << endl;
				id = utility::GetNumberFromUser(10);
				payArray[payment_count].transection_ID = id;

				cout << "-------- Succesfully Saved --------\n";


				payment_count++;
				break;

			}

			case 2:
			{

				system("cls");
				if (payment_count <= 0)
				{
					cout << "\n" << endl;
					cout << "============ List is Empty ==============" << endl;
				}
				else
				{
					cout << "\n" << endl;
					cout << "============ List of Payments ============" << endl;
					cout << "\n";
					for (int i = 0; i < payment_count; i++)
					{
						payArray[i].pay_display();
					}

					cout << "\n";
					cout << "===========================================" << endl;
				}

				break;
			}

			case 3:
			{
				int paym_ID = 0;
				cout << "Enter Payment ID to be searched: " << endl;
				paym_ID = utility::GetNumberFromUser(10);


				int index = FindPayIdNO(paym_ID);

				if (index >= 0)
				{
					cout << "\n";
					cout << "------------- Payment ID Found -------------  " << endl;
					payArray[index].pay_display();
					cout << "\n";
					cout << "--------------------------------------------  " << endl;
					cout << "\n";

				}
				else
				{
					cout << "\n" << endl;
					cout << "------ Payment not Found ------" << endl;
				}

				break;
			}

			case 4: {

				int num = -1;
				cout << "Enter Payment ID to be Updated: " << endl;
				num = utility::GetNumberFromUser(10);

				int index = FindPayIdNO(num);
				if (index >= 0) {

					cout << "\n";
					cout << "--------------- Update Payment ID ---------------" << endl;
					cout << "\n";

					string m;
					int a, id;

					cout << "Enter Payment Method" << endl;
					m = utility::GetStringFromUser(20);
					payArray[index].payment_method = m;

					cout << "Enter Payment Date:" << endl;
					cin >> payArray[index].payment_date;

					cout << "Enter Payment amount:" << endl;
					a = utility::GetNumberFromUser(10);
					payArray[index].amount = a;

					cout << "Enter Payment Time" << endl;
					cin >> payArray[index].payment_time;

					cout << "Enter Payment ID" << endl;
					id = utility::GetNumberFromUser(10);
					payArray[index].transection_ID = id;

					cout << "\n";
					cout << "------------- Sucessfully Updated -------------" << endl;
					cout << "\n";

				}
				else {

					cout << "\n" << endl;
					cout << "------ Payment ID not Found ------" << endl;
				}


				break;

			}
			case 5: {


				int num = -1;
				cout << "Enter Payment ID to be Deleted: " << endl;
				num = utility::GetNumberFromUser(10);

				int index = FindPayIdNO(num);
				if (index >= 0) {

					cout << "\n";
					cout << "--------------- Delete Payment ID ---------------" << endl;
					cout << "\n";


					for (int i = index; i < payment_count - 1; i++) {

						payArray[i] = payArray[i + 1];

					}
					payment_count--;

					cout << "\n";
					cout << "--------------- Sucessfully Deleted ---------------" << endl;
					cout << "\n";

				}
				else {

					cout << "\n" << endl;
					cout << "------ Payment ID not Found ------" << endl;
				}




				break;
			}

			default:
			{
				break;
			}

			}


		} while (choice != 6);

		system("cls");

		color* w = new color;
		w->display(9);
		delete w;

		main_menu();

	}


	int  FindPayIdNO(int Tran_ID)
	{
		for (int i = 0; i < payment_count; i++)
		{
			if (payArray[i].transection_ID == Tran_ID)
			{
				return i;
			}
		}
		return -1;
	}


	void WritedatToFile(const char* filepath)
	{
		ofstream Filewriter;
		Filewriter.open(filepath, ios::out);
		if (!Filewriter)
		{
			cout << "File opening Error...!!!" << endl;
		}
		//File writing
		for (int i = 0; i < payment_count; i++)
		{
			Filewriter << payArray[i].payment_method << "," << payArray[i].payment_date << "," << payArray[i].amount << "," << payArray[i].payment_time << "," << payArray[i].transection_ID << endl;
		}

		Filewriter.close();
	}


	void ReadDatafromFile(const char* filepath)
	{
		ifstream Reader;
		Reader.open(filepath, ios::in);
		if (!Reader)
		{
			cout << "File Openning Error...!!!" << endl;

		}



		// File reading!!!

		while (1)
		{
			string str;
			if (getline(Reader, str))
			{
				payArray[payment_count].pasevalue(str);
				payment_count++;
			}
			else
			{
				break;
			}

		}
		Reader.close();
	}


	~payment_helper() {

		delete[] payArray;


	}

};

class Invoice {
public:
	string sender_ID;
	string receiver_ID;
	string taransection_date;
	int invoice_number;



	int amount;
	date Date;                  //compositon
	customer* ID;               //Agregation
	room roomm;                 //compositon


	void Add_invoice()
	{}
	void delet_invoice()
	{}
	void update_invoice()
	{}
	void payment_record()
	{}
	void invoice_date()
	{}

	Invoice() {


		sender_ID = "12234";
		receiver_ID = "57302";
		taransection_date = "03/07/2020";
		amount = 8969;
		invoice_number = 6865;
	}
	Invoice(string a, string b, string c, int d, int e) {
		sender_ID = a;
		receiver_ID = b;
		taransection_date = c;
		amount = d;
		invoice_number = e;
	}
	Invoice(const Invoice& oo) {
		sender_ID = oo.sender_ID;
		receiver_ID = oo.receiver_ID;
		taransection_date = oo.taransection_date;
		amount = oo.amount;
		invoice_number = oo.invoice_number;
	}
	void display() {


		cout << "Sender ID is:            " << sender_ID << endl;
		cout << "Reciever ID is:          " << receiver_ID << endl;
		cout << "Transection date is:     " << taransection_date << endl;
		cout << "Ammount is:              " << amount << endl;
		cout << "Invoice number is:       " << invoice_number << endl;
	}
	static void bill() {

		cout << "\n\n\n\n\n\n" << endl;
		cout << "\t\t\t\t\t\t\t|===================================|" << endl;
		cout << "\t\t\t\t\t\t\t|***********************************|" << endl;
		cout << "\t\t\t\t\t\t\t|" << "____________: (Sub Menu) :_________|" << endl;
		cout << "\t\t\t\t\t\t\t|" << "\t\t" << "\t" << "\t" << "    |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "   Press 1 To Add Invoice          |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "   Press 2 To List Invoice         |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "   Press 3 To Search Invoice       |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "   Press 4 To Update Invoice       |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "   Press 5 To Delete Invoice       |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "   Press 6 Return to Main Menu     |" << endl;
		cout << "\t\t\t\t\t\t\t|" << "\t\t" << "\t" << "\t" << "    |" << endl;
		cout << "\t\t\t\t\t\t\t|***********************************|" << endl;
		cout << "\t\t\t\t\t\t\t|===================================|" << endl;


	}

	void invo_display() {

		cout << "\n";

		if (ID != NULL) {

			//cout << "Customer name is:        " << ID << endl;
		}

		cout << "Your invoice number is:  " << invoice_number << endl;
		cout << "Your invoice amount is:  " << amount << endl;
		cout << "Sender ID is:            " << sender_ID << endl;
		cout << "Reciever ID is:          " << receiver_ID << endl;
		cout << "Transection  date is:    " << taransection_date << endl;
		//cout << "Num of days are:         " << roomm.num_of_days << endl;
		//cout << "Room Price is:           " << roomm.room_type << endl;
		//cout << "Room type is:            " << roomm.room_price << endl;

	}

	void pasevalue(string str)
	{
		string delimiter = ",";
		size_t pos;
		string  token;

		pos = str.find(delimiter);
		token = str.substr(0, pos);
		invoice_number = atoi(token.c_str());
		str.erase(0, pos + delimiter.length());

		pos = str.find(delimiter);
		token = str.substr(0, pos);
		amount = atoi(token.c_str());
		str.erase(0, pos + delimiter.length());

		pos = str.find(delimiter);
		token = str.substr(0, pos);
		sender_ID = token;
		str.erase(0, pos + delimiter.length());

		pos = str.find(delimiter);
		token = str.substr(0, pos);
		receiver_ID = token;
		str.erase(0, pos + delimiter.length());

		pos = str.find(delimiter);
		token = str.substr(0, pos);
		taransection_date = token;
		str.erase(0, pos + delimiter.length());

	}

};
customer r;
class invoice_helper {

	Invoice* invo_array = new Invoice[50];

public:

	int invo_count = 0;

	void helper_invoice() {

		invo_array->ID = &r;

		//   #unique 

		invo_array->amount;
		invo_array[1].amount;

		system("cls");
		//system("color 8F");

		int choice = 0;

		do {

			Invoice::bill();

			cout << "\n";
			cout << "                                                                  ' Enter choice '     " << endl;
			choice = utility::GetNumberFromUser(10);

			switch (choice) {

			case 1:
			{
				int q, w;

				cout << "\n";
				cout << "----------- New Invoice ---------\n";

				cout << "Enter Invoice Number" << endl;
				q = utility::GetNumberFromUser(10);
				invo_array[invo_count].invoice_number = q;

				cout << "Enter Amount :" << endl;
				w = utility::GetNumberFromUser(10);
				invo_array[invo_count].amount = w;

				cout << "Enter Sender ID :" << endl;
				cin >> invo_array[invo_count].sender_ID;

				cout << "Enter Receiver ID" << endl;
				cin >> invo_array[invo_count].receiver_ID;

				cout << "Enter Transection Date" << endl;
				cin >> invo_array[invo_count].taransection_date;

				cout << "-------- Succesfully Saved --------\n";

				invo_count++;
				break;

			}

			case 2: {


				system("cls");

				if (invo_count >= 0) {

					cout << "\n" << endl;
					cout << "============ List of Invoice ============" << endl;

					for (int i = 0; i < invo_count; i++)
					{
						invo_array[i].invo_display();
					}

					cout << "\n";
					cout << "===========================================" << endl;
				}

				else {

					cout << "\n" << endl;
					cout << "============ List is Empty ================" << endl;
					cout << "\n";

				}


				break;

			}

			case 3:
			{
				int num = -1;
				cout << "Enter Invoice Number to be searched: " << endl;
				num = utility::GetNumberFromUser(10);

				int index = search_invoice(num);

				if (index >= 0)
				{
					cout << "\n";
					cout << "------------- Invoice Number Found -------------  " << endl;
					invo_array[index].invo_display();
					cout << "\n";
					cout << "------------------------------------------------  " << endl;
					cout << "\n";

				}
				else
				{
					cout << "\n" << endl;
					cout << "------ Invoice not Found ------" << endl;
				}

				break;

			}

			case 4: {

				int num = -1;
				cout << "Enter Invoice Number to be Deleted: " << endl;
				num = utility::GetNumberFromUser(10);

				int index = search_invoice(num);
				if (index >= 0) {

					cout << "\n";
					cout << "--------------- Update Invoice Num ---------------" << endl;
					cout << "\n";

					int q, w;

					cout << "Enter Invoice Number" << endl;
					q = utility::GetNumberFromUser(10);
					invo_array[index].invoice_number = q;

					cout << "Enter Amount :" << endl;
					w = utility::GetNumberFromUser(10);
					invo_array[index].amount = w;

					cout << "Enter Sender ID :" << endl;
					cin >> invo_array[index].sender_ID;

					cout << "Enter Receiver ID" << endl;
					cin >> invo_array[index].receiver_ID;

					cout << "Enter Transection Date" << endl;
					cin >> invo_array[index].taransection_date;

					cout << "\n";
					cout << "------------- Sucessfully Updated -------------" << endl;
					cout << "\n";

				}
				else {

					cout << "\n" << endl;
					cout << "------ Invoice Num not Found ------" << endl;
				}

				break;
			}
			case 5: {


				int num = -1;
				cout << "Enter Invoice Number to be Updated: " << endl;
				num = utility::GetNumberFromUser(10);

				int index = search_invoice(num);
				if (index >= 0) {

					cout << "\n";
					cout << "--------------- Delete Invoice Num ---------------" << endl;
					cout << "\n";


					for (int i = index; i < invo_count - 1; i++) {

						invo_array[i] = invo_array[i + 1];

					}
					invo_count--;

					cout << "\n";
					cout << "--------------- Sucessfully Deleted ---------------" << endl;
					cout << "\n";

				}
				else {

					cout << "\n" << endl;
					cout << "------ Invoice Num not Found ------" << endl;
				}


				break;
			}


			default:
				break;

			}

		} while (choice != 6);

		system("cls");

		color* ww = new color;
		ww->display(9);
		delete ww;

		main_menu();


	}


	void ReadDatafromFile(const char* filepath)
	{
		ifstream Reader;
		Reader.open(filepath, ios::in);
		if (!Reader)
		{
			cout << "File Openning Error...!!!" << endl;

		}



		// File reading!!!

		while (1)
		{
			string str;
			if (getline(Reader, str))
			{
				invo_array[invo_count].pasevalue(str);
				invo_count++;
			}
			else
			{
				break;
			}

		}
		Reader.close();
	}



	void WritedatToFile(const char* filepath)
	{
		ofstream Filewriter;
		Filewriter.open(filepath, ios::out);
		if (!Filewriter)
		{
			cout << "File Opening Error...!!!" << endl;
		}
		//File writing
		for (int i = 0; i < invo_count; i++)
		{
			Filewriter << invo_array[i].invoice_number << "," << invo_array[i].amount << "," << invo_array[i].sender_ID << "," << invo_array[i].receiver_ID << "," << invo_array[i].taransection_date << endl;
		}

		Filewriter.close();
	}


	int search_invoice(int num) {

		int index = -1;
		for (int i = 0; i < invo_count; i++) {

			if (invo_array[i].invoice_number == num) {

				return i;
				break;

			}

		}

		return -1;
	}

	~invoice_helper() {

		delete[] invo_array;

	}

};

//--------------------------------------------------------------------------------------------------------------------
												   //User Funtionality

// Node 
struct Reservation {
	string name;
	int age;
	long long phone;
	int roomNumber;
	long long cnic;     
	double payment;

	Reservation* next;   //  data  + p->
};

//Linked List
class HotelReservationSystem {
private:
	Reservation* head;   //p->
	unordered_map<int, bool> rooms;
	stack<double> paymentStack;  

public:

	HotelReservationSystem() : head(nullptr) {

		rooms.reserve(10);
		for (int i = 1; i <= 10; ++i) {
			rooms[i] = true;
		}
		readReservationsFromFile();
		readPaymentsFromFile();
	}

	void addReservation(const Reservation& reservation) {

		Reservation* newReservation = new Reservation(reservation);
		newReservation->next = head;
		head = newReservation;
		rooms[reservation.roomNumber] = false;
		saveReservationsToFile();
	}

	void readReservationsFromFile() {
		ifstream reservationFile("reservations.txt");
		if (reservationFile.is_open()) {
			Reservation newReservation;
			while (reservationFile >> newReservation.name >> newReservation.age >> newReservation.phone
				>> newReservation.cnic >> newReservation.payment >> newReservation.roomNumber)
			{
				addReservation(newReservation);
			}
			reservationFile.close();
		}
	}

	void saveReservationsToFile() {
		ofstream reservationFile("reservations.txt");
		if (reservationFile.is_open()) {
			Reservation* current = head;
			while (current != nullptr) {
				reservationFile << current->name << " "
					<< current->age << " "
					<< current->phone << " "
					<< current->cnic << " "
					<< current->payment << " "
					<< current->roomNumber << "\n";
				current = current->next;
			}
			reservationFile.close();
		}
	}

	void displayReservations() {
		cout << "\n\nReservations:\n\n";
		Reservation* current = head;
		while (current != nullptr) {
			displayReservationPattern(*current);
			current = current->next;
		}
	}

	void displayReservationPattern(const Reservation& reservation) {
		
		cout << "\n-----------------------------------\n";
		cout << "Reservation Details:\n\n";
		cout << "Name:                 " << reservation.name << endl;
		cout << "Age:                  " << reservation.age << endl;
		cout << "Phone:                " << reservation.phone << endl;
		cout << "CNIC:                 " << reservation.cnic << endl;
		cout << "Room Number:          " << reservation.roomNumber << endl;
		cout << "-----------------------------------\n";
	}

	void cancelReservation(int roomNumber) {
		Reservation* current = head;
		Reservation* prev = nullptr;

		while (current != nullptr && current->roomNumber != roomNumber) {
			prev = current;
			current = current->next;
		}

		if (current != nullptr) {
			if (prev != nullptr) {
				prev->next = current->next;
			}
			else {
				head = current->next;
			}
			delete current;
			rooms[roomNumber] = true;
			saveReservationsToFile();
		}
		else {
			cout << "Room number not found.\n";
		}
	}

	void updateReservation(int roomNumber) {
		Reservation* current = head;
		while (current != nullptr && current->roomNumber != roomNumber) {
			current = current->next;
		}

		if (current != nullptr) {
			cout << "Enter updated name: ";
			cin >> current->name;
			cout << "Enter updated age: ";
			cin >> current->age;
			cout << "Enter updated phone: ";
			cin >> current->phone;
			cout << "Enter updated CNIC: ";
			cin >> current->cnic;
			saveReservationsToFile();
		}
		else {
			cout << "Room number not found.\n";
		}
	}

	////////////////------------------- stack start ---------------------------

	void addPayment(double amount) {
		paymentStack.push(amount);
		savePaymentsToFile();
	}

	void savePaymentsToFile() {
		ofstream paymentFile("payments.txt");
		if (paymentFile.is_open()) {
			stack<double> tempStack = paymentStack;
			while (!tempStack.empty()) {
				paymentFile << tempStack.top() << "\n";
				tempStack.pop();
			}
			paymentFile.close();
		}
	}

	void readPaymentsFromFile() {
		ifstream paymentFile("payments.txt");
		if (paymentFile.is_open()) {
			double payment;
			while (paymentFile >> payment) {
				paymentStack.push(payment);
			}
			paymentFile.close();
		}
	}

	void displayPayments() {

		cout << "\n\n";
		cout << "Payments (using Pop Functionality):\n\n";
		stack<double> tempStack = paymentStack;
		while (!tempStack.empty()) {
			cout << "\tPayment:      " << tempStack.top() << endl;
			cout<<"---------------------------------\n";
			tempStack.pop();
		}
		cout << "\n";

	}


	void displayRooms() {

		cout << "\n\n";
		cout << "\t\t\t\t\t\t\t\t\t|----------------------------------|" << endl;
		cout << "\t\t\t\t\t\t\t\t\t|    *** Rooms Availability ***    |" << endl;
		cout << "\t\t\t\t\t\t\t\t\t|----------------------------------|\n\n";
		cout << "\t----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
		cout << "\tRoom No.\t\t\t Status\t\t\t\t  Features\t\t    Area\t\t\t  Cost\n\n";
		cout << "\t----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";

		srand(time(0)); // Seed for random values

		for (int i = 1; i <= 10; ++i) {
			cout << "\t" << std::setw(2) << i << "\t\t\t\t" << std::setw(9) << (rooms[i] ? "Available" : "Booked") << "\t\t\t";

			// Randomly select features
			int featureType = rand() % 3;
			switch (featureType) {
			case 0:
				cout << std::setw(10) << "Wi-Fi";
				break;
			case 1:
				cout << std::setw(10) << "TV";
				break;
			case 2:
				cout << std::setw(10) << "Balcony";
				break;
			}

			// Random area (assuming square feet)
			int area = rand() % 150 + 150; // Generating random area between 150 and 300 square feet
			cout << std::setw(20) << area << " sqft\t\t\t";

			// Random cost (assuming in dollars)
			double cost = (rand() % 1000 + 500) / 10.0; // Generating random cost between $50 and $150
			cout << "$" << std::setw(6) << std::fixed << std::setprecision(2) << cost << "\n";

			cout << "\t----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
		}


		cout << "\n\n\n\n\n";
	}
};

//                                         -----------------------------------


void animation() {

	system("color 2F");

	cout << "\n\n\n\n\n\n" << endl;
	cout << "\t\t\t\t ===========================================================" << endl;
	cout << "\t\t\t\t|***********************************************************|" << endl;
	cout << "\t\t\t\t|===========================================================|" << endl;
	cout << "\t\t\t\t|" << "\t\t\t\t" << "\t" << "\t" << "\t    |" << endl;
	cout << "\t\t\t\t|" << "\t\t\t\t" << "\t" << "\t" << "\t    |" << endl;
	cout << "\t\t\t\t|\t           Hotel Reservation System    \t\t    |" << endl;
	cout << "\t\t\t\t|" << "\t\t\t\t" << "\t" << "\t" << "\t    |" << endl;
	cout << "\t\t\t\t|" << "\t\t\t\t" << "\t" << "\t" << "\t    |" << endl;
	cout << "\t\t\t\t|===========================================================|" << endl;
	cout << "\t\t\t\t|***********************************************************|" << endl;
	cout << "\t\t\t\t ===========================================================" << endl;
	cout << "\n";
	text_delay::slow("\t\t\t\t\t\t\t\t   Coded By:  ADNAN ASAD", 20);
	cout << "\n";
	cout << "\t\t\t\t";
	cout << "Loading" << " ";
	char x = 219;
	for (int i = 0; i < 35; i++)
	{
		cout << x;
		if (i < 10)
			Sleep(50);
		if (i >= 10 && i < 20)
			Sleep(60);
		if (i >= 10)
			Sleep(20);
	}
	system("cls");

}

void display()
{
	blink(R"(

 | |  | |     | |     | |
 | |__| | ___ | |_ ___| |
 |  __  |/ _ \| __/ _ \ |
 | |  | | (_) | ||  __/ |
 |_|  |_|\___/ \__\___|_|

        )", 11, 1); // Yellow text

	blink(R"(
  _____                                _   _             
 |  __ \                              | | (_)            
 | |__) |___  ___  ___ _ ____   ____ _| |_ _  ___  _ __  
 |  _  // _ \/ __|/ _ \ '__\ \ / / _` | __| |/ _ \| '_ \ 
 | | \ \  __/\__ \  __/ |   \ V / (_| | |_| | (_) | | | |
 |_|  \_\___||___/\___|_|    \_/ \__,_|\__|_|\___/|_| |_|
                                                         
                )", 12, 1); // Light Blue text

	blink(R"(
   _____           _                 
  / ____|         | |                
 | (___  _   _ ___| |_ ___ _ __ ___  
  \___ \| | | / __| __/ _ \ '_ ` _ \ 
  ____) | |_| \__ \ ||  __/ | | | | |
 |_____/ \__, |___/\__\___|_| |_| |_|
          __/ |                      
         |___/                                                      
                )", 14, 1); // Light Yellow text

	// Display the full body for 2 seconds
	centerText(R"(
 /$$   /$$             /$$               /$$
| $$  | $$            | $$              | $$
| $$  | $$  /$$$$$$  /$$$$$$    /$$$$$$ | $$
| $$$$$$$$ /$$__  $$|_  $$_/   /$$__  $$| $$
| $$__  $$| $$  \ $$  | $$    | $$$$$$$$| $$
| $$  | $$| $$  | $$  | $$ /$$| $$_____/| $$
| $$  | $$|  $$$$$$/  |  $$$$/|  $$$$$$$| $$
|__/  |__/ \______/    \___/   \_______/|__/
                                            
                                            
                            )", 11); // Yellow text

	centerText(R"(

                    /$$$$$$$                                                                /$$     /$$                    
                   | $$__  $$                                                              | $$    |__/                    
                   | $$  \ $$  /$$$$$$   /$$$$$$$  /$$$$$$   /$$$$$$  /$$    /$$ /$$$$$$  /$$$$$$   /$$  /$$$$$$  /$$$$$$$ 
                   | $$$$$$$/ /$$__  $$ /$$_____/ /$$__  $$ /$$__  $$|  $$  /$$/|____  $$|_  $$_/  | $$ /$$__  $$| $$__  $$
                   | $$__  $$| $$$$$$$$|  $$$$$$ | $$$$$$$$| $$  \__/ \  $$/$$/  /$$$$$$$  | $$    | $$| $$  \ $$| $$  \ $$
                   | $$  \ $$| $$_____/ \____  $$| $$_____/| $$        \  $$$/  /$$__  $$  | $$ /$$| $$| $$  | $$| $$  | $$
                   | $$  | $$|  $$$$$$$ /$$$$$$$/|  $$$$$$$| $$         \  $/  |  $$$$$$$  |  $$$$/| $$|  $$$$$$/| $$  | $$
                   |__/  |__/ \_______/|_______/  \_______/|__/          \_/    \_______/   \___/  |__/ \______/ |__/  |__/
                                                                                                                                                                                             
                                                     
                )", 12); // Light Blue text

	centerText(R"(

  /$$$$$$                        /$$                            
 /$$__  $$                      | $$                            
| $$  \__/ /$$   /$$  /$$$$$$$ /$$$$$$    /$$$$$$  /$$$$$$/$$$$ 
|  $$$$$$ | $$  | $$ /$$_____/|_  $$_/   /$$__  $$| $$_  $$_  $$
 \____  $$| $$  | $$|  $$$$$$   | $$    | $$$$$$$$| $$ \ $$ \ $$
 /$$  \ $$| $$  | $$ \____  $$  | $$ /$$| $$_____/| $$ | $$ | $$
|  $$$$$$/|  $$$$$$$ /$$$$$$$/  |  $$$$/|  $$$$$$$| $$ | $$ | $$
 \______/  \____  $$|_______/    \___/   \_______/|__/ |__/ |__/
           /$$  | $$                                            
          |  $$$$$$/                                            
           \______/    
                                                                             
                )", 14); // Light Yellow text
	cout << "\n\n";
	string made = " Encoded by Adnan Asad ";
	cout << "\t\t\t\t\t\t\t\t\t\t";
	color r;
	r.display(3);
	for (auto& c : made)
	{
		cout << c;
		Sleep(100);
	}
	this_thread::sleep_for(chrono::seconds(2));

	system("cls");
}
void displayWelcome()
{
	blink(R"(
__          __  _                          
 \ \        / / | |                         
  \ \  /\  / /__| | ___ ___  _ __ ___   ___ 
   \ \/  \/ / _ \ |/ __/ _ \| '_ ` _ \ / _ \
    \  /\  /  __/ | (_| (_) | | | | | |  __/
     \/  \/ \___|_|\___\___/|_| |_| |_|\___|
                                            

        )", 11, 1); // Yellow text

	blink(R"(
  _______    
 |__   __|   
    | | ___  
    | |/ _ \ 
    | | (_) |
    |_|\___/ 
             
                                                         
                )", 12, 1); // Light Blue text

	blink(R"(

  _    _                 _____                 _ 
 | |  | |               |  __ \               | |
 | |  | |___  ___ _ __  | |__) |_ _ _ __   ___| |
 | |  | / __|/ _ \ '__| |  ___/ _` | '_ \ / _ \ |
 | |__| \__ \  __/ |    | |  | (_| | | | |  __/ |
  \____/|___/\___|_|    |_|   \__,_|_| |_|\___|_|
                                                 
                                                   
                )", 14, 1); // Light Yellow text

	// Display the full body for 2 seconds
	centerText(R"(

                         /$$                                            
                        | $$                                            
 /$$  /$$  /$$  /$$$$$$ | $$  /$$$$$$$  /$$$$$$  /$$$$$$/$$$$   /$$$$$$ 
| $$ | $$ | $$ /$$__  $$| $$ /$$_____/ /$$__  $$| $$_  $$_  $$ /$$__  $$
| $$ | $$ | $$| $$$$$$$$| $$| $$      | $$  \ $$| $$ \ $$ \ $$| $$$$$$$$
| $$ | $$ | $$| $$_____/| $$| $$      | $$  | $$| $$ | $$ | $$| $$_____/
|  $$$$$/$$$$/|  $$$$$$$| $$|  $$$$$$$|  $$$$$$/| $$ | $$ | $$|  $$$$$$$
 \_____/\___/  \_______/|__/ \_______/ \______/ |__/ |__/ |__/ \_______/
                                                                        
                                                                        
                                           
                            )", 11); // Yellow text

	centerText(R"(    

                                                 /$$$$$$$                               
                                                 | $$__  $$                              
                                                 | $$  \ $$  /$$$$$$   /$$$$$$   /$$$$$$ 
                                                 | $$  | $$ /$$__  $$ |____  $$ /$$__  $$
                                                 | $$  | $$| $$$$$$$$  /$$$$$$$| $$  \__/
                                                 | $$  | $$| $$_____/ /$$__  $$| $$      
                                                 | $$$$$$$/|  $$$$$$$|  $$$$$$$| $$      
                                                 |_______/  \_______/ \_______/|__/      
                                        
                                        
                                                                                                                                                                    
                                                     
                )", 12); // Light Blue text

	centerText(R"(

         /$$   /$$                              
         | $$  | $$                              
         | $$  | $$  /$$$$$$$  /$$$$$$   /$$$$$$ 
         | $$  | $$ /$$_____/ /$$__  $$ /$$__  $$
         | $$  | $$|  $$$$$$ | $$$$$$$$| $$  \__/
         | $$  | $$ \____  $$| $$_____/| $$      
         |  $$$$$$/ /$$$$$$$/|  $$$$$$$| $$      
          \______/ |_______/  \_______/|__/      
                                        
                                        
                                        
                                                                             
                )", 14); // Light Yellow text
	cout << "\n\n";
	string made = " Encoded by Adnan Asad ";
	cout << "\t\t\t\t\t\t\t\t\t\t";
	color r;
	r.display(3);
	for (auto& c : made)
	{
		cout << c;
		Sleep(100);
	}
	this_thread::sleep_for(chrono::seconds(2));

	system("cls");
}

void art() {

	centerText(R"(
                                                    
o(=(=(=(=)=)=)=)o
 !!!!!!}!{!!!!!!                                                ___ 
 !!!!!} | {!!!!!                                               /   \
 !!!!}  |  {!!!!     _!_     ()              ()     _!_       | //  |
 !!!'   |   '!!!    |~@~|    ||______________||    |~@~|      |     |
 ~@~----+----~@~    |___|    |                |    |___|       \___/
 !!!    |    !!!      |      |      ~@@~      |      |       _________
 !!!    |    !!!     ( )     |_______  _______|     ( )     |____-____|
 !!!____|____!!!  __(___)__  {__~@~__}{__~@~__}  __(___)__  |____-____|
 !!!=========!!!   |__-__|   %%%%%%%%%%%%%%%%%%   |__-__|   |____-____|
_!!!_________!!!___|_____|_ %%%%%%%%%%%%%%%%%%%% _|_____|___|____-____|_
                   |     | %%%%%%%%%%%%%%%%%%%%%% |     |   |/       \|
                          %%%%%%%%%%%%%%%%%%%%%%%%
                         %%%%%%%%%%%%%%%%%%%%%%%%%%
                        %%%%%%%%%%%%%%%%%%%%%%%%%%%%
                       /!!!!!!!!!!!!!!!!!!!!!!!!!!!!\
                       !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  
                       !!!!!!!!!!!!!!!!!!!!!!!!!!lc!!
                       `======~@~==========~@~======`
                      `==============================`
                     `====~@~==================~@~====`
                    `==================================`
                   `==~@~==========================~@~==`


                             )", 11); // Yellow text

}
void Asad_Hotel() {


	centerText(R"(

                               Asad's Hotel
 ______________________________________________________________________________
|  --  = .. =  --  = .. =  --  = .. =  --  = .. =  --  = .. =  --  = .. =  --  |
|  ==  .'  '.  ==  .'  '.  ==  .'  '.  ==  .'  '.  ==  .'  '.  ==  .'  '.  ==  |
|`-==-`      `-==-`      `-==-`      `-==-`      `-==-`      `-==-`      `-==-`|
|        **          **          **          **          **          **        |
|  **          **          **          **          **          **          **  |
|        **          **          **          **          **          **        |
|  **        _ ** _____    _____    _  **          **          **          **  |
|        ** / \  _)   (    )   (_**/ \       **          **          **        |
|  **      /___\)      (__)      (/___\**          ** =====================**  | 
|        **  |)    _____  _____    (|        **        [__]     (     [__]     | 
|  **      _)|    (_____)(_____)    |(_**          **  [__] O  ( )  O [__] **  |
|lc_______)__|____%%%%%%%%%%%%%%____|__(_______________[__]/!\@@@@@/!\[__]_____|
            _|_  %%%%%%%%%%%%%%%%  _|_                '===================' 
                %%%%%%%%%%%%%%%%%% 
               %%%%%%%%%%%%%%%%%%%%
     /zzzzzzzz%%%%%%%%%%%%%%%%%%%%%%zzzzzzzzz\
    /zzzzzzzz/||||||||||||||||||||||\zzzzzzzzz\
   /zzzzzzzzz||||||||||||||||||||||||zzzzzzzzzz\
  /zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
 /zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\
/zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz\                                        
                                                                                                                           
                )", 14); // Light Yellow text


}

void ending_art() {

	centerText(R"(

         .   .                     .     .
                  .       |~~             .
       .               ___|___  .
                       ((((())))
          .           (((((()))))         .
                    |-------------|
              +    I_I_I_I_I_I_I_I_I    +
             (()   |---------------|   (()
            |---|  ||-| |-| |-| |-||  |---|
  _________|-----|_|---------------|_|-----|_________
  I_I_I_I_I_I_I_I|I_I_I_I_I_I_I_I_I_I|I_I_I_I_I_I_I_|
  |-------|------|-------------------|------|-------|
  ||-| |-||  |-| ||-| |-| |-| |-| |-|| |-|  ||-| |-||
((|-------|------|-------------------|------|-------|))
()|  |_|  |  |_| |::::: ------- :::::| |_|  |  |_|  |()
))|  |_|  |  |_| | |_| |_.-"-._| |_| | |_|  |  |_|  |((
()|-------|------| |_| | | | | | |_| |------|-------|()
@@@@@@@@@@@@@@@@@|-----|_|_|_|_|-----|@@@@@@@@@@@@@@@@@
Dani^           @@@@/=============\@@@@
                       /       \


                             )", 7); // Yellow text

}
void ending_art2() {

	centerText(R"(

                                  .-.
                                 /___\
                                 |___|
                                 |]_[|
                                 / I \
                              JL/  |  \JL
   .-.                    i   ()   |   ()   i                    .-.
   |_|     .^.           /_\  LJ=======LJ  /_\           .^.     |_|
._/___\._./___\_._._._._.L_J_/.-.     .-.\_L_J._._._._._/___\._./___\._._._
       ., |-,-| .,       L_J  |_| [I] |_|  L_J       ., |-,-| .,        .,
       JL |-O-| JL       L_J%%%%%%%%%%%%%%%L_J       JL |-O-| JL        JL
IIIIII_HH_'-'-'_HH_IIIIII|_|=======H=======|_|IIIIII_HH_'-'-'_HH_IIIIII_HH_
-------[]-------[]-------[_]----\.=I=./----[_]-------[]-------[]--------[]-
 _/\_  ||\\_I_//||  _/\_ [_] []_/_L_J_\_[] [_] _/\_  ||\\_I_//||  _/\_  ||\
 |__|  ||=/_|_\=||  |__|_|_|   _L_L_J_J_   |_|_|__|  ||=/_|_\=||  |__|  ||-
 |__|  |||__|__|||  |__[___]__--__===__--__[___]__|  |||__|__|||  |__|  |||
IIIIIII[_]IIIII[_]IIIIIL___J__II__|_|__II__L___JIIIII[_]IIIII[_]IIIIIIII[_]
 \_I_/ [_]\_I_/[_] \_I_[_]\II/[]\_\I/_/[]\II/[_]\_I_/ [_]\_I_/[_] \_I_/ [_]
./   \.L_J/   \L_J./   L_JI  I[]/     \[]I  IL_J    \.L_J/   \L_J./   \.L_J
|     |L_J|   |L_J|    L_J|  |[]|     |[]|  |L_J     |L_J|   |L_J|     |L_J
|_____JL_JL___JL_JL____|-||  |[]|     |[]|  ||-|_____JL_JL___JL_JL_____JL_J
                       '-''--'--'-----'--'--''-'

                             )", 7); // Yellow text

}

void main_menu() {

	system("cls");
	
	art();

	color* ls = new color;
	ls->display(14);
	delete ls;

	int n;

	cout << "\t\t\t\t\t\t\t|=======================================================================|" << endl;
	cout << "\t\t\t\t\t\t\t|***********************************************************************|" << endl;
	cout << "\t\t\t\t\t\t\t|" << "______________________: (Welcome to Main Menu) :_______________________|" << endl;
	cout << "\t\t\t\t\t\t\t|" << "\t\t" << "\t" << "\t" << "                                        |" << endl;
	cout << "\t\t\t\t\t\t\t|" << "    _ _ _ _ _ _ _  Press 1 For Staff Management     :-_ _ _ _ _ _ _    |" << endl;
	cout << "\t\t\t\t\t\t\t|" << "   _ _ _ _ _ _ _ _ Press 2 For Customer Management  :-_ _ _ _ _        |" << endl;
	cout << "\t\t\t\t\t\t\t|" << "     _ _ _ _ _ _ _ Press 3 For Room Management      :-_ _ _ _ _ _      |" << endl;
	cout << "\t\t\t\t\t\t\t|" << "      _ _ _ _ _ _  Press 4 For Payment Management   :-_ _ _ _          |" << endl;
	cout << "\t\t\t\t\t\t\t|" << "      _ _ _ _ _ _  Press 5 For Invoice Management   :-_ _ _ _ _        |" << endl;
	cout << "\t\t\t\t\t\t\t|" << "         _ _ _ _ _ Press 6 For Exit                 :-_ _ _ _          |" << endl;
	cout << "\t\t\t\t\t\t\t|" << "\t\t" << "\t" << "\t" << "                                        |" << endl;
	cout << "\t\t\t\t\t\t\t|***********************************************************************|" << endl;
	cout << "\t\t\t\t\t\t\t|=======================================================================|" << endl;
	cout << "\n";

	cout << "\t\t\t\t\t\t\t                             ' Enter Option ' " << endl;

	n = utility::GetNumberFromUser(10);


	if (n == 1) {

		//helper classes processing
		staff_helper r;
		r.Read_Events_From_File("staff.txt");

		color* ll = new color;
		ll->display(14);
		delete ll;

		r.helper_staff();
		r.Save_Event_To_File("staff.txt");

	}

	else if (n == 2) {


		customer_helper r;
		r.Read_Events_From_File("guest.txt");

		color* b = new color;
		b->display(14);
		delete b;

		r.helper_customer();
		r.Save_Event_To_File("guest.txt");

	}

	else if (n == 3) {

		room_helper r;
		r.Read_Events_From_File("Room.txt");

		color* i = new color;
		i->display(14);
		delete i;

		r.helper_room();
		r.Save_Event_To_File("Room.txt");

	}

	else if (n == 4) {

		payment_helper l;
		l.ReadDatafromFile("paymentt.txt");

		color* o = new color;
		o->display(14);
		delete o;

		l.helper_payment();
		l.WritedatToFile("paymentt.txt");

	}

	else if (n == 5) {

		invoice_helper r;
		r.ReadDatafromFile("Invoice.txt");

		color* z = new color;
		z->display(14);
		delete z;

		r.helper_invoice();
		r.WritedatToFile("Invoice.txt");
	}


	else if (n == 6) {
		system("cls");
		ending_art();

		color* bz = new color;
		bz->display(14);
		delete bz;

		cout << "\t\t\t\t\t\t\t\t\t\t The Menu has Ended, Thank you Dear User" << endl;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

	}
}
int main() {

	color* f = new color;
	f->display(14);
	delete f;

	int nn = 0;
	cout << "\n\n\n\n\n\n\n\n";
	text_delay::slow("\n\t\t\t\t\t\t|********************************************************|", 1);
	text_delay::slow("\n\t\t\t\t\t\t|                                                        |", 0);
	text_delay::slow("\n\t\t\t\t\t\t|************* Press 1. For Login as an Admin ***********|", 1);
	text_delay::slow("\n\t\t\t\t\t\t|                                                        |", 1);
	text_delay::slow("\n\t\t\t\t\t\t|************* Press 2. For Login as an User ************|", 1);
	text_delay::slow("\n\t\t\t\t\t\t|                                                        |", 0);
	text_delay::slow("\n\t\t\t\t\t\t|********************************************************|", 1);
	cout << "\n";
	text_delay::slow("\n\t\t\t\t\t\t\t\t      ' Enter Option '  \n", 2);
	nn = utility::GetNumberFromUser(2);

	system("cls");
	switch (nn) {
	case 1:
	{
		int n = 0;
		while (n < 3) {

			color* rf = new color;
			rf->display(14);
			delete rf;

			int p = 0;
			cout << "\n\n\n\n\n\n\n\n";
			cout << "\n\t\t\t\t\t\t|********************************************************************|";
			cout << "\n\t\t\t\t\t\t|                                                                    |";
			cout << "\n\t\t\t\t\t\t|************** Enter User Password - (3 Attempts Only) *************|";
			cout << "\n\t\t\t\t\t\t|                                                                    |";
			cout << "\n\t\t\t\t\t\t|********************************************************************|";
			cout << "\n";
			//cin >> p;
			p = utility::Getpassword(4);

			if (p == 1234)
			{
				break;
			}

			else {

				system("cls");
				cout << "\n";

				color* rr = new color;
				rr->display(14);
				delete rr;
				cout << "\n\n\n\n\n\n\n\n";
				cout << "\n\t\t\t\t\t\tIncorrect Password !!!" << endl;
				n++;

			}
		}

		if (n == 3) {
			cout << "\n\n\n\n\n\n\n\n";
			cout << "\n\t\t\t\t\t\tToo Many wrong Attempts" << endl;
			cout << "\n\t\t\t\t\t\tSystem Ended....." << endl;

			return 0;
		}

		/*
		color* r = new color;
		r->display(11);
		delete r;

		system("cls");
		cout << "______________________________________________________________" << endl;
		cout << "\n";
		cout << "************* WELCOME TO HOTEL RESERVATION SYSTEM ************" << endl;
		cout << "\n";
		cout << "\n";
		cout << "_______________________ (Class Data) ________________________" << endl;
		cout << "\n";
		cout << "                     ' See Class Data '    " << endl;
		cout << "\n";
		cout << "1. Staff Class Data " << endl;
		cout << "2. Room  Class Data" << endl;
		cout << "3. Payment Class Data" << endl;
		cout << "4. Customer Class Data" << endl;
		cout << "5. Invoice Class Data" << endl;
		cout << "\n";

		int n1 = 0;
		n1 = utility::GetNumberFromUser(10);
		if (n1 == 1) {

			system("cls");
			cout << "\n";
			cout << "------------------- ( Staff Class Data ) -----------------" << endl;
			cout << "\n";
			//polymorphism
			person* ptr = new staff();
			//staff a;
			//staff b("Kaifi", "Null", 0, 0, "25$");
			//a.display();
			ptr->display();
			//staff c = b;
			delete ptr;


		}

		else if (n1 == 2) {

			system("cls");
			cout << "\n";
			cout << "------------------- ( Room Class Data ) -------------------" << endl;
			cout << "\n";
			//room d;

			room* e = new room(144, "Available", "Medium", "low Class", "4rh");
			room* f = new room;

			f = e;
			f->display();

			delete e;
			delete f;

		}

		else if (n1 == 3) {

			system("cls");
			cout << "\n";
			cout << "----------------------- ( Payment Class Data ) ------------------------" << endl;
			cout << "\n";
			//Payment g;
			Payment* h = new Payment("Debit Card", "20/04/2019", 40000, "11:56 AM", 45367);
			h->display();
			//Payment i = h;

			delete h;
		}

		else if (n1 == 4) {

			system("cls");
			cout << "\n";
			cout << "------------------- ( Customer Class Data ) --------------------" << endl;
			cout << "\n";

			//polymorphism
			person* pttr = new customer();
			//customer j;
			//j.display();
			pttr->display();
			//customer k("Asad", "adnanasad759@gmail.com", "Gujranwala Rahwali Cantt", 0303, 34101);
			//customer l = k;
			delete pttr;

		}

		else if (n1 == 5) {

			system("cls");
			cout << "\n";
			cout << "---------------------- ( Invoice Class Data ) ---------------------------" << endl;
			cout << "\n";
			//Invoice m;
			Invoice* n = new Invoice("A4434", "B5343", "23/12/2017", 25000, 104);
			Invoice* o = new Invoice;
			o = n;
			o->display();

			delete n;
			delete o;
		}

		*/

		system("cls");
		//animation();
		srand(time(0));
		display();
		main_menu();
		break;

	}

	case 2:
	{
		int n = 0;

		while (n < 3) {

			color* rf = new color;
			rf->display(14);
			delete rf;

			int p = 0;
			cout << "\n\n\n\n\n\n\n\n";
			cout << "\n\t\t\t\t\t\t|********************************************************************|";
			cout << "\n\t\t\t\t\t\t|                                                                    |";
			cout << "\n\t\t\t\t\t\t|************** Enter User Password - (3 Attempts Only) *************|";
			cout << "\n\t\t\t\t\t\t|                                                                    |";
			cout << "\n\t\t\t\t\t\t|********************************************************************|";
			cout << "\n";
			//cin >> p;

			p = utility::Getpassword(4);


			if (p == 6789)
			{
				break;
			}

			else {
				system("cls");
				cout << "\n";
				color* rr = new color;
				rr->display(14);
				delete rr;
				cout << "\n\n\n\n\n\n\n\n";
				cout << "\n\t\t\t\t\t\tIncorrect Password !!!" << endl;
				n++;

			}

		}

		if (n == 3) {
			cout << "\n\n\n\n\n\n\n\n";
			cout << "\n\t\t\t\t\t\tToo Many wrong Attempts" << endl;
			cout << "\n\t\t\t\t\t\tSystem Ended....." << endl;
			return 0;
		}


		HotelReservationSystem hotel;
		system("cls");
		displayWelcome();
		Asad_Hotel();
		int choice;
		do {

			color* rrf = new color;
			rrf->display(14);
			delete rrf;
			cout<<"\n\n";
			cout << "\t\t\t\t\t\t\t|=======================================================================|" << endl;
			cout << "\t\t\t\t\t\t\t|***********************************************************************|" << endl;
			cout << "\t\t\t\t\t\t\t|" << "______________________: (Welcome to Main Menu) :_______________________|" << endl;
			cout << "\t\t\t\t\t\t\t|" << "\t\t" << "\t" << "\t" << "                                        |" << endl;
			cout << "\t\t\t\t\t\t\t|" << "                   Press 1 For New Reservation                         |" << endl;
			cout << "\t\t\t\t\t\t\t|" << "                   Press 2 For Display All rooms                       |" << endl;
			cout << "\t\t\t\t\t\t\t|" << "                   Press 3 For Display Reservations                    |" << endl;
			cout << "\t\t\t\t\t\t\t|" << "                   Press 4 For Cancel Reservation                      |" << endl;
			cout << "\t\t\t\t\t\t\t|" << "                   Press 5 For Update Reservation                      |" << endl;
			cout << "\t\t\t\t\t\t\t|" << "                   Press 6 For Add Payment                             |" << endl;
			cout << "\t\t\t\t\t\t\t|" << "                   Press 7 For Display Payments                        |" << endl;
			cout << "\t\t\t\t\t\t\t|" << "                   Press 8 For Exit                                    |" << endl;
			cout << "\t\t\t\t\t\t\t|" << "\t\t" << "\t" << "\t" << "                                        |" << endl;
			cout << "\t\t\t\t\t\t\t|***********************************************************************|" << endl;
			cout << "\t\t\t\t\t\t\t|=======================================================================|" << endl;
			cout << "\n";

			cout << "\t\t\t\t\t\t\t                             ' Enter Option ' " << endl;

			choice = utility::GetNumberFromUser(8);

			switch (choice) {
			case 1: {

				// Add reservation functionality
				string n;
				int ag, rom, ph, cni;
				
				system("cls");
				
				cout << "\n\n\n\n";
				
				Reservation newReservation;
				cout << "Enter name: ";
				n = utility::GetStringFromUser(20);
				newReservation.name = n;

				cout << "Enter age: ";
				ag = utility::GetNumberFromUser(100);
				newReservation.age = ag;

				cout << "Enter phone: ";
				ph = utility::GetNumberFromUser(11);
				newReservation.phone = ph;


				cout << "Enter CNIC: ";
				cni = utility::GetNumberFromUser(16);
				newReservation.cnic = cni;

				cout << "Enter room number (1-10): ";
				rom = utility::GetNumberFromUser(12);
				newReservation.roomNumber = rom;

				if (newReservation.roomNumber < 1 || newReservation.roomNumber > 10) {
					cout << "Invalid room number. Room number must be between 1 and 10.\n";
					break;
				}
				hotel.addReservation(newReservation);

				cout << "\n\n\n\n\t\t" << "*** New Resrvation Added ***" << endl;
				cout << "\n\n\n\n";
				break;

			}
			case 2: {

				system("cls");
				// Display rooms functionality
				hotel.displayRooms();
				break;
			}
			case 3: {

				system("cls");
				// Display reservations functionality
				hotel.displayReservations();
				break;
			}
			case 4: {
				system("cls");
				// Cancel reservation functionality
				cout << "\n\n\n\n";
				int roomNumToCancel;
				cout << "Enter room number to cancel: ";
				cin >> roomNumToCancel;
				hotel.cancelReservation(roomNumToCancel);
				cout << "\n\n\n\n\t\t" << "*** Resrvation Cancelled ***" << endl;
				cout << "\n\n\n\n";
				break;
			}
			case 5: {
				system("cls");
				// Update reservation functionality
				cout << "\n\n\n\n";
				int roomNumToUpdate;
				cout << "Enter room number to update: ";
				cin >> roomNumToUpdate;
				hotel.updateReservation(roomNumToUpdate);
				cout << "\n\n\n\n\t\t" << "*** Resrvation Updated ***" << endl;
				cout << "\n\n\n\n";
				break;
			}
			case 6: {

				int x;
				cout << "\n";
				system("cls");


				cout << "\n\n\n\n\n\n\n\n";
				cout << "\t\t\t\t\t|********************************************************|" << endl;
				cout << "\t\t\t\t\t|                                                        |" << endl;
				cout << "\t\t\t\t\t|          ******( ENTER PAYMENY METHOD )******          |" << endl;
				cout << "\t\t\t\t\t|                                                        |" << endl;
				cout << "\t\t\t\t\t|                   Press 1. Debit Card                  |" << endl;
				cout << "\t\t\t\t\t|                                                        |" << endl;
				cout << "\t\t\t\t\t|                   Press 2. Credit Card                 |" << endl;
				cout << "\t\t\t\t\t|                                                        |" << endl;
				cout << "\t\t\t\t\t|                   Press 3. Cash                        |" << endl;
				cout << "\t\t\t\t\t|                                                        |" << endl;
				cout << "\t\t\t\t\t|********************************************************|" << endl;
				cout << "\n";
				
				x = utility::GetNumberFromUser(3);

				switch (x)
				{
				case 1:
				case 2:
				case 3:

					cout << "\n";
					// Add payment functionality
					double paymentAmount;
					cout << "Enter payment amount: ";
					cin >> paymentAmount;
					hotel.addPayment(paymentAmount);
					cout << "\n\n\n\n\t\t" << "*** Payment Done ***" << endl;
					cout << "\n\n\n\n";
					break;

				default:
					break;
				}

				break;
			}
			case 7: {

				system("cls");
				// Display payments functionality
				hotel.displayPayments();
				break;
			}
			case 8: {
				cout << "Exiting...\n";
				break;
			}
			default: {
				cout << "Invalid choice. Please enter a valid option.\n";
				break;
			}

			}

		} while (choice != 8);

		system("cls");
		ending_art2();

		color* bz = new color;
		bz->display(14);
		delete bz;

		cout << "\t\t\t\t\t\t\t\t\t\t The Menu has Ended, Thank you Dear User" << endl;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		break;

	}

	default: {

		cout << "\n\n\n\n\n\n\n\n";
		cout << "\n\t\t\t\t\t\tYou have entered invalid Choice" << endl;
		cout << "\n\t\t\t\t\t\tSystem Ended" << endl;

		break;

	}

	}

}

