#include "BulkClass.h"
#include "OtherFunctions.h"

//default constructor
BulkClass::BulkClass()
{
	itemArray = NULL;
	memberArray = NULL;
	memberCount = 0;
	transactionCount = 0;

}



int BulkClass::Menu()
{

	int tempChoice = -1;

	// PRINT - Program name screen
	cout
			<< " ____        _ _       _____ _       _        ____   _____       \n"
					"|  _ \\      | | |     / ____| |     | |      / __ \\ / ____|    \n"
					"| |_) |_   _| | | __ | |    | |_   _| |__   | |  | | (___        \n"
					"|  _ <| | | | | |/ / | |    | | | | | '_ \\  | |  | |\\___ \\    \n"
					"| |_) | |_| | |   <  | |____| | |_| | |_) | | |__| |____) |      \n"
					"|____/ \\__,_|_|_|\\_\\  \\_____|_|\\__,_|_.__/   \\____/|_____/ \n\n";

	//OUTPUT - the menu is diplsayed in main program
	cout << setfill('-') << setw(59) << left << '-' << endl;
	cout << setfill(' ');
	cout << setw(58) << "| 0  - EXIT" << '|' << endl;
	cout << setw(58) << "| 1  - ADD DATA" << '|' << endl;
	cout << setw(58) << "| 2  - RE-INITALIZE" << '|' << endl;
	cout << setw(58) << "| 3  - GENRERATE DAILY SALES REPORT" << '|' << endl;
	cout << setw(58) << "| 4  - SEARCH A NAME OR ID" << '|' << endl;
	cout << setw(58) << "| 5  - PRINT TOTAL PURCHASES" << '|' << endl;
	cout << setw(58) << "| 6  - PRINT ITEMS SOLD" << '|' << endl;
	cout << setw(58) << "| 7  - PRINT ITEM QUANTITY" << '|' << endl;
	cout << setw(58) << "| 8  - PRINT REBATE" << '|' << endl;
	cout << setw(58) << "| 9  - PRINT AMOUNT PAID" << '|' << endl;
	cout << setw(58) << "| 10 - PRINT EXPIRATION" << '|' << endl;
	cout << setw(58) << "| 11 - ADD MEMBERS" << '|' << endl;
	cout << setw(58) << "| 12 - ADD TRANSACTIONS" << '|' << endl;
	cout << setw(58) << "| 13 - DELETE MEMBERS" << '|' << endl;
	cout << setw(58) << "| 14 - WHICH BASIC MEMBERS SHOULD CONVERT" << '|'
			<< endl;
	cout << setw(58) << "| 15 - WHICH PREFERRED MEMBERS SHOULD CONVERT" << '|'
			<< endl;

	cout << setfill('-') << setw(59) << left << '-' << endl;
	cout << setfill(' ');

	do
	{

		//function call - menu
		cout << endl;
		cout << "Choice: ";
		//function call - check int input
		tempChoice = GetAndCheckInt(0, 15);

	} while (tempChoice == -1);

	return tempChoice;

}

int BulkClass::GetMemberArraySize()
{

	return memberCount;

}

int BulkClass::GetTransactionArraySize()
{

	return transactionCount;
}

