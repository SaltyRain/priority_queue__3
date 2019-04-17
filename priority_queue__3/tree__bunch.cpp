//
//  tree__bunch.cpp
//  priority_queue__3
//
//  Created by Тимур Гарипов on 17/04/2019.
//  Copyright © 2019 Timur. All rights reserved.
//

#include <iostream>

#include "tree__bunch.hpp"

using namespace std;

tree:: tree()
{
    tail = -1;
}

void tree:: addElem(int el)
{
    tail = tail + 1;
    arr[tail] = el;
}

void tree:: insert(int el)
{
    addElem(el);
    if (tail != 0) //если вставили не в корень
    {
        int i = tail;
        //смещения
        while (arr[i] <= arr[i/2-1] && i != 0) //пока узел меньше родителя и пока узел не стал корнем
        {
            int temp = arr[i];
            arr[i] = arr[i/2-1];
            arr[i/2-1] = temp;
            i = i/2-1;
        }
    }
}

int tree:: deleteMin()
{
    return 0;
}

void tree:: makenull()
{
    
}

void tree:: print() const
{
    for (int i=0; i < tail+1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
