#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.Collections.Generic.Dictionary`2<System.String,System.Action`2<GoogleMobileAds.Api.CustomNativeTemplateAd,System.String>>
struct Dictionary_2_t3127549387;
// System.EventHandler`1<GoogleMobileAds.Api.CustomNativeEventArgs>
struct EventHandler_1_t1249765249;
// System.EventHandler`1<GoogleMobileAds.Api.AdFailedToLoadEventArgs>
struct EventHandler_1_t347919082;
// GoogleMobileAds.iOS.AdLoaderClient/GADUAdLoaderDidReceiveNativeCustomTemplateAdCallback
struct GADUAdLoaderDidReceiveNativeCustomTemplateAdCallback_t3126817269;
// GoogleMobileAds.iOS.AdLoaderClient/GADUAdLoaderDidFailToReceiveAdWithErrorCallback
struct GADUAdLoaderDidFailToReceiveAdWithErrorCallback_t619382744;

#include "mscorlib_System_Object2689449295.h"
#include "mscorlib_System_IntPtr2504060609.h"
#include "AssemblyU2DCSharp_GoogleMobileAds_iOS_NativeAdType3944121833.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// GoogleMobileAds.iOS.AdLoaderClient
struct  AdLoaderClient_t506419447  : public Il2CppObject
{
public:
	// System.IntPtr GoogleMobileAds.iOS.AdLoaderClient::adLoaderPtr
	IntPtr_t ___adLoaderPtr_0;
	// System.IntPtr GoogleMobileAds.iOS.AdLoaderClient::adLoaderClientPtr
	IntPtr_t ___adLoaderClientPtr_1;
	// GoogleMobileAds.iOS.NativeAdTypes GoogleMobileAds.iOS.AdLoaderClient::adTypes
	NativeAdTypes_t3944121833  ___adTypes_2;
	// System.Collections.Generic.Dictionary`2<System.String,System.Action`2<GoogleMobileAds.Api.CustomNativeTemplateAd,System.String>> GoogleMobileAds.iOS.AdLoaderClient::customNativeTemplateCallbacks
	Dictionary_2_t3127549387 * ___customNativeTemplateCallbacks_3;
	// System.EventHandler`1<GoogleMobileAds.Api.CustomNativeEventArgs> GoogleMobileAds.iOS.AdLoaderClient::OnCustomNativeTemplateAdLoaded
	EventHandler_1_t1249765249 * ___OnCustomNativeTemplateAdLoaded_4;
	// System.EventHandler`1<GoogleMobileAds.Api.AdFailedToLoadEventArgs> GoogleMobileAds.iOS.AdLoaderClient::OnAdFailedToLoad
	EventHandler_1_t347919082 * ___OnAdFailedToLoad_5;

public:
	inline static int32_t get_offset_of_adLoaderPtr_0() { return static_cast<int32_t>(offsetof(AdLoaderClient_t506419447, ___adLoaderPtr_0)); }
	inline IntPtr_t get_adLoaderPtr_0() const { return ___adLoaderPtr_0; }
	inline IntPtr_t* get_address_of_adLoaderPtr_0() { return &___adLoaderPtr_0; }
	inline void set_adLoaderPtr_0(IntPtr_t value)
	{
		___adLoaderPtr_0 = value;
	}

	inline static int32_t get_offset_of_adLoaderClientPtr_1() { return static_cast<int32_t>(offsetof(AdLoaderClient_t506419447, ___adLoaderClientPtr_1)); }
	inline IntPtr_t get_adLoaderClientPtr_1() const { return ___adLoaderClientPtr_1; }
	inline IntPtr_t* get_address_of_adLoaderClientPtr_1() { return &___adLoaderClientPtr_1; }
	inline void set_adLoaderClientPtr_1(IntPtr_t value)
	{
		___adLoaderClientPtr_1 = value;
	}

	inline static int32_t get_offset_of_adTypes_2() { return static_cast<int32_t>(offsetof(AdLoaderClient_t506419447, ___adTypes_2)); }
	inline NativeAdTypes_t3944121833  get_adTypes_2() const { return ___adTypes_2; }
	inline NativeAdTypes_t3944121833 * get_address_of_adTypes_2() { return &___adTypes_2; }
	inline void set_adTypes_2(NativeAdTypes_t3944121833  value)
	{
		___adTypes_2 = value;
	}

	inline static int32_t get_offset_of_customNativeTemplateCallbacks_3() { return static_cast<int32_t>(offsetof(AdLoaderClient_t506419447, ___customNativeTemplateCallbacks_3)); }
	inline Dictionary_2_t3127549387 * get_customNativeTemplateCallbacks_3() const { return ___customNativeTemplateCallbacks_3; }
	inline Dictionary_2_t3127549387 ** get_address_of_customNativeTemplateCallbacks_3() { return &___customNativeTemplateCallbacks_3; }
	inline void set_customNativeTemplateCallbacks_3(Dictionary_2_t3127549387 * value)
	{
		___customNativeTemplateCallbacks_3 = value;
		Il2CppCodeGenWriteBarrier(&___customNativeTemplateCallbacks_3, value);
	}