//adds members to a dynamic array
void BulkClass::AddMembers(ifstream &infile, char **path)
{

	//temp variables for the file to read in
	string tempName;
	int tempId;
	string tempMemberType;
	string tempDate;
	BasicMember ** tempArray;
	string formPath(path[0]); // Declares a string and converts char to str
	int found = 0;

	//private data member set to 0;
	//memberCount = 0;

	// This takes the path to the program passed in and modifies it to find
	//		the path of the input file
	found = formPath.find("Debug");
	formPath.erase(found);
	formPath += "InputMembers.txt";

	// Opens input file
	infile.open(formPath.c_str());

	while (infile.good())
	{

		//reads in all temp data
		getline(infile, tempName);
		infile >> tempId;
		infile.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(infile, tempMemberType);
		getline(infile, tempDate);

		//temp array must hold the data of array...
		tempArray = memberArray;

		//creating a whole new array of base member
		memberArray = new BasicMember*[memberCount + 1];

		//will skip the first time when memberCount = 0;
		//but will copy the induvidual elements over as array grows
		for (int i = 0; i < memberCount; i++)
		{

			memberArray[i] = tempArray[i];

		}

		//tempArray must be deleted each time
		delete tempArray;

		//typecast for preferred members since the array is of base type
		if (tempMemberType == "Preferred")
		{
			//constructor call
			memberArray[memberCount] = new PreferredMember(tempName, tempId,
					tempMemberType, tempDate);
		} else if (tempMemberType == "Basic")
		{
			//constructor call
			memberArray[memberCount] = new BasicMember(tempName, tempId,
					tempMemberType, tempDate);
		}

		//used to create a new sized array when program re loops
		memberCount++;

	}

	infile.close();

	/*
	 * Dynamic array logic:
	 *
	 * 1) need a counter starting at zero.
	 * 2) temp pointer to point to current array
	 * 3) increment count.
	 *
	 * How it works:
	 *
	 * 1)counter is zero, so creating a brand new array with 1 object
	 *   starting off
	 *
	 * 2)now,once one object is in the array, the temp Array pointer needs
	 *   to hold this array because we need to create a new array of 2
	 *   elements now.
	 *
	 * 3)once a new array is created then all the individual elements from
	 *   the tempArray pointer are copied over into the original array.
	 *
	 * 4)then the constructor is called again but this time for an array
	 *   of 2 elements.
	 *
	 * 5)this process repeats till the file is all read.
	 */

}

string BulkClass::SubMenu()
{
	int tempChoice = -1;
	string returnString;

	cout << "ENTER THE MEMBERS YOU WANT DISPLAYED" << endl;
	cout << setfill('-') << setw(40) << left << '-' << endl;
	cout << setfill(' ');
	cout << "0  - BASIC" << endl;
	cout << "1  - PREFFERED" << endl;
	cout << "2  - BOTH 0 AND 1" << endl;

	do
	{

		//function call - menu
		cout << endl;
		cout << "Choice: ";
		//function call - check int input
		tempChoice = GetAndCheckInt(0, 2);

	} while (tempChoice == -1);

	if (tempChoice == 0)
	{
		returnString = "Basic";
	} else if (tempChoice == 1)
	{
		returnString = "Preferred";
	} else
	{
		returnString = "All";
	}

	return returnString;

}

