#include <iostream>
#include "stdio.h"
#include "data_structures.h"

using namespace DataStructure;
int main() {
    // " construtor" do array - Stack Memory  - C - Alocação estática
    struct Array arr;
    arr.size=20;
    arr.length=0;
    arr.A=(int *)malloc(sizeof(int)*arr.size);
    // " construtor" do array - Heap Memory  - C - Alocação Dinâmica
    struct Array *p_arr=(struct Array *)malloc(sizeof(struct Array));
    p_arr->size=20;
    p_arr->length=0;
    p_arr->A=(int*)malloc(sizeof(int)*p_arr->size);
    // "construtor" do array - Heap Memory - C - Alocação Dinãmica
    struct Array *p_arr02=(struct Array *)malloc(sizeof(struct Array));
    p_arr02->size=20;
    p_arr02->length=0;
    p_arr02->A=(int*)malloc(sizeof(int)*p_arr->size);

    Append (&arr,1);
    Append (&arr,2);
    Append (&arr,3);
    Insert (&arr,1,10);
    Insert (&arr,2,32);
    //
    std::cout<<"Display -- "<<std::endl;
    sort(&arr);
    Display(arr);
    std::cout<<std::endl;
    std::cout<<" "<<arr.length<<std::endl;
    std::cout<<"Display --"<<std::endl;
    //
    Append (p_arr,1);
    Append (p_arr,2);
    Append (p_arr,3);
    Insert (p_arr,1,37);
    Insert (p_arr,2,32);
    //std::cout<<isSort(arr)<<std::endl;
    std::cout<<BinarySearch(p_arr,32)<<std::endl;
    std::cout<<RBinarySearch (p_arr->A,0,p_arr->length-1,32)<<std::endl;
    //
    std::cout<<"-	-	-	-"<<std::endl;
    std::cout<<p_arr->A[-1]<<std::endl;
    //
    std::cout<<"- 	-	-	-"<<std::endl;
    std::cout<<Sum(arr)<<std::endl;
    system("pause");

    return 0;
    return 0;
}
