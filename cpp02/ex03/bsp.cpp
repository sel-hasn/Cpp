#include "Point.hpp"

bool check_for_point_side(Point const a, Point const b, Point const c, Point const p)
{
    if (a.get_x() != b.get_x()){
        Fixed alpha;
        Fixed beta;
        bool  point_is_up;
	
        alpha = (a.get_y() - b.get_y()) / (a.get_x() - b.get_x());
        beta = a.get_y() - (alpha * a.get_x());

        point_is_up = false;
        if (c.get_y() > (alpha * c.get_x()) + beta)
            point_is_up = true;

        if (point_is_up && (p.get_y() > (alpha * p.get_x()) + beta))
            return (true);

        if (!point_is_up && (p.get_y() < (alpha * p.get_x()) + beta))
            return (true);
    }
    else {
        bool  point_is_right;

        point_is_right = false;
        if (c.get_x() > a.get_x())
            point_is_right = true;

        if (point_is_right && p.get_x() > a.get_x())
            return (true);

        if (!point_is_right && p.get_x() < a.get_x())
            return (true);
    }

    return (false);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	bool ab;
	bool bc;
	bool ac;

	ab = check_for_point_side(a, b, c, point);
	bc = check_for_point_side(b, c, a, point);
	ac = check_for_point_side(a, c, b, point);
	return ab && bc && ac;
}