#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <cstring>
#include <string.h>
#include <stdio.h>
#include <cmath>
#include <limits>
#include <assert.h>

// System.EventHandler`1<System.Object>
struct EventHandler_1_t1280756467;
// System.Object
struct Il2CppObject;
// System.IAsyncResult
struct IAsyncResult_t1999651008;
// System.AsyncCallback
struct AsyncCallback_t163412349;
// System.Func`2<System.Object,System.Boolean>
struct Func_2_t3961629604;
// System.Func`2<System.Object,System.Object>
struct Func_2_t2825504181;
// System.Func`2<System.Object,System.Single>
struct Func_2_t2212564818;
// System.Linq.Enumerable/<CreateCastIterator>c__Iterator0`1<System.Object>
struct U3CCreateCastIteratorU3Ec__Iterator0_1_t1397100709;
// System.Collections.IEnumerator
struct IEnumerator_t1466026749;
// System.Collections.Generic.IEnumerator`1<System.Object>
struct IEnumerator_1_t164973122;
// System.Linq.Enumerable/<CreateWhereIterator>c__Iterator1D`1<System.Object>
struct U3CCreateWhereIteratorU3Ec__Iterator1D_1_t4121738870;
// System.String
struct String_t;

#include "class-internals.h"
#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Array3829468939.h"
#include "mscorlib_System_EventHandler_1_gen1280756467.h"
#include "mscorlib_System_EventHandler_1_gen1280756467MethodDeclarations.h"
#include "mscorlib_System_Object2689449295.h"
#include "mscorlib_System_IntPtr2504060609.h"
#include "mscorlib_System_Void1841601450.h"
#include "mscorlib_System_AsyncCallback163412349.h"
#include "System_Core_System_Func_2_gen3961629604.h"
#include "System_Core_System_Func_2_gen3961629604MethodDeclarations.h"
#include "mscorlib_System_Boolean3825574718.h"
#include "System_Core_System_Func_2_gen2825504181.h"
#include "System_Core_System_Func_2_gen2825504181MethodDeclarations.h"
#include "System_Core_System_Func_2_gen2212564818.h"
#include "System_Core_System_Func_2_gen2212564818MethodDeclarations.h"
#include "mscorlib_System_Single2076509932.h"
#include "System_Core_System_Linq_Enumerable_U3CCreateCastIt1397100709.h"
#include "System_Core_System_Linq_Enumerable_U3CCreateCastIt1397100709MethodDeclarations.h"
#include "mscorlib_System_Object2689449295MethodDeclarations.h"
#include "mscorlib_System_Threading_Interlocked1625106012MethodDeclarations.h"
#include "mscorlib_System_Int322071877448.h"
#include "mscorlib_System_UInt322149682021.h"
#include "mscorlib_System_NotSupportedException1793819818MethodDeclarations.h"
#include "mscorlib_System_NotSupportedException1793819818.h"
#include "System_Core_System_Linq_Enumerable_U3CCreateWhereI4121738870.h"
#include "System_Core_System_Linq_Enumerable_U3CCreateWhereI4121738870MethodDeclarations.h"
#include "mscorlib_System_Nullable_1_gen1791139578.h"
#include "mscorlib_System_Nullable_1_gen1791139578MethodDeclarations.h"
#include "AssemblyU2DCSharp_GoogleMobileAds_Api_Gender3528073263.h"
#include "mscorlib_System_InvalidOperationException721527559MethodDeclarations.h"
#include "mscorlib_System_String2029220233.h"
#include "mscorlib_System_InvalidOperationException721527559.h"
#include "mscorlib_System_ValueType3507792607MethodDeclarations.h"
#include "mscorlib_System_ValueType3507792607.h"
#include "mscorlib_System_String2029220233MethodDeclarations.h"
#include "mscorlib_System_Nullable_1_gen2088641033.h"
#include "mscorlib_System_Nullable_1_gen2088641033MethodDeclarations.h"
#include "mscorlib_System_Boolean3825574718MethodDeclarations.h"
#include "mscorlib_System_Nullable_1_gen3251239280.h"
#include "mscorlib_System_Nullable_1_gen3251239280MethodDeclarations.h"
#include "mscorlib_System_DateTime693205669.h"
#include "mscorlib_System_DateTime693205669MethodDeclarations.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void System.EventHandler`1<System.Object>::.ctor(System.Object,System.IntPtr)
extern "C"  void EventHandler_1__ctor_m805401670_gshared (EventHandler_1_t1280756467 * __this, Il2CppObject * ___object0, IntPtr_t ___method1, const MethodInfo* method)
{
	__this->set_method_ptr_0((Il2CppMethodPointer)((MethodInfo*)___method1.get_m_value_0())->methodPointer);
	__this->set_method_3(___method1);
	__this->set_m_target_2(___object0);
}
// System.Void System.EventHandler`1<System.Object>::Invoke(System.Object,TEventArgs)
extern "C"  void EventHandler_1_Invoke_m3162899003_gshared (EventHandler_1_t1280756467 * __this, Il2CppObject * ___sender0, Il2CppObject * ___e1, const MethodInfo* method)
{
	if(__this->get_prev_9() != NULL)
	{
		EventHandler_1_Invoke_m3162899003((EventHandler_1_t1280756467 *)__this->get_prev_9(),___sender0, ___e1, method);
	}
	il2cpp_codegen_raise_execution_engine_exception_if_method_is_not_found((MethodInfo*)(__this->get_method_3().get_m_value_0()));
	bool ___methodIsStatic = MethodIsStatic((MethodInfo*)(__this->get_method_3().get_m_value_0()));
	if (__this->get_m_target_2() != NULL && ___methodIsStatic)
	{
		typedef void (*FunctionPointerType) (Il2CppObject *, void* __this, Il2CppObject * ___sender0, Il2CppObject * ___e1, const MethodInfo* method);
		((FunctionPointerType)__this->get_method_ptr_0())(NULL,__this->get_m_target_2(),___sender0, ___e1,(MethodInfo*)(__this->get_method_3().get_m_value_0()));
	}
	else if (__this->get_m_target_2() != NULL || ___methodIsStatic)
	{
		typedef void (*FunctionPointerType) (void* __this, Il2CppObject * ___sender0, Il2CppObject * ___e1, const MethodInfo* method);
		((FunctionPointerType)__this->get_method_ptr_0())(__this->get_m_target_2(),___sender0, ___e1,(MethodInfo*)(__this->get_method_3().get_m_value_0()));
	}
	else
	{
		typedef void (*FunctionPointerType) (void* __this, Il2CppObject * ___e1, const MethodInfo* method);
		((FunctionPointerType)__this->get_method_ptr_0())(___sender0, ___e1,(MethodInfo*)(__this->get_method_3().get_m_value_0()));
	}
}
// System.IAsyncResult System.EventHandler`1<System.Object>::BeginInvoke(System.Object,TEventArgs,System.AsyncCallback,System.Object)
extern "C"  Il2CppObject * EventHandler_1_BeginInvoke_m2005697352_gshared (EventHandler_1_t1280756467 * __this, Il2CppObject * ___sender0, Il2CppObject * ___e1, AsyncCallback_t163412349 * ___callback2, Il2CppObject * ___object3, const MethodInfo* method)
{
	void *__d_args[3] = {0};
	__d_args[0] = ___sender0;
	__d_args[1] = ___e1;
	return (Il2CppObject *)il2cpp_codegen_delegate_begin_invoke((Il2CppDelegate*)__this, __d_args, (Il2CppDelegate*)___callback2, (Il2CppObject*)___object3);
}
// System.Void System.EventHandler`1<System.Object>::EndInvoke(System.IAsyncResult)
extern "C"  void EventHandler_1_EndInvoke_m487063176_gshared (EventHandler_1_t1280756467 * __this, Il2CppObject * ___result0, const MethodInfo* method)
{
	il2cpp_codegen_delegate_end_invoke((Il2CppAsyncResult*) ___result0, 0);
}
// System.Void System.Func`2<System.Object,System.Boolean>::.ctor(System.Object,System.IntPtr)
extern "C"  void Func_2__ctor_m1354888807_gshared (Func_2_t3961629604 * __this, Il2CppObject * ___object0, IntPtr_t ___method1, const MethodInfo* method)
{
	__this->set_method_ptr_0((Il2CppMethodPointer)((MethodInfo*)___method1.get_m_value_0())->methodPointer);
	__this->set_method_3(___method1);
	__this->set_m_target_2(___object0);
}
// TResult System.Func`2<System.Object,System.Boolean>::Invoke(T)
extern "C"  bool Func_2_Invoke_m2968608789_gshared (Func_2_t3961629604 * __this, Il2CppObject * ___arg10, const MethodInfo* method)
{
	if(__this->get_prev_9() != NULL)
	{
		Func_2_Invoke_m2968608789((Func_2_t3961629604 *)__this->get_prev_9(),___arg10, method);
	}
	il2cpp_codegen_raise_execution_engine_exception_if_method_is_not_found((MethodInfo*)(__this->get_method_3().get_m_value_0()));
	bool ___methodIsStatic = MethodIsStatic((MethodInfo*)(__this->get_method_3().get_m_value_0()));
	if (__this->get_m_target_2() != NULL && ___methodIsStatic)
	{
		typedef bool (*FunctionPointerType) (Il2CppObject *, void* __this, Il2CppObject * ___arg10, const MethodInfo* method);
		return ((FunctionPointerType)__this->get_method_ptr_0())(NULL,__this->get_m_target_2(),___arg10,(MethodInfo*)(__this->get_method_3().get_m_value_0()));
	}
	else if (__this->get_m_target_2() != NULL || ___methodIsStatic)
	{
		typedef bool (*FunctionPointerType) (void* __this, Il2CppObject * ___arg10, const MethodInfo* method);
		return ((FunctionPointerType)__this->get_method_ptr_0())(__this->get_m_target_2(),___arg10,(MethodInfo*)(__this->get_method_3().get_m_value_0()));
	}
	else
	{
		typedef bool (*FunctionPointerType) (void* __this, const MethodInfo* method);
		return ((FunctionPointerType)__this->get_method_ptr_0())(___arg10,(MethodInfo*)(__this->get_method_3().get_m_value_0()));
	}
}
// System.IAsyncResult System.Func`2<System.Object,System.Boolean>::BeginInvoke(T,System.AsyncCallback,System.Object)
extern "C"  Il2CppObject * Func_2_BeginInvoke_m1429757044_gshared (Func_2_t3961629604 * __this, Il2CppObject * ___arg10, AsyncCallback_t163412349 * ___callback1, Il2CppObject * ___object2, const MethodInfo* method)
{
	void *__d_args[2] = {0};
	__d_args[0] = ___arg10;
	return (Il2CppObject *)il2cpp_codegen_delegate_begin_invoke((Il2CppDelegate*)__this, __d_args, (Il2CppDelegate*)___callback1, (Il2CppObject*)___object2);
}
// TResult System.Func`2<System.Object,System.Boolean>::EndInvoke(System.IAsyncResult)
extern "C"  bool Func_2_EndInvoke_m924416567_gshared (Func_2_t3961629604 * __this, Il2CppObject * ___result0, const MethodInfo* method)
{
	Il2CppObject *__result = il2cpp_codegen_delegate_end_invoke((Il2CppAsyncResult*) ___result0, 0);
	return *(bool*)UnBox ((Il2CppCodeGenObject*)__result);
}
// System.Void System.Func`2<System.Object,System.Object>::.ctor(System.Object,System.IntPtr)
extern "C"  void Func_2__ctor_m1684831714_gshared (Func_2_t2825504181 * __this, Il2CppObject * ___object0, IntPtr_t ___method1, const MethodInfo* method)
{
	__this->set_method_ptr_0((Il2CppMethodPointer)((MethodInfo*)___method1.get_m_value_0())->methodPointer);
	__this->set_method_3(___method1);
	__this->set_m_target_2(___object0);
}
// TResult System.Func`2<System.Object,System.Object>::Invoke(T)
extern "C"  Il2CppObject * Func_2_Invoke_m3288232740_gshared (Func_2_t2825504181 * __this, Il2CppObject * ___arg10, const MethodInfo* method)
{
	if(__this->get_prev_9() != NULL)
	{
		Func_2_Invoke_m3288232740((Func_2_t2825504181 *)__this->get_prev_9(),___arg10, method);
	}
	il2cpp_codegen_raise_execution_engine_exception_if_method_is_not_found((MethodInfo*)(__this->get_method_3().get_m_value_0()));
	bool ___methodIsStatic = MethodIsStatic((MethodInfo*)(__this->get_method_3().get_m_value_0()));
	if (__this->get_m_target_2() != NULL && ___methodIsStatic)
	{
		typedef Il2CppObject * (*FunctionPointerType) (Il2CppObject *, void* __this, Il2CppObject * ___arg10, const MethodInfo* method);
		return ((FunctionPointerType)__this->get_method_ptr_0())(NULL,__this->get_m_target_2(),___arg10,(MethodInfo*)(__this->get_method_3().get_m_value_0()));
	}
	else if (__this->get_m_target_2() != NULL || ___methodIsStatic)
	{
		typedef Il2CppObject * (*FunctionPointerType) (void* __this, Il2CppObject * ___arg10, const MethodInfo* method);
		return ((FunctionPointerType)__this->get_method_ptr_0())(__this->get_m_target_2(),___arg10,(MethodInfo*)(__this->get_method_3().get_m_value_0()));
	}
	else
	{
		typedef Il2CppObject * (*FunctionPointerType) (void* __this, const MethodInfo* method);
		return ((FunctionPointerType)__this->get_method_ptr_0())(___arg10,(MethodInfo*)(__this->get_method_3().get_m_value_0()));
	}
}
// System.IAsyncResult System.Func`2<System.Object,System.Object>::BeginInvoke(T,System.AsyncCallback,System.Object)
extern "C"  Il2CppObject * Func_2_BeginInvoke_m4034295761_gshared (Func_2_t2825504181 * __this, Il2CppObject * ___arg10, AsyncCallback_t163412349 * ___callback1, Il2CppObject * ___object2, const MethodInfo* method)
{
	void *__d_args[2] = {0};
	__d_args[0] = ___arg10;
	return (Il2CppObject *)il2cpp_codegen_delegate_begin_invoke((Il2CppDelegate*)__this, __d_args, (Il2CppDelegate*)___callback1, (Il2CppObject*)___object2);
}
// TResult System.Func`2<System.Object,System.Object>::EndInvoke(System.IAsyncResult)
extern "C"  Il2CppObject * Func_2_EndInvoke_m1674435418_gshared (Func_2_t2825504181 * __this, Il2CppObject * ___result0, const MethodInfo* method)
{
	Il2CppObject *__result = il2cpp_codegen_delegate_end_invoke((Il2CppAsyncResult*) ___result0, 0);
	return (Il2CppObject *)__result;
}
// System.Void System.Func`2<System.Object,System.Single>::.ctor(System.Object,System.IntPtr)
extern "C"  void Func_2__ctor_m1874497973_gshared (Func_2_t2212564818 * __this, Il2CppObject * ___object0, IntPtr_t ___method1, const MethodInfo* method)
{
	__this->set_method_ptr_0((Il2CppMethodPointer)((MethodInfo*)___method1.get_m_value_0())->methodPointer);
	__this->set_method_3(___method1);
	__this->set_m_target_2(___object0);
}
// TResult System.Func`2<System.Object,System.Single>::Invoke(T)
extern "C"  float Func_2_Invoke_m1144286175_gshared (Func_2_t2212564818 * __this, Il2CppObject * ___arg10, const MethodInfo* method)
{
	if(__this->get_prev_9() != NULL)
	{
		Func_2_Invoke_m1144286175((Func_2_t2212564818 *)__this->get_prev_9(),___arg10, method);
	}
	il2cpp_codegen_raise_execution_engine_exception_if_method_is_not_found((MethodInfo*)(__this->get_method_3().get_m_value_0()));
	bool ___methodIsStatic = MethodIsStatic((MethodInfo*)(__this->get_method_3().get_m_value_0()));
	if (__this->get_m_target_2() != NULL && ___methodIsStatic)
	{
		typedef float (*FunctionPointerType) (Il2CppObject *, void* __this, Il2CppObject * ___arg10, const MethodInfo* method);
		return ((FunctionPointerType)__this->get_method_ptr_0())(NULL,__this->get_m_target_2(),___arg10,(MethodInfo*)(__this->get_method_3().get_m_value_0()));
	}
	else if (__this->get_m_target_2() != NULL || ___methodIsStatic)
	{
		typedef float (*FunctionPointerType) (void* __this, Il2CppObject * ___arg10, const MethodInfo* method);
		return ((FunctionPointerType)__this->get_method_ptr_0())(__this->get_m_target_2(),___arg10,(MethodInfo*)(__this->get_method_3().get_m_value_0()));
	}
	else
	{
		typedef float (*FunctionPointerType) (void* __this, const MethodInfo* method);
		return ((FunctionPointerType)__this->get_method_ptr_0())(___arg10,(MethodInfo*)(__this->get_method_3().get_m_value_0()));
	}
}
// System.IAsyncResult System.Func`2<System.Object,System.Single>::BeginInvoke(T,System.AsyncCallback,System.Object)
extern "C"  Il2CppObject * Func_2_BeginInvoke_m669892004_gshared (Func_2_t2212564818 * __this, Il2CppObject * ___arg10, AsyncCallback_t163412349 * ___callback1, Il2CppObject * ___object2, const MethodInfo* method)
{
	void *__d_args[2] = {0};
	__d_args[0] = ___arg10;
	return (Il2CppObject *)il2cpp_codegen_delegate_begin_invoke((Il2CppDelegate*)__this, __d_args, (Il2CppDelegate*)___callback1, (Il2CppObject*)___object2);
}
// TResult System.Func`2<System.Object,System.Single>::EndInvoke(System.IAsyncResult)
extern "C"  float Func_2_EndInvoke_m971580865_gshared (Func_2_t2212564818 * __this, Il2CppObject * ___result0, const MethodInfo* method)
{
	Il2CppObject *__result = il2cpp_codegen_delegate_end_invoke((Il2CppAsyncResult*) ___result0, 0);
	return *(float*)UnBox ((Il2CppCodeGenObject*)__result);
}
// System.Void System.Linq.Enumerable/<CreateCastIterator>c__Iterator0`1<System.Object>::.ctor()
extern "C"  void U3CCreateCastIteratorU3Ec__Iterator0_1__ctor_m3321498162_gshared (U3CCreateCastIteratorU3Ec__Iterator0_1_t1397100709 * __this, const MethodInfo* method)
{
	{
		NullCheck((Il2CppObject *)__this);
		Object__ctor_m2551263788((Il2CppObject *)__this, /*hidden argument*/NULL);
		return;
	}
}
// TResult System.Linq.Enumerable/<CreateCastIterator>c__Iterator0`1<System.Object>::System.Collections.Generic.IEnumerator<TResult>.get_Current()
extern "C"  Il2CppObject * U3CCreateCastIteratorU3Ec__Iterator0_1_System_Collections_Generic_IEnumeratorU3CTResultU3E_get_Current_m2659351773_gshared (U3CCreateCastIteratorU3Ec__Iterator0_1_t1397100709 * __this, const MethodInfo* method)
{
	{
		Il2CppObject * L_0 = (Il2CppObject *)__this->get_U24current_4();
		return L_0;
	}
}
// System.Object System.Linq.Enumerable/<CreateCastIterator>c__Iterator0`1<System.Object>::System.Collections.IEnumerator.get_Current()
extern "C"  Il2CppObject * U3CCreateCastIteratorU3Ec__Iterator0_1_System_Collections_IEnumerator_get_Current_m2940047778_gshared (U3CCreateCastIteratorU3Ec__Iterator0_1_t1397100709 * __this, const MethodInfo* method)
{
	{
		Il2CppObject * L_0 = (Il2CppObject *)__this->get_U24current_4();
		return L_0;
	}
}
// System.Collections.IEnumerator System.Linq.Enumerable/<CreateCastIterator>c__Iterator0`1<System.Object>::System.Collections.IEnumerable.GetEnumerator()
extern "C"  Il2CppObject * U3CCreateCastIteratorU3Ec__Iterator0_1_System_Collections_IEnumerable_GetEnumerator_m3746809729_gshared (U3CCreateCastIteratorU3Ec__Iterator0_1_t1397100709 * __this, const MethodInfo* method)
{
	{
		NullCheck((U3CCreateCastIteratorU3Ec__Iterator0_1_t1397100709 *)__this);
		Il2CppObject* L_0 = ((  Il2CppObject* (*) (U3CCreateCastIteratorU3Ec__Iterator0_1_t1397100709 *, const MethodInfo*))IL2CPP_RGCTX_METHOD_INFO(method->declaring_type->rgctx_data, 1)->methodPointer)((U3CCreateCastIteratorU3Ec__Iterator0_1_t1397100709 *)__this, /*hidden argument*/IL2CPP_RGCTX_METHOD_INFO(method->declaring_type->rgctx_data, 1));
		return L_0;
	}
}
// System.Collections.Generic.IEnumerator`1<TResult> System.Linq.Enumerable/<CreateCastIterator>c__Iterator0`1<System.Object>::System.Collections.Generic.IEnumerable<TResult>.GetEnumerator()
extern "C"  Il2CppObject* U3CCreateCastIteratorU3Ec__Iterator0_1_System_Collections_Generic_IEnumerableU3CTResultU3E_GetEnumerator_m3785434980_gshared (U3CCreateCastIteratorU3Ec__Iterator0_1_t1397100709 * __this, const MethodInfo* method)
{
	U3CCreateCastIteratorU3Ec__Iterator0_1_t1397100709 * V_0 = NULL;
	{
		int32_t* L_0 = (int32_t*)__this->get_address_of_U24PC_3();
		int32_t L_1 = Interlocked_CompareExchange_m3339239614(NULL /*static, unused*/, (int32_t*)L_0, (int32_t)0, (int32_t)((int32_t)-2), /*hidden argument*/NULL);
		if ((!(((uint32_t)L_1) == ((uint32_t)((int32_t)-2)))))
		{
			goto IL_0014;
		}
	}
	{
		return __this;
	}

IL_0014:
	{
		U3CCreateCastIteratorU3Ec__Iterator0_1_t1397100709 * L_2 = (U3CCreateCastIteratorU3Ec__Iterator0_1_t1397100709 *)il2cpp_codegen_object_new(IL2CPP_RGCTX_DATA(method->declaring_type->rgctx_data, 2));
		((  void (*) (U3CCreateCastIteratorU3Ec__Iterator0_1_t1397100709 *, const MethodInfo*))IL2CPP_RGCTX_METHOD_INFO(method->declaring_type->rgctx_data, 3)->methodPointer)(L_2, /*hidden argument*/IL2CPP_RGCTX_METHOD_INFO(method->declaring_type->rgctx_data, 3));
		V_0 = (U3CCreateCastIteratorU3Ec__Iterator0_1_t1397100709 *)L_2;
		U3CCreateCastIteratorU3Ec__Iterator0_1_t1397100709 * L_3 = V_0;
		Il2CppObject * L_4 = (Il2CppObject *)__this->get_U3CU24U3Esource_5();
		NullCheck(L_3);
		L_3->set_source_0(L_4);
		U3CCreateCastIteratorU3Ec__Iterator0_1_t1397100709 * L_5 = V_0;
		return L_5;
	}
}
// System.Boolean System.Linq.Enumerable/<CreateCastIterator>c__Iterator0`1<System.Object>::MoveNext()
extern Il2CppClass* IEnumerable_t2911409499_il2cpp_TypeInfo_var;
extern Il2CppClass* IEnumerator_t1466026749_il2cpp_TypeInfo_var;
extern Il2CppClass* IDisposable_t2427283555_il2cpp_TypeInfo_var;
extern const uint32_t U3CCreateCastIteratorU3Ec__Iterator0_1_MoveNext_m3444743414_MetadataUsageId;
extern "C"  bool U3CCreateCastIteratorU3Ec__Iterator0_1_MoveNext_m3444743414_gshared (U3CCreateCastIteratorU3Ec__Iterator0_1_t1397100709 * __this, const MethodInfo* method)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_method (U3CCreateCastIteratorU3Ec__Iterator0_1_MoveNext_m3444743414_MetadataUsageId);
		s_Il2CppMethodInitialized = true;
	}
	uint32_t V_0 = 0;
	bool V_1 = false;
	Il2CppObject * V_2 = NULL;
	bool V_3 = false;
	Exception_t1927440687 * __last_unhandled_exception = 0;
	NO_UNUSED_WARNING (__last_unhandled_exception);
	Exception_t1927440687 * __exception_local = 0;
	NO_UNUSED_WARNING (__exception_local);
	int32_t __leave_target = 0;
	NO_UNUSED_WARNING (__leave_target);
	{
		int32_t L_0 = (int32_t)__this->get_U24PC_3();
		V_0 = (uint32_t)L_0;
		__this->set_U24PC_3((-1));
		V_1 = (bool)0;
		uint32_t L_1 = V_0;
		if (L_1 == 0)
		{
			goto IL_0023;
		}
		if (L_1 == 1)
		{
			goto IL_0037;
		}
	}
	{
		goto IL_00af;
	}

