#define __vc
#include "../cobject/cobjs.h"

#define CLASSNAME test
Function(test, int, int a, int b)
{
	printf("hello world");
}
ClassBegin
Metdef(test, int, int a, int b)
VALUE(int,testval)
ClassEnd
CLASSINIT
USE(test)
VALUEFOR(testval,20)
END

int main()
{
	new(test, val);
	val->test(1, 23);
	printf("%d", val->testval);
	scanf("%d");
}