void BulkClass::PrintSalesReport(int enteredDay)
{

	float totalRevenue = 0;
	string memberChoice;

	int lastMem = 0;
	int totalMem = 0;

	Transaction * tempItem = NULL;

	cout << endl;

	memberChoice = SubMenu();
	cout << endl;

	for (int i = 0; i < transactionCount; i++)
	{
		for (int j = 0; j < transactionCount; j++)
		{
			if (itemArray[i]->memberId < itemArray[j]->memberId)
			{
				tempItem = itemArray[i];
				itemArray[i] = itemArray[j];
				itemArray[j] = tempItem;
			}
		}
	}

	//outter loop to loop through transactions array
	for (int tCount = 0; tCount < transactionCount; tCount++)
	{
		//must be looking through data on the right day
		if (enteredDay == itemArray[tCount]->day)
		{
			//adds up all the revenue that day * the quantity of items
			//bought as well
			totalRevenue += itemArray[tCount]->itemPrice
					* itemArray[tCount]->itemQuantity;

			//cross reference, need to compare the id in the transaction
			//file with the member list
			for (int mCount = 0; mCount < memberCount; mCount++)
			{

				if (memberChoice == "Basic"
						&& memberArray[mCount]->GetMemberType() != "Basic")
				{
					continue;
				}

				if (memberChoice == "Preferred"
						&& memberArray[mCount]->GetMemberType() != "Preferred")
				{
					continue;
				}

				//need to search the member array to a member number at
				//the current itemArray postion to see who shopped that
				//day
				if (itemArray[tCount]->memberId == memberArray[mCount]->GetId())
				{
					// PRINT - Splits up information groups(member and item)
					cout << setfill('-') << setw(63) << '-' << setfill(' ')
							<< endl;
					//output member
					cout << "Member Name: " << memberArray[mCount]->GetName()
							<< endl;

					if (itemArray[tCount]->memberId != lastMem)
					{
						totalMem++;
						lastMem = itemArray[tCount]->memberId;
						//cout << endl << '*' << itemArray[tCount]->memberId << '|' << itemArray[tCount]->memberId << '|' << totalMem << endl;
					}

					break;

				}

			}

			//output of item name and the quantity of each item.
			cout << setw(11) << "Item Name" << ": " << setw(30)
					<< itemArray[tCount]->itemName << "  ";
			cout << "Item Quantity: " << itemArray[tCount]->itemQuantity
					<< endl;

		}

	}

	// PRINT - Last divider on list
	cout << setfill('-') << setw(63) << '-' << setfill(' ') << endl;

	cout << endl;
	cout << "TOTAL SPENT ON DAY " << enteredDay << ": $" << totalRevenue;
	cout << endl;
	cout << "TOTAL MEMBER COUNT ON DAY: " << totalMem << endl;

}

bool BulkClass::SearchNameOrId(string memberNameOrNumber)
{

	bool found = false; //is the name or ID found?

	// will convert the string to an int...
	// if a name is passed in, then the function will return zero, so then
	// we have to look the name up to find an ID
	long memberNum = std::strtol(memberNameOrNumber.c_str(), NULL, 10);

	if (memberNum != 0)
	{
		//if the user just entered an ID
		cout << "Searching the ID: " << memberNum;
		cout << endl << endl;
	}

	cout << endl;
	//if the function above is a zero...
	if (memberNum == 0)
	{
		cout << "Searching for data for the name: " << memberNameOrNumber;
		cout << endl << endl;

		//searching the members for the name entered
		for (int i = 0; i < memberCount; i++)
		{
			if (memberNameOrNumber == memberArray[i]->GetName())
			{
				//since the name is found at a certain index, the id for
				//that person will be in the same index
				memberNum = memberArray[i]->GetId();
			}
		}
	}

	//all we have to do is search the transaction array
	//either way (if name found) will enter and search for a matching
	//ID number in the transactions arrray
	for (int i = 0; i < transactionCount; i++)
	{
		//matching IDs
		if (memberNum == itemArray[i]->memberId)
		{

			//output data
			found = true;

			// PRINT - Separates data
			cout << setfill('-') << setw(45) << '-' << setfill(' ') << endl;
			cout << "Item Purchased: " << setw(30) << itemArray[i]->itemName;
			cout << endl;
			cout << setw(14) << "Quantity" << ": "
					<< itemArray[i]->itemQuantity;
			cout << endl;

		}

	}

	// PRINT - Separates data
	cout << setfill('-') << setw(45) << '-' << setfill(' ') << endl;

	// if not found, will output statement in main.
	return found;
}

