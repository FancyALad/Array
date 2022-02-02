#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996)

const BLOCKSIZE = 20;

typedef struct{
    int* array;
    int size;
}Array;

Array array_creat(int init_size){
    Array a;
    a.size = init_size;
    a.array = NULL;
    a.array=(int*)malloc(sizeof(int) * a.size);
    return a;
}

void array_free(Array* a){
    free(a->array);
    a->size=0;
    a->array = NULL;
}

int array_size(const Array*a){
    return a->size;
}

void array_inflate(Array*a,int more_size)
{
    int* p = (int*)malloc(sizeof(int) * (a->size + more_size));
    for(int i=0;i<a->size;i++){
        p[i]=a->array[i];
    }
    free(a->array);
    a->array = p;
    a->size = a->size+more_size;
}

int* array_at(Array *a,int index){
    if(index >= a->size){
        array_inflate(a,(index/BLOCKSIZE+1)*BLOCKSIZE-a->size);
    }
    return &(a->array[index]);
}

int main(int argc,const char *argv[])
{
    Array a=array_creat(1);
    printf("%d\n",array_size(&a));
    //*array_at(&a,0)=10;
    //printf("%d\n",*array_at(&a,0));
    int cnt=0;
    int number=0;
    while(number!=-1){
        scanf("%d",&number);
        *array_at(&a,cnt++)=number;
    }
    int num = 0;
    for (; num < cnt-1; num++) {
        printf("%d\n", *array_at(&a,num));
    }
    array_free(&a);

    return 0;
}