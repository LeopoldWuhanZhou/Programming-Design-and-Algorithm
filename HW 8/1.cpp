#include "Simple_window.h"
#include "Graph.h"
using namespace Graph_lib;
int main() {

    Simple_window  win(Point(100, 100), 400, 400, "Chess board");
    win.set_label("Chessboard");

    Rectangle r1(Point(150,150), 50, 50);
    r1.set_color(Color::red);
    win.attach(r1);
    Rectangle r2(Point(201,150), 50, 50);
    r2.set_color(Color::white);
    win.attach(r2);
    Rectangle r3(Point(252,150), 50, 50);
    r3.set_color(Color::red);
    win.attach(r3);
    Rectangle r4(Point(150,201), 50, 50);
    r4.set_color(Color::white);
    win.attach(r4);
    Rectangle r5(Point(201,201), 50, 50);
    r5.set_color(Color::red);
    win.attach(r5);
    Rectangle r6(Point(252,201), 50, 50);
    r6.set_color(Color::white);
    win.attach(r6);
    Rectangle r7(Point(150,252), 50, 50);
    r7.set_color(Color::red);
    win.attach(r7);
    Rectangle r8(Point(201,252), 50, 50);
    r8.set_color(Color::white);
    win.attach(r8);
    Rectangle r9(Point(252,252), 50, 50);
    r9.set_color(Color::red);
    win.attach(r9);
    win.wait_for_button();
}