IL_0023:
	{
		Il2CppObject * L_2 = (Il2CppObject *)__this->get_source_0();
		NullCheck((Il2CppObject *)L_2);
		Il2CppObject * L_3 = InterfaceFuncInvoker0< Il2CppObject * >::Invoke(0 /* System.Collections.IEnumerator System.Collections.IEnumerable::GetEnumerator() */, IEnumerable_t2911409499_il2cpp_TypeInfo_var, (Il2CppObject *)L_2);
		__this->set_U3CU24s_59U3E__0_1(L_3);
		V_0 = (uint32_t)((int32_t)-3);
	}

IL_0037:
	try
	{ // begin try (depth: 1)
		{
			uint32_t L_4 = V_0;
			if (((int32_t)((int32_t)L_4-(int32_t)1)) == 0)
			{
				goto IL_0078;
			}
		}

IL_0043:
		{
			goto IL_0078;
		}

IL_0048:
		{
			Il2CppObject * L_5 = (Il2CppObject *)__this->get_U3CU24s_59U3E__0_1();
			NullCheck((Il2CppObject *)L_5);
			Il2CppObject * L_6 = InterfaceFuncInvoker0< Il2CppObject * >::Invoke(0 /* System.Object System.Collections.IEnumerator::get_Current() */, IEnumerator_t1466026749_il2cpp_TypeInfo_var, (Il2CppObject *)L_5);
			__this->set_U3CelementU3E__1_2(((Il2CppObject *)Castclass(L_6, IL2CPP_RGCTX_DATA(method->declaring_type->rgctx_data, 0))));
			Il2CppObject * L_7 = (Il2CppObject *)__this->get_U3CelementU3E__1_2();
			__this->set_U24current_4(L_7);
			__this->set_U24PC_3(1);
			V_1 = (bool)1;
			IL2CPP_LEAVE(0xB1, FINALLY_008d);
		}

IL_0078:
		{
			Il2CppObject * L_8 = (Il2CppObject *)__this->get_U3CU24s_59U3E__0_1();
			NullCheck((Il2CppObject *)L_8);
			bool L_9 = InterfaceFuncInvoker0< bool >::Invoke(1 /* System.Boolean System.Collections.IEnumerator::MoveNext() */, IEnumerator_t1466026749_il2cpp_TypeInfo_var, (Il2CppObject *)L_8);
			if (L_9)
			{
				goto IL_0048;
			}
		}

IL_0088:
		{
			IL2CPP_LEAVE(0xA8, FINALLY_008d);
		}
	} // end try (depth: 1)
	catch(Il2CppExceptionWrapper& e)
	{
		__last_unhandled_exception = (Exception_t1927440687 *)e.ex;
		goto FINALLY_008d;
	}

