#include<stdio.h>
#include<math.h>

int values[10];
int length = 0;

void BubbleUp(int value){
    int index = length;
    while(index>=0){
        int parentindex = floor((index-1)/2);
        if(values[parentindex] >= values[index]){
            break;
            }
        values[index] = values[parentindex];
        values[parentindex] = value;
        index = parentindex;
    }
}

void insert(int value){
    values[length] = value;
    BubbleUp(value);
    length++;
}

void SinkDown(){
    int index = 0;
    int value = values[index];
    int childIndex1 = 2*index+1;
    int childIndex2 = 2*index+2;

    while(value<values[childIndex1] || value<values[childIndex2]){

        if(childIndex2>=length){
            if(childIndex1>=length){
                break;
            }
            else if(value<values[childIndex1]){
                values[index] = values[childIndex1];
                values[childIndex1] = value;
                index = childIndex1;
            }
            break;
        }

        if(value<values[childIndex1] && value<values[childIndex2])
        {
            if(values[childIndex1]>values[childIndex2]){
                values[index] = values[childIndex1];
                values[childIndex1] = value;
                index = childIndex1;
            }
            else if(values[childIndex2]>values[childIndex1]){
                values[index] = values[childIndex2];
                values[childIndex2] = value;
                index = childIndex2;
            }
        }

        else if(value<values[childIndex1]){
                values[index] = values[childIndex1];
                values[childIndex1] = value;
                index = childIndex1;
        }

        else if(value<values[childIndex2]){
                values[index] = values[childIndex2];
                values[childIndex2] = value;
                index = childIndex2;
        }
        childIndex1 = 2*index+1;
        childIndex2 = 2*index+2;
    }
}

int ExtractMax(void){
    int root = values[0];
    values[0] = values[length - 1];
    values[length - 1]=0;
    length--;
    SinkDown();
    return (root);
}

void  main(void){
    insert(-21);
    insert(2);
    insert(3);
    insert(41);
    insert(5);
    insert(62);
    insert(7);
    insert(80);
    insert(9);
    insert(100);
    ExtractMax();
    for (int i = 0; i < length;i++){
        printf("%d,", values[i]);
    }
}