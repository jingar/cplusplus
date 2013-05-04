#include <iostream>
#include <cstring>

void pound_conversion(char convert_to,double quantity)
{
  const double pound_to_yen = 152.12;
  const double pound_to_euro = 1.1866;

 switch(convert_to)
  {
  case'Y': 
    std::cout << pound_to_yen * quantity << std::endl;
    break;
  case'E':
    std::cout << pound_to_euro * quantity << std::endl;
    break;
  default:
    std::cout << "Unrecognized symbol " << convert_to << std::endl;
    break;
  }

  
}

void euro_conversion(char convert_to,double quantity)
{
  const double euro_to_pound = 0.8411;
  const double euro_to_yen = 129.04;

 switch(convert_to)
  {
  case'Y': 
    std::cout << euro_to_yen * quantity << std::endl;
    break;
  case'P':
    std::cout << euro_to_pound * quantity << std::endl;
    break;
  default:
    std::cout << "Unrecognized symbol " << convert_to << std::endl;
    break;
  }

}

void yen_conversion(char convert_to,double quantity)
{
  const double yen_to_euro = 0.0078;
  const double yen_to_pound = 0.0066;


 switch(convert_to)
  {
  case'E': 
    std::cout << yen_to_euro * quantity << std::endl;
    break;
  case'P':
    std::cout << yen_to_pound * quantity << std::endl;
    break;
  default:
    std::cout << "Unrecognized symbol for converting to  " << convert_to << std::endl;
    break;
  }
}



int main()
{

  char convert_from = ' ';
  char convert_to = ' ';
  double quantity = 0.0;
 
  std::cout << "This is a Money conversion program the following currencies are available for conversion" << std::endl;
  std::cout << "Y for Yenn ,P for Pound and E for Euro" << std::endl;

  std::cout << "Please enter the currency to convet from" << std::endl;
  std::cin >> convert_from;
  

  std::cout << "Please enter the currency to convet to" << std::endl;
  std::cin >> convert_to;

  std::cout << "Please enter the quantity to be converted" << std::endl;
  std::cin >> quantity;
 
  std::cout << convert_from << " " << convert_to << std::endl;


 switch(convert_from)
  {
  case'Y': 
    yen_conversion(convert_to,quantity);
    break;
  case'P':
    pound_conversion(convert_to,quantity);
    break;
  case'E':
    euro_conversion(convert_to,quantity);
    break;
  default:
    std::cout << "Unrecognized symbol to convert from " << convert_from << std::endl;
    break;
  }
}
