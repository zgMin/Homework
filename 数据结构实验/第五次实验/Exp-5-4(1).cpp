bool AddQ( Queue Q, ElementType X ){
    if(Q->Count==Q->MaxSize){
        printf("Queue Full\n");
        return 0;
    }
    Q->Count++;
    Q->Data[(Q->Front+Q->Count)%Q->MaxSize]=X;
    return 1;
}
ElementType DeleteQ( Queue Q ){
    if(Q->Count==0){
        printf("Queue Empty\n");
        return ERROR;
    }
    Q->Count--;
	Q->Front=(Q->Front+1)%Q->MaxSize;
	return Q->Data[Q->Front];
}
