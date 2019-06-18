//
//  main.cpp
//  priority_queue__3
//
//  Created by Тимур Гарипов on 17/04/2019.
//  Copyright © 2019 Timur. All rights reserved.
//

#include <iostream>
#include <fstream>

#include "tree__bunch.hpp"


using namespace std;

void readTreeFromFile(const char *filename, tree& t)
{
    ifstream f;
    f.open(filename); //открываем файл
    if (!f.is_open()) //если не получилось открыть файл
    {
        cout << "Файл не открыт" << endl;
        f.close();
        return;
    }
    int x;
    while (!f.eof())
    {
        f >> x;
        t.insert(x);
    }
}
int main() {
    tree t;
    readTreeFromFile("tree.txt", t);
    t.print();
    
    t.deleteMin();
    t.print();
    t.deleteMin();
    t.print();
    t.deleteMin();
    t.print();
    t.deleteMin();
    t.print();
    t.deleteMin();
    t.print();
    t.deleteMin();
    t.print();
    
    
    t.makenull();
    t.print();
}
