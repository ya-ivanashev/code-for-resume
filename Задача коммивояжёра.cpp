#include <fstream>
#include <deque>
#include <math.h>
#include <vector>

using namespace std;

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int n;
    cin >> n;
    vector<pair<double, double>> coordinates;
    double x, y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        coordinates.push_back(make_pair(x, y));
    }

    vector<bool> used(n, false);
    deque <int> order;
    double ans = 0;


    order.push_back(0);
    used[0] = true;
    bool back = true;

    for (int i = 0; i < n - 1; ++i) {
        double min = -1;
        int v, last;
        if (back) {
            last = order[order.size() - 1];
        } else {
            last = order[0];
        }
        for (int j = 0; j < n; ++j) {
            if (!used[j]) {
                double dist = sqrt((coordinates[last].first - coordinates[j].first) * (coordinates[last].first - coordinates[j].first) + (coordinates[last].second - coordinates[j].second) * (coordinates[last].second - coordinates[j].second));
                if (min == -1 || dist < min) {
                    min = dist;
                    v = j;
                }
            }
        }
        if (back) {
            order.push_back(v);
        } else {
            order.push_front(v);
        }
        used[v] = true;
        ans += min;
        back = !back;
    }
    ans += sqrt((coordinates[order[0]].first - coordinates[order[n - 1]].first) * (coordinates[order[0]].first - coordinates[order[n - 1]].first) + (coordinates[order[0]].second - coordinates[order[n - 1]].second) * (coordinates[order[0]].second - coordinates[order[n - 1]].second));
    
    cout << ans << endl;
    for (int i = 0; i < n; ++i) {
        cout << order[i] + 1 << ' '; 
    }

    cout.close();
}

