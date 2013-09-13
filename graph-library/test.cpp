#include <Simple_window.h>
#include <Graph.h>

int main()
{
  using namespace Graph_lib;
  Simple_window win(Point(0,0),600,400,"Canvas");
  
  Rectangle rect(Point(200,200),100,50);
  rect.set_color(Color::blue);
  win.attach(rect);

  Polygon poly_rect;
  poly_rect.add(Point(400,200));
  poly_rect.add(Point(400,250));
  poly_rect.add(Point(500,250));
  poly_rect.add(Point(500,200));

  poly_rect.set_color(Color::red);
  win.attach(poly_rect);
  win.wait_for_button();

}
