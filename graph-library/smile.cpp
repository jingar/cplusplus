#include <Simple_window.h>
#include <Graph.h>
using namespace Graph_lib;

class Smiley: public Circle 
{
  Smiley(Point p, int rr);    // center and radius

  void draw_lines() const;

  Point center() const ; 
  int radius() const { return r; }
  void set_radius(int rr) { r=rr; }
private:
  int r;
};


int main()
{
  // Point tl(100,100);
  // Simple_window win(tl,600,400,"Canvas");

  // win.attach();

  // win.wait_for_button();
}
