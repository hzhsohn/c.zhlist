#include <stdio.h>
#include <stdlib.h>
#include "zhlist-1.1/zhlist_exp.h"

//���������
typedef enum _EzhListElementType{
	ezhListEleDefault
}EzhListElementType;

int main(int argc, char **argv)
{
	TzhList userList;
	TzhListElementNode *pNode;
	TzhListElementNode *pNode2;

	zhListInit(&userList);
	pNode=zhListNodeAdd(&userList,(void*)"12345",6,ezhListEleDefault);
	pNode=zhListNodeAdd(&userList,(void*)"54321",6,ezhListEleDefault);
	printf("user count=%d\n",zhListCount(&userList));

    pNode2=(TzhListElementNode*)zhListFirst(&userList);
	printf("user =%s\n",pNode2->pElement);
	
	pNode2=zhListNodeFind(&userList,pNode2);
	printf("user =%s\n",pNode2->pElement);
	
	pNode2=zhListNodeFindWithObject(&userList,pNode2->pElement);
	printf("user =%s\n",pNode2->pElement);

//ѭ��
{
    TzhListElementNode *eleNode;
    for(eleNode = (TzhListElementNode *)zhListFirst(&userList);
          eleNode != NULL;)
    {
      char* buf=eleNode->pElement;
      if(0==strcmp(buf,"12345"))
      {
        #if 0
        free(eleNode->pElement);
        eleNode->pElement=NULL;
        //ɾ������ڵ�
        eleNode=zhListNodeDelete(&userList,eleNode);
        #else
        //ɾ������ڵ�
        eleNode=zhListNodeFreeAndDelete(&userList,eleNode);
        #endif
      }
      else
      {
         eleNode = (TzhListElementNode *)zhListNext((TzhListNode *)eleNode);
      }
    }
}
	getchar();
	return 0;
}

