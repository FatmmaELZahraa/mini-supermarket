#include <iostream>
#include<string.h>
#include<string>
using namespace std;
struct date {
	int day;
	int month;
	int year;
};
struct product {
	string name;
	string category;
	int code;
	date production_date, Expireed_date;
	float price;
};
struct order {
	int customerID;
	product products_list[60];
	float totalprice;
} order1 = {};
struct customer {
	string username;
	string password;
	int id;
	string location;
	string phonenumber;

};
int login(customer clients[], int numberofcustomers);
void registration(customer clients[], int& numberofcustomers);
void logout();
void Forget(customer clients[], int numberofcustomers);
void EditInformation(customer clients[], int client_id);
void Menu(product food[5], product juices[5], product cleaning_products[5]);
void information(product food[5], product juices[5], product cleaning_products[5], int category, int product_no);
void select(product food[5], product juices[5], product cleaning_products[5], product products_list[], int& numberofproducts, int category, int product_no);
void Review(product products_list[], int numberofproducts);
void modify(product products_list[], int& numberofproducts);
float totalprice(product products_list[], int& numberofproducts);
int main() {
	product food[5] = {}, juices[5] = {}, cleaning_products[5] = {};
	food[0] = { "Sugar","food",1001,{20,7,2022},{20,7,2024},20 };
	food[1] = { "Rise","food",1002,{15,10,2022},{15,10,2024},30 };
	food[2] = { "Pasta","food",1003,{20,3,2023},{20,10,2026},25 };
	food[3] = { "Salt","food",1004,{9,4,2023},{30,6,2024},2 };
	food[4] = { "Oil","food",1005,{16,7,2022},{16,7,2024},50 };
	juices[0] = { "Beti Tropicana Mango Juice","Juice",1111 ,{2,2,2023},{1,8,2023},13.50 };
	juices[1] = { "Beti Tropicana Orange Juice","Juice",2222 ,{2,2,2023},{1,8,2023},13 };
	juices[2] = { "Beti Tropicana Guava Juice","Juice",3333 ,{2,2,2023},{1,8,2023},13 };
	juices[3] = { "Beti Tropicana Apple Juice","Juice",4444 ,{2,2,2023},{1,8,2023},13 };
	juices[4] = { "Beti Tropicana Cocktail Juice","Juice",5555 ,{2,2,2023},{1,8,2023},17 };
	cleaning_products[0] = { "Dettol","Cleaning Product",2001,{11,4,2023},{11,4,2026},60 };
	cleaning_products[1] = { "Harpic","Cleaning Product",2002,{12,3,2023},{12,3,2025},50 };
	cleaning_products[2] = { "Persil","Cleaning Product",2003,{13,2,2023},{13,2,2026},125 };
	cleaning_products[3] = { "Downy","Cleaning Product",2004,{14,6,2023},{14,6,2026},110 };
	cleaning_products[4] = { "Pril","Cleaning Product",2004,{15,5,2023},{15,5,2027},65 };
	customer  clients[50] = {};
	clients[0] = { "laila","1234",1,"obour","01022358452" };
	clients[1] = { "fatma","12345",2,"10th of ramadan","01132353842" };
	clients[2] = { "salma","123456",3,"ppp","01212457859" };
	int category, product_no, add_or_remove, client_id;
	bool flag_category = true, flag_product = true, flag_edit_buy = true, flag_anotherfunction = true, flag_login_registration = true;
	char ans, add, error, anotherfunction, forget;
	int numberofproducts = 0, numberofcustomers = 3;
	char login_registration;
	do {
		cout << "\t\t\t ----------------------------------------------------- \n\n\n";
		cout << "\t\t\t Welcome in login page \n\n\n";
		cout << "\t\t\t-----------Menue------------------\n\n\n";
		cout << "press 1 to login\n";
		cout << "press 2 to register \n\n\n";
		cout << "\n\t\t\t please enter your choice:";
		cin >> login_registration;
		cout << endl;
		switch (login_registration) {
		case '1':
			client_id = login(clients, numberofcustomers);
			if (client_id == 0) {
				cout << "Did you forget password? Press(Y) or (y) for yes, any other key if you do not" << endl;
				cin >> forget;
				if (forget == 'Y' || forget == 'y') {
					Forget(clients, numberofcustomers);
					flag_login_registration = true;
					continue;
				}
				else {
					flag_login_registration = true;
					continue;
				}
			}
			flag_login_registration = false;
			break;
		case '2': {
			registration(clients, numberofcustomers);
			flag_login_registration = true;
			continue;
			break;
		}
		default:
			system("cls");
			cout << "\t\t\t please select from options given above\n" << endl;
			flag_login_registration = true;
			continue;
			break;
		}
	} while (flag_login_registration == true);
	order1.customerID = client_id;
	do {
		cout << "If you want to edit your information press 1\n";
		cout << "If you want to go to the supermarket   press 2\n";
		cout << "If you want to logout press 3\n";
		int choice;
		cin >> choice;
		while (cin.fail())
		{
			cin.clear(); // clear input buffer to restore cin to a usable state
			cin.ignore(INT_MAX, '\n'); // ignore last input
			cout << "You can only enter numbers.\n";
			cout << "Enter a number.\n";
			cin >> choice;
		}

		do {


			switch (choice) {
			case 1:
			case 2:
			case 3:
				flag_edit_buy = true;
				break;
			default:
				cout << "Invalid Number!Please Enter correct Number." << endl;
				cin >> choice;
				flag_edit_buy = false;
			}
		} while (flag_edit_buy == false);
		if (choice == 1) {
			EditInformation(clients, client_id);
			cout << "Do you want to do Another Function, Press(Y) or (y) for yes, any other key if you don't want to and want to logout" << endl;
			cin >> anotherfunction;
			switch (anotherfunction) {
			case'Y':
			case'y':
				flag_anotherfunction = true;
				continue;
				break;
			default:
				flag_anotherfunction = false;
				logout();
			}
		}
		else if (choice == 2) {
			do {
				do {
					Menu(food, juices, cleaning_products);
					do {
						cout << "Enter The Number Of Category You Want:";
						cin >> category;
						while (cin.fail())
						{
							cin.clear(); // clear input buffer to restore cin to a usable state
							cin.ignore(INT_MAX, '\n'); // ignore last input
							cout << "You can only enter numbers.\n";
							cout << "Enter a number.\n";
							cin >> category;
						}
						if (category == 1 || category == 2 || category == 3) {
							flag_category = true;
						}
						else {
							cout << "Invalid Number!please Enter Correct Number." << endl;
							flag_category = false;
						}
						cout << endl;
					} while (flag_category == false);
					do {
						cout << "Enter The Number Of Product You Want:";
						cin >> product_no;
						while (cin.fail())
						{
							cin.clear(); // clear input buffer to restore cin to a usable state
							cin.ignore(INT_MAX, '\n'); // ignore last input
							cout << "You can only enter numbers.\n";
							cout << "Enter a number.\n";
							cin >> product_no;
						}
						if (product_no == 1 || product_no == 2 || product_no == 3 || product_no == 4 || product_no == 5)
							flag_product = true;
						else {
							cout << "Invalid Number!please Enter Correct Number." << endl;
							flag_product = false;
						}
						cout << endl;
					} while (flag_product == false);
					information(food, juices, cleaning_products, category, product_no);

					select(food, juices, cleaning_products, order1.products_list, numberofproducts, category, product_no);
					cout << "Do YOu Want To Saw another Product ? Press(Y) or (y) for yes, any other key if you don't want to" << endl;
					cin >> ans;

				} while (ans == 'y' || ans == 'Y');
				cout << "Your List:" << endl;
				Review(order1.products_list, numberofproducts);
				cout << "If You Want To Add Somthing Else in Your List press 1 " << endl;
				cout << "If You Want To Remove Anything From Your List press 2 " << endl;
				cout << "If You Do not Want To Modify Anything in Your List press 3" << endl;
				cin >> add_or_remove;
				while (cin.fail())
				{
					cin.clear(); // clear input buffer to restore cin to a usable state
					cin.ignore(INT_MAX, '\n'); // ignore last input
					cout << "You can only enter numbers.\n";
					cout << "Enter a number.\n";
					cin >> add_or_remove;
				}
				do {
					switch (add_or_remove) {
					case 1:
					case 2:
					case 3:
						error = 'N';
						break;
					default:
						cout << "Invalid Number!Please Enter correct Number." << endl;
						cin >> add_or_remove;
						error = 'Y';
					}
				} while (error == 'Y');
				if (add_or_remove == 2) {
					modify(order1.products_list, numberofproducts);
					cout << "Do you want to add products, Press(Y) or (y) for yes, any other key if you don't want to" << endl;
					cin >> add;
					switch (add) {
					case'Y':
					case'y':
						add_or_remove = 1;
						break;
					default:
						add_or_remove = 3;
					}
				}
				else if (add_or_remove == 3) {
					break;
				}
			} while (add_or_remove == 1);
			cout << "Your ID is:  " << order1.customerID << endl;
			cout << "YOUR FINAL LIST:" << endl;
			Review(order1.products_list, numberofproducts);
			float price = totalprice(order1.products_list, numberofproducts);
			cout << "Total Price:" << "  " << price << " " << "EGP" << endl << endl << endl;
			cout << "Do you want to do Another Function, Press(Y) or (y) for yes, any other key if you don't want to and want to logout" << endl;
			cin >> anotherfunction;
			switch (anotherfunction) {
			case'Y':
			case'y':
				flag_anotherfunction = true;
				continue;
				break;
			default:
				flag_anotherfunction = false;
				logout();
			}
		}
		else {
			logout();
		}
	} while (flag_anotherfunction == true);
	return 0;
}

