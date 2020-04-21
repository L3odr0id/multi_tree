#ifndef CL_H
#define CL_H

#include <string>
#include <vector>
using namespace std;
class cl_base{
    string name="";
    cl_base* master = nullptr;
    vector<cl_base*> slaves;
    vector < cl_base * > :: iterator  it_slave;
    int ready;

    void delete_children();
public:
    cl_base(){}
    cl_base(cl_base* m);
    cl_base(cl_base* m, string n, int r):name(n),master(m), ready(r){}

    cl_base* getMaster();
    string getName();
    int getReady();

    void showTree();
    void coutIsReady();

    void add_slave(cl_base*);
    cl_base* get_slave(string n);
    void kill_slave(string n);
};

class cl_base2 : public cl_base{
public:
    cl_base2():cl_base(){}
    cl_base2(cl_base* m):cl_base(m){}
    cl_base2(cl_base* m, string n, int r):cl_base(m,n,r){}
};

class cl_base3 : public cl_base{
public:
    cl_base3():cl_base(){}
    cl_base3(cl_base* m):cl_base(m){}
    cl_base3(cl_base* m, string n, int r):cl_base(m,n,r){}
};

class cl_base4 : public cl_base{
public:
    cl_base4():cl_base(){}
    cl_base4(cl_base* m):cl_base(m){}
    cl_base4(cl_base* m, string n, int r):cl_base(m,n,r){}
};


class cl_application{
    cl_base* root;
    void add_slave(string, cl_base*);
public:
    void build_tree();
    void show_tree();
};

#endif // CL_H
