//
// Created by davim on 10/11/2021.
//
#include "stdio.h"
#include "data_structures.h"

namespace DataStructure {
    struct Array {
        int *A;
        int size;
        int length;
    };
    void Display(struct Array arr) {
        if (arr.length > 0) {
            for (int i = 0; i < arr.length; i++) {
                printf("\n %d", arr.A[i]);
            }
        }
    }
    void Append(struct Array *arr, int x) {
        if (arr->length < arr->size) {
            arr->A[arr->length++] = x;
        }
    }
    void Insert(struct Array *arr, int index, int x) {
        if (arr->length < arr->size && index < arr->length && index > 0) {
            for (int i = arr->length - 1; i >= index; i--) {
                arr->A[i + 1] = arr->A[i];
            }
            arr->A[index] = x;
            arr->length++;
        }
    }
    int isSort(struct Array arr) {
        if (arr.length > 0) {
            for (int i = 0; i < arr.length - 1; i++) {
                if (arr.A[i] > arr.A[i + 1]) {
                    return 0;
                }
            }
            return 1;
        }
        printf("\n%d", "Vazio");
        return 1;
    }
    void swap(int *x, int *y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
    int LinearSearch(struct Array *arr, int key) {
        if (arr->length > 0) {
            for (int i = 0; i < arr->length; i++) {
                if (arr->A[i] == key) {
                    swap(&arr->A[0], &arr->A[i]);
                    return 0;
                }
            }
        }
        return -1;
    }
    void sort(struct Array *arr) {
        int i = 0;
        if (arr->length > 0) {

            while (i != (arr->length - 1)) {
                i = 0;
                do {
                    if (arr->A[i] > arr->A[i + 1]) {
                        swap(&arr->A[i], &arr->A[i + 1]);
                        break;
                    }
                    i++;
                } while (i < arr->length - 1);
            }

        }
    }
    int Get(struct Array arr, int index) {
        if (index < arr.length && index > 0) {
            return arr.A[index];
        }
    }
    void Set(struct Array *arr, int index, int x) {
        if (index < arr->length && index > 0) {
            arr->A[index] = x;
        }
    }
    int Max(struct Array arr) {

        if (arr.length > 0) {
            int max = arr.A[0];
            for (int i = 0; i < arr.length; i++) {
                if (arr.A[i] > max) {
                    max = arr.A[i];
                }
            }
            return max;
        }
        return 0;
    }
    int Min(struct Array arr) {
        if (arr.length > 0) {
            int min = arr.A[0];
            for (int i = 0; i < arr.length; i++) {
                if (arr.A[i] < min) {
                    min = arr.A[i];
                }
            }
        }
        return 0;
    }
    int BinarySearch(struct Array *arr, int key) {
        int l, h, m;
        l = 0;
        h = arr->length - 1;
        if (arr->length > 0) {
            if (isSort(*arr) == 0) {
                sort(arr);
            }
            while (l <= h) {
                m = (l + h) / 2;
                if (key > arr->A[m]) {
                    l = m + 1;
                } else if (key < arr->A[m]) {
                    h = m - 1;
                } else {
                    return m;
                }
            }


        }
        return -1;
    }
    int RBinarySearch(int a[], int l, int h, int key) {
        int m = 0;
        if (l <= h) {
            m = (l + h) / 2;
            if (key > a[m]) {
                RBinarySearch(a, m + 1, h, key);
            } else if (key < a[m]) {
                RBinarySearch(a, l, m - 1, key);
            } else {
                return m;
            }
        }
    }
    int Sum(struct Array arr) {
        int i, sum = 0;
        if (arr.length > 0) {
            for (i = 0; i < arr.length; i++) {
                sum += arr.A[i];
            }
            return sum;
        }

    }
    float Avg(struct Array arr) {
        if (arr.length > 0) {
            return Sum(arr) / arr.length;
        }
    }
    void insertSort(struct Array *arr, int x) {
        int i = arr->length - 1;
        while (arr->A[i] > x) {
            arr->A[i + 1] = arr->A[i];
            i--;
        }
        arr->A[i + 1] = x;
    }
    void Rearrange(struct Array *arr) {
        int i, j;
        i = 0;
        j = arr->length - 1;

        while (i < j) {
            while (arr->A[i] < 0)i++;
            while (arr->A[j >= 0])j--;

            if (i < j) swap(&arr->A[i], &arr->A[j]);
        }
    }
    struct Array *Merge(struct Array *arr01, struct Array *arr02) {
        int i = 0;
        int j = 0;
        int n = arr01->length;
        int m = arr02->length;
        int k = 0;
        //inicialização do array de retorno - construtor em C
        struct Array *arr03 = (struct Array *) malloc(sizeof(struct Array));
        arr03->length = 0;
        arr03->size = n + m;
        arr02->A = (int *) malloc(sizeof(int) * arr02->size);
        // fim de construção
        if (!isSort(*arr01)) {
            sort(arr01);
        }
        if (!isSort(*arr02)) {
            sort(arr02);
        }
        if (arr01->length > 0 || arr02->length > 0) {
            while (i < n && j < m) {
                if (arr01->A[i] > arr02->A[j]) {
                    arr03->A[k++] = arr01->A[i++];
                    arr03->length++;
                }
                if (arr01->A[i] < arr02->A[j]) {
                    arr03->A[k++] = arr02->A[j++];
                    arr03->length++;
                }
            }

            while (i < n) {
                if (arr01->A[i] > arr01->A[i - 1]) {
                    arr03->A[k++] = arr01->A[i++];
                    arr03->length++;
                }
            }

            while (j < m) {
                if (arr02->A[j] > arr02->A[j - 1]) {
                    arr03->A[k++] = arr02->A[j++];
                    arr03->length++;
                }
            }

        }

    }
    struct Array *Union(struct Array *arr01, struct Array *arr02) {
        int i = 0;
        int j = 0;
        int n = arr01->length;
        int m = arr02->length;
        int k = 0;
        //inicialização do array de retorno - construtor em C
        struct Array *arr03 = (struct Array *) malloc(sizeof(struct Array));
        arr03->length = 0;
        arr03->size = n + m;
        arr02->A = (int *) malloc(sizeof(int) * arr02->size);
        // fim de construção
        if (!isSort(*arr01)) {
            sort(arr01);
        }
        if (!isSort(*arr02)) {
            sort(arr02);
        }
        if (arr01->length > 0 || arr02->length > 0) {
            while (i < n && j < m) {
                if (arr01->A[i] > arr02->A[j]) {
                    arr03->A[k++] = arr01->A[i++];
                    arr03->length++;
                } else if (arr01->A[i] < arr02->A[j]) {
                    arr03->A[k++] = arr02->A[j++];
                    arr03->length++;
                } else {
                    arr03->A[k++] = arr01->A[i++];
                    j++;
                }
            }

            while (i < n) {
                if (arr01->A[i] > arr01->A[i - 1]) {
                    arr03->A[k++] = arr01->A[i++];
                    arr03->length++;
                }
            }

            while (j < m) {
                if (arr02->A[j] > arr02->A[j - 1]) {
                    arr03->A[k++] = arr02->A[j++];
                    arr03->length++;
                }
            }

        }

    }
    struct Array *Intersection(struct Array *arr01, struct Array *arr02) {
        int i = 0;
        int j = 0;
        int n = arr01->length;
        int m = arr02->length;
        int k = 0;
        //inicialização do array de retorno - construtor em C
        struct Array *arr03 = (struct Array *) malloc(sizeof(struct Array));
        arr03->length = 0;
        arr03->size = n + m;
        arr02->A = (int *) malloc(sizeof(int) * arr02->size);
        // fim de construção
        if (!isSort(*arr01)) {
            sort(arr01);
        }
        if (!isSort(*arr02)) {
            sort(arr02);
        }
        if (arr01->length > 0 || arr02->length > 0) {
            while (i < n && j < m) {
                if (arr01->A[i] > arr02->A[j]) {
                    i++;
                } else if (arr01->A[i] < arr02->A[j]) {
                    j++;
                } else {
                    arr03->A[k++] = arr01->A[i++];
                    j++;
                    arr03->length++;
                }
            }


        }

    }
    struct Array *Difference(struct Array *arr01, struct Array *arr02) {
        int i = 0;
        int j = 0;
        int n = arr01->length;
        int m = arr02->length;
        int k = 0;
        //inicialização do array de retorno - construtor em C
        struct Array *arr03 = (struct Array *) malloc(sizeof(struct Array));
        arr03->length = 0;
        arr03->size = n + m;
        arr02->A = (int *) malloc(sizeof(int) * arr02->size);
        // fim de construção
        if (!isSort(*arr01)) {
            sort(arr01);
        }
        if (!isSort(*arr02)) {
            sort(arr02);
        }
        if (arr01->length > 0 || arr02->length > 0) {
            while (i < n && j < m) {
                if (arr01->A[i] > arr02->A[j]) {
                    arr03->A[k++] = arr01->A[i++];
                    arr03->length++;
                }
                if (arr01->A[i] < arr02->A[j]) {
                    arr03->A[k++] = arr02->A[j++];
                    arr03->length++;
                }
                if (arr01->A[i] == arr02->A[j]) {
                    i++;
                    j++;
                }
            }

            while (i < n) {
                if (arr01->A[i] > arr01->A[i - 1]) {
                    arr03->A[k++] = arr01->A[i++];
                    arr03->length++;
                }
            }

            while (j < m) {
                if (arr02->A[j] > arr02->A[j - 1]) {
                    arr03->A[k++] = arr02->A[j++];
                    arr03->length++;
                }
            }

        }

    }


}