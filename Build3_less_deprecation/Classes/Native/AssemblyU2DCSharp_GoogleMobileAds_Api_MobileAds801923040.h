#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// GoogleMobileAds.Common.IMobileAdsClient
struct IMobileAdsClient_t325171676;

#include "mscorlib_System_Object2689449295.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// GoogleMobileAds.Api.MobileAds
struct  MobileAds_t801923040  : public Il2CppObject
{
public:

public:
};

struct MobileAds_t801923040_StaticFields
{
public:
	// GoogleMobileAds.Common.IMobileAdsClient GoogleMobileAds.Api.MobileAds::client
	Il2CppObject * ___client_0;

public:
	inline static int32_t get_offset_of_client_0() { return static_cast<int32_t>(offsetof(MobileAds_t801923040_StaticFields, ___client_0)); }
	inline Il2CppObject * get_client_0() const { return ___client_0; }
	inline Il2CppObject ** get_address_of_client_0() { return &___client_0; }
	inline void set_client_0(Il2CppObject * value)
	{
		___client_0 = value;
		Il2CppCodeGenWriteBarrier(&___client_0, value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
