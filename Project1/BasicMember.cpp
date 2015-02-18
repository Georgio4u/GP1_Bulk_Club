/*
 * BasicMember.cpp
 *
 *  Created on: Feb 12, 2015
 *      Author: aenglish3
 */

#include "BasicMember.h"

//default constructor
BasicMember::BasicMember()
{

	totalSpent = 0;
	name.clear();
	memberId = 0;
	memberType.clear();
	basicDues = 0;

}

//non default constructor
BasicMember::BasicMember(string name, int id, string memberType,
							string memberExpiration)
{

	//setting temp variables to the actual class members
	this->name = name;
	memberId = id;
	this->memberType = memberType;

	// calls the date class to convert string to ints and also to set the
	// temp varaible
	this->memberExpiration.SetDate(memberExpiration);

	basicDues = 55.00;
	totalSpent = 0;

}

//will set the total spent by each member
void BasicMember::SettotalSpent(double itemCost)
{

	//calculates the total and then adds the sales tax.
	totalSpent = (totalSpent + itemCost);
	totalSpent += totalSpent * .08;
}

//returns total spent
double BasicMember::GetTotalSpent()
{

	return totalSpent;
}

//returns the type of membership
string BasicMember::GetMemberType()
{

	return memberType;
}

//returns the member name
string BasicMember::GetName()
{

	return name;

}

//returns the member ID
int BasicMember::GetId()
{
	return memberId;

}