void registration(customer clients[], int& numberofcustomers) {
	system("cls");
	cout << "\t\t\t Enter the user name : ";
	cin.ignore();
	getline(cin, clients[numberofcustomers].username);
	cout << "\t\t\t Enter the password : ";
	getline(cin, clients[numberofcustomers].password);
	cout << "\t\t\t Enter the Phone Number : ";
	getline(cin, clients[numberofcustomers].phonenumber);
	cout << "\t\t\t Enter The Location : ";;
	getline(cin, clients[numberofcustomers].location);
	system("cls");
	cout << "\n\t\t\t Registration is Successful You Can Log In Now If You Want. \n";
	clients[numberofcustomers].id = numberofcustomers + 1;
	numberofcustomers++;
}

int login(customer clients[], int numberofcustomers) {
	int id = 1;
	bool flaglogin = true;
	string username, password;
	bool enter = 0;
	cout << "Enter Your UserName : " << "\t";
	cin.ignore();
	getline(cin, username);
	cout << "Enter Your PassWord : " << "\t";
	getline(cin, password);
	for (int i = 0; i < numberofcustomers; i++) {
		if (username == clients[i].username && password == clients[i].password) {
			flaglogin = true;
			id = clients[i].id;
			break;
		}
		else {

			flaglogin = false;
			id = 0;
		}
	}
	if (flaglogin == false) {
		cout << "\n Login Error!\n Check Your UserName and PassWord Or Please Register If you Do not do That before. \n";
		return id;
	}
	else {
		system("cls");
		cout << username << "   ." << "Your Log In Is Successful." << endl;
		return id;
	}
}

