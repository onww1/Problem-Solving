struct Geometry {
    struct Point {
        int x, y;
        Point(): Point(0, 0){}
        Point(int _x, int _y): x(_x), y(_y){}
    };

    struct Line {
        Point p, q;
        Line(){}
        Line(Point _p, Point _q): p(_p), q(_q){}
    };

    int ccw(Point a, Point b, Point c) {
        ll res = 1LL * (b.x - a.x) * (c.y - b.y) - 1LL * (b.y - a.y) * (c.x - b.x);
        if (res > 0)  // CCW
            return 1; 
        else if (res < 0)  // CW
            return -1; 
        else  // Line
            return 0; 
    }

    bool is_intersect(Line a, Line b) {
        int scope_a = ccw(a.p, a.q, b.p) * ccw(a.p, a.q, b.q);
        int scope_b = ccw(b.p, b.q, a.p) * ccw(b.p, b.q, a.q);
        if (scope_a > 0 || scope_b > 0) return false;
        if (min(a.p.x, a.q.x) > max(b.p.x, b.q.x) || min(b.p.x, b.q.x) > max(a.p.x, a.q.x) ||
            min(a.p.y, a.q.y) > max(b.p.y, a.q.y) || min(b.p.y, b.q.y) > max(a.p.y, a.q.y))
            return false;
        return true;
    }
};