FINALLY_008d:
	{ // begin finally (depth: 1)
		{
			bool L_10 = V_1;
			if (!L_10)
			{
				goto IL_0091;
			}
		}

IL_0090:
		{
			IL2CPP_END_FINALLY(141)
		}

IL_0091:
		{
			Il2CppObject * L_11 = (Il2CppObject *)__this->get_U3CU24s_59U3E__0_1();
			V_2 = (Il2CppObject *)((Il2CppObject *)IsInst(L_11, IDisposable_t2427283555_il2cpp_TypeInfo_var));
			Il2CppObject * L_12 = V_2;
			if (L_12)
			{
				goto IL_00a1;
			}
		}

IL_00a0:
		{
			IL2CPP_END_FINALLY(141)
		}

IL_00a1:
		{
			Il2CppObject * L_13 = V_2;
			NullCheck((Il2CppObject *)L_13);
			InterfaceActionInvoker0::Invoke(0 /* System.Void System.IDisposable::Dispose() */, IDisposable_t2427283555_il2cpp_TypeInfo_var, (Il2CppObject *)L_13);
			IL2CPP_END_FINALLY(141)
		}
	} // end finally (depth: 1)
	IL2CPP_CLEANUP(141)
	{
		IL2CPP_JUMP_TBL(0xB1, IL_00b1)
		IL2CPP_JUMP_TBL(0xA8, IL_00a8)
		IL2CPP_RETHROW_IF_UNHANDLED(Exception_t1927440687 *)
	}

IL_00a8:
	{
		__this->set_U24PC_3((-1));
	}

IL_00af:
	{
		return (bool)0;
	}

IL_00b1:
	{
		return (bool)1;
	}
	// Dead block : IL_00b3: ldloc.3
}
// System.Void System.Linq.Enumerable/<CreateCastIterator>c__Iterator0`1<System.Object>::Dispose()
extern Il2CppClass* IDisposable_t2427283555_il2cpp_TypeInfo_var;
extern const uint32_t U3CCreateCastIteratorU3Ec__Iterator0_1_Dispose_m3972648411_MetadataUsageId;
extern "C"  void U3CCreateCastIteratorU3Ec__Iterator0_1_Dispose_m3972648411_gshared (U3CCreateCastIteratorU3Ec__Iterator0_1_t1397100709 * __this, const MethodInfo* method)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_method (U3CCreateCastIteratorU3Ec__Iterator0_1_Dispose_m3972648411_MetadataUsageId);
		s_Il2CppMethodInitialized = true;
	}
	uint32_t V_0 = 0;
	Il2CppObject * V_1 = NULL;
	Exception_t1927440687 * __last_unhandled_exception = 0;
	NO_UNUSED_WARNING (__last_unhandled_exception);
	Exception_t1927440687 * __exception_local = 0;
	NO_UNUSED_WARNING (__exception_local);
	int32_t __leave_target = 0;
	NO_UNUSED_WARNING (__leave_target);
	{
		int32_t L_0 = (int32_t)__this->get_U24PC_3();
		V_0 = (uint32_t)L_0;
		__this->set_U24PC_3((-1));
		uint32_t L_1 = V_0;
		if (L_1 == 0)
		{
			goto IL_003d;
		}
		if (L_1 == 1)
		{
			goto IL_0021;
		}
	}
	{
		goto IL_003d;
	}

IL_0021:
	try
	{ // begin try (depth: 1)
		IL2CPP_LEAVE(0x3D, FINALLY_0026);
	} // end try (depth: 1)
	catch(Il2CppExceptionWrapper& e)
	{
		__last_unhandled_exception = (Exception_t1927440687 *)e.ex;
		goto FINALLY_0026;
	}

FINALLY_0026:
	{ // begin finally (depth: 1)
		{
			Il2CppObject * L_2 = (Il2CppObject *)__this->get_U3CU24s_59U3E__0_1();
			V_1 = (Il2CppObject *)((Il2CppObject *)IsInst(L_2, IDisposable_t2427283555_il2cpp_TypeInfo_var));
			Il2CppObject * L_3 = V_1;
			if (L_3)
			{
				goto IL_0036;
			}
		}

IL_0035:
		{
			IL2CPP_END_FINALLY(38)
		}

IL_0036:
		{
			Il2CppObject * L_4 = V_1;
			NullCheck((Il2CppObject *)L_4);
			InterfaceActionInvoker0::Invoke(0 /* System.Void System.IDisposable::Dispose() */, IDisposable_t2427283555_il2cpp_TypeInfo_var, (Il2CppObject *)L_4);
			IL2CPP_END_FINALLY(38)
		}
	} // end finally (depth: 1)
	IL2CPP_CLEANUP(38)
	{
		IL2CPP_JUMP_TBL(0x3D, IL_003d)
		IL2CPP_RETHROW_IF_UNHANDLED(Exception_t1927440687 *)
	}

