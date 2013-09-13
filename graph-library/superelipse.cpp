#include <Simple_window.h>
#include <Graph.h>
#include <iostream>
#include <cmath>
#include <stdexcept>
const double PI = 3.14159265;

int sgn(double d) {

  if (d < 0)
    return -1;
  if (d == 0)
    return 0;
  if (d > 0)
    return 1;
  throw std::runtime_error("cannot determine sign");
}


int main()
{
  using namespace Graph_lib;
  Point tl(100,100);
  Simple_window win(tl,800,800,"Canvas");
  double n = 0.5;
  int a = 1;
  int b = 1;
  Closed_polyline p;
  p.set_color(Color::red);
  p.set_style(Line_style(Line_style::dash,4));
  for(double i = -1.0; i < 1.0; i+=0.01)
    {
      double ct = cos(i * PI);
      double st = sin(i * PI);
      int x =  a * sgn(ct) * pow(abs(ct),2.0f/n) * 100 ;
      int y =  b * sgn(st) * pow(abs(st),2.0f/n) * 100;
      std::cout << "x: " << x << '\n';
      std::cout << "y: " << y << '\n';
      p.add(Point(x+400,y+200)); // shift each point to be more in the center of the window
    }
  win.attach(p);
  win.wait_for_button();
}
