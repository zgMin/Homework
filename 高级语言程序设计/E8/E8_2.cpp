/*
	试写一个程序统计输入的字符串中，包含的字符数、行数及单词数。
	提示：这里的单词是指前后均是空白字符的字符序列，
	例如 adsaf asdfdsaf, <sdfsd 中共有 1 行、23 个字符、3 个单词
*/
#include<stdio.h>
int main(){ 
 	char c; 
	int chars=0;
	int lines=1;
	int words=0;
	bool inword=false;
	
	printf("请输入字符($用于结束输入):\n"); 
	
	while((c=getchar())!='$'){ 
		chars++;
		if(c=='\n') lines++; 
		if(c==' '&& !inword){ 
			inword=true; 
			words++;
		}else if(c==' '&&inword)  inword=false; 
	} 
	printf("\n字符数=%d,行数=%d,单词数=%d",chars,lines,words); 
	return 0; 
}