void BulkClass::PrintTotalPurchases()
{

	float tempGrand = 0;
	BasicMember* tempMem = NULL;
	string memberChoice;

	memberChoice = SubMenu();
	cout << endl;

	//sorts members by ID
	for (int i = 0; i < memberCount; i++)
	{
		for (int j = 0; j < memberCount; j++)
		{
			if (memberArray[i]->GetId() < memberArray[j]->GetId())
			{
				tempMem = memberArray[i];
				memberArray[i] = memberArray[j];
				memberArray[j] = tempMem;
			}
		}
	}

	//outputs all data thats nesessary for this function
	for (int i = 0; i < memberCount; i++)
	{
		if (memberChoice == "Basic"
				&& memberArray[i]->GetMemberType() != "Basic")
		{
			continue;
		}

		if (memberChoice == "Preferred"
				&& memberArray[i]->GetMemberType() != "Preferred")
		{
			continue;
		}

		// PRINT - Separates data
		cout << setfill('-') << setw(50) << '-' << setfill(' ') << endl;
		cout << "ID: " << setw(20) << memberArray[i]->GetId();
		cout << "Total Purchases: $" << memberArray[i]->GetTotalSpent();

		tempGrand += memberArray[i]->GetTotalSpent();
		cout << endl;
	}

	// PRINT - Separates data
	cout << setfill('-') << setw(50) << '-' << setfill(' ') << endl << endl;

	cout << "Total Spent: $" << tempGrand;
}

void BulkClass::PrintTotalSalesAndItemsSold(string item)
{

	int tempCount = 0;
	float tempTotal = 0.0;
	bool found = false;

	for (int i = 0; i < transactionCount; i++)
	{

		if (itemArray[i]->itemName == item)
		{
			found = true;
			tempCount += itemArray[i]->itemQuantity;
			tempTotal += itemArray[i]->itemPrice;
		}

	}

	if (found)
	{
		cout << endl;
		cout << setfill('-') << setw(50) << '-' << setfill(' ') << endl << endl;
		cout << "The number of " << item << " sold is: " << tempCount;
		cout << endl << endl;
		cout << "The total cost of " << item << " sold is: " << tempTotal
				<< endl << endl;
		cout << setfill('-') << setw(50) << '-' << setfill(' ') << endl << endl;
	} else
	{
		cout << setfill('-') << setw(50) << '-' << setfill(' ') << endl << endl;
		cout << "Item not found...\n\n";
		cout << setfill('-') << setw(50) << '-' << setfill(' ') << endl << endl;

	}

}

void BulkClass::PrintItemQuantity()
{

	Transaction * tempItem = NULL;

	//sorts item array by item name
	for (int i = 0; i < transactionCount; i++)
	{
		for (int j = 0; j < transactionCount; j++)
		{
			if (itemArray[i]->itemName < itemArray[j]->itemName)
			{
				tempItem = itemArray[i];
				itemArray[i] = itemArray[j];
				itemArray[j] = tempItem;
			}
		}
	}

	int qty = 0;

	//loop for item array
	cout << setw(40) << "ITEM NAME" << "QUANTITY" << endl;

	cout << right << setfill('-') << setw(40) << ' ' << setw(8) << '-'
			<< setfill(' ') << left << endl;

	for (int i = 0; i < transactionCount; i++)
	{
		//will always keep increasing quanity as long as the "if" is never
		//true(Meaning the item names are the same).Once the "if" is true
		//(meaning the item names are different)the count will reset.
		qty += itemArray[i]->itemQuantity;

		if (i == transactionCount - 1
				|| itemArray[i]->itemName != itemArray[i + 1]->itemName)
		{
			cout << setw(40) << itemArray[i]->itemName << qty << endl;
			qty = 0;
		}
	}

}

void BulkClass::PrintPreferredRebate()
{

	BasicMember * tempMem;

	cout << setw(15) << "ID" << "REBATE\n";
	cout << right << setfill('-') << setw(15) << ' ' << setw(6) << '-'
			<< setfill(' ') << left << endl;

	//sorts members by ID
	for (int i = 0; i < memberCount; i++)
	{
		for (int j = 0; j < memberCount; j++)
		{
			if (memberArray[i]->GetId() < memberArray[j]->GetId())
			{
				tempMem = memberArray[i];
				memberArray[i] = memberArray[j];
				memberArray[j] = tempMem;
			}
		}
	}

	for (int i = 0; i < memberCount; i++)
	{

		if (memberArray[i]->GetMemberType() == "Preferred")
		{

			cout << setw(15) << memberArray[i]->GetId();

			//typecast to access child class
			cout << '$' << ((PreferredMember*) memberArray[i])->GetRebate();
			cout << endl;

		}

	}

}

