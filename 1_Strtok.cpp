//借助strtok实现split
/*output: 
Hello 
world
engineers 
~  

原理解析：
每次切割返回的是char*型的；被切割的字符串是char数字型的；切割符是const char*型的。
如果被切割字符串是string类型的，可以用(char*)str.data()进行类型转换。

第一次调用时候，strtok函数从不是分隔符的第一个字符开始搜索，找到第一个是分隔符为止，将其替换为‘\0’作为结束。
但是函数此时已经保存了分隔符之后的那个字符，因此后续再调用strtok时，第一个参数为NULL，继续将string标记化（切割）。
NULL参数表示调用strtok继续从string中上次调用 strtok时保存的位置开始标记化。 

注意strtok会修改输入字符串，如果调用strtok之后还要在程序中使用这个字符串，则应复制这个字符串。
每执行一次strtok，都会改变原来的字符串。因为它将分隔符转换为‘\0’了，字符串从这里就断掉了
*/ 
#include <string.h>
#include <stdio.h>
 
int main()
{
    char s[] = "Hello world,engineers!~";
    const char *d = " ,!";//以空格，逗号和感叹号作为分隔符，注意是可以取多个的
    char *p;
    p = strtok(s,d);
    while(p)
    {
        printf("%s\n",p);
        p=strtok(NULL,d);//注意上一行与此行的顺序 不能反过来 
    }
 
    return 0;
}
