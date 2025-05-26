#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

//data base

int user_count = 2;
int userID = 0;
bool isAdmin = false, isOpen = true;
std::string* loginarr = new std::string[user_count]{ "admin","cashier" };
std::string* password = new std::string[user_count]{ "admin","1" };
double* sellsArr = new double[user_count]{0.0, 0.0};
//----------------------------------------------------------------------//
bool dy = false;
bool bdaySale = false;
bool HELL_iMeanBlackFriday = false;
int size = 10;
int* ID_arr = new int[size];
std::string* name_arr = new std::string[size];
double* price_arr = new double[size];
int* count_arr = new int[size];
//functions
void ShowStorage(int mode);

void ChangeStaff();

void RedactStaff();

void start();

bool Login();

void Getline(std::string& stringname);

void CreateStorage();

void CreateDynamicStorage();

void ShowAdminMenu();

void ReffilStuff();

//===============================================================//
int sizeCheck = 1;
double cashbox = 10000;
double E_cash_income = 0;
double cash_income = 0;

std::string* name_arrCheck = new std::string[sizeCheck];
double* price_arrCheck = new double[sizeCheck];
int* count_arrCheck = new int[sizeCheck];
double* total_arrCheck = new double[sizeCheck];
void Selling();
void increaseCheckArr();
void PrintCheck();
void ResetCheck();


template<typename ArrType>
void FillArray(ArrType staticArr[], ArrType dynamicArr[]);

bool isnumber(std::string &numbers);

int getID(int mode = 0)
{
	std::string  stringid;
	int result = 0;
	int currentsize = 0;
	if (mode == 0)
	{
		currentsize = size;
	}
	else if (mode == 1)
	{
		currentsize = user_count;
	}

	while (true)
	{
		Sleep(1000);
		std::cout << "input ID: ";
		Getline(stringid);
		system("cls");
		if (isnumber(stringid))
		{
			result = std::stoi(stringid);
			if (result > 0 && result <= currentsize)
			{
				return result;
			}
			if (currentsize == user_count && result <= 0)
			{
				std::cout << "\n\nID error, dumbass\n\n";
			}
			else
			{
				std::cout << "\n\ninput error, dumbass\n\n";
			}
		}
		else
		{
			std::cout << "\n\ninput error, dumbass\n\n";
		}
	}
}

void RemoveStuff();

void ChangePrice();

void AddNewShit();

void RenameOldShit();

void ChangeStorage();

void ChangeStaff();

void Showemployee();

void AddnewStaff();

void RemoveoldStaff();

void ShowStaff();

void ShowIncome();

bool Exit();

//====================//
  int main()
{
	CreateStorage();
	start();
	delete[] ID_arr;
	delete[] name_arr;
	delete[] price_arr;
	delete[] count_arr;
	delete[] loginarr;
	delete[] password;
	delete[] sellsArr;
	delete[] name_arrCheck;
	delete[] count_arrCheck;
	delete[] price_arrCheck;
	delete[] total_arrCheck;
	return 0;
}
//====================//

