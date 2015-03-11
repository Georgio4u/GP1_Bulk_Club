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

	cout <<
	"__          __  _                            _______            \n"
	"\\ \\        / / | |                          |__   __|         \n"
	" \\ \\  /\\  / /__| | ___ ___  _ __ ___   ___     | | ___       \n"
	"  \\ \\/  \\/ / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\    | |/ _ \\ \n"
	"   \\  /\\  /  __/ | (_| (_) | | | | | |  __/    | | (_) |      \n"
	"    \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|    |_|\\___/  \n\n";

	cout <<
	" ____        _ _       _____ _       _        ____   _____       \n"
	"|  _ \\      | | |     / ____| |     | |      / __ \\ / ____|    \n"
	"| |_) |_   _| | | __ | |    | |_   _| |__   | |  | | (___        \n"
	"|  _ <| | | | | |/ / | |    | | | | | '_ \\  | |  | |\\___ \\    \n"
	"| |_) | |_| | |   <  | |____| | |_| | |_) | | |__| |____) |      \n"
	"|____/ \\__,_|_|_|\\_\\  \\_____|_|\\__,_|_.__/   \\____/|_____/ \n\n";

	//OUTPUT - the menu is diplsayed in main program
	cout << setfill('-') << setw(26) << left << '-' << endl;
	cout << setfill(' ');
	cout << "0  - EXIT" << endl;
	cout << "1  - PROCESS MEMBERS" << endl;
	cout << "2  - PROCESS TRANSACTIONS" << endl;
	cout << "3  - GENRERATE DAILY SALES REPORT" << endl;
	cout << "4  - SEARCH A NAME OR ID" << endl;
	cout << "5  - PRINT TOTAL PURCHASES" << endl;
	cout << "6  - PRINT ITEMS SOLD" << endl;
	cout << "7  - PRINT ITEM QUANTITY" << endl;
	cout << "8  - PRINT REBATE" << endl;
	cout << "9  - PRINT AMOUNT PAID" << endl;
	cout << "10 - PRINT EXPIRATION" << endl;
	cout << "11 - ADD MEMBERS" << endl;
	cout << "12 - DELETE MEMBERS" << endl;

	do
	{

		//function call - menu
		cout << endl;
		cout << "Choice: ";
		//function call - check int input
		tempChoice = GetAndCheckInt(0, 12);

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
void BulkClass::AddMembers(ifstream &infile)
{

	//temp variables for the file to read in
	string tempName;
	int tempId;
	string tempMemberType;
	string tempDate;
	BasicMember ** tempArray;

	//private data member set to 0;
	//memberCount = 0;

	infile.open("InputMembers.txt");

	while (infile.good())
	{

		//reads in all temp data
		getline(infile, tempName);
		infile >> tempId;
		infile.ignore(1000, '\n');
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
	cout << setfill('-') << setw(26) << left << '-' << endl;
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
	cout << endl << endl;

	memberChoice = SubMenu();

	cout << "OPTION 1 FOR MENU: \n\n";
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
					//output member
					cout << "Member Name: " << memberArray[mCount]->GetName()
							<< endl;
					break;

				}
			}

			//output of item name and the quantity of each item.
			cout << "Item Name: " << setw(30) << itemArray[tCount]->itemName
					<< "  ";
			cout << "Item Quantity: " << itemArray[tCount]->itemQuantity
					<< endl;

		}

	}

	cout << endl;
	cout << "TOTAL SPENT ON DAY " << enteredDay << " : " << totalRevenue;

}

bool BulkClass::SearchNameOrId(string memberNameOrNumber)
{

	bool found = false; //is the name or ID found?

	// will convert the string to an int...
	// if a name is passed in, then the function will return zero, so then
	// we have to look the name up to find an ID
	long memberNum = std::strtol(memberNameOrNumber.c_str(), NULL, 10);

	cout << "\n\n\nOPTION #2 ON MENU:\n";

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
				found = true;
			}
		}
	}

	//if the user just entered an ID
	cout << "Searching the ID: " << memberNum;
	cout << endl << endl;

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
			cout << "itemPurchased: " << setw(30) << itemArray[i]->itemName;
			cout << endl;
			cout << "Quantity: " << itemArray[i]->itemQuantity;
			cout << endl;

		}

	}

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

		cout << "ID: " << setw(20) << memberArray[i]->GetId();
		cout << "Total Purchases: " << memberArray[i]->GetTotalSpent();

		tempGrand += memberArray[i]->GetTotalSpent();
		cout << endl << endl;
	}

	cout << "total Spent: " << tempGrand;
}