void Forget(customer clients[], int numberofcustomers) {
	bool answer = 0, found = 1;
	string option;
	system("cls");
	cout << "\t\t\t You Forget The Password\n";
	do {
		cout << "Write Your UserName To Search Your Password by It" << endl;
		cin.ignore();
		getline(cin, option);
		for (int i = 0; i < numberofcustomers; i++) {
			if (option == clients[i].username) {
				cout << "Great!!  We Found Your PassWord." << endl << "Your PassWord Is : " << clients[i].password << endl << endl;
				answer = 1;
				found = 1;
				break;
			}
			else {
				found = 0;
			}
		}
		if (found == 0) {
			cout << "We Can Not Find This UserName!Please Try Again And Enter The Correct UserName." << endl;
			answer = 0;
		}
	} while (answer == 0);
}

void EditInformation(customer clients[], int client_id) {
	int answer;
	char ans;
	bool check = 0;
	cout << "Your Id is: " << client_id << endl;
	cout << "Your Current Information : " << endl;
	cout << "1-" << "UserName: " << clients[client_id - 1].username << endl << "2-" << "password: " << clients[client_id - 1].password << endl << "3-" << "Location:" << clients[client_id - 1].location << endl << "4-" << "Phone Number:" << clients[client_id - 1].phonenumber << endl;
	do {
		do {
			cout << "Enter The Number Of Tybe Of Information You Want To Edit Or If You Want To Edit ALL Press 5." << endl;
			cin >> answer;
			while (cin.fail())
			{
				cin.clear(); // clear input buffer to restore cin to a usable state
				cin.ignore(INT_MAX, '\n'); // ignore last input
				cout << "You can only enter numbers.\n";
				cout << "Enter a number.\n";
				cin >> answer;
			}

			switch (answer) {
			case 1:
				cout << "Enter Your New UserName : " << "\t";
				cin.ignore();
				getline(cin, clients[client_id - 1].username);
				check = 1;
				break;
			case 2:
				cout << "Enter Your New Password : " << "\t";
				cin.ignore();
				getline(cin, clients[client_id - 1].password);
				check = 1;
				break;
			case 3:
				cout << "Enter Your New Location : " << "\t";
				cin.ignore();
				getline(cin, clients[client_id - 1].location);
				check = 1;
				break;
			case 4:
				cout << "Enter Your New Phone Number : " << "\t";
				cin.ignore();
				getline(cin, clients[client_id - 1].phonenumber);
				check = 1;
				break;
			case 5:
				cout << "Enter Your New UserName : " << "\t";
				cin.ignore();
				getline(cin, clients[client_id - 1].username);
				cout << "Enter Your New Password : " << "\t";
				getline(cin, clients[client_id - 1].password);
				cout << "Enter Your New Location : " << "\t";
				getline(cin, clients[client_id - 1].location);
				cout << "Enter Your New Phone Number : " << "\t";
				getline(cin, clients[client_id - 1].phonenumber);
				check = 1;
				break;
			default:
				cout << "Invalid Number!Please Enter correct Number." << endl;
				check = 0;
				break;
			}
		} while (check == 0);
		cout << "DO you want To Edit another Thing ?? Press(Y) or (y) for yes, any other key if you don't want to" << endl;
		cin >> ans;
	} while (ans == 'y');
	cout << "Your New Information : " << endl;
	cout << "1-" << "UserName: " << clients[client_id - 1].username << endl << "2-" << "password: " << clients[client_id - 1].password << endl << "3-" << "Location:" << clients[client_id - 1].location << endl << "4-" << "Phone Number:" << clients[client_id - 1].phonenumber << endl;
}

