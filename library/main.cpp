#include "library.h"
#include <iostream>




void initailize_books(Library& ls)
{
  // chrono::Date d(03,chrono::Date::feb,1993);
  // Book b("The great programmer","Saad Arif","2220-0000020-22222-A",d,Book::Genre::fiction);
  ls.add_book(Book("The great programmer","saad arif","01-02-12-A",chrono::Date(3,chrono::Date::feb,1993),Book::Genre::nonfiction));
  ls.add_book(Book("Philosphy of stupidity","fahad arif","433-22-232-A",chrono::Date(8,chrono::Date::may,1996),Book::Genre::fiction));
  
}

int main()
{
  try
    {
      Library ls;
      initailize_books(ls);
      return 0;
    }
  catch(std::runtime_error& e)
    {
      std::cerr << "runtime error: " << e.what() << '\n';
    }
}