void BulkClass::PrintAmountPaid()
{

	BasicMember * tempMem;
	string memberChoice;

	memberChoice = SubMenu();
	cout << endl;

	//sorts members by ID
	for (int i = 0; i < memberCount; i++)
	{
		for (int j = 0; j < memberCount; j++)
		{
			if (memberArray[i]->GetMemberType() + memberArray[i]->GetName()
					< memberArray[j]->GetMemberType()
							+ memberArray[j]->GetName())
			{
				tempMem = memberArray[i];
				memberArray[i] = memberArray[j];
				memberArray[j] = tempMem;
			}
		}
	}

	cout << setw(25) << "Membership Type";
	cout << setw(25) << "Member Name";
	cout << "Dues" << endl;
	cout << right << setfill('-') << setw(25) << ' ' << setw(25) << ' '
			<< setw(6) << '-' << setfill(' ') << left << endl;

	for (int i = 0; i < memberCount; i++)
	{

		if (memberChoice == "Basic"
				&& memberArray[i]->GetMemberType() != "Basic")
		{
			continue;
		}

		if (memberChoice == "Preferred"
				&& memberArray[i]->GetMemberType() != "Preferred")
		{
			continue;
		}

		cout << setw(25) << memberArray[i]->GetMemberType();
		cout << setw(25) << memberArray[i]->GetName();
		cout << '$';
		memberArray[i]->PrintDues();

	}

}

void BulkClass::PrintMemberExpiration(int inputMonth)
{

	bool found = false;

	cout << "The member(s) whos memberships expire on " << inputMonth
			<< " are:\n\n";

	cout << setw(25) << "Name" << "Dues\n";
	cout << right << setfill('-') << setw(25) << ' ' << setw(6) << '-'
			<< setfill(' ') << left << endl;

	for (int i = 0; i < memberCount; i++)
	{

		if (memberArray[i]->ReturnMonthFromDate() == inputMonth)
		{

			found = true;
			cout << setw(25) << memberArray[i]->GetName();
			cout << '$';
			memberArray[i]->PrintDues();

		}

	}

	if (!found)
	{
		cout << "\nNo members expire on that month!\n";
	}

}

void BulkClass::AddMembers()
{

	string tempName;
	int tempId = 0;
	int intTempMemberType;
	string tempMemberType;
	string tempDate;
	bool dateWrong = false;
	BasicMember ** tempArray;

	//reads in all temp data
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Enter a name: ";
	getline(cin, tempName);
	cout << endl;

	do
	{
		//function call - menu
		cout << "Enter an ID: ";
		//function call - check int input
		tempId = GetAndCheckInt(00000, 99999);
		cin.ignore(1000, '\n');
		for (int i = 0; i < memberCount; i++)
		{

			if (memberArray[i]->GetId() == tempId)
			{
				tempId = -1;
				cout << "\n\nID already in use\n\n\n";
			}

		}

	} while (tempId == -1);

	cout << endl;

	do
	{
		cout << "1 - BASIC\n";
		cout << "2 - PREFERRED\n";
		cout << "Enter a membership type: ";

		intTempMemberType = GetAndCheckInt(1, 2);
		cin.ignore(1000, '\n');

	} while (intTempMemberType == -1);

	if (intTempMemberType == 1)
	{
		tempMemberType = "Basic";
	} else
	{
		tempMemberType = "Preferred";
	}

	do
	{
		int month = 0;
		int day = 0;
		int year = 0;
		dateWrong = false;

		cout << endl;
		cout << "Enter a expiration date:(MM/DD/YRRR) ";
		getline(cin, tempDate);

		sscanf(tempDate.c_str(), "%2d/%2d/%4d", &month, &day, &year);

		if (day < 0 || day > 32)
		{

			cout << "\nInvalid Day\n";
			dateWrong = true;

		}
		if (month < 0 || month > 12)
		{
			cout << "\nInvalid Month\n";
			dateWrong = true;
		}
		if (year < 1000 || year > 2100)
		{
			cout << "\nInvalid Year\n";
			dateWrong = true;
		}

	} while (dateWrong);

	//temp array must hold the data of array...
	tempArray = memberArray;

	//creating a whole new array of base member
	memberArray = new BasicMember*[memberCount + 1];

	//will skip the first time when memberCount = 0;
	//but will copy the induvidual elements over as array grows
	for (int i = 0; i < memberCount; i++)
	{

		memberArray[i] = tempArray[i];

	}

	//tempArray must be deleted each time
	delete tempArray;

	//typecast for preferred members since the array is of base type
	if (tempMemberType == "Preferred")
	{
		//constructor call
		memberArray[memberCount] = new PreferredMember(tempName, tempId,
				tempMemberType, tempDate);
	} else if (tempMemberType == "Basic")
	{
		//constructor call
		memberArray[memberCount] = new BasicMember(tempName, tempId,
				tempMemberType, tempDate);
	}

	memberCount++;

	OverWriteMemberFile();
	cout << "\n\nMember " << tempName << " was added!\n\n";

}