void Menu(product food[5], product juices[5], product cleaning_products[5]) {
	cout << "SuperMarket Menu" << endl;
	cout << "1-Food" << "\t" << "\t" << "2-Juices" << "\t" << "\t" << "\t" << "\t" << "3-cleaning Products" << endl;
	cout << endl;
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << "-" << food[i].name << "\t" << "\t" << i + 1 << "-" << juices[i].name << "\t" << "\t" << i + 1 << "-" << cleaning_products[i].name << endl;
	}
}

void information(product food[5], product juices[5], product cleaning_products[5], int category, int product_no) {
	switch (category) {
	case 1: {
		cout << food[product_no - 1].name << endl << "Code:" << food[product_no - 1].code << endl << "Production Date:" << food[product_no - 1].production_date.day << "/" << food[product_no - 1].production_date.month << "/" << food[product_no - 1].production_date.year << endl <<
			"Expired Date:" << food[product_no - 1].Expireed_date.day << "/" << food[product_no - 1].Expireed_date.month << "/" << food[product_no - 1].Expireed_date.year << endl << "Price:" << food[product_no - 1].price << " " << "EGP" << endl << endl;
		break;
	}
	case 2:
		cout << juices[product_no - 1].name << endl << "Code:" << juices[product_no - 1].code << endl << "Production Date:" << juices[product_no - 1].production_date.day << "/" << juices[product_no - 1].production_date.month << "/" << juices[product_no - 1].production_date.year << endl <<
			"Expired Date:" << juices[product_no - 1].Expireed_date.day << "/" << juices[product_no - 1].Expireed_date.month << "/" << juices[product_no - 1].Expireed_date.year << endl << "Price:" << juices[product_no - 1].price << " " << "EGP" << endl << endl;
		break;
	case 3:
		cout << cleaning_products[product_no - 1].name << endl << "Code:" << cleaning_products[product_no - 1].code << endl << "Production Date:" << cleaning_products[product_no - 1].production_date.day << "/" << cleaning_products[product_no - 1].production_date.month << "/" << cleaning_products[product_no - 1].production_date.year << endl <<
			"Expired Date:" << cleaning_products[product_no - 1].Expireed_date.day << "/" << cleaning_products[product_no - 1].Expireed_date.month << "/" << cleaning_products[product_no - 1].Expireed_date.year << endl << "Price:" << cleaning_products[product_no - 1].price << " " << "EGP" << endl << endl;
		break;
	}
}
void select(product food[5], product juices[5], product cleaning_products[5], product products_list[], int& numberofproducts, int category, int product_no) {
	cout << "If You Want TO select this product Press(Y) or (y) for yes, any other key if you don't want to" << endl;
	char answer;
	cin >> answer;
	if (answer == 'Y' || answer == 'y') {
		switch (category) {
		case (1): {

			products_list[numberofproducts] = { food[product_no - 1].name,food[product_no - 1].category,0,{0,0,0},{0,0,0},food[product_no - 1].price };
			numberofproducts++;
			cout << "Done" << endl;
			break;
		}
		case (2): {

			products_list[numberofproducts] = { juices[product_no - 1].name,juices[product_no - 1].category,0,{0,0,0},{0,0,0},juices[product_no - 1].price };
			numberofproducts++;
			cout << "Done" << endl;
			break;
		}
		case (3): {

			products_list[numberofproducts] = { cleaning_products[product_no - 1].name,cleaning_products[product_no - 1].category,0,{0,0,0},{0,0,0},cleaning_products[product_no - 1].price };
			numberofproducts++;
			cout << "Done" << endl;
			break;
		}
		}
	}
}
void Review(product products_list[], int numberofproducts)
{
	if (numberofproducts == 0) {
		cout << "You DONT Buy Anything." << endl;
	}
	else {
		for (int i = 0; i < numberofproducts; i++) {
			cout << i + 1 << '-' << products_list[i].name << endl << "Price" << '\t' << products_list[i].price << " " << "EGP" << endl << "Category" << '\t' << products_list[i].category << endl << endl;
		}
	}
}
void modify(product products_list[], int& numberofproducts) {
	int numb;
	char  remove;
	bool error2 = 0;
	do {
		cout << "Enter number of the product you want to remove it" << endl;
		cin >> numb;
		while (cin.fail())
		{
			cin.clear(); // clear input buffer to restore cin to a usable state
			cin.ignore(INT_MAX, '\n'); // ignore last input
			cout << "You can only enter numbers.\n";
			cout << "Enter a number.\n";
			cin >> numb;
		}

		do {

			if (numb <= numberofproducts) {
				error2 = 1;

			}
			else {
				cout << "Invalid Number!please Enter Correct Number." << endl;
				cin >> numb;
				error2 = 0;
			}
		} while (error2 == 0);

		if (numb == numberofproducts) {
			numberofproducts--;
		}
		else {
			for (int i = numb - 1; i < numberofproducts - 1; i++) {
				products_list[i] = products_list[i + 1];
			}
			numberofproducts--;
		}
		cout << "The Number of Products:" << endl << numberofproducts << endl << endl;
		Review(order1.products_list, numberofproducts);
		if (numberofproducts != 0) {
			cout << "Do you want to remove another product, Press(Y) or (y) for yes, any other key if you don't want to" << endl;
			cin >> remove;
		}
		else
			remove = 'n';
	} while (remove == 'Y' || remove == 'y');
}
float totalprice(product products_list[], int& numberofproducts) {
	float totalprice = 0;
	for (int i = 0; i < numberofproducts; i++) {
		totalprice += products_list[i].price;
	}
	return totalprice;
}
void logout() {
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t" << "Thank You For Using Our Site" << endl;
	cout << "\n\n\n\n\n\n\n\n\n\n";
	exit(0);
}
