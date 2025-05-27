#include "Simple_window.h"
#include "Graph.h"
using namespace Graph_lib;
int main() {

    Simple_window  win(Point(-200,-200), 1000, 1000, "Olympic");
    win.set_label("Olimpic");
    Circle c1(Point(240,200),120);
    c1.set_color(Color::blue);
    win.attach(c1);
    Circle c2(Point(760,200),120);
    c2.set_color(Color::red);
    win.attach(c2);
    Circle c3(Point(500,200),120);
    c3.set_color(Color::black);
    win.attach(c3);
    Circle c4(Point(370,290),120);
    c4.set_color(Color::yellow);
    win.attach(c4);
    Circle c5(Point(630,290),120);
    c5.set_color(Color::green);
    win.attach(c5);
    win.wait_for_button();
}