void BulkClass::AddTransaction()
{

	int tempId;
	string tempName;
	int tempDay;
	double tempItemPrice;
	int tempItemQuantity;
	int index = 0;
	double tempTotal;
	double tempRebate;

	Transaction** tempArray = NULL;

	//temp array must hold the data of array...
	tempArray = itemArray;

	//creating a whole new array of base member
	itemArray = new Transaction*[transactionCount + 1];

	//will skip the first time when memberCount = 0;
	//but will copy the induvidual elements over as array grows
	for (int i = 0; i < transactionCount; i++)
	{

		itemArray[i] = tempArray[i];

	}

	delete tempArray;

	do
	{
		cout << "Enter an transaction ID: ";
		//function call - check int input
		tempId = GetAndCheckInt(10000, 99999);
		cin.ignore(1000, '\n');

	} while (tempId == -1);

	cout << endl;

	do
	{
		//function call - menu
		cout << "Enter a day the transaction took place: ";
		//function call - check int input
		tempDay = GetAndCheckInt(1, 5);
		cin.ignore(1000, '\n');

	} while (tempDay == -1);

	cout << endl;

	cout << "Enter item name: ";
	getline(cin, tempName);

	cout << endl;
	do
	{
		//function call - menu
		cout << setw(24) << "Enter a item price: ";
		//function call - check int input
		tempItemPrice = GetAndCheckInt(.10, 500.00);
		cin.ignore(1000, '\n');

	} while (tempItemPrice == -1);

	cout << endl;

	do
	{
		//function call - menu
		cout << setw(24) << "Enter a item quantity: ";
		//function call - check int input
		tempItemQuantity = GetAndCheckInt(1, 200);
		cin.ignore(1000, '\n');

	} while (tempItemQuantity == -1);

	itemArray[transactionCount] = new Transaction();

	itemArray[transactionCount]->AddData(tempId, tempDay, tempName,
			tempItemPrice, tempItemQuantity);

	while (index < memberCount)
	{
		//comparing the IDs of the transaction file and the member objects
		if (itemArray[transactionCount]->memberId
				== memberArray[index]->GetId())
		{
			//if they match we will update their total.
			tempTotal = (itemArray[transactionCount]->itemPrice
					* itemArray[transactionCount]->itemQuantity);

			//update is called right here
			memberArray[index]->SettotalSpent(tempTotal);

			//need to do rebate for preferred members
			if (memberArray[index]->GetMemberType() == "Preferred")
			{

				//typecast nesessary to get rebate for totaling
				tempRebate =
						((PreferredMember*) memberArray[index])->GetRebate();

				//get the total rebate without taxes
				tempRebate += tempTotal * .06;

				//now we set the new rebate
				((PreferredMember*) memberArray[index])->SetRebate(tempRebate);
			}

		}
		index++;
	}

	transactionCount++;
	cout << "\n\nTransaction successfully added\n\n";

}