IL_003d:
	{
		return;
	}
}
// System.Void System.Linq.Enumerable/<CreateCastIterator>c__Iterator0`1<System.Object>::Reset()
extern Il2CppClass* NotSupportedException_t1793819818_il2cpp_TypeInfo_var;
extern const uint32_t U3CCreateCastIteratorU3Ec__Iterator0_1_Reset_m2250535601_MetadataUsageId;
extern "C"  void U3CCreateCastIteratorU3Ec__Iterator0_1_Reset_m2250535601_gshared (U3CCreateCastIteratorU3Ec__Iterator0_1_t1397100709 * __this, const MethodInfo* method)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_method (U3CCreateCastIteratorU3Ec__Iterator0_1_Reset_m2250535601_MetadataUsageId);
		s_Il2CppMethodInitialized = true;
	}
	{
		NotSupportedException_t1793819818 * L_0 = (NotSupportedException_t1793819818 *)il2cpp_codegen_object_new(NotSupportedException_t1793819818_il2cpp_TypeInfo_var);
		NotSupportedException__ctor_m3232764727(L_0, /*hidden argument*/NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0);
	}
}
// System.Void System.Linq.Enumerable/<CreateWhereIterator>c__Iterator1D`1<System.Object>::.ctor()
extern "C"  void U3CCreateWhereIteratorU3Ec__Iterator1D_1__ctor_m1958283157_gshared (U3CCreateWhereIteratorU3Ec__Iterator1D_1_t4121738870 * __this, const MethodInfo* method)
{
	{
		NullCheck((Il2CppObject *)__this);
		Object__ctor_m2551263788((Il2CppObject *)__this, /*hidden argument*/NULL);
		return;
	}
}
// TSource System.Linq.Enumerable/<CreateWhereIterator>c__Iterator1D`1<System.Object>::System.Collections.Generic.IEnumerator<TSource>.get_Current()
extern "C"  Il2CppObject * U3CCreateWhereIteratorU3Ec__Iterator1D_1_System_Collections_Generic_IEnumeratorU3CTSourceU3E_get_Current_m3602665650_gshared (U3CCreateWhereIteratorU3Ec__Iterator1D_1_t4121738870 * __this, const MethodInfo* method)
{
	{
		Il2CppObject * L_0 = (Il2CppObject *)__this->get_U24current_5();
		return L_0;
	}
}
// System.Object System.Linq.Enumerable/<CreateWhereIterator>c__Iterator1D`1<System.Object>::System.Collections.IEnumerator.get_Current()
extern "C"  Il2CppObject * U3CCreateWhereIteratorU3Ec__Iterator1D_1_System_Collections_IEnumerator_get_Current_m269113779_gshared (U3CCreateWhereIteratorU3Ec__Iterator1D_1_t4121738870 * __this, const MethodInfo* method)
{
	{
		Il2CppObject * L_0 = (Il2CppObject *)__this->get_U24current_5();
		return L_0;
	}
}
// System.Collections.IEnumerator System.Linq.Enumerable/<CreateWhereIterator>c__Iterator1D`1<System.Object>::System.Collections.IEnumerable.GetEnumerator()
extern "C"  Il2CppObject * U3CCreateWhereIteratorU3Ec__Iterator1D_1_System_Collections_IEnumerable_GetEnumerator_m3279674866_gshared (U3CCreateWhereIteratorU3Ec__Iterator1D_1_t4121738870 * __this, const MethodInfo* method)
{
	{
		NullCheck((U3CCreateWhereIteratorU3Ec__Iterator1D_1_t4121738870 *)__this);
		Il2CppObject* L_0 = ((  Il2CppObject* (*) (U3CCreateWhereIteratorU3Ec__Iterator1D_1_t4121738870 *, const MethodInfo*))IL2CPP_RGCTX_METHOD_INFO(method->declaring_type->rgctx_data, 1)->methodPointer)((U3CCreateWhereIteratorU3Ec__Iterator1D_1_t4121738870 *)__this, /*hidden argument*/IL2CPP_RGCTX_METHOD_INFO(method->declaring_type->rgctx_data, 1));
		return L_0;
	}
}
// System.Collections.Generic.IEnumerator`1<TSource> System.Linq.Enumerable/<CreateWhereIterator>c__Iterator1D`1<System.Object>::System.Collections.Generic.IEnumerable<TSource>.GetEnumerator()
extern "C"  Il2CppObject* U3CCreateWhereIteratorU3Ec__Iterator1D_1_System_Collections_Generic_IEnumerableU3CTSourceU3E_GetEnumerator_m2682676065_gshared (U3CCreateWhereIteratorU3Ec__Iterator1D_1_t4121738870 * __this, const MethodInfo* method)
{
	U3CCreateWhereIteratorU3Ec__Iterator1D_1_t4121738870 * V_0 = NULL;
	{
		int32_t* L_0 = (int32_t*)__this->get_address_of_U24PC_4();
		int32_t L_1 = Interlocked_CompareExchange_m3339239614(NULL /*static, unused*/, (int32_t*)L_0, (int32_t)0, (int32_t)((int32_t)-2), /*hidden argument*/NULL);
		if ((!(((uint32_t)L_1) == ((uint32_t)((int32_t)-2)))))
		{
			goto IL_0014;
		}
	}
	{
		return __this;
	}

IL_0014:
	{
		U3CCreateWhereIteratorU3Ec__Iterator1D_1_t4121738870 * L_2 = (U3CCreateWhereIteratorU3Ec__Iterator1D_1_t4121738870 *)il2cpp_codegen_object_new(IL2CPP_RGCTX_DATA(method->declaring_type->rgctx_data, 2));
		((  void (*) (U3CCreateWhereIteratorU3Ec__Iterator1D_1_t4121738870 *, const MethodInfo*))IL2CPP_RGCTX_METHOD_INFO(method->declaring_type->rgctx_data, 3)->methodPointer)(L_2, /*hidden argument*/IL2CPP_RGCTX_METHOD_INFO(method->declaring_type->rgctx_data, 3));
		V_0 = (U3CCreateWhereIteratorU3Ec__Iterator1D_1_t4121738870 *)L_2;
		U3CCreateWhereIteratorU3Ec__Iterator1D_1_t4121738870 * L_3 = V_0;
		Il2CppObject* L_4 = (Il2CppObject*)__this->get_U3CU24U3Esource_6();
		NullCheck(L_3);
		L_3->set_source_0(L_4);
		U3CCreateWhereIteratorU3Ec__Iterator1D_1_t4121738870 * L_5 = V_0;
		Func_2_t3961629604 * L_6 = (Func_2_t3961629604 *)__this->get_U3CU24U3Epredicate_7();
		NullCheck(L_5);
		L_5->set_predicate_3(L_6);
		U3CCreateWhereIteratorU3Ec__Iterator1D_1_t4121738870 * L_7 = V_0;
		return L_7;
	}
}
// System.Boolean System.Linq.Enumerable/<CreateWhereIterator>c__Iterator1D`1<System.Object>::MoveNext()
extern Il2CppClass* IEnumerator_t1466026749_il2cpp_TypeInfo_var;
extern Il2CppClass* IDisposable_t2427283555_il2cpp_TypeInfo_var;
extern const uint32_t U3CCreateWhereIteratorU3Ec__Iterator1D_1_MoveNext_m3533253043_MetadataUsageId;
extern "C"  bool U3CCreateWhereIteratorU3Ec__Iterator1D_1_MoveNext_m3533253043_gshared (U3CCreateWhereIteratorU3Ec__Iterator1D_1_t4121738870 * __this, const MethodInfo* method)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_method (U3CCreateWhereIteratorU3Ec__Iterator1D_1_MoveNext_m3533253043_MetadataUsageId);
		s_Il2CppMethodInitialized = true;
	}
	uint32_t V_0 = 0;
	bool V_1 = false;
	bool V_2 = false;
	Exception_t1927440687 * __last_unhandled_exception = 0;
	NO_UNUSED_WARNING (__last_unhandled_exception);
	Exception_t1927440687 * __exception_local = 0;
	NO_UNUSED_WARNING (__exception_local);
	int32_t __leave_target = 0;
	NO_UNUSED_WARNING (__leave_target);
	{
		int32_t L_0 = (int32_t)__this->get_U24PC_4();
		V_0 = (uint32_t)L_0;
		__this->set_U24PC_4((-1));
		V_1 = (bool)0;
		uint32_t L_1 = V_0;
		if (L_1 == 0)
		{
			goto IL_0023;
		}
		if (L_1 == 1)
		{
			goto IL_0037;
		}
	}
	{
		goto IL_00be;
	}

IL_0023:
	{
		Il2CppObject* L_2 = (Il2CppObject*)__this->get_source_0();
		NullCheck((Il2CppObject*)L_2);
		Il2CppObject* L_3 = InterfaceFuncInvoker0< Il2CppObject* >::Invoke(0 /* System.Collections.Generic.IEnumerator`1<!0> System.Collections.Generic.IEnumerable`1<System.Object>::GetEnumerator() */, IL2CPP_RGCTX_DATA(method->declaring_type->rgctx_data, 4), (Il2CppObject*)L_2);
		__this->set_U3CU24s_120U3E__0_1(L_3);
		V_0 = (uint32_t)((int32_t)-3);
	}

IL_0037:
	try
	{ // begin try (depth: 1)
		{
			uint32_t L_4 = V_0;
			if (((int32_t)((int32_t)L_4-(int32_t)1)) == 0)
			{
				goto IL_0089;
			}
		}

IL_0043:
		{
			goto IL_0089;
		}

IL_0048:
		{
			Il2CppObject* L_5 = (Il2CppObject*)__this->get_U3CU24s_120U3E__0_1();
			NullCheck((Il2CppObject*)L_5);
			Il2CppObject * L_6 = InterfaceFuncInvoker0< Il2CppObject * >::Invoke(0 /* !0 System.Collections.Generic.IEnumerator`1<System.Object>::get_Current() */, IL2CPP_RGCTX_DATA(method->declaring_type->rgctx_data, 5), (Il2CppObject*)L_5);
			__this->set_U3CelementU3E__1_2(L_6);
			Func_2_t3961629604 * L_7 = (Func_2_t3961629604 *)__this->get_predicate_3();
			Il2CppObject * L_8 = (Il2CppObject *)__this->get_U3CelementU3E__1_2();
			NullCheck((Func_2_t3961629604 *)L_7);
			bool L_9 = ((  bool (*) (Func_2_t3961629604 *, Il2CppObject *, const MethodInfo*))IL2CPP_RGCTX_METHOD_INFO(method->declaring_type->rgctx_data, 6)->methodPointer)((Func_2_t3961629604 *)L_7, (Il2CppObject *)L_8, /*hidden argument*/IL2CPP_RGCTX_METHOD_INFO(method->declaring_type->rgctx_data, 6));
			if (!L_9)
			{
				goto IL_0089;
			}
		}

IL_006f:
		{
			Il2CppObject * L_10 = (Il2CppObject *)__this->get_U3CelementU3E__1_2();
			__this->set_U24current_5(L_10);
			__this->set_U24PC_4(1);
			V_1 = (bool)1;
			IL2CPP_LEAVE(0xC0, FINALLY_009e);
		}

IL_0089:
		{
			Il2CppObject* L_11 = (Il2CppObject*)__this->get_U3CU24s_120U3E__0_1();
			NullCheck((Il2CppObject *)L_11);
			bool L_12 = InterfaceFuncInvoker0< bool >::Invoke(1 /* System.Boolean System.Collections.IEnumerator::MoveNext() */, IEnumerator_t1466026749_il2cpp_TypeInfo_var, (Il2CppObject *)L_11);
			if (L_12)
			{
				goto IL_0048;
			}
		}

IL_0099:
		{
			IL2CPP_LEAVE(0xB7, FINALLY_009e);
		}
	} // end try (depth: 1)
	catch(Il2CppExceptionWrapper& e)
	{
		__last_unhandled_exception = (Exception_t1927440687 *)e.ex;
		goto FINALLY_009e;
	}

