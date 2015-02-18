#include "BulkClass.h"

//default constructor
BulkClass::BulkClass()
{
	itemArray = NULL;
	memberArray = NULL;
	memberCount = 0;
	transactionCount = 0;

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
	memberCount = 0;

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
		}
		else if (tempMemberType == "Basic")
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

//temp functiion to see if the correct date is used as output
void BulkClass::OutputMembers()
{
	cout << setprecision(2) << fixed;


	for (int i = 0; i < memberCount; i++)
	{
		cout << left;

		cout << setw(30) << memberArray[i]->GetName() <<
		"  totalSpent: " <<setw(15)<< memberArray[i]->GetTotalSpent() ;

		if(memberArray[i]->GetMemberType() == "Preferred")
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
	transactionCount = 0;

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
				if (memberArray[index]->GetMemberType()== "Preferred")
				{

					//typecast nesessary to get rebate for totaling
					tempRebate =((PreferredMember*)
							      memberArray[index])->GetRebate();

					//get the total rebate without taxes
					tempRebate += tempTotal*.06;

					//now we set the new rebate
					((PreferredMember*)
							memberArray[index])->SetRebate(tempRebate);
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

