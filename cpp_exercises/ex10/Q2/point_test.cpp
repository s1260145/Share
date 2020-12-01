#include<iostream>
#include<unordered_set>
#include<fstream>

using namespace std;

struct Point
{
    int x, y;
};


struct ptohash
{
    size_t operator()(const Point& p) const
    {
        hash<int> hs;
        return hs(p.x) ^ hs(p.y);
    }
};

struct point_equal {
    bool operator()(const Point& p1, const Point& p2) const
    {
        return (p1.x==p2.x) && (p1.y==p2.y);
    }
};



int main(void) {
    // define the hash set for storing the point
    unordered_set<Point, ptohash, point_equal> table;

    ifstream in("points_list.txt");
    cout << "Reading points from file" << endl;
    while (!in.eof()) {
        int x, y;
        in >> x >> y;
        
        Point p{x,y};
        table.insert(p);
    }
    cout << "Points read from file. Now enter some query point." << endl;

    while (cin) {
        int x, y;
        cin >> x >> y;
        Point p{x,y};

        // check if p is in the table, 
        // if it is print "point found"
        // otherwise print "not found"
        auto itr = table.find(p);
        if(itr == table.end()) cout << "not found" << endl;
        else cout << "point found" << endl;
        
    }

}