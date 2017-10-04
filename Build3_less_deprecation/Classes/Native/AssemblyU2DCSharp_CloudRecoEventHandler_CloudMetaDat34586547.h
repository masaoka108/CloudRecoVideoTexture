#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.String
struct String_t;

#include "mscorlib_System_Object2689449295.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// CloudRecoEventHandler/CloudMetaData
struct  CloudMetaData_t34586547  : public Il2CppObject
{
public:
	// System.String CloudRecoEventHandler/CloudMetaData::title
	String_t* ___title_0;
	// System.String CloudRecoEventHandler/CloudMetaData::url
	String_t* ___url_1;

public:
	inline static int32_t get_offset_of_title_0() { return static_cast<int32_t>(offsetof(CloudMetaData_t34586547, ___title_0)); }
	inline String_t* get_title_0() const { return ___title_0; }
	inline String_t** get_address_of_title_0() { return &___title_0; }
	inline void set_title_0(String_t* value)
	{
		___title_0 = value;
		Il2CppCodeGenWriteBarrier(&___title_0, value);
	}

	inline static int32_t get_offset_of_url_1() { return static_cast<int32_t>(offsetof(CloudMetaData_t34586547, ___url_1)); }
	inline String_t* get_url_1() const { return ___url_1; }
	inline String_t** get_address_of_url_1() { return &___url_1; }
	inline void set_url_1(String_t* value)
	{
		___url_1 = value;
		Il2CppCodeGenWriteBarrier(&___url_1, value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
