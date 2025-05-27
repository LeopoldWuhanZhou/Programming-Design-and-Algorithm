#include "Simple_window.h"
#include "Graph.h"
int main()
{
    double alpha = 0;
    Simple_window win(Point(100, 100), 500, 500, "Circle");
    while (1)
    {
        Circle c(Point(200, 200), 100);
        double delta = 1;
        Rectangle r(Point(195 + 100 * cos(alpha), 195 + 100 * sin(alpha)), 10, 10);
        r.set_fill_color(Color::black);
        win.attach(c);
        win.attach(r);
        if (win.wait_for_button() == 1)
        {
            alpha += delta;
        }
    }
}