#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//I split the functionality of deciding the message depending on the age into a different method
// This method checks the age and returns the appropriate message.
string age_message(int age)
{

  std::stringstream message;
    if(age < 12)
    {
      age = age + 1;
      message << "Next year you will be age " << age;
    }
    else if (age == 17)
      {
	message << "Next year you will be able to vote ";
      }
    else if(age > 70)
      {
	message << "I hope you are enjoying your retirement";
      }

    return message.str();
}

void letter(string sender_name,string first_name,string friend_name,char friend_gender,string message)
{
  
  //The actual letter
  std::cout << "Dear " << first_name << "," << std::endl;
  std::cout << "How are you? I am brilliant, who knew you could have so much fun on mars." << std::endl;
  std::cout << "Have you seen " << friend_name << " lately?" << std::endl;
  // Decide if male then use "him" else if female use "her"
  if(friend_gender == 'm')
    {
      std::cout << "If you see " << friend_name << " please ask him to call me" << std::endl;
    }
  else if (friend_gender == 'f')
    {
      std::cout << "If you see " << friend_name << " please ask her to call me" << std::endl;
    }  
  std::cout << message << std::endl;
  std::cout << std::endl << std::endl;
  std::cout << sender_name << std::endl;

}

int main()
{
  std::string first_name = "";
  std::string friend_name = "";
  std::string sender_name = "";
  char friend_gender = 0;
  int age = 0;

  
  std::cout << "Enter senders name" << std::endl;
  std::cin >> sender_name;
  // Take in the recipient name
  std::cout << "Enter the name of the person you want to write to" << std::endl;
  std::cin >> first_name;
  // Take in the senders friend's name
  std::cout << "Please enter your friends name" << std::endl;
  std::cin >> friend_name;
  //Take in the gender of the friend
  std::cout << "Enter the gender of your friend. If your friend is male then type m , else if your friend is female type f" 
	    << friend_name << " lately?" << std::endl;
  std::cin >> friend_gender;
  //Take in the age of the recipient's age
  std::cout << "Please enter the age of the recipient" << std::endl;
  //std::cin >> age;
  
  while(std::cin >> age && (age <= 0 || age >=110))
    {
      cout << "Age out of range , age must be greater than 0 and less than 110: "<< age << std::endl;
    }
  
  letter(sender_name,first_name,friend_name,friend_gender,age_message(age));
}
