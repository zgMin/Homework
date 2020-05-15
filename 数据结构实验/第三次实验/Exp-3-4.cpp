List Reverse( List L ){
    List Prior,tmp;
    Prior=NULL;
    while(L!=NULL){
        tmp=L->Next;    //·ÀÖ¹¶ªÊ§ºóÐøÁ´±í
        L->Next=Prior;  
        Prior=L;
        L=tmp;
    }
    return Prior;
}