	inline static int32_t get_offset_of_OnCustomNativeTemplateAdLoaded_4() { return static_cast<int32_t>(offsetof(AdLoaderClient_t506419447, ___OnCustomNativeTemplateAdLoaded_4)); }
	inline EventHandler_1_t1249765249 * get_OnCustomNativeTemplateAdLoaded_4() const { return ___OnCustomNativeTemplateAdLoaded_4; }
	inline EventHandler_1_t1249765249 ** get_address_of_OnCustomNativeTemplateAdLoaded_4() { return &___OnCustomNativeTemplateAdLoaded_4; }
	inline void set_OnCustomNativeTemplateAdLoaded_4(EventHandler_1_t1249765249 * value)
	{
		___OnCustomNativeTemplateAdLoaded_4 = value;
		Il2CppCodeGenWriteBarrier(&___OnCustomNativeTemplateAdLoaded_4, value);
	}

	inline static int32_t get_offset_of_OnAdFailedToLoad_5() { return static_cast<int32_t>(offsetof(AdLoaderClient_t506419447, ___OnAdFailedToLoad_5)); }
	inline EventHandler_1_t347919082 * get_OnAdFailedToLoad_5() const { return ___OnAdFailedToLoad_5; }
	inline EventHandler_1_t347919082 ** get_address_of_OnAdFailedToLoad_5() { return &___OnAdFailedToLoad_5; }
	inline void set_OnAdFailedToLoad_5(EventHandler_1_t347919082 * value)
	{
		___OnAdFailedToLoad_5 = value;
		Il2CppCodeGenWriteBarrier(&___OnAdFailedToLoad_5, value);
	}
};

struct AdLoaderClient_t506419447_StaticFields
{
public:
	// GoogleMobileAds.iOS.AdLoaderClient/GADUAdLoaderDidReceiveNativeCustomTemplateAdCallback GoogleMobileAds.iOS.AdLoaderClient::<>f__mg$cache0
	GADUAdLoaderDidReceiveNativeCustomTemplateAdCallback_t3126817269 * ___U3CU3Ef__mgU24cache0_6;
	// GoogleMobileAds.iOS.AdLoaderClient/GADUAdLoaderDidFailToReceiveAdWithErrorCallback GoogleMobileAds.iOS.AdLoaderClient::<>f__mg$cache1
	GADUAdLoaderDidFailToReceiveAdWithErrorCallback_t619382744 * ___U3CU3Ef__mgU24cache1_7;

public:
	inline static int32_t get_offset_of_U3CU3Ef__mgU24cache0_6() { return static_cast<int32_t>(offsetof(AdLoaderClient_t506419447_StaticFields, ___U3CU3Ef__mgU24cache0_6)); }
	inline GADUAdLoaderDidReceiveNativeCustomTemplateAdCallback_t3126817269 * get_U3CU3Ef__mgU24cache0_6() const { return ___U3CU3Ef__mgU24cache0_6; }
	inline GADUAdLoaderDidReceiveNativeCustomTemplateAdCallback_t3126817269 ** get_address_of_U3CU3Ef__mgU24cache0_6() { return &___U3CU3Ef__mgU24cache0_6; }
	inline void set_U3CU3Ef__mgU24cache0_6(GADUAdLoaderDidReceiveNativeCustomTemplateAdCallback_t3126817269 * value)
	{
		___U3CU3Ef__mgU24cache0_6 = value;
		Il2CppCodeGenWriteBarrier(&___U3CU3Ef__mgU24cache0_6, value);
	}

	inline static int32_t get_offset_of_U3CU3Ef__mgU24cache1_7() { return static_cast<int32_t>(offsetof(AdLoaderClient_t506419447_StaticFields, ___U3CU3Ef__mgU24cache1_7)); }
	inline GADUAdLoaderDidFailToReceiveAdWithErrorCallback_t619382744 * get_U3CU3Ef__mgU24cache1_7() const { return ___U3CU3Ef__mgU24cache1_7; }
	inline GADUAdLoaderDidFailToReceiveAdWithErrorCallback_t619382744 ** get_address_of_U3CU3Ef__mgU24cache1_7() { return &___U3CU3Ef__mgU24cache1_7; }
	inline void set_U3CU3Ef__mgU24cache1_7(GADUAdLoaderDidFailToReceiveAdWithErrorCallback_t619382744 * value)
	{
		___U3CU3Ef__mgU24cache1_7 = value;
		Il2CppCodeGenWriteBarrier(&___U3CU3Ef__mgU24cache1_7, value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
