#ifndef MINN
#define MINN



int minn(unsigned int* n1){
    int i = 0;
    int smallest = 2147483647;
    while (n1[i] != 0)
    {
        i++;
        if (n1[i] < smallest){
            smallest = n1[i];
        }
    }
    return smallest;
}


#endif