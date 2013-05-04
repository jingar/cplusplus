#include <iostream>
#include <cstring>

int main()
{
  const double yen_to_euro = 0.0078;
  const double yen_to_pound = 0.0066;
  const double pound_to_yen = 152.12;
  const double pound_to_euro = 1.1866;
  const double euro_to_pound = 0.8411;
  const double euro_to_yen = 129.04;
  std::string convert_from = "";
  std::string convert_to = "";
  double quantity = 0.0;


 
  std::cout << "This is a Money conversion program the following currencies are available for conversion" << std::endl;
  std::cout << "Yen ,Pound and Euro" << std::endl;

  std::cout << "Please enter the currency to convet from" << std::endl;
  std::cin >> convert_from;
  

  std::cout << "Please enter the currency to convet to" << std::endl;
  std::cin >> convert_to;

  std::cout << "Please enter the quantity to be converted" << std::endl;
  std::cin >> quantity;
  

  std::cout << convert_from << " " << convert_to << std::endl;
  
 
  if((convert_from == "Yen") && (convert_to == "Pound"))
    {
      std::cout << quantity * yen_to_pound << std::endl;
    }
  else if((convert_from == "Yen") && (convert_to == "Euro"))
    {
      std::cout << quantity * yen_to_euro << std::endl;
    }
  else if((convert_from == "Pound") && (convert_to == "Yen"))
    {
      std::cout << quantity * pound_to_yen << std::endl;
    }
  else if((convert_from == "Pound") && (convert_to == "Euro"))
    {
      std::cout << quantity * pound_to_euro << std::endl;
    }
  else if((convert_from == "Euro") && (convert_to == "Pound"))
    {
      std::cout << quantity * euro_to_pound << std::endl;
    }
  else if((convert_from == "Euro") && (convert_to == "Yen"))
    {
      std::cout << quantity * euro_to_yen << std::endl;
    }
  else
    {
      std::cout << "Inputs not recognized" << std::endl;
    }




}
