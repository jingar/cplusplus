#include "book.h"

Book::Book(std::string t,std::string a,std::string i,chrono::Date d,Book::Genre g)
  :title(t),author(a),ISBN(i),copy_right(d),genre(g),available(true)
{
  if(!is_valid_isbn(ISBN))
    {
      throw std::runtime_error("invalid isbn");
    }
  else if(!is_valid_author(author))
    {
      throw std::runtime_error("invalid author name");
    }
}
void Book::check_out()
{
  available = false;
}
void Book::check_in()
{
  available = false;
}
std::string Book::get_title() const
{
  return title;
}
std::string Book::get_author() const
{
  return author;
}

std::string Book::get_isbn() const
{
  return ISBN;
}

Book::Genre Book::get_genre() const
{
  return genre;
}
bool Book::is_available() const
{
  return available;
}

// ISBN must follow this format Integer-Integer-Integer-AlphaNumeric
bool Book::is_valid_isbn(const std::string& isbn) const
{
  int chunk = 0; //chunk reperesnts a an integer followed by a dash
  bool found_digit = false; // have we found atleast one digit before a dash
  //iterate through till the second last character ( last character is aplhanumeric)
  for(unsigned int i = 0; i < isbn.size()-1;++i)
    {
      if(isdigit(isbn[i]))
        {
          found_digit = true;
        }
      else if(isbn[i] == '-' && found_digit)
        {
          found_digit = false;
          ++chunk;
        }
      else if(isalpha(isbn[i]))
        {
          std::cout << "looking for chunk found letter \n";
          return false;
        }
    }

  if(chunk != 3)
    {
      std::cout << "need 3 chunks \n";
      return false;
    }

  //the last part must be a letter or digit and the second last part must be a dash
  if(!isalnum(isbn.back()) || isbn[isbn.size()-2] != '-')
    {
      std::cout << "last digit was not an alphanumber or second last digint was not a dash \n";
      return false;
    }
  return true;
}

//iterate though author name to make sure there are no numbers or punctuation excluding space and fullstop
bool Book::is_valid_author(const std::string& a) const
{
  for(unsigned int i = 0; i < a.size();++i)
    {
      if(a[i] == '.') // ignore the full stop
        {
          continue;
        }
      else if(isdigit(a[i]) || ispunct(a[i]))
        {
          return false;
        }
    }
  
  return true;
}


bool operator==(const Book& left,const Book& right)
{
  if(left.get_isbn() == right.get_isbn())
    {
      return true;
    }
  return false;
}

bool operator!=(const Book& left,const Book& right)
{
  return !(left == right);
}

std::ostream& operator<<(std::ostream& s,const Book::Genre right)
{
  std::string e;
  switch(right)
    {
    case Book::fiction:
      e = "fiction";
      break;
    case Book::nonfiction:
      e = "nonfiction";
      break;
    case Book::periodica1:
      e = "periodica1";
      break;
    case Book::biography:
      e = "biography";
      break;
    case Book::children:
      e = "children";
      break;
    default:
      throw std::runtime_error("trying to print unrecognized genre");
    }
    
  return s << e;
}

std::ostream& operator<<(std::ostream& s,const Book& book)
{
  s << "Book Title: " << book.get_title() << '\n'
    << "Book Author: " << book.get_author() << '\n'
    << "Book ISBN: " << book.get_isbn() << '\n'
    << "Book Availability: " << (book.is_available() == 0 ?"checked out":"available") << '\n'
    << "Book Genre: " << book.get_genre() << '\n';
    return s;
}

