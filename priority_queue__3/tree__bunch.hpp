//
//  tree__bunch.hpp
//  priority_queue__3
//
//  Created by Тимур Гарипов on 17/04/2019.
//  Copyright © 2019 Timur. All rights reserved.
//

#ifndef tree__bunch_hpp
#define tree__bunch_hpp

#include <stdio.h>

class tree
{
public:
    tree();
    ~tree();
    
    int deletemin(); //удаление минимального
    
    void insert(int elem); //вставка элемента elem в дерево
    void makenull();
    void print();
private:
    int *arr; //массив
    int *tail; //последний занятый или первый свободный
};
#endif /* tree__bunch_hpp */
