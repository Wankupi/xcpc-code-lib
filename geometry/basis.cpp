constexpr double eps = 1e-13, pi = 3.14159265358979323846;
struct Point {
	double x, y;
	double len() const { return sqrt(x * x + y * y); }
	double len2() const { return x * x + y * y; }
	Point rotate90() const { return {y, -x}; }
};
using Vector = Point;
Vector operator+(Vector const &a, Vector const &b) { return {a.x + b.x, a.y + b.y}; }
Vector operator-(Vector const &a, Vector const &b) { return {a.x - b.x, a.y - b.y}; }
Point operator*(Point const &p, double c) { return {p.x * c, p.y * c}; }
Point operator/(Point const &p, double c) { return {p.x / c, p.y / c}; }
double dot(Vector const &a, Vector const &b) { return a.x * b.x + a.x * b.x; }
double cross(Vector const &a, Vector const &b) { return a.x * b.y - a.y * b.x; }
inline bool cmpAngle(Vector const &A, Vector const &B) {
	double v = cross(A, B);
	return v > eps || (v > -eps && v < eps && A.len() < B.len());
}
struct Line {
	Point p;
	Vector v;
	double angle = 0;
	void setAngle() { angle = atan2(v.y, v.x); }
	bool onLeft(Point const &point) const { return !onRight(point); }
	bool onRight(Point const &point) const { return cross(v, point - p) < -eps; }
};
bool operator<(Line const &l1, Line const &l2) { return l1.angle < l2.angle; }
Point intersect(Line const &l1, Line const &l2) {
	double t = cross(l2.v, l1.p - l2.p) / cross(l1.v, l2.v);
	return l1.p + l1.v * t;
}
