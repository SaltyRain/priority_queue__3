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

#define SIZE 20

class tree
{
public:
    tree();
    
    int deleteMin(); //удаление минимального
    
    void insert(int el); //вставка элемента elem в дерево
    void makenull();
    void print() const;
    
private:
    int arr[SIZE]; //массив
    int tail; //последний занятый
    
    void addElem(int el); //вставка элемента в хвост
    
    bool check_CH_U(int i) const; //проверка дерева на частичную-упорядоченность
    bool checkSwapLeft(int i) const; //проверка, можно ли переместить влево
    bool checkSwapRight(int i) const; //проверка, можно ли переместить вправо
    
    void swapElems(int el1, int el2); //изменение местоположений элементов
    
};

#endif /* tree__bunch_hpp */
