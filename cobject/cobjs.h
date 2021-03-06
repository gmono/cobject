#ifndef COBJS_H
#define COBJS_H
#ifndef __cplusplus
//此头文件仅给纯c使用
//使用方法：定义CLASSNAME宏 然后定义函数接着定义结构体
//注意 vc请声明 __vc宏
#include <malloc.h>
#include <stdio.h>
#define Metdef(name,restype,...) restype (*name)(__VA_ARGS__);
#define Function(name,restype,...) restype __GOBJ_CLASSNAME_##name(__VA_ARGS__)
#define ClassBegin typedef struct{
#define ClassEnd }CLASSNAME;
#ifndef __vc
#define new(type) ({type *temp=malloc(sizeof(type);__GOBJ_CLASSNAME_INIT(temp);temp;}) //分配空间并调用初始化函数
#define newarray(type,sum) malloc(sizeof(type)*sum)
#else
#define new(type,name) type *name=malloc(sizeof(type));__GOBJ_CLASSNAME_INIT(name)           //这是VC专用new (由于无语句块支持)
#define newarray(type,sum,name) type *name=malloc(sizeof(type)*sum);for(int _temp=0;_temp<sum;_temp++) __GOBJ_CLASSNAME_INIT(&name[_temp]) //vc专用newarray 由于无可返回语句块支持
#endif

#define delete(ptr) free(ptr)
#define CLASSINIT __GOBJ_CLASSNAME_INIT(CLASSNAME *ptr){
#define USE(name) ptr->name=&__GOBJ_CLASSNAME_##name;
#define END }
#define VALUE(type,name) type name;//定义一个值成员
#define VALUEFOR(name,val) ptr->name=val;//初始化成员
//以下为属性部分 属性使用方式为 属性por 则有 getpor与setpor两种 暂时没有找到不用外部处理器的解决方案




#endif
#endif // COBJS_H
