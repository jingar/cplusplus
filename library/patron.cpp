#include "patron.h"
Patron::Patron(std::string un,int ln)
  :username(un),library_number(ln),owes_fee(false),fees_owed(0)
{

}
void Patron::set_fee(int fee)
{
  if(fee == 0)
    {
      owes_fee = false;
    }
  fees_owed = fee;
}
bool Patron::has_fee() const
{
  return owes_fee;
}

std::string Patron::get_username() const
{
  return username;
}
int Patron::amount_fees_owed() const
{
  return fees_owed;
}

bool operator==(const Patron& left, const Patron& right)
{
  if(left.get_username() == right.get_username())
    {
      return true;
    }
  return false;
}
