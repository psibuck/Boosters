// Lamdas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <iostream>
#include <vector>

class UI_MEMBER
{
public:
	std::string name;
	std::string job;
	int age{ 0 };
};

int main()
{
	std::vector<UI_MEMBER*> ui_members;
	auto create_ui_member = [&ui_members]( const std::string member_name, const std::string member_job,
								const int member_age )
	{
		UI_MEMBER* new_member = new UI_MEMBER();
		new_member->name = member_name;
		new_member->job = member_job;
		new_member->age = member_age;
		ui_members.push_back( new_member );
	};

	create_ui_member( "phil", "qa tester", 26 );
	create_ui_member( "archie", "programmer", 28 );
	create_ui_member( "stu", "qa tester", 33 );
	create_ui_member( "kev", "programmer", 23 );
	create_ui_member( "foose", "qa tester", 36 );
	create_ui_member( "jack", "qa tester", 46 );
	create_ui_member( "richard", "programmer", 24 );
	create_ui_member( "matt", "qa tester", 26 );

	std::sort( ui_members.begin(), ui_members.end(), []( const UI_MEMBER* member_1, const UI_MEMBER* member_2 )
			   {
				   return member_1->age > member_2->age;
			   } );

	for ( auto member : ui_members )
	{
		std::cout << member->name << std::endl;
		std::cout << member->age << std::endl;
		std::cout << member->job << std::endl << std::endl;
	}
	
	// clean up 
	for ( auto member : ui_members )
	{
		delete member;
	}

	return 0;
}
