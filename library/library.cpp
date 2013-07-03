#include "library.h"
#include <algorithm>
Library::Library()
  :books(),patrons(),transactions()
{

}

bool Library::book_exists(const Book& b) const
{
  if(std::find(books.begin(), books.end(), b)!=books.end())
    {
      return true;
    }
  return false;
}
bool Library::patron_exists(const Patron& p) const
{
  if(std::find(patrons.begin(), patrons.end(), p)!=patrons.end())
    {
      return true;
    }
  return false;
}


void Library::add_book(Book b)
{  
  if(book_exists(b))
    {
      throw std::runtime_error("already have that book inserted");
    }
  books.push_back(b);
}



void Library::add_patron(Patron p)
{
  if(patron_exists(p))
    {
      throw std::runtime_error("already have that book inserted");
    }
  patrons.push_back(p);
}

void Library::check_out_book(const chrono::Date& d,const Patron& p,Book& b)
{
  if(!book_exists(b) || !patron_exists(p))
    {
      throw std::runtime_error("patron or book doesnt exist");
    }

  if(p.has_fee())
    {
      throw std::runtime_error("patron has a fee: " + p.amount_fees_owed());
    }

  transactions.push_back(Transactions(d,p,b));
  b.check_out();
}

void Library::return_book(Book& b,const Patron& p)
{
  if(!book_exists(b) || !patron_exists(p))
    {
      throw std::runtime_error("patron or book doesnt exist");
    }
  b.check_in();
}
