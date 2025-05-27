#include "Simple_window.h"
#include "Graph.h"
struct Box: Shape
{
public:
    Point centre;
    double width;
    double height;
    double R;
    Box(Point c, double l1, double l2)
    {
        centre = c;
        width = l2;
        height = l1;
        R = 1 / 10.0 * sqrt(l1 * l2);
    }
    void draw_lines()const
    {
        double centre_x = centre.x;
        double centre_y = centre.y;
        if (color().visibility())
        {
            Line(Point(centre_x + width / 2.0 - R, centre_y + height / 2.0), Point(centre_x - width / 2.0 + R, centre_y + height / 2.0)).draw();
            Line(Point(centre_x + width / 2.0 - R, centre_y - height / 2.0), Point(centre_x - width / 2.0 + R, centre_y - height / 2.0)).draw();
            Line(Point(centre_x + width / 2.0, centre_y - height / 2.0 + R), Point(centre_x + width / 2.0, centre_y + height / 2.0 - R)).draw();
            Line(Point(centre_x - width / 2.0, centre_y - height / 2.0 + R), Point(centre_x - width / 2.0, centre_y + height / 2.0 - R)).draw();
            Arc(Point(centre_x + width / 2.0 -R, centre_y + height / 2.0-R ), R, R, 270,360).draw();
            Arc(Point(centre_x + width / 2.0 - R, centre_y - height / 2.0 + R), R, R, 0, 90).draw();
            Arc(Point(centre_x - width / 2.0 + R, centre_y + height / 2.0 - R), R, R, 180, 270).draw();
            Arc(Point(centre_x - width / 2.0 + R, centre_y - height / 2.0 +R), R, R, 90, 180).draw();
        }
    }
    Box(Point c, double l1, double l2, double r)
    {
        centre = c;
        width = l2;
        height = l1;
        R = r;
    }
};
int main()
{
    Simple_window win(Point(100, 100), 500, 500, "Box");
    Box b(Point(200, 200), 100, 200);
    win.attach(b);
    win.wait_for_button();
    return 0;
}