void BulkClass::deleteMember()
{

	BasicMember**tempArray;
	string deletionName;
	int deletedIndex = 0;
	bool found = false;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "\n\nEnter a member for deletion:  ";
	getline(cin, deletionName);

	for (int i = 0; i < memberCount; i++)
	{
		if (deletionName == memberArray[i]->GetName())
		{
			deletedIndex = i;
			found = true;
			break;
		}

	}

	if (found)
	{

		// get pointer to current array
		tempArray = memberArray;

		// create new array size
		memberArray = new BasicMember*[memberCount - 1];

		//element size for new array
		int a = 0;

		for (int i = 0; i < memberCount; i++)
		{
			// copy elements, except the one to be deleted
			if (i != deletedIndex)  // skip item at position 25
			{
				memberArray[a] = tempArray[i];
				a++;
			}
		}

		// delete old array
		delete tempArray;
		memberCount--;

		cout << "\n\nMember " << deletionName << " was deleted!\n\n";

	} else
	{
		cout << "\n\nName not found!\n\n";
	}

	OverWriteMemberFile();

}

void BulkClass::OverWriteMemberFile()
{

	ofstream outfile;

	// Opens input file
	outfile.clear();
	outfile.open("InputMembers.txt");

	for (int i = 0; i < memberCount; i++)
	{

		outfile << memberArray[i]->GetName() << endl;
		outfile << memberArray[i]->GetId() << endl;
		outfile << memberArray[i]->GetMemberType() << endl;
		outfile << memberArray[i]->ReturnDate();

		if (i < memberCount - 1)
		{
			outfile << endl;
		}

	}

	outfile.close();
}

void BulkClass::ShouldBasicMembersConvert()
{

	double tempTotalSpent = 0;
	double taxRate = 0;
	double basicMemberRebate = 0;

	cout << setw(30) << "MEMBER NAME" << "BASIC MEMBERS HYPOTHETICAL REBATE"
			<< endl;
	cout << right << setfill('-') << setw(30) << ' ' << setw(35) << '-'
			<< setfill(' ') << left << endl;

	for (int i = 0; i < memberCount; i++)
	{

		basicMemberRebate = 0;
		tempTotalSpent = 0;
		taxRate = 0;

		if (memberArray[i]->GetMemberType() == "Basic")
		{

			tempTotalSpent = memberArray[i]->GetTotalSpent();
			taxRate = (tempTotalSpent * .083);
			tempTotalSpent -= taxRate;
			basicMemberRebate = tempTotalSpent * .06;

		}

		if (basicMemberRebate > 95.00)
		{

			cout << setw(30) << memberArray[i]->GetName();
			cout << basicMemberRebate;
			cout << endl;
		}

	}

}

void BulkClass::ShouldPreferredMembersConvert()
{

	double tempRebate = 0;

	cout << setw(30) << "MEMBER NAME" << "CONVERT OR NOT?" << endl;

	cout << right << setfill('-') << setw(30) << ' ' << setw(35) << '-'
			<< setfill(' ') << left << endl;

	for (int i = 0; i < memberCount; i++)
	{

		if (memberArray[i]->GetMemberType() == "Preferred")
		{

			tempRebate = ((PreferredMember*) memberArray[i])->GetRebate();

			if (tempRebate < 95.00)
			{
				cout << setw(30) << memberArray[i]->GetName();
				cout << "   Should convert to basic\n\n";

			} else
			{
				cout << setw(30) << "    Do not need to convert\n\n";
			}

		}

	}

}

