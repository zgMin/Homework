List Reverse( List L ){
    List Prior,tmp;
    Prior=NULL;
    while(L!=NULL){
        tmp=L->Next;    //��ֹ��ʧ��������
        L->Next=Prior;  
        Prior=L;
        L=tmp;
    }
    return Prior;
}
