#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

//data base
int user_count = 2;
bool isAdmin = false;
std::string* loginarr = new std::string[user_count]{ "admin","cashier" };
std::string* password = new std::string[user_count]{ "admin","1" };
//---------------------------------------------------------------------//
int size = 10;
int* ID_arr = new int[size];
std::string* name_arr = new std::string[size];
double* price_arr = new double[size];
int* count_arr = new int[size];

//functions
void ShowStorage(int mode);
void start();
bool Login();
void Getline(std::string& stringname);
void CreateStorage();
void ShowAdminMenu();
void ReffilStuff();
template<typename ArrType>
void FillArray(ArrType staticArr[], ArrType dynamicArr[])
{
	for (int i = 0; i < size; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}
bool isnumber(std::string numbers);

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
		ShowStorage(0);
		Getline(stringid);
		system("cls");
		if (isnumber(stringid))
		{
			result = std::stoi(stringid);
			if (result > 0 && result <= 10)
			{
				return result;
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

//====================//
void ChangeStorage();


//====================//
  int main()
{
	start();
	delete[] ID_arr;
	delete[] name_arr;
	delete[] price_arr;
	delete[] count_arr;
	delete[] loginarr;
	delete[] password;
	return 0;
}
//====================//

void start()
{
	std::cout << "\n\n\t\t\t Welcome to Games Don't Stop! (GDS for short)\n\t\t\tenjoy your stay:3\n\n";
	if (Login())
	{
		if (isAdmin == true)
		{
			//std::string choose;
			//while (true)
			//{
			//	std::cout << "1-already stocked storage\n2-create new storage\nInput: ";
			//	Getline(choose);
			//	if (choose == "1")
			//	{
			//		//already stocked storage, admin
			//	}
			//	else if (choose == "2")
			//	{
			//		CreateStorage();
			//		
			//	}
			//	else if ()
			//	{
			//		// stocked storage, cashier
			//		break;
			//	}
			//	else
			//	{
			//		std::system("cls");
			//		std::cout << "input error, dumbass\n\n";
			//	}
			//}
			CreateStorage();
			ShowAdminMenu();
		}
	}
	else
	{
		std::cerr << "Login error\n";
	}
}

void CreateStorage()
{
	int const static_size = 10;
	int id[static_size]{ 1,2,3,4,5,6,7,8,9,10 };
	std::string name[static_size];
	{
		"The Legend Of Zelda: TOTK", "The Legend Of Zelda : BOTW", "Titanfall 2",
			"MGR:REVENGANCE", "MGS5:PHANTOM PAIN", "WARHAMMER 40K: SPACE MARINE 2",
			"Ghost of Tsushima", "Sniper Ghost Warrior, Contracts 2",
			"Risk Of Rain2", "Risk Of Rain: Returns";
	}
	double price[static_size]{ 123, 85435, 914, 325, 456, 45621, 25,525 ,253, 35 };
	int count[static_size]{ 12, 65, 77, 82, 12, 3, 5, 6,  54, 76 };
	FillArray(id, ID_arr);
	FillArray(name, name_arr);
	FillArray(price, price_arr);
	FillArray(count, count_arr);
}

void ShowStorage(int mode)
{
	if (mode == 0)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Item name\t\t" << "Price\t" << "Ammount\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << ID_arr[i] << "\t" << std::left << std::setw(25) << name_arr[i] << "\t" << price_arr[i]
				<< "\t" << count_arr[i] << "\t\n";
		}
		std::cout << "\n\n";
	}
	else if (mode == 1)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Item name\t\t" << "Price\t" << "Ammount\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << ID_arr[i] << std::left << std::setw(25) << "\t" << name_arr[i] << "\t" << count_arr[i] << "\t";
		}
		std::cout << "\n\n";
	}
	else if (mode == 2)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "Item name\t\t" << "Price\t" << "Ammount\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << ID_arr[i] << "\t" << std::left << std::setw(25) << name_arr[i] << "\t" << price_arr[i] << "\t" << count_arr[i] << "\t";
		}
		std::cout << "\n\n";
		system("pause");
	}
}

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
			std::cout << "Welcome back, doctor (anime/game reference you probably won't understand, i'm a weeb and i'm proud of it)\nstatus: Admin\n\n";
			return true;
		}
		for (int i = 1; i < user_count; i++)
		{
			if (login == loginarr[i] && pass == password[i])
			{
				isAdmin = false;
				std::cout << "Good evening and welcome, what can i get for you?\nstatus: cashier\n\n";
				return true;
			}
		}
		std::cout << "wrong password or login\n\n";
	}
}

void ShowAdminMenu()
{
	std::string choose;
	while (true)
	{
		std::cout << name_arr[0];
		std::cout << "1)Start selling \n";
		std::cout << "2)Show storage \n";
		std::cout << "3)Add to storage \n";
		std::cout << "4)Remove item \n";
		std::cout << "5)Change price \n";
		std::cout << "6)Change storage \n";
		std::cout << "7)Change staff \n";
		std::cout << "8)Profit report \n";
		std::cout << "0)End shift \n";
		std::cout << "Input: ";
		Getline(choose);
		CreateStorage();
		if (choose == "1")
		{

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

		}
		else if (choose == "8")
		{

		}
		else if (choose == "0")
		{
			break;
		}
	}
}

void Getline(std::string& stringname)
{
	std::getline(std::cin, stringname, '\n');
}

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

bool isnumber(std::string number) // 42
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

void RemoveStuff()
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
					if (count >= 0 && count <= count_arr[ID-1])
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

void ChangePrice()
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

void AddNewShit()
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

void RenameOldShit()
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

void DeleteUnwantedShit()
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

