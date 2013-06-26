/*
  calculator08buggy.cpp
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <stdexcept>
#include <cctype>


void error(const std::string& s)
{
  throw std::runtime_error(s);
}

void error(const std::string& s, const std::string& s2)
{
  error(s+s2);
}

struct Token {
  char kind;
  double value;
  std::string name;
  Token(char ch) :kind(ch), value(0) { }
  Token(char ch, double val) :kind(ch), value(val) { }
  Token(char ch,std::string s)
    : kind(ch),value(0),name(s){}
};

class Token_stream {
  bool full;
  Token buffer;
public:
  Token_stream() :full(0), buffer(0) { }

  Token get();
  void unget(Token t) { buffer=t; full=true; }
  void print_buffer();
  void ignore(char);
};

const char let = 'L';
const char var_constant = 'C';
const char quit = 'Q';
const char print = '\n';
const char number = '8';
const char name = 'a';
const char function = 'f';
std::vector<Token> function_names;

bool is_declared_function(std::string function_name)
{
  for(unsigned int i = 0; i < function_names.size(); ++i)
    {
      if(function_names[i].name == function_name)
        {
          return true;
        }
    }
  return false;
}
void define_function(std::string name)
{
  if(!is_declared_function(name))
    {
      function_names.push_back(Token(function,name));
      return;
    }
  error(name," is already a declared function");
}


Token function_or_variable(std::string s)
{
  if(is_declared_function(s))
    {
      
      std::cout << "function or variable is declared";
      return Token(function,s);
    }
  std::cout << "function or variable is name \n";
  return Token(name,s);
}

Token Token_stream::get()
{
  if (full) 
    { 
      full=false; 
      return buffer; 
    }
  char ch;
  std::cin.get(ch);
  if(ch == ' ')
    {
      while(ch == ' ')
        {
          std::cin.get(ch);
        }
    }
  switch (ch){
  case quit:
  case '(':
  case ')':
  case ',':
  case '+':
  case '-':
  case '*':
  case '/':
  case '%':
  case print:
  case '=':
    std::cout << "get token ch: " << ch << '\n';
    return Token(ch);
  case '.':
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
    {	
      std::cin.unget();
      double val;
      std::cin >> val;
      return Token(number,val);
	}
  default:
    if (isalpha(ch)){
      std::string s;
      s += ch;
      while(std::cin.get(ch) && !isspace(ch) && ch != '\n' && (isalpha(ch) || isdigit(ch) || ch == '_'))
        {
          s+=ch;
          std::cout << "STRING----: " << s << '\n';
        }

      std::cin.unget();
      if (s == "let")
        {
          return Token(let);	
        }
      else if(s == "const")
        {
          return Token(var_constant);	
        }
      std::cout << "function or variable " << s << '\n';
      return function_or_variable(s);
    }
    error("Bad token");
  }
}

void Token_stream::ignore(char c)
{
  std::cout << "c: " << (int)c << '\n';
  if (full && c==buffer.kind) {
    full = false;
    return;
  }
  full = false;
  char ch;
  while (std::cin.get(ch))
    {
      std::cout << "ignore ch: " << (int)ch << '\n';
      if (ch==c)
        {
          std::cout << "return \n";
          return;
        }
    }
}

struct Variable {
  std::string name;
  double value;
  bool constant;
  Variable(std::string n, double v,bool c) 
    : name(n), value(v), constant(c) { }
};

class Symbol_table
{
private:
  std::vector<Variable> names; 
public:
  double get_value(std::string name);
  void set_value(std::string name, double value);
  bool is_const_value(std::string name);
  bool is_declared(std::string );
  void define_name(std::string name ,double value, bool constant);
  void add_variable(Variable v);
};

double Symbol_table::get_value(std::string s)
{
  for (int i = 0; i<names.size(); ++i)
    {
      if (names[i].name == s)
        {
          return names[i].value;
        }
    }
  error("get: undefined name ",s);
}

void Symbol_table::set_value(std::string s, double d)
{
  for (int i = 0; i<=names.size(); ++i)
    if (names[i].name == s) {
      names[i].value = d;
      return;
    }
  error("set: undefined name ",s);
}

bool Symbol_table::is_const_value(std::string s)
{
  for (int i = 0; i<names.size(); ++i)
    {
      if (names[i].name == s)
        {
          return names[i].constant;
        }
    }
  error("get: undefined name ",s);
}


bool Symbol_table::is_declared(std::string s)
{
  for (int i = 0; i<names.size(); ++i)
    if (names[i].name == s) return true;
  return false;
}


void Symbol_table::define_name(std::string name , double value, bool constant)
{
  if(!is_declared(name))
    {
      names.push_back(Variable(name,value,constant));
      return;
    }
  error(name," is already a declared variable");
}

void Symbol_table::add_variable(Variable v)
{
  names.push_back(v);
}
Symbol_table symbol_table;

double expression(Token_stream& ts);

std::vector<int> handle_arguments(Token_stream& ts)
{
  std::vector<int> args;

  while(true)
    {
      Token t = ts.get();
      if(t.kind == ')')
        {
          ts.unget(t);
          break;
        }
      else if (t.kind == ',')
        {
          continue;
        }
      ts.unget(t);
      double exp = expression(ts);
      args.push_back(exp);
    }
  return args;
}


double fun_sqrt(std::vector<int> args)
{
  if(args[0] <= -1)
    {
      error("sqrt arguments cannot be negative");
    }
  return sqrt(args[0]);
}

double fun_pow(std::vector<int> args)
{
  return pow(args[0],args[1]);
}
double run_function(std::string s,Token_stream& ts)
{
  //handle arguments
  std::vector<int> args = handle_arguments(ts);
  //check if its a function we know
  if(s == "sqrt")
    {
      return fun_sqrt(args);
    }
  else if(s == "pow")
    {
      return fun_pow(args);
    }
  error(s, " is not a declared function");
   
}
double parse_function(std::string s,Token_stream& ts)
{ 
  std::vector<int> args;
  double result;
  // error handling for left bracket
  Token left_brace = ts.get();
  if(!left_brace.kind == '(')
    {
      error(s, " function is missing: (");
    }
  // actually run the function then get the result
  result  = run_function(s,ts);
  // error handling for right bracket
  Token right_brace = ts.get();
  if(!right_brace.kind == ')')
    {
      error(s," function is missing: )");
    }
  return result;
}

double primary(Token_stream& ts)
{
  std::cout << "in primary\n";
  Token t = ts.get();
  switch (t.kind) {
  case '(':
	{	
      double d = expression(ts);
      t = ts.get();
      if (t.kind != ')') error("'(' expected");
      return d;
	}
  case '-':
    return - primary(ts);
  case number:
    return t.value;
  case name:
    {
      Token n = ts.get();
      if(n.kind == '=')
        {
          if(symbol_table.is_const_value(t.name))
            {
              error(t.name," is a constant value, it cannot be reassigned");
            }
          double d = expression(ts);
          symbol_table.set_value(t.name,d);
          return d;
        }
      ts.unget(n);
      return symbol_table.get_value(t.name);
    }
  case function:
    return parse_function(t.name,ts);
  default:
    error("primary expected near " + t.kind);
  }
}

double term(Token_stream& ts)
{
  std::cout << "in term \n";
  double left = primary(ts);
  while(true) {
    Token t = ts.get();
    switch(t.kind) {
    case '*':
      left *= primary(ts);
      break;
    case '/':
      {	double d = primary(ts);
        if (d == 0) error("divide by zero");
        left /= d;
        break;
      }
    default:
      ts.unget(t);
      return left;
    }
  }
}

double expression(Token_stream& ts)
{
  std::cout << "in expression \n";
  double left = term(ts);
  while(true) {
    Token t = ts.get();
    switch(t.kind) {
    case '+':
      left += term(ts);
      break;
    case '-':
      left -= term(ts);
      break;
    default:
      ts.unget(t);
      return left;
    }
  }
}


double declaration(bool var_status,Token_stream& ts)
{
  Token t = ts.get();
  if (t.kind != 'a')
    {
      error ("name expected in declaration");
    }
  std::string name = t.name;
  std::cout << "declaration name : " << t.name << '\n';
  if (symbol_table.is_declared(name))
    { 
      error(name, " declared twice");
    }
  Token t2 = ts.get();
  if (t2.kind != '=')
    {
      error("= missing in declaration of " ,name);
    }
  double d = expression(ts);
  symbol_table.add_variable(Variable(name,d,var_status));
  return d;
}

double statement(Token_stream& ts)
{
  std::cout << "in statement \n";
  Token t = ts.get();
  switch(t.kind) 
    {
    case let:
      return declaration(false,ts);// if let then it is not a constant
    case var_constant:
      return declaration(true,ts); // otherwise it is a constant
    default:
      ts.unget(t);
      return expression(ts);
  }
}


void clean_up_mess(Token_stream& ts)
{
  ts.ignore(print);
}

const std::string prompt = "> ";
const std::string result = "= ";

void calculate()
{
  Token_stream ts;
  while(true) try {
      std::cout << "calculate while \n";
      std::cout << prompt;
      Token t = ts.get();
      while (t.kind == print)
        {
          t=ts.get();
          std::cout << "calculate while print\n";
        }
      if (t.kind == quit)
        {
          return;
        }
      ts.unget(t);
      std::cout << "calculate after unget, t.kind " << t.kind  << '\n';
      std::cout << result << statement(ts) << std::endl;
      std::cout << "calculate after statement" << '\n';
	}
    catch(std::runtime_error& e) {
      std::cerr << e.what() << std::endl;
      clean_up_mess(ts);
	}
}



int main()
{
  try {
    define_function("sqrt");
    define_function("pow");
    symbol_table.define_name("k",100,true); 
    symbol_table.define_name("pi",3.143,true);
    calculate();
    return 0;
  }
  catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
    char c;
    while (std::cin >>c&& c!=';') ;
    return 1;
  }
  catch (...) {
    std::cerr << "exception\n";
    char c;
    while (std::cin>>c && c!=';');
    return 2;
  }
}