//used for the 5 files, converts an int into a string
//(called in next function)
string BulkClass::to_string(int number)
{
	stringstream ss;
	ss << number;
	return ss.str();
}

//fills the array of items from the struct transaction
void BulkClass::FillItemArray(ifstream &infile, int fileNumber, char **path)
{

	Transaction** tempArray;
	tempArray = NULL;

	//temp variables from file again.
	string tempDate;
	string fileName;
	double tempTotal;
	float tempRebate;
	int index = 0;
	string formPath(path[0]); // Declares a string and converts char to str
	int found = 0;

	//private member data
	//transactionCount = 0;

	// This takes the path to the program passed in and modifies it to find
	//		the path of the input file
	found = formPath.find("Debug");
	formPath.erase(found);
	formPath += "Day";

	//since the 5 days are in different files, we need to call this
	//function 5 times each passing in a different file name verytime.
	//so When we pass in a 1 from main it turns the one into
	//"Day1transactions.txt" and so on up till Day5transactions.

	fileName = formPath + to_string(fileNumber) + "Transactions.txt";

	infile.open(fileName.c_str());

	while (infile.good())
	{

		//same array logic as previous function
		tempArray = itemArray;
		index = 0;

		itemArray = new Transaction*[transactionCount + 1];

		for (int i = 0; i < transactionCount; i++)
		{

			itemArray[i] = tempArray[i];

		}

		delete tempArray;

		itemArray[transactionCount] = new Transaction();

		// need to know which day transactions were done on
		// file number is passed in
		itemArray[transactionCount]->day = fileNumber;

		// cout << fileNumber << endl;
		// cout << itemArray[transactionCount]->day;

		//setting all data in a struct object
		getline(infile, tempDate);
		itemArray[transactionCount]->ConvertStringDate(tempDate);

		infile >> itemArray[transactionCount]->memberId;
		infile.ignore(numeric_limits<streamsize>::max(), '\n');

		getline(infile, itemArray[transactionCount]->itemName);

		infile >> itemArray[transactionCount]->itemPrice
				>> itemArray[transactionCount]->itemQuantity;
		infile.ignore(numeric_limits<streamsize>::max(), '\n');

		//NEED TO UPDATE DATA IN MEMBER OBJECTS
		while (index < memberCount)
		{
			//comparing the IDs of the transaction file and the member objects
			if (itemArray[transactionCount]->memberId
					== memberArray[index]->GetId())
			{
				//if they match we will update their total.
				tempTotal = (itemArray[transactionCount]->itemPrice
						* itemArray[transactionCount]->itemQuantity);

				//update is called right here
				memberArray[index]->SettotalSpent(tempTotal);

				//need to do rebate for preferred members
				if (memberArray[index]->GetMemberType() == "Preferred")
				{

					//typecast nesessary to get rebate for totaling
					tempRebate =
							((PreferredMember*) memberArray[index])->GetRebate();

					//get the total rebate without taxes
					tempRebate += tempTotal * .06;

					//now we set the new rebate
					((PreferredMember*) memberArray[index])->SetRebate(
							tempRebate);
				}

			}
			index++;
		}

		transactionCount++;

	}

	infile.close();

}

//converts the struct date into 3 ints for the date class
//notice type struct, method of the struct
void Transaction::ConvertStringDate(string tempDate)
{
	date.SetDate(tempDate);
}

void Transaction::AddData(int tempId, int day, string itemName,
		double itemPrice, int itemQuantity)
{

	this->memberId = tempId;
	this->day = day;
	this->itemName = itemName;
	this->itemPrice = itemPrice;
	this->itemQuantity = itemQuantity;

}

void BulkClass::DeleteMemberList()
{

	for (int i = 0; i < memberCount; i++)
	{

		delete memberArray[i];

	}

	memberCount = 0;
}

void BulkClass::DeleteTransactionList()
{

	for (int i = 0; i < transactionCount; i++)
	{

		delete itemArray[i];

	}
	transactionCount = 0;

}

