#include <string>
class Patron
{
 public:
  Patron(std::string username,int library_number);
  void set_fee(int fee);
  bool has_fee() const;
  int amount_fees_owed() const;
  std::string get_username() const;
 private:
  std::string username;
  int library_number;
  bool owes_fee;
  int fees_owed;
};

bool operator==(const Patron& left, const Patron& right);