void BulkClass::PrintTotalSalesAndItemsSold(string item)
{

	int tempCount = 0;
	float tempTotal = 0.0;
	bool found = false;

	cout << "OPTION #4 ON MENU:\n\n";

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
		cout << "The number of " << item << " sold is: " << tempCount;
		cout << endl << endl;
		cout << "The total cost of " << item << " sold is: " << tempTotal;

	} else
	{
		cout << "\nItem not found...\n";
	}

}

void BulkClass::PrintItemQuantity()
{

	Transaction * tempItem = NULL;

	cout << "OPTION #5 FOR MENU:\n\n";

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
	cout << setw(40) << "ITEM NAME" << "QUANTITY" << endl << endl;

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

	cout << "OPTION #6 FOR MENU:\n\n";

	cout << setw(15) << "ID" << "Rebate\n\n";

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
			cout << ((PreferredMember*) memberArray[i])->GetRebate();
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

	cout << setw(25) << "membership type";
	cout << setw(25) << "member name";
	cout << "Dues" << endl << endl;

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
		memberArray[i]->PrintDues();

	}

}

void BulkClass::PrintMemberExpiration(int inputMonth)
{

	cout << "OPTION #8:\n\n";

	cout << "The member(s) whos memberships expire on " << inputMonth
			<< " are:\n\n";

	cout << setw(25) << "Name" << "Dues\n\n";

	for (int i = 0; i < memberCount; i++)
	{

		if (memberArray[i]->ReturnMonthFromDate() == inputMonth)
		{

			cout << setw(25) << memberArray[i]->GetName();
			memberArray[i]->PrintDues();

		}

	}

}

void BulkClass::AddMembers()
{

	string tempName;
	int tempId;
	string tempMemberType;
	string tempDate;
	BasicMember ** tempArray;

	//reads in all temp data
	cin.ignore(1000, '\n');

	cout << setw(24) << "Enter a name: ";
	getline(cin, tempName);
	cout << endl;
	cout << setw(24) << "Enter an ID: ";
	cin >> tempId;
	cin.ignore(1000, '\n');
	cout << endl;
	cout << setw(24) << "Enter a membership type: ";
	getline(cin, tempMemberType);
	cout << endl;
	cout << "Enter a expiration date: ";
	getline(cin, tempDate);

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

}

void BulkClass::deleteMember()
{

	BasicMember**tempArray;
	string deletionName;
	int deletedIndex = 0;
	bool found = false;

	cin.ignore(1000, '\n');
	cout << "\n\nEnter a member for deletion: \n";
	getline(cin, deletionName);

	for (int i = 0; i < memberCount; i++)
	{
		if (deletionName == memberArray[i]->GetName())
		{
			deletedIndex = i;
			found = true;
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

		for (int i = 0; i < memberCount - 1; i++)
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
	} else
	{
		cout << "\n\nName not found!\n\n";
	}

}

//temp functiion to see if the correct date is used as output
void BulkClass::OutputMembers()
{
	cout << setprecision(2) << fixed;

	cout << "TESTING DATA...\n\n\n";
	for (int i = 0; i < memberCount; i++)
	{

		cout << left;

		cout << setw(30) << memberArray[i]->GetName() << "  totalSpent: "
				<< setw(15) << memberArray[i]->GetTotalSpent();

		if (memberArray[i]->GetMemberType() == "Preferred")
		{

			//typecast for rebate since it is of preferred class
			cout << "Rebate: "
					<< ((PreferredMember*) memberArray[i])->GetRebate();
		}

		cout << endl;

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
void BulkClass::FillItemArray(ifstream &infile, int fileNumber)
{

	Transaction** tempArray;
	tempArray = NULL;

	//temp variables from file again.
	string tempDate;
	string fileName;
	double tempTotal;
	float tempRebate;
	int index = 0;

	//private member data
	//transactionCount = 0;

	//since the 5 days are in different files, we need to call this
	//function 5 times each passing in a different file name verytime.
	//so When we pass in a 1 from main it turns the one into
	//"Day1transactions.txt" and so on up till Day5transactions.

	fileName = "Day" + to_string(fileNumber) + "Transactions.txt";
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
		infile.ignore(1000, '\n');

		getline(infile, itemArray[transactionCount]->itemName);

		infile >> itemArray[transactionCount]->itemPrice
				>> itemArray[transactionCount]->itemQuantity;
		infile.ignore(1000, '\n');

		/****
		 ERROR CHECK CODE:
		 cout << itemArray[transactionCount]->itemPrice << endl;
		 cout << itemArray[transactionCount]->itemQuantity << endl;
		 cout << itemArray[transactionCount]->memberId << endl;
		 cout << itemArray[transactionCount]->itemName << endl;
		 cout << tempDate << endl;

		 ****/

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

void BulkClass::DeleteMemberList()
{

	delete[] memberArray;

	memberCount = 0;
}

void BulkClass::DeleteTransactionList()
{
	delete[] itemArray;
	transactionCount = 0;

}