FINALLY_009e:
	{ // begin finally (depth: 1)
		{
			bool L_13 = V_1;
			if (!L_13)
			{
				goto IL_00a2;
			}
		}

IL_00a1:
		{
			IL2CPP_END_FINALLY(158)
		}

IL_00a2:
		{
			Il2CppObject* L_14 = (Il2CppObject*)__this->get_U3CU24s_120U3E__0_1();
			if (L_14)
			{
				goto IL_00ab;
			}
		}

IL_00aa:
		{
			IL2CPP_END_FINALLY(158)
		}

IL_00ab:
		{
			Il2CppObject* L_15 = (Il2CppObject*)__this->get_U3CU24s_120U3E__0_1();
			NullCheck((Il2CppObject *)L_15);
			InterfaceActionInvoker0::Invoke(0 /* System.Void System.IDisposable::Dispose() */, IDisposable_t2427283555_il2cpp_TypeInfo_var, (Il2CppObject *)L_15);
			IL2CPP_END_FINALLY(158)
		}
	} // end finally (depth: 1)
	IL2CPP_CLEANUP(158)
	{
		IL2CPP_JUMP_TBL(0xC0, IL_00c0)
		IL2CPP_JUMP_TBL(0xB7, IL_00b7)
		IL2CPP_RETHROW_IF_UNHANDLED(Exception_t1927440687 *)
	}

IL_00b7:
	{
		__this->set_U24PC_4((-1));
	}

IL_00be:
	{
		return (bool)0;
	}

IL_00c0:
	{
		return (bool)1;
	}
	// Dead block : IL_00c2: ldloc.2
}
// System.Void System.Linq.Enumerable/<CreateWhereIterator>c__Iterator1D`1<System.Object>::Dispose()
extern Il2CppClass* IDisposable_t2427283555_il2cpp_TypeInfo_var;
extern const uint32_t U3CCreateWhereIteratorU3Ec__Iterator1D_1_Dispose_m1879652802_MetadataUsageId;
extern "C"  void U3CCreateWhereIteratorU3Ec__Iterator1D_1_Dispose_m1879652802_gshared (U3CCreateWhereIteratorU3Ec__Iterator1D_1_t4121738870 * __this, const MethodInfo* method)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_method (U3CCreateWhereIteratorU3Ec__Iterator1D_1_Dispose_m1879652802_MetadataUsageId);
		s_Il2CppMethodInitialized = true;
	}
	uint32_t V_0 = 0;
	Exception_t1927440687 * __last_unhandled_exception = 0;
	NO_UNUSED_WARNING (__last_unhandled_exception);
	Exception_t1927440687 * __exception_local = 0;
	NO_UNUSED_WARNING (__exception_local);
	int32_t __leave_target = 0;
	NO_UNUSED_WARNING (__leave_target);
	{
		int32_t L_0 = (int32_t)__this->get_U24PC_4();
		V_0 = (uint32_t)L_0;
		__this->set_U24PC_4((-1));
		uint32_t L_1 = V_0;
		if (L_1 == 0)
		{
			goto IL_003b;
		}
		if (L_1 == 1)
		{
			goto IL_0021;
		}
	}
	{
		goto IL_003b;
	}

IL_0021:
	try
	{ // begin try (depth: 1)
		IL2CPP_LEAVE(0x3B, FINALLY_0026);
	} // end try (depth: 1)
	catch(Il2CppExceptionWrapper& e)
	{
		__last_unhandled_exception = (Exception_t1927440687 *)e.ex;
		goto FINALLY_0026;
	}

FINALLY_0026:
	{ // begin finally (depth: 1)
		{
			Il2CppObject* L_2 = (Il2CppObject*)__this->get_U3CU24s_120U3E__0_1();
			if (L_2)
			{
				goto IL_002f;
			}
		}

IL_002e:
		{
			IL2CPP_END_FINALLY(38)
		}

IL_002f:
		{
			Il2CppObject* L_3 = (Il2CppObject*)__this->get_U3CU24s_120U3E__0_1();
			NullCheck((Il2CppObject *)L_3);
			InterfaceActionInvoker0::Invoke(0 /* System.Void System.IDisposable::Dispose() */, IDisposable_t2427283555_il2cpp_TypeInfo_var, (Il2CppObject *)L_3);
			IL2CPP_END_FINALLY(38)
		}
	} // end finally (depth: 1)
	IL2CPP_CLEANUP(38)
	{
		IL2CPP_JUMP_TBL(0x3B, IL_003b)
		IL2CPP_RETHROW_IF_UNHANDLED(Exception_t1927440687 *)
	}

IL_003b:
	{
		return;
	}
}
// System.Void System.Linq.Enumerable/<CreateWhereIterator>c__Iterator1D`1<System.Object>::Reset()
extern Il2CppClass* NotSupportedException_t1793819818_il2cpp_TypeInfo_var;
extern const uint32_t U3CCreateWhereIteratorU3Ec__Iterator1D_1_Reset_m1773515612_MetadataUsageId;
extern "C"  void U3CCreateWhereIteratorU3Ec__Iterator1D_1_Reset_m1773515612_gshared (U3CCreateWhereIteratorU3Ec__Iterator1D_1_t4121738870 * __this, const MethodInfo* method)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_method (U3CCreateWhereIteratorU3Ec__Iterator1D_1_Reset_m1773515612_MetadataUsageId);
		s_Il2CppMethodInitialized = true;
	}
	{
		NotSupportedException_t1793819818 * L_0 = (NotSupportedException_t1793819818 *)il2cpp_codegen_object_new(NotSupportedException_t1793819818_il2cpp_TypeInfo_var);
		NotSupportedException__ctor_m3232764727(L_0, /*hidden argument*/NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0);
	}
}
// System.Void System.Nullable`1<GoogleMobileAds.Api.Gender>::.ctor(T)
extern "C"  void Nullable_1__ctor_m3936753491_gshared (Nullable_1_t1791139578 * __this, int32_t ___value0, const MethodInfo* method)
{
	{
		__this->set_has_value_1((bool)1);
		int32_t L_0 = ___value0;
		__this->set_value_0(L_0);
		return;
	}
}
extern "C"  void Nullable_1__ctor_m3936753491_AdjustorThunk (Il2CppObject * __this, int32_t ___value0, const MethodInfo* method)
{
	Nullable_1_t1791139578  _thisAdjusted;
	_thisAdjusted.set_value_0(*reinterpret_cast<int32_t*>(__this + 1));
	_thisAdjusted.set_has_value_1(true);
	Nullable_1__ctor_m3936753491(&_thisAdjusted, ___value0, method);
	*reinterpret_cast<int32_t*>(__this + 1) = _thisAdjusted.get_value_0();
}
// System.Boolean System.Nullable`1<GoogleMobileAds.Api.Gender>::get_HasValue()
extern "C"  bool Nullable_1_get_HasValue_m2852364250_gshared (Nullable_1_t1791139578 * __this, const MethodInfo* method)
{
	{
		bool L_0 = (bool)__this->get_has_value_1();
		return L_0;
	}
}
extern "C"  bool Nullable_1_get_HasValue_m2852364250_AdjustorThunk (Il2CppObject * __this, const MethodInfo* method)
{
	Nullable_1_t1791139578  _thisAdjusted;
	_thisAdjusted.set_value_0(*reinterpret_cast<int32_t*>(__this + 1));
	_thisAdjusted.set_has_value_1(true);
	bool _returnValue = Nullable_1_get_HasValue_m2852364250(&_thisAdjusted, method);
	*reinterpret_cast<int32_t*>(__this + 1) = _thisAdjusted.get_value_0();
	return _returnValue;
}
// T System.Nullable`1<GoogleMobileAds.Api.Gender>::get_Value()
extern Il2CppClass* InvalidOperationException_t721527559_il2cpp_TypeInfo_var;
extern Il2CppCodeGenString* _stringLiteral2004437333;
extern const uint32_t Nullable_1_get_Value_m4028165204_MetadataUsageId;
extern "C"  int32_t Nullable_1_get_Value_m4028165204_gshared (Nullable_1_t1791139578 * __this, const MethodInfo* method)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_method (Nullable_1_get_Value_m4028165204_MetadataUsageId);
		s_Il2CppMethodInitialized = true;
	}
	{
		bool L_0 = (bool)__this->get_has_value_1();
		if (L_0)
		{
			goto IL_0016;
		}
	}
	{
		InvalidOperationException_t721527559 * L_1 = (InvalidOperationException_t721527559 *)il2cpp_codegen_object_new(InvalidOperationException_t721527559_il2cpp_TypeInfo_var);
		InvalidOperationException__ctor_m2801133788(L_1, (String_t*)_stringLiteral2004437333, /*hidden argument*/NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1);
	}

