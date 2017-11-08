#include <bits/stdc++.h>

using namespace std;

struct point{
    float x;
    float y;
};

float direction(point, point, point);
bool on(point, point, point);
void kaamka(point []);

int main()
{ 
  int n, ct = 0;
  cout << "\nNumber of lines: ";
  cin >> n;
  vector< pair <point, point> > p(n);
  cout << "\nEnter the lines: ";
  for(int i = 0; i < n; i++)
  {
      cout << "\nLine " << i+1 << ": ";
      cout << "Point A: ";
      cin >> p[i].first.x >> p[i].first.y;
      cout << "\tPoint B: ";
      cin >> p[i].second.x >> p[i].second.y;
  }
  //function here
  point a[4];
  cout << endl << "Line 1 \t\t Line 2 \n";
  for(int i = 0; i < n-1; i++)
  {
      for(int j = i+1; j < n; j++)
      {
          a[0] = p[i].first;
          a[1] = p[i].second;
          a[2] = p[j].first;
          a[3] = p[j].second;
          cout << a[0].x << ' ' << a[0].y << "; " <<a[1].x << ' ' << a[1].y << "\t" << a[2].x << ' ' << a[2].y << "; " << a[3].x << " " << a[3].y << " ";
          kaamka(a);
          ct++;
      }
  }
  //cout << endl << ct;
  return 0;
}

float direction(point p0, point p1, point p2)
{
    return (p1.x-p0.x)*(p2.y-p0.y) - (p2.x-p0.x)*(p1.y-p0.y);
}

bool on(point pi, point pj, point pk)
{
    if(min(pi.x, pj.x) <= pk.x && pk.x <= max(pi.x, pj.x) && min(pj.y, pi.y) <= pk.y && pk.y <= max(pj.y, pi.y))
        return true;
    return false;
}

void kaamka(point p[4])
{
    float d[4];
    d[0] = direction(p[2], p[3], p[0]);
    d[1] = direction(p[2], p[3], p[1]);
    d[2] = direction(p[0], p[1], p[2]);
    d[3] = direction(p[0], p[1], p[3]);
  
    if (((d[0] > 0 && d[1] < 0) || (d[0] < 0 && d[1] > 0)) && ((d[2] > 0 && d[3] < 0) || (d[2] < 0 && d[3] > 0)))
        puts("Intersects");
        
    else if (d[0] == 0 && on(p[2], p[3], p[0]))
        puts("Intersects");
    else if (d[1] == 0 && on(p[2], p[3], p[1]))
        puts("Intersects");
    else if (d[2] == 0 && on(p[0], p[1], p[2]))
        puts("Intersects");
    else if (d[3] == 0 && on(p[0], p[1], p[3]))
        puts("Intersects");
    else
        puts("Does not intersect");
}