//------------------//
void start()
{
	srand(time(NULL));
	std::cout << "\n\n\t\t\t Welcome to Games Don't Stop! (GDS for short)\n\t\t\tenjoy your stay:3\n\n";
	
	while (true)
	{
		if (Login())
		{
			if (isAdmin == true)
			{
				std::string choose;
				while (true)
				{
					std::cout << "1-already stocked storage\n2-create new storage\nInput: ";
					Getline(choose);
					if (choose == "1")
					{
						dy = true;
						CreateStorage();
						ShowAdminMenu();
					}
					else if (choose == "2")
					{
						dy = true;
						CreateDynamicStorage();
						ShowAdminMenu();
					}
					else
					{
						std::system("cls");
						std::cout << "input error, dumbass\n\n";
					}
				}
			}
			else
			{
				CreateStorage();
				//ShowUserMenu();
			}
		}
		else
		{
			std::cerr << "Login error\n";
		}
	}
	
}
//------------------//
void CreateStorage()
{
	int const static_size = 10;
	int id[static_size]{ 1,2,3,4,5,6,7,8,9,10 };
	std::string name[static_size]
	{
		"The Legend Of Zelda: TOTK",
		"The Legend Of Zelda : BOTW",
		"Titanfall 2",
		"MGR:REVENGANCE",
		"MGS5:PHANTOM PAIN",
		"WARHAMMER 40K: SPACE MARINE 2",
		"Ghost of Tsushima",
		"Sniper Ghost Warrior, Contracts 2",
		"Risk Of Rain2",
		"Risk Of Rain: Returns"
	};
	double price[static_size]{ 123, 85435, 914, 325, 456, 45621, 25,525 ,253, 35 };
	int count[static_size]{ 12, 65, 77, 82, 12, 3, 5, 6,  54, 76 };
	FillArray(id, ID_arr);
	FillArray(name, name_arr);
	FillArray(price, price_arr);
	FillArray(count, count_arr);
}
//--------------------------------//
void CreateDynamicStorage()
{
	int dy_size = 1;
	int* dy_ID_arr = new int[dy_size];
	std::string* dy_name_arr = new std::string[dy_size];
	double* dy_price_arr = new double[dy_size];
	int* dy_count_arr = new int[dy_size];
}
//--------------------------------//
void ShowStorage(int mode)
{
	if (dy = false)
	{
		if (mode == 0)
		{
			std::cout << "ID\t" << std::left << std::setw(25) << "Item name\t\t" << "Price\t" << "Ammount\n";
			for (int i = 0; i < size; i++)
			{
				std::cout << ID_arr[i] << "\t" << std::left << std::setw(25) << name_arr[i] << "\t      " << price_arr[i]
					<< "\t" << count_arr[i] << "\t\n";
			}
			std::cout << "\n\n";
		}
		else if (mode == 1)
		{
			std::cout << "ID\t" << std::left << std::setw(25) << "Item name\t\t" << "Price\t" << "Ammount\n";
			for (int i = 0; i < size; i++)
			{
				std::cout << ID_arr[i] << std::left << std::setw(25) << "\t" << name_arr[i] << "\t      " << count_arr[i] << "\n";
			}
			std::cout << "\n\n";
		}
		else if (mode == 2)
		{
			std::cout << "ID\t" << std::left << std::setw(25) << "Item name\t\t" << "Price\t" << "Ammount\n";
			for (int i = 0; i < size; i++)
			{
				std::cout << ID_arr[i] << "\t" << std::left << std::setw(25) << name_arr[i] << "\t      " << price_arr[i] << "\t" << count_arr[i] << "\n";
			}
			std::cout << "\n\n";
			system("pause");
		}
	}
	else
	{
		if (mode == 0)
		{
			std::cout << "ID\t" << std::left << std::setw(25) << "Item name\t\t" << "Price\t" << "Ammount\n";
			for (int i = 0; i < size; i++)
			{
				std::cout << dy_ID_arr[i] << "\t" << std::left << std::setw(25) << dy_name_arr[i] << "\t      " << dy_price_arr[i]
					<< "\t" << dy_count_arr[i] << "\t\n";
			}
			std::cout << "\n\n";
		}
		else if (mode == 1)
		{
			std::cout << "ID\t" << std::left << std::setw(25) << "Item name\t\t" << "Price\t" << "Ammount\n";
			for (int i = 0; i < size; i++)
			{
				std::cout << dy_ID_arr[i] << std::left << std::setw(25) << "\t" << dy_name_arr[i] << "\t      " << dy_count_arr[i] << "\n";
			}
			std::cout << "\n\n";
		}
		else if (mode == 2)
		{
			std::cout << "ID\t" << std::left << std::setw(25) << "Item name\t\t" << "Price\t" << "Ammount\n";
			for (int i = 0; i < size; i++)
			{
				std::cout << dy_ID_arr[i] << "\t" << std::left << std::setw(25) << dy_name_arr[i] << "\t      " << dy_price_arr[i] << "\t" << dy_count_arr[i] << "\n";
			}
			std::cout << "\n\n";
			system("pause");
		}
	}
}
//--------------------------------//
bool Login()
{
	std::string login, pass;
	while (true)
	{
		std::cout << "input login: ";
		//std::getline(std::cin, login, '\n');
		Getline(login);
		std::cout << "input password: ";
		Getline(pass);
		if (login == loginarr[0] && pass == password[0])
		{
			isAdmin = true;
			userID = 0;
			std::cout << "Welcome back, doctor (anime/game reference you probably won't understand, i'm a weeb and i'm proud of it)\nstatus: Admin\n\n";
			return true;
		}
		for (int i = 1; i < user_count; i++)
		{
			if (login == loginarr[i] && pass == password[i])
			{
				isAdmin = false;
				userID = i;
				std::cout << "Good evening and welcome, what can i get for you?\nstatus: cashier\n\n";
				return true;
			}
		}
		std::cout << "wrong password or login\n\n";
	}
}
//--------------------------//
void ShowAdminMenu()
{
	std::string choose;
	while (true)
	{
		std::cout << "1)Start selling \n";
		std::cout << "2)Show storage \n";
		std::cout << "3)Add to storage \n";
		std::cout << "4)Remove item \n";
		std::cout << "5)Change price \n";
		std::cout << "6)Change storage \n";
		std::cout << "7)Change staff \n";
		std::cout << "8)Profit report \n";
		std::cout << "0)Log out \n";
		std::cout << "Input: ";
		Getline(choose);
		if (choose == "1")
		{
			Selling();
		}
		else if (choose == "2")
		{
			ShowStorage(0);
		}
		else if (choose == "3")
		{
			ReffilStuff();
		}
		else if (choose == "4")
		{
			RemoveStuff();
		}
		else if (choose == "5")
		{
			ChangePrice();
		}
		else if (choose == "6")
		{
			ChangeStorage();
		}
		else if (choose == "7")
		{
			ChangeStaff();
		}
		else if (choose == "8")
		{
			ShowIncome();
		}
		else if (choose == "0")
		{
			if (Exit())
			{
				std::cout << "exit\n";
				Sleep(100);
				break;
			}
			else if (!Exit())
			{
				std::cout << "going back\n";
			}
			else
			{
				std::cout << "\n\nNUH UH\n\n";
				Sleep(100);
			}
		}
	}
}
//-------------------------------------------//
void Getline(std::string& stringname)
{
	std::getline(std::cin, stringname, '\n');
}
//-------------------------------------------//
void ReffilStuff()
{
		std::string choose, chooseCount;
		int ID = 0, count = 0;
		while (true)
		{
			std::cout << "Refill stuff?\n1) ye\n2) nah (go back)\nInput: ";
			Getline(choose);
			if (choose == "1")
			{
				ShowStorage(1);
				ID = getID();
				while (true)
				{
					std::cout << "Input ammount of stuff to refill: ";
					Getline(chooseCount);
					if (isnumber(chooseCount))
					{
						count = std::stoi(chooseCount);
						if (count >= 0 && count <= 1000)
						{
							count_arr[ID - 1] += count;
							std::cout << "refill cucsessfull\n";
							Sleep(800);
							break;
						}
						else
						{
							std::cout << "\n\nincorrect ammount, dumbass\n\n";
						}
					}

				}
			}
			else if (choose == "2")
			{
				break;
			}
			else
			{
				std::cout << "\n\ninput error, dumbass\n\n";
				Sleep(1000);
			}
		}
}
//----------------------------------------//
bool isnumber(std::string &number) // 42
{
	if (number.size() <= 0 && number.size() >= 10)
	{
		return  false;
	}
	for (int i = 0; i < number.size(); i++)
	{
		if (!std::isdigit(number[i]))
		{
			return false;
		}
	}
	return true;
}
//----------------------------------------//
void RemoveStuff()
{
	if (dy = false)
	{
		std::string choose, chooseCount;
		int ID = 0, count = 0;
		while (true)
		{
			std::cout << "Remove stuff?\n1) ye\n2) nah (go back)\nInput: ";
			Getline(choose);
			if (choose == "1")
			{
				ShowStorage(1);
				ID = getID();
				while (true)
				{
					std::cout << "Input ammount of stuff to remove: ";
					Getline(chooseCount);
					if (isnumber(chooseCount))
					{
						count = std::stoi(chooseCount);
						if (count >= 0 && count <= count_arr[ID - 1])
						{
							if (count_arr[ID - 1] -= count <= 0)
							{
								std::cout << "\n\n incorrect ammount dumbass\n\n";
							}
							else
							{
								count_arr[ID - 1] -= count;
								std::cout << "remove cucsessfull\n";
								Sleep(800);
								break;
							}
						}
						else
						{
							std::cout << "\n\nincorrect ammount, dumbass\n\n";
						}
					}

				}
			}
			else if (choose == "2")
			{
				break;
			}
			else
			{
				std::cout << "\n\ninput error, dumbass\n\n";
				Sleep(1000);
			}
		}
	}
}
//------------------------//
void ChangePrice()
{
	if (dy = false)
	{
		std::string choose, choosePrice;
		int ID = 0, count = 0;
		double price = 0;
		while (true)
		{
			std::cout << "Change price of stuff?\n1) ye\n2) nah (go back)\nInput: ";
			Getline(choose);
			if (choose == "1")
			{
				ShowStorage(1);
				ID = getID();
				while (true)
				{
					std::cout << "new price: ";
					Getline(choosePrice);
					if (isnumber(choosePrice))
					{
						price = std::stod(choosePrice);
						if (price >= 0 && price <= 9999.99)
						{
							count_arr[ID - 1] = price;
							std::cout << "price changed";
							Sleep;
							break;
						}
						else
						{
							std::cout << "\n\nNo, YOU'RE WRONG (incorrect price)\n\n";
						}
					}
					else
					{
						std::cout << "\n\nNO, YOU'RE WRONG (input error dumbass)";
					}
				}
			}
			else if (choose == "2")
			{
				break;
			}
			else
			{
				std::cout << "\n\ninput error, dumbass\n\n";
				Sleep(1000);
			}
		}
	}
	else
	{

		std::string choose, choosePrice;
		int ID = 0, count = 0;
		double price = 0;
		while (true)
		{
			std::cout << "Change price of stuff?\n1) ye\n2) nah (go back)\nInput: ";
			Getline(choose);
			if (choose == "1")
			{
				ShowStorage(1);
				ID = getID();
				while (true)
				{
					std::cout << "new price: ";
					Getline(choosePrice);
					if (isnumber(choosePrice))
					{
						price = std::stod(choosePrice);
						if (price >= 0 && price <= 9999.99)
						{
							dy_count_arr[ID - 1] = price;
							std::cout << "price changed";
							Sleep;
							break;
						}
						else
						{
							std::cout << "\n\nNo, YOU'RE WRONG (incorrect price)\n\n";
						}
					}
					else
					{
						std::cout << "\n\nNO, YOU'RE WRONG (input error dumbass)";
					}
				}
			}
			else if (choose == "2")
			{
				break;
			}
			else
			{
				std::cout << "\n\ninput error, dumbass\n\n";
				Sleep(1000);
			}
		}
	}
}
//--------------------------//
void ChangeStorage()
{
		std::string choose;
		while (true)
		{
			std::cout << "1 - add new item\n2 - redact name of existing item\n3 - delete item\ninput: \n(0 - exit)";
			Getline(choose);
			if (choose == "1")
			{
				AddNewShit();
			}
			else if (choose == "2")
			{
				RenameOldShit();
			}
			else if (choose == "3")
			{

			}
			else if (choose == "0")
			{
				break;
			}
			else
			{
				std::cout << "\n\ninput error, dumbass\n\n";
			}
		}
}
//--------------------------//
void AddNewShit()
{
	if (dy = false)
	{
		system("cls");
		++size;
		int* ID_arrTemp = new int[size];
		std::string* name_arrTemp = new std::string[size];
		double* price_arrTemp = new double[size];
		int* count_arrTemp = new int[size];

		for (int i = 0; i < size - 1;i++)
		{
			ID_arrTemp[i] = ID_arr[i];
			name_arrTemp[i] = name_arr[i];
			price_arrTemp[i] = price_arr[i];
			count_arrTemp[i] = count_arr[i];
		}

		std::string choose;

		ID_arrTemp[size - 1] = size;
		//name
		while (true)
		{
			system("cls");
			std::cout << "input name of the new product: ";
			Getline(choose);
			if (choose.size() <= 20 && choose.size() >= 3)
			{
				name_arrTemp[size - 1] = choose;
				break;
			}
			else
			{
				std::cout << "\nwrong name lenght, dumbass\n";
				Sleep(1000);
			}

		}
		int count = 0;
		while (true)
		{
			system("cls");
			std::cout << "input the ammount of the new product: ";
			Getline(choose);
			if (isnumber(choose))
			{
				count = std::stoi(choose);
				if (count >= 0 && count <= 1000)
				{
					count_arrTemp[size - 1] = count;
					break;
				}
				else
				{
					std::cout << "\n\nincorrect ammount dumbass, 1000 is max\n\n";
				}
			}
			else
			{
				std::cout << "\ninput error dumbass\n";
				Sleep(1000);
			}
		}
		double price = 0;
		while (true)
		{
			system("cls");
			std::cout << "input the price of the new product: ";
			Getline(choose);
			if (isnumber(choose))
			{
				price = std::stod(choose);
				if (count >= 0 && count <= 100000000)
				{
					price_arrTemp[size - 1] = count;
					break;
				}
				else
				{
					std::cout << "\n\nincorrect price dumbass, 100000000 is max\n\n";
				}
			}
			else
			{
				std::cout << "\ninput error dumbass\n";
				Sleep(1000);
			}
		}


		std::swap(ID_arr, ID_arrTemp);
		std::swap(name_arr, name_arrTemp);
		std::swap(price_arr, price_arrTemp);
		std::swap(count_arr, count_arrTemp);


		system("cls");
		std::cout << "ID\t" << std::left << std::setw(25) << "Item name\t\t" << "Price\t" << "Ammount\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << ID_arr[i] << "\t" << std::left << std::setw(25) << name_arr[i] << "\t" << price_arr[i]
				<< "\t" << count_arr[i] << "\t\n";
		}
		std::cout << "\n\n";
		system("pause");


		delete[] ID_arrTemp;
		delete[] name_arrTemp;
		delete[] price_arrTemp;
		delete[] count_arrTemp;
	}
	else
	{
		system("cls");
		++size;
		int* ID_arrTemp = new int[size];
		std::string* name_arrTemp = new std::string[size];
		double* price_arrTemp = new double[size];
		int* count_arrTemp = new int[size];

		for (int i = 0; i < size - 1;i++)
		{
			ID_arrTemp[i] = dy_ID_arr[i];
			name_arrTemp[i] = dy_name_arr[i];
			price_arrTemp[i] = dy_price_arr[i];
			count_arrTemp[i] = dy_count_arr[i];
		}

		std::string choose;

		ID_arrTemp[size - 1] = size;
		//name
		while (true)
		{
			system("cls");
			std::cout << "input name of the new product: ";
			Getline(choose);
			if (choose.size() <= 20 && choose.size() >= 3)
			{
				name_arrTemp[size - 1] = choose;
				break;
			}
			else
			{
				std::cout << "\nwrong name lenght, dumbass\n";
				Sleep(1000);
			}

		}
		int count = 0;
		while (true)
		{
			system("cls");
			std::cout << "input the ammount of the new product: ";
			Getline(choose);
			if (isnumber(choose))
			{
				count = std::stoi(choose);
				if (count >= 0 && count <= 1000)
				{
					count_arrTemp[size - 1] = count;
					break;
				}
				else
				{
					std::cout << "\n\nincorrect ammount dumbass, 1000 is max\n\n";
				}
			}
			else
			{
				std::cout << "\ninput error dumbass\n";
				Sleep(1000);
			}
		}
		double price = 0;
		while (true)
		{
			system("cls");
			std::cout << "input the price of the new product: ";
			Getline(choose);
			if (isnumber(choose))
			{
				price = std::stod(choose);
				if (count >= 0 && count <= 100000000)
				{
					price_arrTemp[size - 1] = count;
					break;
				}
				else
				{
					std::cout << "\n\nincorrect price dumbass, 100000000 is max\n\n";
				}
			}
			else
			{
				std::cout << "\ninput error dumbass\n";
				Sleep(1000);
			}
		}


		std::swap(dy_ID_arr, ID_arrTemp);
		std::swap(dy_name_arr, name_arrTemp);
		std::swap(dy_price_arr, price_arrTemp);
		std::swap(dy_count_arr, count_arrTemp);


		system("cls");
		std::cout << "ID\t" << std::left << std::setw(25) << "Item name\t\t" << "Price\t" << "Ammount\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << dy_ID_arr[i] << "\t" << std::left << std::setw(25) << dy_name_arr[i] << "\t" << dy_price_arr[i]
				<< "\t" << dy_count_arr[i] << "\t\n";
		}
		std::cout << "\n\n";
		system("pause");


		delete[] ID_arrTemp;
		delete[] name_arrTemp;
		delete[] price_arrTemp;
		delete[] count_arrTemp;

	}
}
//--------------------------//
void RenameOldShit()
{
	if (dy = false)
	{
		std::string choise;
		int ID = 0;
		while (true)
		{
			system("cls");
			ID = getID();

			std::cout << "input new name for the product: ";
			Getline(choise);



			if (choise.size() <= 20 && choise.size() >= 3)
			{
				name_arr[ID - 1] = choise;
				break;
			}
			else
			{
				std::cout << "\nwrong name lenght, dumbass\n";
				Sleep(1000);
			}

		}
		ShowStorage(0);
	}
	else
	{
		std::string choise;
		int ID = 0;
		while (true)
		{
			system("cls");
			ID = getID();

			std::cout << "input new name for the product: ";
			Getline(choise);



			if (choise.size() <= 20 && choise.size() >= 3)
			{
				dy_name_arr[ID - 1] = choise;
				break;
			}
			else
			{
				std::cout << "\nwrong name lenght, dumbass\n";
				Sleep(1000);
			}

		}
		ShowStorage(0);
	}
}
//-------------------------------//
void DeleteUnwantedShit()
{
	if (dy = false)
	{
		--size;
		int* ID_arrTemp = new int[size];
		std::string* name_arrTemp = new std::string[size];
		double* price_arrTemp = new double[size];
		int* count_arrTemp = new int[size];

		for (int i = 0; i < size; i++)
		{
			ID_arrTemp[i] = ID_arr[i];
		}
		int ID = getID();
		for (int i = 0, j = 0; i < size; i++, j++)
		{
			if (i != ID - 1)
			{
				name_arrTemp[i] = name_arr[j];
				price_arrTemp[i] = price_arr[j];
				count_arrTemp[i] = count_arr[j];
			}
			else
			{
				j++;
				name_arrTemp[i] = name_arr[j];
				price_arrTemp[i] = price_arr[j];
				count_arrTemp[i] = count_arr[j];
			}
		}
		std::swap(ID_arr, ID_arrTemp);
		std::swap(name_arr, name_arrTemp);
		std::swap(price_arr, price_arrTemp);
		std::swap(count_arr, count_arrTemp);



		delete[] ID_arrTemp;
		delete[] name_arrTemp;
		delete[] price_arrTemp;
		delete[] count_arrTemp;
	}
	else
	{
		--size;
		int* ID_arrTemp = new int[size];
		std::string* name_arrTemp = new std::string[size];
		double* price_arrTemp = new double[size];
		int* count_arrTemp = new int[size];

		for (int i = 0; i < size; i++)
		{
			ID_arrTemp[i] = dy_ID_arr[i];
		}
		int ID = getID();
		for (int i = 0, j = 0; i < size; i++, j++)
		{
			if (i != ID - 1)
			{
				name_arrTemp[i] = dy_name_arr[j];
				price_arrTemp[i] = dy_price_arr[j];
				count_arrTemp[i] = dy_count_arr[j];
			}
			else
			{
				j++;
				name_arrTemp[i] = dy_name_arr[j];
				price_arrTemp[i] = dy_price_arr[j];
				count_arrTemp[i] = dy_count_arr[j];
			}
		}
		std::swap(dy_ID_arr, ID_arrTemp);
		std::swap(dy_name_arr, name_arrTemp);
		std::swap(dy_price_arr, price_arrTemp);
		std::swap(dy_count_arr, count_arrTemp);



		delete[] ID_arrTemp;
		delete[] name_arrTemp;
		delete[] price_arrTemp;
		delete[] count_arrTemp;
	}
}
//-------------------------------//
void ShowStaff()
{
	std::cout << "No\t" << std::left << std::setw(15) << "Employee login\t" << "password\t" <<
		"sells\n";
	for (int i = 1; i < user_count; i++)
	{
		std::cout << i << "\t" << std::left << std::setw(15) << loginarr[i] << "\t" << password[i] << "\t" << sellsArr[i] << "\t";
	}
	std::cout << "\n\n";
}
//---------------------------//
void RemoveoldStaff()
{
	system("cls");
	Showemployee();
	int ID = getID(1);
	--user_count;


	std::string* loginArrTemp = new std::string[user_count];
	std::string* passArrTemp = new std::string[user_count];
	double* sellsArrTemp = new double[user_count];

	for (int i = 0, j = 0; i < user_count; i++, j++)
	{
		if (j != ID)
		{
			loginArrTemp[i] = loginarr[j];
			passArrTemp[i] = password[j];
			sellsArrTemp[i] = sellsArr[j];
		}
		else
		{
			j++;
			loginArrTemp[i] = loginarr[j];
			passArrTemp[i] = password[j];
			sellsArrTemp[i] = sellsArr[j];
		}
	}

	system("cls");
	std::cout << "user removed\n";
	std::cout << "No\t" << std::left << std::setw(15) << "Employee login\t" << "password\t" <<
		"sells\n";
	for (int i = 0; i < user_count; i++)
	{
		std::cout << ID << "\t" << std::left << std::setw(15) << loginarr[ID] << "\t" << password[ID]  << "\t" << sellsArr[ID] << "\t";
	}
	std::cout << "\n\n";

	std::swap(loginarr, loginArrTemp);
	std::swap(password, passArrTemp);
	std::swap(sellsArr, sellsArrTemp);

	system("pause");
	delete[]loginArrTemp;
	delete[]passArrTemp;
	delete[]sellsArrTemp;
}
//---------------------------//
void Showemployee()
{
	std::cout << "No\t" << std::left << std::setw(15) << "Employee login\t" << "password\t" <<
		"sells\n";
	for (int i = 0; i < user_count; i++)
	{
		std::cout << i << "\t" << std::left << std::setw(15) << loginarr[i] << "\t" << password[i] << "\t" << sellsArr[i] << "\t";
	}
	std::cout << "\n\n";
}
//-------------------------//
void ChangeStaff()
{
	while (true)
	{
		std::string choose;
		std::cout << "1 - see employee list\n2 - add a new staff member\n3 - otherwise redact staff member\n4 - remove staff member\n0 - exit\nchoise = ";
		Getline(choose);
		if (choose == "1")
		{
			ShowStaff();
		}
		else if (choose == "2")
		{
			AddnewStaff();
		}
		else if (choose == "3")
		{
			RedactStaff();
		}
		else if (choose == "4")
		{
			if (user_count >= 2)
			{
				RemoveoldStaff();
			}
			else
			{
				std::cout << "there's only one staff member left, you can't delete him";
			}
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "\n\ninput error dumbass\n\n";
			Sleep(1000);
		}
	}
}
//------------------------//
void AddnewStaff()
{
	++user_count;
	std::string* loginArrTemp = new std::string[user_count];
	std::string* passArrTemp = new std::string[user_count];
	double* sellsArrTemp = new double[user_count];

	for (size_t i = 0; i < user_count; i++)
	{
		loginArrTemp[i] = loginarr[i];
		passArrTemp[i] = password[i];
		sellsArrTemp[i] = sellsArr[i];
		std::string choose;
		sellsArrTemp[user_count - 1] = 0.0;
		while (true)
		{
			system("cls");
			std::cout << "input login of new staff member: ";
			Getline(choose);
			if (choose.size() <= 15 && choose.size() >= 5)
			{
				loginArrTemp[user_count - 1] = choose;
				break;
			}
			else
			{
				std::cout << "\nname error dumbas, max 15 min 5 symbols\n";
				Sleep(1000);
			}
		}
		std::swap(loginarr, loginArrTemp);
		std::swap(password, passArrTemp);
		std::swap(sellsArr, sellsArrTemp);
		system("cls");

		std::cout << "No\t" << std::left << std::setw(15) << "Employee login\t" << "password\t" <<
			"sells\n";
		for (int i = 0; i < user_count; i++)
		{
			std::cout << user_count << "\t" << std::left << std::setw(15) << loginarr[user_count - 1] << "\t" << password[user_count - 1] << "\t" << sellsArr[user_count - 1] << "\t";
		}
		std::cout << "\n\n";

		system("pause");
		delete[]loginArrTemp;
		delete[]passArrTemp;
		delete[]sellsArrTemp;
	}
}
//------------------------//
void RedactStaff()
{
	std::string choose;
	Showemployee();
	int ID = getID(1);
	std::cout << "choose the option to redact\n1 - login\n2 - password\ninput = ";
	Getline(choose);
	if (choose == "1")
	{
		while (true)
		{
			system("cls");
			std::cout << "input new staff member's login\n";
			std::string newlogin;
			Getline(newlogin);
			if (choose.size() <= 15 && choose.size() >= 5)
			{
				loginarr[ID] = newlogin;
				std::cout << "login changed\n";
				Sleep(100);
				break;
			}
			else
			{
				std::cout << "\n\nlogin length error, dumbass max is 15 min is 5\n\n";
			}
		}

	}
	else if (choose == "2")
	{
		while (true)
		{
			system("cls");
			std::cout << "input new staff member's password\n";
			std::string newPassword;
			Getline(newPassword);
			if (choose.size() <= 30 && choose.size() >= 8)
			{
				password[ID] = newPassword;
				std::cout << "password changed\n";
				Sleep(100);
				break;
			}
			else
			{
				std::cout << "\n\npassword length error, dumbass max is 30 min is 8\n\n";
			}
		}

	}
}
//------------------------//
void Selling()
{
	std::string choise; std::string choose;
	int ID = 0, ammount = 0;
	std::string bdaySale_s; std::string blackFriday;
	bool isFirst = true, isBuy = true;
	double totalSum = 0, cash = 0;
	ResetCheck();
	while (isBuy)
	{
		ShowStorage(1);
		ID = getID();

		std::cout << "input amount of stuff to buy: ";
		while (true)
		{
			Getline(choise);
			if (isnumber(choise))
			{
				ammount = std::stoi(choise);
				if (ammount > count_arr[ID - 1] || ammount < 1)
				{
					std::cout << "\n\nNUH UH\n\n";
					Sleep(100);
				}
				else
				{
					break;
				}
			}
			else
			{
				std::cout << "\n\ninput error dumbass\n\n";
				Sleep(100);
			}
		}

		if (isFirst)
		{
			name_arrCheck[sizeCheck - 1] = name_arr[ID - 1];
			count_arrCheck[sizeCheck - 1] = ammount;
			price_arrCheck[sizeCheck - 1] = price_arr[ID - 1];
			total_arrCheck[sizeCheck - 1] = count_arr[ID - 1] * price_arr[ID - 1];
			count_arr[ID - 1] -= ammount;
			totalSum += ammount * price_arr[ID - 1];
			isFirst = false;
		}
		else
		{
			increaseCheckArr();
			name_arrCheck[sizeCheck - 1] = name_arr[ID - 1];
			count_arrCheck[sizeCheck - 1] = ammount;
			price_arrCheck[sizeCheck - 1] = price_arr[ID - 1];
			total_arrCheck[sizeCheck - 1] = count_arr[ID - 1] * price_arr[ID - 1];
			count_arr[ID - 1] -= ammount;
			totalSum += ammount * price_arr[ID - 1];
		}

		while (true)
		{
			std::cout << "buy more stuff?\n1-yes\n2-no\ninput: ";
			Getline(choise);
			if (choise == "1")
			{
				continue;
			}
			else if (choise == "2")
			{
				isBuy = false;
				break;
			}
			else
			{
				std::cout << "\n\ninput error, dumbass\n\n";
			}
		}
		while (true)
		{
			system("cls");
			while (true)
			{
				std::cout << "is it the customer's birbday?\nyes or no\n";
				Getline(bdaySale_s);
				std::cout << "is it black friday?\nyes or no\n";
				Getline(blackFriday);
				if (bdaySale_s == "yes")
				{
					totalSum = totalSum - totalSum * 0.50; // я забыл как нормальные проценты делать, и да это первый и ЕДИНСТВЕННЫЙ коммент на русском
					break;
				}
				else if (blackFriday == "yes")
				{
					totalSum = totalSum * 1.5; // yes negative sale, the price goes up, that's how it works IRL
					break;
				}
				else if (bdaySale_s == "yes" && blackFriday == "yes")
				{
					totalSum = totalSum - totalSum * 0.8;
					break;
				}
				else
				{
					std::cout << "input error, dumbass";
				}
			}

			PrintCheck();
			std::cout << "\t\t\t\t\tTotal price = " << totalSum << "\n\nchoose payment methodd\n1-cash\n2-card\ninput: ";
			Getline(choose);

			if (choose == "1")
			{
				while (true)
				{
					std::cout << "input the ammount of cash: ";
					Getline(choose);
					if (isnumber(choose))
					{
						cash = std::stod(choose);
						if (cash <= 0 || cash < totalSum)
						{
							std::cout << "\n\ninsuficcient cash\n\n";
						}
						else if (cash - totalSum < cashbox)
						{
							std::cout << "\n\nnothing to give change with\n";
						}
						else
						{
							std::cout << "your " << cash << "\nOperation sucsessfull\byour change: " <<
								cash - totalSum << "\n\n";
							cashbox += cash - (cash - totalSum);
							cash_income += totalSum;
							sellsArr[userID] += totalSum;
							break;
						}
					}
					else
					{
						std::cout << "\n\nNUH UH\n\n";
					}
				}
				break;
			}
			else if (choose == "2")
			{
				std::cout << "please attach your card\n\n";
				system("pause");
				while (true)
				{
					if (rand() % 10 <= 2)
					{
						for (int i = 0; i < 5; i++)
						{
							std::cout << i + 1 << " ";
							Sleep(850);
						}
						std::cout << "connection error! try again\n\n";
						Sleep(1300);
						system("cls");
					}
					else
					{
						for (int i = 0; i < 5; i++)
						{
							std::cout << i + 1 << " ";
							Sleep(850);
						}
						std::cout << "\n\nOperation complete\n\n";
						E_cash_income += totalSum;
						sellsArr[userID] += totalSum;
					}
					break;
				}
				break;
			}
			else
			{
				std::cout << "\n\ninput error, dumbass\n\n";
			}
		}
		Sleep(1500);
	}
}
//-----------------------------//
void increaseCheckArr()
{
	++sizeCheck;
	std::string* name_arrCheckTemp = new std::string[sizeCheck];
	double* price_arrCheckTemp = new double[sizeCheck];
	int* count_arrCheckTemp = new int[sizeCheck];
	double* total_arrCheckTemp = new double[sizeCheck];

	for (int i = 0; i < sizeCheck - 1; i++)
	{
		name_arrCheckTemp[i] = name_arrCheck[i];
		price_arrCheckTemp[i] = price_arrCheck[i];
		count_arrCheckTemp[i] = count_arrCheck[i];
		total_arrCheckTemp[i] = total_arrCheck[i];
	}
	std::swap(name_arrCheck, name_arrCheckTemp);
	std::swap(price_arrCheck, price_arrCheckTemp);
	std::swap(count_arrCheck, count_arrCheckTemp);
	std::swap(total_arrCheck, total_arrCheckTemp);

	delete[] name_arrCheckTemp;
	delete[] count_arrCheckTemp;
	delete[] price_arrCheckTemp;
	delete[] total_arrCheckTemp;
}
//-----------------------------//
void PrintCheck()
{
	std::cout << "\t" << std::left << std::setw(25) << "Item name\t\t" << "Price per unit\t" << "Ammount\t" << "total";
	for (int i = 0; i < sizeCheck; i++)
	{
		std::cout << i+1 << "\t" << std::left << std::setw(25) << name_arrCheck[i] << "\t      " << price_arrCheck[i]
			<< "\t" << count_arrCheck[i] << "\t" << "\n";
	}
	std::cout << "\n\n";
}
//-----------------------//
void ResetCheck()
{
	sizeCheck = 0;
	delete[] name_arrCheck;
	delete[] count_arrCheck;
	delete[] price_arrCheck;
	delete[] total_arrCheck;

	name_arrCheck = new std::string[sizeCheck];
	price_arrCheck = new double[sizeCheck];
	count_arrCheck = new int[sizeCheck];
	total_arrCheck = new double[sizeCheck];
}
//-----------------------//
void ShowIncome()
{
	system("cls");
	std::cout << "cash in cashbox: " << cashbox << "\n\nE encome: " << E_cash_income <<
		"\n\ntotal income from this shift" << cash_income + E_cash_income << "\nyour sells: " << sellsArr[userID]
		<< "\n\n\n";
	system("pause");
}
//-----------------------//
bool Exit()
{
	std::string choise, choose;
	while (true)
	{
		system("cls");
		std::cout << "1) Log out\n2) end shift\n3)go back\ninput:  ";
		Getline(choise);
		if (choise == "1")
		{
			std::cout << "good job\n";
			return true;
		}
		else if (choise == "2")
		{
			system("cls");
			std::cout << "input admin password to end shift: ";
			Getline(choose);
			if (choose == password[0])
			{
				isOpen = false;
				return true;
			}
			else
			{
				std::cout << "\n\nNUH UH\n\n";
				Sleep(100);
			}
		}
		else if (choise == "3")
		{
			std::cout << "going back\n\n";
			Sleep(500);
			return false;
		}
		else
		{
			std::cout << "\n\nNUH UH\n\n";
			Sleep(100);
		}
	}
}
//-----------------//
template<typename ArrType>
void FillArray(ArrType staticArr[], ArrType dynamicArr[])
{
	for (int i = 0; i < size; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}