IL_0016:
	{
		int32_t L_2 = (int32_t)__this->get_value_0();
		return L_2;
	}
}
extern "C"  int32_t Nullable_1_get_Value_m4028165204_AdjustorThunk (Il2CppObject * __this, const MethodInfo* method)
{
	Nullable_1_t1791139578  _thisAdjusted;
	_thisAdjusted.set_value_0(*reinterpret_cast<int32_t*>(__this + 1));
	_thisAdjusted.set_has_value_1(true);
	int32_t _returnValue = Nullable_1_get_Value_m4028165204(&_thisAdjusted, method);
	*reinterpret_cast<int32_t*>(__this + 1) = _thisAdjusted.get_value_0();
	return _returnValue;
}
// System.Boolean System.Nullable`1<GoogleMobileAds.Api.Gender>::Equals(System.Object)
extern "C"  bool Nullable_1_Equals_m946252930_gshared (Nullable_1_t1791139578 * __this, Il2CppObject * ___other0, const MethodInfo* method)
{
	{
		Il2CppObject * L_0 = ___other0;
		if (L_0)
		{
			goto IL_0010;
		}
	}
	{
		bool L_1 = (bool)__this->get_has_value_1();
		return (bool)((((int32_t)L_1) == ((int32_t)0))? 1 : 0);
	}

IL_0010:
	{
		Il2CppObject * L_2 = ___other0;
		if (((Il2CppObject *)IsInst(L_2, IL2CPP_RGCTX_DATA(InitializedTypeInfo(method->declaring_type)->rgctx_data, 0))))
		{
			goto IL_001d;
		}
	}
	{
		return (bool)0;
	}

IL_001d:
	{
		Il2CppObject * L_3 = ___other0;
		void* L_4 = alloca(sizeof(Nullable_1_t1791139578 ));
		UnBoxNullable(L_3, IL2CPP_RGCTX_DATA(InitializedTypeInfo(method->declaring_type)->rgctx_data, 0), L_4);
		bool L_5 = Nullable_1_Equals_m3656023435((Nullable_1_t1791139578 *)__this, (Nullable_1_t1791139578 )((*(Nullable_1_t1791139578 *)((Nullable_1_t1791139578 *)L_4))), /*hidden argument*/IL2CPP_RGCTX_METHOD_INFO(InitializedTypeInfo(method->declaring_type)->rgctx_data, 1));
		return L_5;
	}
}
extern "C"  bool Nullable_1_Equals_m946252930_AdjustorThunk (Il2CppObject * __this, Il2CppObject * ___other0, const MethodInfo* method)
{
	Nullable_1_t1791139578  _thisAdjusted;
	_thisAdjusted.set_value_0(*reinterpret_cast<int32_t*>(__this + 1));
	_thisAdjusted.set_has_value_1(true);
	bool _returnValue = Nullable_1_Equals_m946252930(&_thisAdjusted, ___other0, method);
	*reinterpret_cast<int32_t*>(__this + 1) = _thisAdjusted.get_value_0();
	return _returnValue;
}
// System.Boolean System.Nullable`1<GoogleMobileAds.Api.Gender>::Equals(System.Nullable`1<T>)
extern "C"  bool Nullable_1_Equals_m3656023435_gshared (Nullable_1_t1791139578 * __this, Nullable_1_t1791139578  ___other0, const MethodInfo* method)
{
	{
		bool L_0 = (bool)(&___other0)->get_has_value_1();
		bool L_1 = (bool)__this->get_has_value_1();
		if ((((int32_t)L_0) == ((int32_t)L_1)))
		{
			goto IL_0014;
		}
	}
	{
		return (bool)0;
	}

IL_0014:
	{
		bool L_2 = (bool)__this->get_has_value_1();
		if (L_2)
		{
			goto IL_0021;
		}
	}
	{
		return (bool)1;
	}

IL_0021:
	{
		int32_t* L_3 = (int32_t*)(&___other0)->get_address_of_value_0();
		int32_t L_4 = (int32_t)__this->get_value_0();
		int32_t L_5 = L_4;
		Il2CppObject * L_6 = Box(IL2CPP_RGCTX_DATA(InitializedTypeInfo(method->declaring_type)->rgctx_data, 2), &L_5);
		Il2CppObject * L_7 = Box(IL2CPP_RGCTX_DATA(InitializedTypeInfo(method->declaring_type)->rgctx_data, 2), L_3);
		NullCheck((ValueType_t3507792607 *)L_7);
		bool L_8 = VirtFuncInvoker1< bool, Il2CppObject * >::Invoke(0 /* System.Boolean System.ValueType::Equals(System.Object) */, (ValueType_t3507792607 *)L_7, (Il2CppObject *)L_6);
		return L_8;
	}
}
extern "C"  bool Nullable_1_Equals_m3656023435_AdjustorThunk (Il2CppObject * __this, Nullable_1_t1791139578  ___other0, const MethodInfo* method)
{
	Nullable_1_t1791139578  _thisAdjusted;
	_thisAdjusted.set_value_0(*reinterpret_cast<int32_t*>(__this + 1));
	_thisAdjusted.set_has_value_1(true);
	bool _returnValue = Nullable_1_Equals_m3656023435(&_thisAdjusted, ___other0, method);
	*reinterpret_cast<int32_t*>(__this + 1) = _thisAdjusted.get_value_0();
	return _returnValue;
}
// System.Int32 System.Nullable`1<GoogleMobileAds.Api.Gender>::GetHashCode()
extern "C"  int32_t Nullable_1_GetHashCode_m1605271698_gshared (Nullable_1_t1791139578 * __this, const MethodInfo* method)
{
	{
		bool L_0 = (bool)__this->get_has_value_1();
		if (L_0)
		{
			goto IL_000d;
		}
	}
	{
		return 0;
	}

IL_000d:
	{
		int32_t* L_1 = (int32_t*)__this->get_address_of_value_0();
		Il2CppObject * L_2 = Box(IL2CPP_RGCTX_DATA(InitializedTypeInfo(method->declaring_type)->rgctx_data, 2), L_1);
		NullCheck((ValueType_t3507792607 *)L_2);
		int32_t L_3 = VirtFuncInvoker0< int32_t >::Invoke(2 /* System.Int32 System.ValueType::GetHashCode() */, (ValueType_t3507792607 *)L_2);
		return L_3;
	}
}
extern "C"  int32_t Nullable_1_GetHashCode_m1605271698_AdjustorThunk (Il2CppObject * __this, const MethodInfo* method)
{
	Nullable_1_t1791139578  _thisAdjusted;
	_thisAdjusted.set_value_0(*reinterpret_cast<int32_t*>(__this + 1));
	_thisAdjusted.set_has_value_1(true);
	int32_t _returnValue = Nullable_1_GetHashCode_m1605271698(&_thisAdjusted, method);
	*reinterpret_cast<int32_t*>(__this + 1) = _thisAdjusted.get_value_0();
	return _returnValue;
}
// T System.Nullable`1<GoogleMobileAds.Api.Gender>::GetValueOrDefault()
extern Il2CppClass* Gender_t3528073263_il2cpp_TypeInfo_var;
extern const uint32_t Nullable_1_GetValueOrDefault_m278040267_MetadataUsageId;
extern "C"  int32_t Nullable_1_GetValueOrDefault_m278040267_gshared (Nullable_1_t1791139578 * __this, const MethodInfo* method)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_method (Nullable_1_GetValueOrDefault_m278040267_MetadataUsageId);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t G_B3_0 = 0;
	{
		bool L_0 = (bool)__this->get_has_value_1();
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		int32_t L_1 = (int32_t)__this->get_value_0();
		G_B3_0 = L_1;
		goto IL_001f;
	}

IL_0016:
	{
		Initobj (Gender_t3528073263_il2cpp_TypeInfo_var, (&V_0));
		int32_t L_2 = V_0;
		G_B3_0 = L_2;
	}

IL_001f:
	{
		return G_B3_0;
	}
}
extern "C"  int32_t Nullable_1_GetValueOrDefault_m278040267_AdjustorThunk (Il2CppObject * __this, const MethodInfo* method)
{
	Nullable_1_t1791139578  _thisAdjusted;
	_thisAdjusted.set_value_0(*reinterpret_cast<int32_t*>(__this + 1));
	_thisAdjusted.set_has_value_1(true);
	int32_t _returnValue = Nullable_1_GetValueOrDefault_m278040267(&_thisAdjusted, method);
	*reinterpret_cast<int32_t*>(__this + 1) = _thisAdjusted.get_value_0();
	return _returnValue;
}
// System.String System.Nullable`1<GoogleMobileAds.Api.Gender>::ToString()
extern Il2CppClass* String_t_il2cpp_TypeInfo_var;
extern const uint32_t Nullable_1_ToString_m2922378208_MetadataUsageId;
extern "C"  String_t* Nullable_1_ToString_m2922378208_gshared (Nullable_1_t1791139578 * __this, const MethodInfo* method)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_method (Nullable_1_ToString_m2922378208_MetadataUsageId);
		s_Il2CppMethodInitialized = true;
	}
	{
		bool L_0 = (bool)__this->get_has_value_1();
		if (!L_0)
		{
			goto IL_001d;
		}
	}
	{
		int32_t* L_1 = (int32_t*)__this->get_address_of_value_0();
		Il2CppObject * L_2 = Box(IL2CPP_RGCTX_DATA(InitializedTypeInfo(method->declaring_type)->rgctx_data, 2), L_1);
		NullCheck((ValueType_t3507792607 *)L_2);
		String_t* L_3 = VirtFuncInvoker0< String_t* >::Invoke(3 /* System.String System.ValueType::ToString() */, (ValueType_t3507792607 *)L_2);
		return L_3;
	}

IL_001d:
	{
		IL2CPP_RUNTIME_CLASS_INIT(String_t_il2cpp_TypeInfo_var);
		String_t* L_4 = ((String_t_StaticFields*)String_t_il2cpp_TypeInfo_var->static_fields)->get_Empty_2();
		return L_4;
	}
}
extern "C"  String_t* Nullable_1_ToString_m2922378208_AdjustorThunk (Il2CppObject * __this, const MethodInfo* method)
{
	Nullable_1_t1791139578  _thisAdjusted;
	_thisAdjusted.set_value_0(*reinterpret_cast<int32_t*>(__this + 1));
	_thisAdjusted.set_has_value_1(true);
	String_t* _returnValue = Nullable_1_ToString_m2922378208(&_thisAdjusted, method);
	*reinterpret_cast<int32_t*>(__this + 1) = _thisAdjusted.get_value_0();
	return _returnValue;
}
// System.Void System.Nullable`1<System.Boolean>::.ctor(T)
extern "C"  void Nullable_1__ctor_m3575886808_gshared (Nullable_1_t2088641033 * __this, bool ___value0, const MethodInfo* method)
{
	{
		__this->set_has_value_1((bool)1);
		bool L_0 = ___value0;
		__this->set_value_0(L_0);
		return;
	}
}
extern "C"  void Nullable_1__ctor_m3575886808_AdjustorThunk (Il2CppObject * __this, bool ___value0, const MethodInfo* method)
{
	Nullable_1_t2088641033  _thisAdjusted;
	_thisAdjusted.set_value_0(*reinterpret_cast<bool*>(__this + 1));
	_thisAdjusted.set_has_value_1(true);
	Nullable_1__ctor_m3575886808(&_thisAdjusted, ___value0, method);
	*reinterpret_cast<bool*>(__this + 1) = _thisAdjusted.get_value_0();
}
// System.Boolean System.Nullable`1<System.Boolean>::get_HasValue()
extern "C"  bool Nullable_1_get_HasValue_m1733730025_gshared (Nullable_1_t2088641033 * __this, const MethodInfo* method)
{
	{
		bool L_0 = (bool)__this->get_has_value_1();
		return L_0;
	}
}
extern "C"  bool Nullable_1_get_HasValue_m1733730025_AdjustorThunk (Il2CppObject * __this, const MethodInfo* method)
{
	Nullable_1_t2088641033  _thisAdjusted;
	_thisAdjusted.set_value_0(*reinterpret_cast<bool*>(__this + 1));
	_thisAdjusted.set_has_value_1(true);
	bool _returnValue = Nullable_1_get_HasValue_m1733730025(&_thisAdjusted, method);
	*reinterpret_cast<bool*>(__this + 1) = _thisAdjusted.get_value_0();
	return _returnValue;
}
// T System.Nullable`1<System.Boolean>::get_Value()
extern Il2CppClass* InvalidOperationException_t721527559_il2cpp_TypeInfo_var;
extern Il2CppCodeGenString* _stringLiteral2004437333;
extern const uint32_t Nullable_1_get_Value_m1158440123_MetadataUsageId;
extern "C"  bool Nullable_1_get_Value_m1158440123_gshared (Nullable_1_t2088641033 * __this, const MethodInfo* method)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_method (Nullable_1_get_Value_m1158440123_MetadataUsageId);
		s_Il2CppMethodInitialized = true;
	}
	{
		bool L_0 = (bool)__this->get_has_value_1();
		if (L_0)
		{
			goto IL_0016;
		}
	}
	{
		InvalidOperationException_t721527559 * L_1 = (InvalidOperationException_t721527559 *)il2cpp_codegen_object_new(InvalidOperationException_t721527559_il2cpp_TypeInfo_var);
		InvalidOperationException__ctor_m2801133788(L_1, (String_t*)_stringLiteral2004437333, /*hidden argument*/NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1);
	}

