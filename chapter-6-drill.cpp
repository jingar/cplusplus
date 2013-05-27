
//
// This is example code from Chapter 6.7 "Trying the second version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

/*
	This file is known as calculator02buggy.cpp

	I have inserted 5 errors that should cause this not to compile
	I have inserted 3 logic errors that should cause the program to give wrong results

	First try to find an remove the bugs without looking in the book.
	If that gets tedious, compare the code to that in the book (or posted source code)

	Happy hunting!

*/
#include <iostream>
#include <stdexcept>

void error(const std::string& s)
{
	throw std::runtime_error(s);
}

//------------------------------------------------------------------------------

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------
// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
:full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full=false;
        return buffer;
    }

    char ch;
    std::cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case '=':    // for "print"
    case 'x':    // for "quit"
    case '(': case ')': case '+': case '-': case '*': case '/':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '9':
        {
            std::cin.putback(ch);         // put digit back into the input stream
            double val;
            std::cin >> val;              // read a floating-point number
            return Token('8',val);   // let '8' represent "a number"
        }
    default:
        error("Bad token");
    }
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback()

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
    std::cout << "in primary \n";
    Token t = ts.get();
    std::cout << "Primary get Token-kind " << t.kind << "\n";
    std::cout << "Primary get Token-value " << t.value << "\n";
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
    case '8':            // we use '8' to represent a number
        return t.value;  // return the number's value
    default:
        error("primary expected");
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    std::cout << "in term \n";
    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while(true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break; // WAS MISSING BREAK;
        case '/':
            {
                double d = primary();
                if (d == 0) error("divide by zero");
                left /= d;
                t = ts.get();
                break;
            }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    std::cout << "in expression \n";
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    std::cout << "Expresion ->Term: " << left << "\n";
    std::cout << "Expresion ->Token-kind: " << t.kind << "\n";
    std::cout << "Expresion ->Token-value: " << t.value << "\n";
    while(true) {
        std::cout << "While Expression" << "\n";
        switch(t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left += term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

//------------------------------------------------------------------------------

int main()
try
{
    std::cout << "Welcome to our simple calculator.\n"
    << "Please enter expressions using floating-point numbers.\n";
    std::cout << "Operators available (), *, /, +, -, = (print answer), x (quit program)\n";
    double val = 0.0;
    while (std::cin) {
        Token t = ts.get();
        std::cout << "In while Token: " << t.kind << std::endl;
        std::cout << "in while Token: " << t.value << std::endl;
        if (t.kind == 'x')
        {
            std::cout << "Good Bye\n";
            break; // 'q' for quit
        }
        else if (t.kind == '=')
        {
            std::cout << "=" << val << '\n'; // '=' for "print now"
        }
        else
        {
            ts.putback(t);
            val = expression();
        }

    }
}
catch (std::exception& e) {
    std::cerr << "error: " << e.what() << '\n';
    return 1;
}
catch (...) {
    std::cerr << "Oops: unknown exception!\n";
    return 2;
}

//------------------------------------------------------------------------------
