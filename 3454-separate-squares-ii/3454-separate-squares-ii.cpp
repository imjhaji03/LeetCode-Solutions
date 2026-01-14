class Solution {
public:
    struct Event {
        double y;
        int type;
        int x1, x2;
    };

    vector<int> cover;
    vector<double> coveredLen;
    vector<int> xs;

    void update(int node, int l, int r, int ql, int qr, int val) {
        if (qr <= l || r <= ql) return;

        if (ql <= l && r <= qr) {
            cover[node] += val;
        } else {
            int mid = (l + r) / 2;
            update(node * 2, l, mid, ql, qr, val);
            update(node * 2 + 1, mid, r, ql, qr, val);
        }

        if (cover[node] > 0) {
            coveredLen[node] = xs[r] - xs[l];
        } else if (r - l == 1) {
            coveredLen[node] = 0.0;
        } else {
            coveredLen[node] = coveredLen[node * 2] + coveredLen[node * 2 + 1];
        }
    }

    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;
        set<int> xset;

        for (auto &s : squares) {
            int x = s[0], y = s[1], len = s[2];
            events.push_back({(double)y, 1, x, x + len});
            events.push_back({(double)y + len, -1, x, x + len});
            xset.insert(x);
            xset.insert(x + len);
        }

        xs.assign(xset.begin(), xset.end());
        int n = xs.size();

        sort(events.begin(), events.end(),
             [](const Event& a, const Event& b) { return a.y < b.y; });

        cover.assign(4 * n, 0);
        coveredLen.assign(4 * n, 0.0);

        double totalArea = 0.0;
        double prevY = events[0].y;
        vector<array<double, 3>> strips;

        int i = 0;
        while (i < events.size()) {
            double currY = events[i].y;

            if (currY > prevY) {
                double h = currY - prevY;
                double w = coveredLen[1];
                totalArea += w * h;
                strips.push_back({prevY, currY, w});
                prevY = currY;
            }

            while (i < events.size() && events[i].y == currY) {
                int l = lower_bound(xs.begin(), xs.end(), events[i].x1) - xs.begin();
                int r = lower_bound(xs.begin(), xs.end(), events[i].x2) - xs.begin();
                update(1, 0, n, l, r, events[i].type);
                i++;
            }
        }

        double half = totalArea / 2.0;
        double acc = 0.0;

        for (auto &s : strips) {
            double y1 = s[0], y2 = s[1], w = s[2];
            double area = w * (y2 - y1);
            if (acc + area >= half) {
                return y1 + (half - acc) / w;
            }
            acc += area;
        }

        return prevY;
    }
};