IL_0016:
	{
		bool L_2 = (bool)__this->get_value_0();
		return L_2;
	}
}
extern "C"  bool Nullable_1_get_Value_m1158440123_AdjustorThunk (Il2CppObject * __this, const MethodInfo* method)
{
	Nullable_1_t2088641033  _thisAdjusted;
	_thisAdjusted.set_value_0(*reinterpret_cast<bool*>(__this + 1));
	_thisAdjusted.set_has_value_1(true);
	bool _returnValue = Nullable_1_get_Value_m1158440123(&_thisAdjusted, method);
	*reinterpret_cast<bool*>(__this + 1) = _thisAdjusted.get_value_0();
	return _returnValue;
}
// System.Boolean System.Nullable`1<System.Boolean>::Equals(System.Object)
extern "C"  bool Nullable_1_Equals_m1318699267_gshared (Nullable_1_t2088641033 * __this, Il2CppObject * ___other0, const MethodInfo* method)
{
	{
		Il2CppObject * L_0 = ___other0;
		if (L_0)
		{
			goto IL_0010;
		}
	}
	{
		bool L_1 = (bool)__this->get_has_value_1();
		return (bool)((((int32_t)L_1) == ((int32_t)0))? 1 : 0);
	}

IL_0010:
	{
		Il2CppObject * L_2 = ___other0;
		if (((Il2CppObject *)IsInst(L_2, IL2CPP_RGCTX_DATA(InitializedTypeInfo(method->declaring_type)->rgctx_data, 0))))
		{
			goto IL_001d;
		}
	}
	{
		return (bool)0;
	}

IL_001d:
	{
		Il2CppObject * L_3 = ___other0;
		void* L_4 = alloca(sizeof(Nullable_1_t2088641033 ));
		UnBoxNullable(L_3, IL2CPP_RGCTX_DATA(InitializedTypeInfo(method->declaring_type)->rgctx_data, 0), L_4);
		bool L_5 = Nullable_1_Equals_m2189684888((Nullable_1_t2088641033 *)__this, (Nullable_1_t2088641033 )((*(Nullable_1_t2088641033 *)((Nullable_1_t2088641033 *)L_4))), /*hidden argument*/IL2CPP_RGCTX_METHOD_INFO(InitializedTypeInfo(method->declaring_type)->rgctx_data, 1));
		return L_5;
	}
}
extern "C"  bool Nullable_1_Equals_m1318699267_AdjustorThunk (Il2CppObject * __this, Il2CppObject * ___other0, const MethodInfo* method)
{
	Nullable_1_t2088641033  _thisAdjusted;
	_thisAdjusted.set_value_0(*reinterpret_cast<bool*>(__this + 1));
	_thisAdjusted.set_has_value_1(true);
	bool _returnValue = Nullable_1_Equals_m1318699267(&_thisAdjusted, ___other0, method);
	*reinterpret_cast<bool*>(__this + 1) = _thisAdjusted.get_value_0();
	return _returnValue;
}
// System.Boolean System.Nullable`1<System.Boolean>::Equals(System.Nullable`1<T>)
extern "C"  bool Nullable_1_Equals_m2189684888_gshared (Nullable_1_t2088641033 * __this, Nullable_1_t2088641033  ___other0, const MethodInfo* method)
{
	{
		bool L_0 = (bool)(&___other0)->get_has_value_1();
		bool L_1 = (bool)__this->get_has_value_1();
		if ((((int32_t)L_0) == ((int32_t)L_1)))
		{
			goto IL_0014;
		}
	}
	{
		return (bool)0;
	}

IL_0014:
	{
		bool L_2 = (bool)__this->get_has_value_1();
		if (L_2)
		{
			goto IL_0021;
		}
	}
	{
		return (bool)1;
	}

IL_0021:
	{
		bool* L_3 = (bool*)(&___other0)->get_address_of_value_0();
		bool L_4 = (bool)__this->get_value_0();
		bool L_5 = L_4;
		Il2CppObject * L_6 = Box(IL2CPP_RGCTX_DATA(InitializedTypeInfo(method->declaring_type)->rgctx_data, 2), &L_5);
		bool L_7 = Boolean_Equals_m2118901528((bool*)L_3, (Il2CppObject *)L_6, /*hidden argument*/NULL);
		return L_7;
	}
}
extern "C"  bool Nullable_1_Equals_m2189684888_AdjustorThunk (Il2CppObject * __this, Nullable_1_t2088641033  ___other0, const MethodInfo* method)
{
	Nullable_1_t2088641033  _thisAdjusted;
	_thisAdjusted.set_value_0(*reinterpret_cast<bool*>(__this + 1));
	_thisAdjusted.set_has_value_1(true);
	bool _returnValue = Nullable_1_Equals_m2189684888(&_thisAdjusted, ___other0, method);
	*reinterpret_cast<bool*>(__this + 1) = _thisAdjusted.get_value_0();
	return _returnValue;
}
// System.Int32 System.Nullable`1<System.Boolean>::GetHashCode()
extern "C"  int32_t Nullable_1_GetHashCode_m1645245653_gshared (Nullable_1_t2088641033 * __this, const MethodInfo* method)
{
	{
		bool L_0 = (bool)__this->get_has_value_1();
		if (L_0)
		{
			goto IL_000d;
		}
	}
	{
		return 0;
	}

IL_000d:
	{
		bool* L_1 = (bool*)__this->get_address_of_value_0();
		int32_t L_2 = Boolean_GetHashCode_m1894638460((bool*)L_1, /*hidden argument*/NULL);
		return L_2;
	}
}
extern "C"  int32_t Nullable_1_GetHashCode_m1645245653_AdjustorThunk (Il2CppObject * __this, const MethodInfo* method)
{
	Nullable_1_t2088641033  _thisAdjusted;
	_thisAdjusted.set_value_0(*reinterpret_cast<bool*>(__this + 1));
	_thisAdjusted.set_has_value_1(true);
	int32_t _returnValue = Nullable_1_GetHashCode_m1645245653(&_thisAdjusted, method);
	*reinterpret_cast<bool*>(__this + 1) = _thisAdjusted.get_value_0();
	return _returnValue;
}
// T System.Nullable`1<System.Boolean>::GetValueOrDefault()
extern Il2CppClass* Boolean_t3825574718_il2cpp_TypeInfo_var;
extern const uint32_t Nullable_1_GetValueOrDefault_m2607283502_MetadataUsageId;
extern "C"  bool Nullable_1_GetValueOrDefault_m2607283502_gshared (Nullable_1_t2088641033 * __this, const MethodInfo* method)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_method (Nullable_1_GetValueOrDefault_m2607283502_MetadataUsageId);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	bool G_B3_0 = false;
	{
		bool L_0 = (bool)__this->get_has_value_1();
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		bool L_1 = (bool)__this->get_value_0();
		G_B3_0 = L_1;
		goto IL_001f;
	}

IL_0016:
	{
		Initobj (Boolean_t3825574718_il2cpp_TypeInfo_var, (&V_0));
		bool L_2 = V_0;
		G_B3_0 = L_2;
	}

IL_001f:
	{
		return G_B3_0;
	}
}
extern "C"  bool Nullable_1_GetValueOrDefault_m2607283502_AdjustorThunk (Il2CppObject * __this, const MethodInfo* method)
{
	Nullable_1_t2088641033  _thisAdjusted;
	_thisAdjusted.set_value_0(*reinterpret_cast<bool*>(__this + 1));
	_thisAdjusted.set_has_value_1(true);
	bool _returnValue = Nullable_1_GetValueOrDefault_m2607283502(&_thisAdjusted, method);
	*reinterpret_cast<bool*>(__this + 1) = _thisAdjusted.get_value_0();
	return _returnValue;
}
// System.String System.Nullable`1<System.Boolean>::ToString()
extern Il2CppClass* String_t_il2cpp_TypeInfo_var;
extern const uint32_t Nullable_1_ToString_m678068069_MetadataUsageId;
extern "C"  String_t* Nullable_1_ToString_m678068069_gshared (Nullable_1_t2088641033 * __this, const MethodInfo* method)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_method (Nullable_1_ToString_m678068069_MetadataUsageId);
		s_Il2CppMethodInitialized = true;
	}
	{
		bool L_0 = (bool)__this->get_has_value_1();
		if (!L_0)
		{
			goto IL_001d;
		}
	}
	{
		bool* L_1 = (bool*)__this->get_address_of_value_0();
		String_t* L_2 = Boolean_ToString_m1253164328((bool*)L_1, /*hidden argument*/NULL);
		return L_2;
	}

IL_001d:
	{
		IL2CPP_RUNTIME_CLASS_INIT(String_t_il2cpp_TypeInfo_var);
		String_t* L_3 = ((String_t_StaticFields*)String_t_il2cpp_TypeInfo_var->static_fields)->get_Empty_2();
		return L_3;
	}
}
extern "C"  String_t* Nullable_1_ToString_m678068069_AdjustorThunk (Il2CppObject * __this, const MethodInfo* method)
{
	Nullable_1_t2088641033  _thisAdjusted;
	_thisAdjusted.set_value_0(*reinterpret_cast<bool*>(__this + 1));
	_thisAdjusted.set_has_value_1(true);
	String_t* _returnValue = Nullable_1_ToString_m678068069(&_thisAdjusted, method);
	*reinterpret_cast<bool*>(__this + 1) = _thisAdjusted.get_value_0();
	return _returnValue;
}
// System.Void System.Nullable`1<System.DateTime>::.ctor(T)
extern "C"  void Nullable_1__ctor_m4027593417_gshared (Nullable_1_t3251239280 * __this, DateTime_t693205669  ___value0, const MethodInfo* method)
{
	{
		__this->set_has_value_1((bool)1);
		DateTime_t693205669  L_0 = ___value0;
		__this->set_value_0(L_0);
		return;
	}
}
extern "C"  void Nullable_1__ctor_m4027593417_AdjustorThunk (Il2CppObject * __this, DateTime_t693205669  ___value0, const MethodInfo* method)
{
	Nullable_1_t3251239280  _thisAdjusted;
	_thisAdjusted.set_value_0(*reinterpret_cast<DateTime_t693205669 *>(__this + 1));
	_thisAdjusted.set_has_value_1(true);
	Nullable_1__ctor_m4027593417(&_thisAdjusted, ___value0, method);
	*reinterpret_cast<DateTime_t693205669 *>(__this + 1) = _thisAdjusted.get_value_0();
}
// System.Boolean System.Nullable`1<System.DateTime>::get_HasValue()
extern "C"  bool Nullable_1_get_HasValue_m3795771450_gshared (Nullable_1_t3251239280 * __this, const MethodInfo* method)
{
	{
		bool L_0 = (bool)__this->get_has_value_1();
		return L_0;
	}
}
extern "C"  bool Nullable_1_get_HasValue_m3795771450_AdjustorThunk (Il2CppObject * __this, const MethodInfo* method)
{
	Nullable_1_t3251239280  _thisAdjusted;
	_thisAdjusted.set_value_0(*reinterpret_cast<DateTime_t693205669 *>(__this + 1));
	_thisAdjusted.set_has_value_1(true);
	bool _returnValue = Nullable_1_get_HasValue_m3795771450(&_thisAdjusted, method);
	*reinterpret_cast<DateTime_t693205669 *>(__this + 1) = _thisAdjusted.get_value_0();
	return _returnValue;
}
// T System.Nullable`1<System.DateTime>::get_Value()
extern Il2CppClass* InvalidOperationException_t721527559_il2cpp_TypeInfo_var;
extern Il2CppCodeGenString* _stringLiteral2004437333;
extern const uint32_t Nullable_1_get_Value_m1118025076_MetadataUsageId;
extern "C"  DateTime_t693205669  Nullable_1_get_Value_m1118025076_gshared (Nullable_1_t3251239280 * __this, const MethodInfo* method)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_method (Nullable_1_get_Value_m1118025076_MetadataUsageId);
		s_Il2CppMethodInitialized = true;
	}
	{
		bool L_0 = (bool)__this->get_has_value_1();
		if (L_0)
		{
			goto IL_0016;
		}
	}
	{
		InvalidOperationException_t721527559 * L_1 = (InvalidOperationException_t721527559 *)il2cpp_codegen_object_new(InvalidOperationException_t721527559_il2cpp_TypeInfo_var);
		InvalidOperationException__ctor_m2801133788(L_1, (String_t*)_stringLiteral2004437333, /*hidden argument*/NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1);
	}

