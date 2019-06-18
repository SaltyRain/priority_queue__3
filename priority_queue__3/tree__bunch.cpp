//
//  tree__bunch.cpp
//  priority_queue__3
//
//  Created by Тимур Гарипов on 17/04/2019.
//  Copyright © 2019 Timur. All rights reserved.
//

#include <iostream>

#include "tree__bunch.hpp"

#define ERROR -1
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

void tree:: swapElems(int el1, int el2)
{
    int temp = arr[el1];
    arr[el1] = arr[el2];
    arr[el2] = temp;

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
            swapElems(i, i/2-1);
            i = i/2-1;
        }
    }
}

bool tree:: check_CH_U(int i) const
{
    return ((arr[2*i +1] < arr[i] || arr[2*i +2] < arr[i]) && 2*i +2 < tail && i < tail);
    // левый сын меньше родителя или правый брат меньше родителя и родитель меньше последнего занятого и правый брат меньше последнего занятого
}

bool tree:: checkSwapLeft(int i) const
{
    return (arr[2*i+1] < arr[i] && arr[2*i+2] >= arr[2*i+1]);
    //если левый сын больше родителя и правый брат больше или равен левому сыну
}

bool tree:: checkSwapRight(int i) const
{
    return (arr[2*i+2] < arr[i] && arr[2*i+2] < arr[2*i+1]);
    //если правый брат меньше родителя и правый брат меньше левого сына
}


int tree:: deleteMin()
{
    if (tail != -1)
    {
        int min = arr[0];
        if (tail > 0) //если у нас больше одного эл-та
        {
            arr[0] = arr[tail]; //самый правый элемент на нижнем уровне переносится в корень
            tail = tail - 1; //удаляем элемент со старого уровня
            
            int i = 0;
            cout << "tail = " << tail << endl;
            if (tail == 1 && arr[0] > arr[tail]) //если в дереве 2 элемента и родитель больше сына
            {
                cout << "зашел в if" << endl;
                swapElems(0, tail);
                return min;
            }
            
            while (check_CH_U(i))
            {
                if (checkSwapLeft(i))
                {
                    swapElems(i, 2*i+1);
                    i = 2*i +1;
                }
                if (checkSwapRight(i))
                {
                    swapElems(i, 2*i + 2);
                    i = 2*i + 2;
                }
            }
            cout << "min = " << min << endl;
            return min;
        }
        tail--; //уменьшаем корень (ставим на -1)
        return min; //возвращаем корень
    }
    return ERROR;
}

void tree:: makenull()
{
    tail = -1;
}

void tree:: print() const
{
    for (int i=0; i < tail+1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
