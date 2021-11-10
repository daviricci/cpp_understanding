//
// Created by davim on 10/11/2021.
//

#ifndef _C_CPP_DATA_STRUCTURES_H
#define _C_CPP_DATA_STRUCTURES_H
struct Array;
namespace DataStructure{
    void Display(struct Array arr);
    void Append(struct Array *arr, int x);
    void Insert (struct Array *arr,int index, int x);
    int isSort (struct Array arr);
    void swap (int *x,int*y);
    int LinearSearch (struct Array *arr,int key);
    void sort(struct Array *arr);
    int Get(struct Array arr,int index);
    void Set(struct Array *arr, int index,int x);
    int Max(struct Array arr);
    int Min(struct Array arr);
    int BinarySearch (struct Array *arr, int key);
    int RBinarySearch (int a[],int l, int h, int key);
    int Sum (struct Array arr);
    float Avg(struct Array arr);
    void insertSort(struct Array *arr, int x);
    void Rearrange(struct Array *arr);
    struct Array *Merge(struct Array *arr01,struct Array *arr02);
    struct Array *Union(struct Array *arr01,struct Array *arr02);
    struct Array *Intersection(struct Array *arr01,struct Array *arr02);
    struct Array *Difference(struct Array *arr01,struct Array *arr02);
}
#endif //_C_CPP_DATA_STRUCTURES_H