IL_0016:
	{
		DateTime_t693205669  L_2 = (DateTime_t693205669 )__this->get_value_0();
		return L_2;
	}
}
extern "C"  DateTime_t693205669  Nullable_1_get_Value_m1118025076_AdjustorThunk (Il2CppObject * __this, const MethodInfo* method)
{
	Nullable_1_t3251239280  _thisAdjusted;
	_thisAdjusted.set_value_0(*reinterpret_cast<DateTime_t693205669 *>(__this + 1));
	_thisAdjusted.set_has_value_1(true);
	DateTime_t693205669  _returnValue = Nullable_1_get_Value_m1118025076(&_thisAdjusted, method);
	*reinterpret_cast<DateTime_t693205669 *>(__this + 1) = _thisAdjusted.get_value_0();
	return _returnValue;
}
// System.Boolean System.Nullable`1<System.DateTime>::Equals(System.Object)
extern "C"  bool Nullable_1_Equals_m1089953100_gshared (Nullable_1_t3251239280 * __this, Il2CppObject * ___other0, const MethodInfo* method)
{
	{
		Il2CppObject * L_0 = ___other0;
		if (L_0)
		{
			goto IL_0010;
		}
	}
	{
		bool L_1 = (bool)__this->get_has_value_1();
		return (bool)((((int32_t)L_1) == ((int32_t)0))? 1 : 0);
	}

IL_0010:
	{
		Il2CppObject * L_2 = ___other0;
		if (((Il2CppObject *)IsInst(L_2, IL2CPP_RGCTX_DATA(InitializedTypeInfo(method->declaring_type)->rgctx_data, 0))))
		{
			goto IL_001d;
		}
	}
	{
		return (bool)0;
	}

IL_001d:
	{
		Il2CppObject * L_3 = ___other0;
		void* L_4 = alloca(sizeof(Nullable_1_t3251239280 ));
		UnBoxNullable(L_3, IL2CPP_RGCTX_DATA(InitializedTypeInfo(method->declaring_type)->rgctx_data, 0), L_4);
		bool L_5 = Nullable_1_Equals_m1817623273((Nullable_1_t3251239280 *)__this, (Nullable_1_t3251239280 )((*(Nullable_1_t3251239280 *)((Nullable_1_t3251239280 *)L_4))), /*hidden argument*/IL2CPP_RGCTX_METHOD_INFO(InitializedTypeInfo(method->declaring_type)->rgctx_data, 1));
		return L_5;
	}
}
extern "C"  bool Nullable_1_Equals_m1089953100_AdjustorThunk (Il2CppObject * __this, Il2CppObject * ___other0, const MethodInfo* method)
{
	Nullable_1_t3251239280  _thisAdjusted;
	_thisAdjusted.set_value_0(*reinterpret_cast<DateTime_t693205669 *>(__this + 1));
	_thisAdjusted.set_has_value_1(true);
	bool _returnValue = Nullable_1_Equals_m1089953100(&_thisAdjusted, ___other0, method);
	*reinterpret_cast<DateTime_t693205669 *>(__this + 1) = _thisAdjusted.get_value_0();
	return _returnValue;
}
// System.Boolean System.Nullable`1<System.DateTime>::Equals(System.Nullable`1<T>)
extern "C"  bool Nullable_1_Equals_m1817623273_gshared (Nullable_1_t3251239280 * __this, Nullable_1_t3251239280  ___other0, const MethodInfo* method)
{
	{
		bool L_0 = (bool)(&___other0)->get_has_value_1();
		bool L_1 = (bool)__this->get_has_value_1();
		if ((((int32_t)L_0) == ((int32_t)L_1)))
		{
			goto IL_0014;
		}
	}
	{
		return (bool)0;
	}

IL_0014:
	{
		bool L_2 = (bool)__this->get_has_value_1();
		if (L_2)
		{
			goto IL_0021;
		}
	}
	{
		return (bool)1;
	}

IL_0021:
	{
		DateTime_t693205669 * L_3 = (DateTime_t693205669 *)(&___other0)->get_address_of_value_0();
		DateTime_t693205669  L_4 = (DateTime_t693205669 )__this->get_value_0();
		DateTime_t693205669  L_5 = L_4;
		Il2CppObject * L_6 = Box(IL2CPP_RGCTX_DATA(InitializedTypeInfo(method->declaring_type)->rgctx_data, 2), &L_5);
		bool L_7 = DateTime_Equals_m2562884703((DateTime_t693205669 *)L_3, (Il2CppObject *)L_6, /*hidden argument*/NULL);
		return L_7;
	}
}
extern "C"  bool Nullable_1_Equals_m1817623273_AdjustorThunk (Il2CppObject * __this, Nullable_1_t3251239280  ___other0, const MethodInfo* method)
{
	Nullable_1_t3251239280  _thisAdjusted;
	_thisAdjusted.set_value_0(*reinterpret_cast<DateTime_t693205669 *>(__this + 1));
	_thisAdjusted.set_has_value_1(true);
	bool _returnValue = Nullable_1_Equals_m1817623273(&_thisAdjusted, ___other0, method);
	*reinterpret_cast<DateTime_t693205669 *>(__this + 1) = _thisAdjusted.get_value_0();
	return _returnValue;
}
// System.Int32 System.Nullable`1<System.DateTime>::GetHashCode()
extern "C"  int32_t Nullable_1_GetHashCode_m3047479588_gshared (Nullable_1_t3251239280 * __this, const MethodInfo* method)
{
	{
		bool L_0 = (bool)__this->get_has_value_1();
		if (L_0)
		{
			goto IL_000d;
		}
	}
	{
		return 0;
	}

IL_000d:
	{
		DateTime_t693205669 * L_1 = (DateTime_t693205669 *)__this->get_address_of_value_0();
		int32_t L_2 = DateTime_GetHashCode_m974799321((DateTime_t693205669 *)L_1, /*hidden argument*/NULL);
		return L_2;
	}
}
extern "C"  int32_t Nullable_1_GetHashCode_m3047479588_AdjustorThunk (Il2CppObject * __this, const MethodInfo* method)
{
	Nullable_1_t3251239280  _thisAdjusted;
	_thisAdjusted.set_value_0(*reinterpret_cast<DateTime_t693205669 *>(__this + 1));
	_thisAdjusted.set_has_value_1(true);
	int32_t _returnValue = Nullable_1_GetHashCode_m3047479588(&_thisAdjusted, method);
	*reinterpret_cast<DateTime_t693205669 *>(__this + 1) = _thisAdjusted.get_value_0();
	return _returnValue;
}
// T System.Nullable`1<System.DateTime>::GetValueOrDefault()
extern Il2CppClass* DateTime_t693205669_il2cpp_TypeInfo_var;
extern const uint32_t Nullable_1_GetValueOrDefault_m706662709_MetadataUsageId;
extern "C"  DateTime_t693205669  Nullable_1_GetValueOrDefault_m706662709_gshared (Nullable_1_t3251239280 * __this, const MethodInfo* method)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_method (Nullable_1_GetValueOrDefault_m706662709_MetadataUsageId);
		s_Il2CppMethodInitialized = true;
	}
	DateTime_t693205669  V_0;
	memset(&V_0, 0, sizeof(V_0));
	DateTime_t693205669  G_B3_0;
	memset(&G_B3_0, 0, sizeof(G_B3_0));
	{
		bool L_0 = (bool)__this->get_has_value_1();
		if (!L_0)
		{
			goto IL_0016;
		}
	}
	{
		DateTime_t693205669  L_1 = (DateTime_t693205669 )__this->get_value_0();
		G_B3_0 = L_1;
		goto IL_001f;
	}

IL_0016:
	{
		Initobj (DateTime_t693205669_il2cpp_TypeInfo_var, (&V_0));
		DateTime_t693205669  L_2 = V_0;
		G_B3_0 = L_2;
	}

IL_001f:
	{
		return G_B3_0;
	}
}
extern "C"  DateTime_t693205669  Nullable_1_GetValueOrDefault_m706662709_AdjustorThunk (Il2CppObject * __this, const MethodInfo* method)
{
	Nullable_1_t3251239280  _thisAdjusted;
	_thisAdjusted.set_value_0(*reinterpret_cast<DateTime_t693205669 *>(__this + 1));
	_thisAdjusted.set_has_value_1(true);
	DateTime_t693205669  _returnValue = Nullable_1_GetValueOrDefault_m706662709(&_thisAdjusted, method);
	*reinterpret_cast<DateTime_t693205669 *>(__this + 1) = _thisAdjusted.get_value_0();
	return _returnValue;
}
// System.String System.Nullable`1<System.DateTime>::ToString()
extern Il2CppClass* String_t_il2cpp_TypeInfo_var;
extern const uint32_t Nullable_1_ToString_m1419821888_MetadataUsageId;
extern "C"  String_t* Nullable_1_ToString_m1419821888_gshared (Nullable_1_t3251239280 * __this, const MethodInfo* method)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_method (Nullable_1_ToString_m1419821888_MetadataUsageId);
		s_Il2CppMethodInitialized = true;
	}
	{
		bool L_0 = (bool)__this->get_has_value_1();
		if (!L_0)
		{
			goto IL_001d;
		}
	}
	{
		DateTime_t693205669 * L_1 = (DateTime_t693205669 *)__this->get_address_of_value_0();
		String_t* L_2 = DateTime_ToString_m1117481977((DateTime_t693205669 *)L_1, /*hidden argument*/NULL);
		return L_2;
	}

IL_001d:
	{
		IL2CPP_RUNTIME_CLASS_INIT(String_t_il2cpp_TypeInfo_var);
		String_t* L_3 = ((String_t_StaticFields*)String_t_il2cpp_TypeInfo_var->static_fields)->get_Empty_2();
		return L_3;
	}
}
extern "C"  String_t* Nullable_1_ToString_m1419821888_AdjustorThunk (Il2CppObject * __this, const MethodInfo* method)
{
	Nullable_1_t3251239280  _thisAdjusted;
	_thisAdjusted.set_value_0(*reinterpret_cast<DateTime_t693205669 *>(__this + 1));
	_thisAdjusted.set_has_value_1(true);
	String_t* _returnValue = Nullable_1_ToString_m1419821888(&_thisAdjusted, method);
	*reinterpret_cast<DateTime_t693205669 *>(__this + 1) = _thisAdjusted.get_value_0();
	return _returnValue;
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
