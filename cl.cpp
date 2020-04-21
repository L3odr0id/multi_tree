#include <iostream>
#include <cl.h>

cl_base::cl_base(cl_base* m){
    name = m->getName();
    master = m->getMaster();
    ready = m->getReady();
}

cl_base* cl_base::getMaster(){
    return master;
}

string cl_base::getName(){
    return name;
}

int cl_base::getReady(){
    return ready;
}

void cl_base::add_slave(cl_base* new_ob){
    slaves.push_back(new_ob);
}

void cl_base::showTree(){
    coutIsReady();
    for (it_slave = slaves.begin();it_slave!=slaves.end();++it_slave)
        (*it_slave)->showTree();
}

void cl_base::coutIsReady(){
    if (master!=nullptr)
        cout<<endl;
    if (ready>0)
        cout<<"The object "<<name<<" is ready";
    else
        cout<<"The object "<<name<<" is not ready";
}

cl_base* cl_base::get_slave(string n){
    if (name == n)
        return this;

    for (it_slave = slaves.begin();it_slave!=slaves.end();++it_slave)
        if ((* it_slave)->getName() == n){
            return (* it_slave);
        }

    for (it_slave = slaves.begin();it_slave!=slaves.end();++it_slave){
        cl_base* tmp = (* it_slave)->get_slave(n);
        if (tmp!=nullptr)
            return tmp;
    }

    return nullptr;
}

void cl_base::delete_children(){
    for (it_slave = slaves.begin();it_slave!=slaves.end();++it_slave)
        delete (*it_slave);
}

void cl_base::kill_slave(string n){
    for (it_slave = slaves.begin();it_slave!=slaves.end();++it_slave)
        if ((* it_slave)->getName() == n){
            (*it_slave)->delete_children();
            delete (*it_slave);
        }
}

void cl_application::add_slave(string master,cl_base* cl){
    root->get_slave(master)->add_slave(cl);
}

void cl_application::build_tree(){
    string master;
    cin>>master;
    root = new cl_base(nullptr, master, 1);
    cin>>master;
    while(master!="0"){
        string slave;cin>>slave;
        int cl,ready;cin>>cl>>ready;
        if (cl == 2)
            add_slave(master, new cl_base2(root->get_slave(master), slave, ready));
        if (cl == 3)
            add_slave(master, new cl_base3(root->get_slave(master), slave, ready));
        if (cl == 4)
            add_slave(master, new cl_base4(root->get_slave(master), slave, ready));
        cin>>master;
    }
}

void cl_application::show_tree(){
    root->showTree();
}
