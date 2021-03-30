#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, m;
vector<pii> roombas, cords;
bool cmp(pii a, pii b) {
    return a.second < b.second;
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int maX = -1, maY = -1;
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y; roombas.push_back({x, y});
        maX = max(maX, x);
    }
    int intersect = 0;
    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y; cords.push_back({x, y});
        maY = max(maY, y);
    }
    sort(roombas.begin(), roombas.end(), cmp);
    sort(cords.begin(), cords.end());
    for (int i = 0; i < n; i++) {
        if (roombas[i].second > maY) {
            roombas.resize(i);
            break;
        }
    }
    for (int i = 0; i < m; i++) {
        if (cords[i].first > maX) {
            cords.resize(i);
            break;
        }
    }
    for (pii u : roombas) {
        for (pii v : cords) {
            if (u.second <= v.second && v.first <= u.first) {
                intersect++;
            }
        }
    }
    cout << intersect << '\n';
}
/*
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef pair<int, int> pii;
const int mm = 1e9 + 5;
struct node {
    pii k;
    node *l, *r;
    int h;
};
int height(node *n) {
    if (n == NULL) {
        return 0;
    }
    return n->h;
}
node* create(pii k) {
    node* node;
    node->k = k;
    node->l = NULL;
    node->r = NULL;
    node->h = 1;
    return node;
}
node *rRotate(node *y) {
    node *x = y->l;
    node *t = x->r;
    x-> r = y; y->l = t;
    y->h = max(height(y->l), height(y->r)) + 1;
    x->h = max(height(x->l), height(x->r)) + 1;
    return x;
}
node *lRotate(node *x) {
    node *y = x->r;
    node *t = y->l;
    y->l = x; x->r = t;
    x->h = max(height(x->l), height(x->r)) + 1;
    y->h = max(height(y->l), height(y->r)) + 1;
    return y;
}
int bal(node *n) {
    if(n == NULL) {
        return 0;
    }
    return height(n->l) - height(n->r);
}
node* insert(node* node, pii k) {
    if (node == NULL) {
        return create(k);
    }
    if(k < node-> k) {
        node->l = insert(node->l, k);
    } else if (k > node->k) {
        node->r = insert(node->r, k);
    } else {
        return node;
    }
    node->h = 1 + max(height(node->l), height(node->r));
    int balance = bal(node);
    if(balance > 1 && k < node->l->k) {
        return rRotate(node);
    } 
    if(balance < -1 && k > node->r->k) {
        return lRotate(node);
    }
    if(balance > 1 && k > node->l->k) {
        node->l = lRotate(node->l);
        return rRotate(node);
    }
    if(balance < -1 && k < node->l->k) {
        node->r = rRotate(node->r);
        return lRotate(node);
    }
    return node;
}
node *minValueNode(node* nn) {
    node* curr = nn;
    while(curr->l != NULL) {
        curr = curr->l;
    }
    return curr;
}
node* del(node* r, pii k) {
    if(r = NULL) {
        return r;
    }
    if(k < r->k) {
        r->l = del(r->l, k);
    } else if(k > r->k) {
        r->r = del(r->r, k);
    } else {
        if((r->l == NULL) || (r->r == NULL)) {
            node *temp = r->l ? r->l : r->r;
            if(temp == NULL) {
                temp = r;
                r = NULL;
            } else {
                *r = *temp;
                free(temp);
            }
        } else {
            node* temp = minValueNode(r->r);
            r->k = temp->k;
            r->r = del(r->r, temp->k);
        }
    }
    if (r == NULL) {
        return r;
    }
    r->h = 1 + max(height(r->l), height(r->r));
    int balance = bal(r);
    if(balance > 1 && bal(r->l) >= 0) {
        return rRotate(r);
    } 
    if(balance > 1 && bal(r->l) < 0) {
        r->l = lRotate(r->l);
        return rRotate(r);
    }
    if(balance < -1 && bal(r->r) <= 0) {
        return lRotate(r);
    }
    if(balance < -1 && bal(r->r) > 0) {
        r->r = rRotate(r->r);
        return lRotate(r);
    }
    return r;
}
int n, m;
vector<pii> p;
short grid[mm][mm], abc[mm][mm];
bool cmp(pii a, pii b) {
    return a.x < b.x;
}
bool intersects(pii a, pii b) {
    
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int count = 1;
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y; p.push_back({x, y}); p.push_back({0, y});
        grid[0][y] = 1; grid[x][y] = 2;
        abc[0][y] = count; abc[x][y] = count; count++;
    }
    int intersect = 0;
    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y; p.push_back({x, y}); p.push_back({x, 0});
        grid[x][0] = 1; grid[x][y] = 2;
        abc[x][0] = count; abc[x][y] = count; count++;
    }
    sort(p.begin(), p.end(), cmp);
    node *t;
    for (int i = 0; i < 2*(n + m); i++) {
        pii u = p[i];
        if(grid[u.x][u.y] == 1) {
            t = insert(t, u);
            if(intersects(u, t->l->k) || intersects(u, t->r->k)) {
                intersect++;
            }
        } else {
            while(true) {

            }
            if (intersects(t->k, t->l->k) || intersects(t->k, t->r->k)) {

            }
            t = del(t, u);
        }
    }
}
*/