class segmentTree {
public:
    vector<int> nodes, lazy;
    int size;

    segmentTree(int n) {
        nodes.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        size = n;
    }

    void push(int start, int end, int node) {
        if (lazy[node]) {
            nodes[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int l, int r, int val, int start, int end, int node) {
        push(start, end, node);
        if (start > r || end < l)
            return;
        if (start >= l && end <= r) {
            lazy[node] += val;
            push(start, end, node);
            return;
        }
        int mid = (start + end) / 2;
        update(l, r, val, start, mid, 2 * node + 1);
        update(l, r, val, mid + 1, end, 2 * node + 2);
        nodes[node] = nodes[2 * node + 1] + nodes[2 * node + 2];
    }

    int query(int l, int r, int start, int end, int node) {
        push(start, end, node);
        if (start > r || end < l)
            return 0;
        if (start >= l && end <= r)
            return nodes[node];
        int mid = (start + end) / 2;
        return query(l, r, start, mid, 2 * node + 1) +
               query(l, r, mid + 1, end, 2 * node + 2);
    }

    int pointQuery(int index, int start, int end, int node) {
        push(start, end, node);
        if (start == end)
            return nodes[node];
        int mid = (start + end) / 2;
        if (index <= mid)
            return pointQuery(index, start, mid, 2 * node + 1);
        else
            return pointQuery(index, mid + 1, end, 2 * node + 2);
    }
};

class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(),
             [](auto& a, auto& b) { return a[1] < b[1]; });

        segmentTree seg(2001);

        for (auto& task : tasks) {
            int l = task[0], r = task[1], t = task[2];
            int have = seg.query(l, r, 0, 2000, 0);

            int need = t - have;

            for (int i = r; i >= l && need > 0; --i) {
                if (seg.pointQuery(i, 0, 2000, 0) == 0) {
                    seg.update(i, i, 1, 0, 2000, 0);
                    --need;
                }
            }
        }

        return seg.query(0, 2000, 0, 2000, 0);
    }
};