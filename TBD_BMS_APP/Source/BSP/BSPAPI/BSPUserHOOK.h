//=======================================Copyright(c)===========================================
// 								  深圳易马达科技有限公司
//---------------------------------------文件信息----------------------------------------------
//文件名   	: BSPUserHOOK.h
//创建人  	: Handry
//创建日期	:
//描述	    : API钩子函数头文件
//-----------------------------------------------当前版本修订----------------------------------
//修改人   	:
//版本	    :
//修改日期	:
//描述	    :
//=============================================================================================
#ifndef  _USER_HOOK_H
#define  _USER_HOOK_H

//=============================================================================================
//头文件
//=============================================================================================

//=============================================================================================
//全局变量定义
//=============================================================================================

//=============================================================================================
//静态函数声明
//=============================================================================================

//=============================================================================================
//函数名称	: void BeforeInitAllHook(void) 
//输入参数	: void
//输出参数	: void
//静态变量	: 
//功	能	: 
//注	意	: 在InitAll之前调用 
//=============================================================================================
void BeforeInitAllHook(void);

//=============================================================================================
//函数名称	: void AfterInitAllHook(void) 
//输入参数	: void
//输出参数	: void
//静态变量	: 
//功	能	: 
//注	意	: 在InitAll之后调用 
//=============================================================================================
void AfterInitAllHook(void);

//=============================================================================================
//函数名称	: void BeforeEnableIntHook(void)
//输入参数	: void
//输出参数	: void
//静态变量	:
//功	能	:
//注	意	: 在中断开启之前调用
//=============================================================================================
void BeforeEnableIntHook(void);

//=============================================================================================
//函数名称	: void AfterEnableIntHook(void)
//输入参数	: void
//输出参数	: void
//静态变量	:
//功	能	:
//注	意	: 在中断开启之后调用
//=============================================================================================
void AfterEnableIntHook(void);

#endif

/*****************************************end of BSPUserHOOK.h*****************************************/