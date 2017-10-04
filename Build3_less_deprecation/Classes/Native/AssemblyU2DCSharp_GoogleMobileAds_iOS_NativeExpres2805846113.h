#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.EventHandler`1<System.EventArgs>
struct EventHandler_1_t1880931879;
// System.EventHandler`1<GoogleMobileAds.Api.AdFailedToLoadEventArgs>
struct EventHandler_1_t347919082;
// GoogleMobileAds.iOS.NativeExpressAdClient/GADUNativeExpressAdViewDidReceiveAdCallback
struct GADUNativeExpressAdViewDidReceiveAdCallback_t2677637168;
// GoogleMobileAds.iOS.NativeExpressAdClient/GADUNativeExpressAdViewDidFailToReceiveAdWithErrorCallback
struct GADUNativeExpressAdViewDidFailToReceiveAdWithErrorCallback_t3648222485;
// GoogleMobileAds.iOS.NativeExpressAdClient/GADUNativeExpressAdViewWillPresentScreenCallback
struct GADUNativeExpressAdViewWillPresentScreenCallback_t3478706784;
// GoogleMobileAds.iOS.NativeExpressAdClient/GADUNativeExpressAdViewDidDismissScreenCallback
struct GADUNativeExpressAdViewDidDismissScreenCallback_t784484480;
// GoogleMobileAds.iOS.NativeExpressAdClient/GADUNativeExpressAdViewWillLeaveApplicationCallback
struct GADUNativeExpressAdViewWillLeaveApplicationCallback_t548165752;

#include "mscorlib_System_Object2689449295.h"
#include "mscorlib_System_IntPtr2504060609.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// GoogleMobileAds.iOS.NativeExpressAdClient
struct  NativeExpressAdClient_t2805846113  : public Il2CppObject
{
public:
	// System.IntPtr GoogleMobileAds.iOS.NativeExpressAdClient::nativeExpressAdViewPtr
	IntPtr_t ___nativeExpressAdViewPtr_0;
	// System.IntPtr GoogleMobileAds.iOS.NativeExpressAdClient::nativeExpressAdClientPtr
	IntPtr_t ___nativeExpressAdClientPtr_1;
	// System.EventHandler`1<System.EventArgs> GoogleMobileAds.iOS.NativeExpressAdClient::OnAdLoaded
	EventHandler_1_t1880931879 * ___OnAdLoaded_2;
	// System.EventHandler`1<GoogleMobileAds.Api.AdFailedToLoadEventArgs> GoogleMobileAds.iOS.NativeExpressAdClient::OnAdFailedToLoad
	EventHandler_1_t347919082 * ___OnAdFailedToLoad_3;
	// System.EventHandler`1<System.EventArgs> GoogleMobileAds.iOS.NativeExpressAdClient::OnAdOpening
	EventHandler_1_t1880931879 * ___OnAdOpening_4;
	// System.EventHandler`1<System.EventArgs> GoogleMobileAds.iOS.NativeExpressAdClient::OnAdClosed
	EventHandler_1_t1880931879 * ___OnAdClosed_5;
	// System.EventHandler`1<System.EventArgs> GoogleMobileAds.iOS.NativeExpressAdClient::OnAdLeavingApplication
	EventHandler_1_t1880931879 * ___OnAdLeavingApplication_6;

public:
	inline static int32_t get_offset_of_nativeExpressAdViewPtr_0() { return static_cast<int32_t>(offsetof(NativeExpressAdClient_t2805846113, ___nativeExpressAdViewPtr_0)); }
	inline IntPtr_t get_nativeExpressAdViewPtr_0() const { return ___nativeExpressAdViewPtr_0; }
	inline IntPtr_t* get_address_of_nativeExpressAdViewPtr_0() { return &___nativeExpressAdViewPtr_0; }
	inline void set_nativeExpressAdViewPtr_0(IntPtr_t value)
	{
		___nativeExpressAdViewPtr_0 = value;
	}

	inline static int32_t get_offset_of_nativeExpressAdClientPtr_1() { return static_cast<int32_t>(offsetof(NativeExpressAdClient_t2805846113, ___nativeExpressAdClientPtr_1)); }
	inline IntPtr_t get_nativeExpressAdClientPtr_1() const { return ___nativeExpressAdClientPtr_1; }
	inline IntPtr_t* get_address_of_nativeExpressAdClientPtr_1() { return &___nativeExpressAdClientPtr_1; }
	inline void set_nativeExpressAdClientPtr_1(IntPtr_t value)
	{
		___nativeExpressAdClientPtr_1 = value;
	}

	inline static int32_t get_offset_of_OnAdLoaded_2() { return static_cast<int32_t>(offsetof(NativeExpressAdClient_t2805846113, ___OnAdLoaded_2)); }
	inline EventHandler_1_t1880931879 * get_OnAdLoaded_2() const { return ___OnAdLoaded_2; }
	inline EventHandler_1_t1880931879 ** get_address_of_OnAdLoaded_2() { return &___OnAdLoaded_2; }
	inline void set_OnAdLoaded_2(EventHandler_1_t1880931879 * value)
	{
		___OnAdLoaded_2 = value;
		Il2CppCodeGenWriteBarrier(&___OnAdLoaded_2, value);
	}

	inline static int32_t get_offset_of_OnAdFailedToLoad_3() { return static_cast<int32_t>(offsetof(NativeExpressAdClient_t2805846113, ___OnAdFailedToLoad_3)); }
	inline EventHandler_1_t347919082 * get_OnAdFailedToLoad_3() const { return ___OnAdFailedToLoad_3; }
	inline EventHandler_1_t347919082 ** get_address_of_OnAdFailedToLoad_3() { return &___OnAdFailedToLoad_3; }
	inline void set_OnAdFailedToLoad_3(EventHandler_1_t347919082 * value)
	{
		___OnAdFailedToLoad_3 = value;
		Il2CppCodeGenWriteBarrier(&___OnAdFailedToLoad_3, value);
	}

	inline static int32_t get_offset_of_OnAdOpening_4() { return static_cast<int32_t>(offsetof(NativeExpressAdClient_t2805846113, ___OnAdOpening_4)); }
	inline EventHandler_1_t1880931879 * get_OnAdOpening_4() const { return ___OnAdOpening_4; }
	inline EventHandler_1_t1880931879 ** get_address_of_OnAdOpening_4() { return &___OnAdOpening_4; }
	inline void set_OnAdOpening_4(EventHandler_1_t1880931879 * value)
	{
		___OnAdOpening_4 = value;
		Il2CppCodeGenWriteBarrier(&___OnAdOpening_4, value);
	}

	inline static int32_t get_offset_of_OnAdClosed_5() { return static_cast<int32_t>(offsetof(NativeExpressAdClient_t2805846113, ___OnAdClosed_5)); }
	inline EventHandler_1_t1880931879 * get_OnAdClosed_5() const { return ___OnAdClosed_5; }
	inline EventHandler_1_t1880931879 ** get_address_of_OnAdClosed_5() { return &___OnAdClosed_5; }
	inline void set_OnAdClosed_5(EventHandler_1_t1880931879 * value)
	{
		___OnAdClosed_5 = value;
		Il2CppCodeGenWriteBarrier(&___OnAdClosed_5, value);
	}

	inline static int32_t get_offset_of_OnAdLeavingApplication_6() { return static_cast<int32_t>(offsetof(NativeExpressAdClient_t2805846113, ___OnAdLeavingApplication_6)); }
	inline EventHandler_1_t1880931879 * get_OnAdLeavingApplication_6() const { return ___OnAdLeavingApplication_6; }
	inline EventHandler_1_t1880931879 ** get_address_of_OnAdLeavingApplication_6() { return &___OnAdLeavingApplication_6; }
	inline void set_OnAdLeavingApplication_6(EventHandler_1_t1880931879 * value)
	{
		___OnAdLeavingApplication_6 = value;
		Il2CppCodeGenWriteBarrier(&___OnAdLeavingApplication_6, value);
	}
};

struct NativeExpressAdClient_t2805846113_StaticFields
{
public:
	// GoogleMobileAds.iOS.NativeExpressAdClient/GADUNativeExpressAdViewDidReceiveAdCallback GoogleMobileAds.iOS.NativeExpressAdClient::<>f__mg$cache0
	GADUNativeExpressAdViewDidReceiveAdCallback_t2677637168 * ___U3CU3Ef__mgU24cache0_7;
	// GoogleMobileAds.iOS.NativeExpressAdClient/GADUNativeExpressAdViewDidFailToReceiveAdWithErrorCallback GoogleMobileAds.iOS.NativeExpressAdClient::<>f__mg$cache1
	GADUNativeExpressAdViewDidFailToReceiveAdWithErrorCallback_t3648222485 * ___U3CU3Ef__mgU24cache1_8;
	// GoogleMobileAds.iOS.NativeExpressAdClient/GADUNativeExpressAdViewWillPresentScreenCallback GoogleMobileAds.iOS.NativeExpressAdClient::<>f__mg$cache2
	GADUNativeExpressAdViewWillPresentScreenCallback_t3478706784 * ___U3CU3Ef__mgU24cache2_9;
	// GoogleMobileAds.iOS.NativeExpressAdClient/GADUNativeExpressAdViewDidDismissScreenCallback GoogleMobileAds.iOS.NativeExpressAdClient::<>f__mg$cache3
	GADUNativeExpressAdViewDidDismissScreenCallback_t784484480 * ___U3CU3Ef__mgU24cache3_10;
	// GoogleMobileAds.iOS.NativeExpressAdClient/GADUNativeExpressAdViewWillLeaveApplicationCallback GoogleMobileAds.iOS.NativeExpressAdClient::<>f__mg$cache4
	GADUNativeExpressAdViewWillLeaveApplicationCallback_t548165752 * ___U3CU3Ef__mgU24cache4_11;
	// GoogleMobileAds.iOS.NativeExpressAdClient/GADUNativeExpressAdViewDidReceiveAdCallback GoogleMobileAds.iOS.NativeExpressAdClient::<>f__mg$cache5
	GADUNativeExpressAdViewDidReceiveAdCallback_t2677637168 * ___U3CU3Ef__mgU24cache5_12;
	// GoogleMobileAds.iOS.NativeExpressAdClient/GADUNativeExpressAdViewDidFailToReceiveAdWithErrorCallback GoogleMobileAds.iOS.NativeExpressAdClient::<>f__mg$cache6
	GADUNativeExpressAdViewDidFailToReceiveAdWithErrorCallback_t3648222485 * ___U3CU3Ef__mgU24cache6_13;
	// GoogleMobileAds.iOS.NativeExpressAdClient/GADUNativeExpressAdViewWillPresentScreenCallback GoogleMobileAds.iOS.NativeExpressAdClient::<>f__mg$cache7
	GADUNativeExpressAdViewWillPresentScreenCallback_t3478706784 * ___U3CU3Ef__mgU24cache7_14;
	// GoogleMobileAds.iOS.NativeExpressAdClient/GADUNativeExpressAdViewDidDismissScreenCallback GoogleMobileAds.iOS.NativeExpressAdClient::<>f__mg$cache8
	GADUNativeExpressAdViewDidDismissScreenCallback_t784484480 * ___U3CU3Ef__mgU24cache8_15;
	// GoogleMobileAds.iOS.NativeExpressAdClient/GADUNativeExpressAdViewWillLeaveApplicationCallback GoogleMobileAds.iOS.NativeExpressAdClient::<>f__mg$cache9
	GADUNativeExpressAdViewWillLeaveApplicationCallback_t548165752 * ___U3CU3Ef__mgU24cache9_16;

public:
	inline static int32_t get_offset_of_U3CU3Ef__mgU24cache0_7() { return static_cast<int32_t>(offsetof(NativeExpressAdClient_t2805846113_StaticFields, ___U3CU3Ef__mgU24cache0_7)); }
	inline GADUNativeExpressAdViewDidReceiveAdCallback_t2677637168 * get_U3CU3Ef__mgU24cache0_7() const { return ___U3CU3Ef__mgU24cache0_7; }
	inline GADUNativeExpressAdViewDidReceiveAdCallback_t2677637168 ** get_address_of_U3CU3Ef__mgU24cache0_7() { return &___U3CU3Ef__mgU24cache0_7; }
	inline void set_U3CU3Ef__mgU24cache0_7(GADUNativeExpressAdViewDidReceiveAdCallback_t2677637168 * value)
	{
		___U3CU3Ef__mgU24cache0_7 = value;
		Il2CppCodeGenWriteBarrier(&___U3CU3Ef__mgU24cache0_7, value);
	}

	inline static int32_t get_offset_of_U3CU3Ef__mgU24cache1_8() { return static_cast<int32_t>(offsetof(NativeExpressAdClient_t2805846113_StaticFields, ___U3CU3Ef__mgU24cache1_8)); }
	inline GADUNativeExpressAdViewDidFailToReceiveAdWithErrorCallback_t3648222485 * get_U3CU3Ef__mgU24cache1_8() const { return ___U3CU3Ef__mgU24cache1_8; }
	inline GADUNativeExpressAdViewDidFailToReceiveAdWithErrorCallback_t3648222485 ** get_address_of_U3CU3Ef__mgU24cache1_8() { return &___U3CU3Ef__mgU24cache1_8; }
	inline void set_U3CU3Ef__mgU24cache1_8(GADUNativeExpressAdViewDidFailToReceiveAdWithErrorCallback_t3648222485 * value)
	{
		___U3CU3Ef__mgU24cache1_8 = value;
		Il2CppCodeGenWriteBarrier(&___U3CU3Ef__mgU24cache1_8, value);
	}

	inline static int32_t get_offset_of_U3CU3Ef__mgU24cache2_9() { return static_cast<int32_t>(offsetof(NativeExpressAdClient_t2805846113_StaticFields, ___U3CU3Ef__mgU24cache2_9)); }
	inline GADUNativeExpressAdViewWillPresentScreenCallback_t3478706784 * get_U3CU3Ef__mgU24cache2_9() const { return ___U3CU3Ef__mgU24cache2_9; }
	inline GADUNativeExpressAdViewWillPresentScreenCallback_t3478706784 ** get_address_of_U3CU3Ef__mgU24cache2_9() { return &___U3CU3Ef__mgU24cache2_9; }
	inline void set_U3CU3Ef__mgU24cache2_9(GADUNativeExpressAdViewWillPresentScreenCallback_t3478706784 * value)
	{
		___U3CU3Ef__mgU24cache2_9 = value;
		Il2CppCodeGenWriteBarrier(&___U3CU3Ef__mgU24cache2_9, value);
	}

	inline static int32_t get_offset_of_U3CU3Ef__mgU24cache3_10() { return static_cast<int32_t>(offsetof(NativeExpressAdClient_t2805846113_StaticFields, ___U3CU3Ef__mgU24cache3_10)); }
	inline GADUNativeExpressAdViewDidDismissScreenCallback_t784484480 * get_U3CU3Ef__mgU24cache3_10() const { return ___U3CU3Ef__mgU24cache3_10; }
	inline GADUNativeExpressAdViewDidDismissScreenCallback_t784484480 ** get_address_of_U3CU3Ef__mgU24cache3_10() { return &___U3CU3Ef__mgU24cache3_10; }
	inline void set_U3CU3Ef__mgU24cache3_10(GADUNativeExpressAdViewDidDismissScreenCallback_t784484480 * value)
	{
		___U3CU3Ef__mgU24cache3_10 = value;
		Il2CppCodeGenWriteBarrier(&___U3CU3Ef__mgU24cache3_10, value);
	}

	inline static int32_t get_offset_of_U3CU3Ef__mgU24cache4_11() { return static_cast<int32_t>(offsetof(NativeExpressAdClient_t2805846113_StaticFields, ___U3CU3Ef__mgU24cache4_11)); }
	inline GADUNativeExpressAdViewWillLeaveApplicationCallback_t548165752 * get_U3CU3Ef__mgU24cache4_11() const { return ___U3CU3Ef__mgU24cache4_11; }
	inline GADUNativeExpressAdViewWillLeaveApplicationCallback_t548165752 ** get_address_of_U3CU3Ef__mgU24cache4_11() { return &___U3CU3Ef__mgU24cache4_11; }
	inline void set_U3CU3Ef__mgU24cache4_11(GADUNativeExpressAdViewWillLeaveApplicationCallback_t548165752 * value)
	{
		___U3CU3Ef__mgU24cache4_11 = value;
		Il2CppCodeGenWriteBarrier(&___U3CU3Ef__mgU24cache4_11, value);
	}

	inline static int32_t get_offset_of_U3CU3Ef__mgU24cache5_12() { return static_cast<int32_t>(offsetof(NativeExpressAdClient_t2805846113_StaticFields, ___U3CU3Ef__mgU24cache5_12)); }
	inline GADUNativeExpressAdViewDidReceiveAdCallback_t2677637168 * get_U3CU3Ef__mgU24cache5_12() const { return ___U3CU3Ef__mgU24cache5_12; }
	inline GADUNativeExpressAdViewDidReceiveAdCallback_t2677637168 ** get_address_of_U3CU3Ef__mgU24cache5_12() { return &___U3CU3Ef__mgU24cache5_12; }
	inline void set_U3CU3Ef__mgU24cache5_12(GADUNativeExpressAdViewDidReceiveAdCallback_t2677637168 * value)
	{
		___U3CU3Ef__mgU24cache5_12 = value;
		Il2CppCodeGenWriteBarrier(&___U3CU3Ef__mgU24cache5_12, value);
	}

	inline static int32_t get_offset_of_U3CU3Ef__mgU24cache6_13() { return static_cast<int32_t>(offsetof(NativeExpressAdClient_t2805846113_StaticFields, ___U3CU3Ef__mgU24cache6_13)); }
	inline GADUNativeExpressAdViewDidFailToReceiveAdWithErrorCallback_t3648222485 * get_U3CU3Ef__mgU24cache6_13() const { return ___U3CU3Ef__mgU24cache6_13; }
	inline GADUNativeExpressAdViewDidFailToReceiveAdWithErrorCallback_t3648222485 ** get_address_of_U3CU3Ef__mgU24cache6_13() { return &___U3CU3Ef__mgU24cache6_13; }
	inline void set_U3CU3Ef__mgU24cache6_13(GADUNativeExpressAdViewDidFailToReceiveAdWithErrorCallback_t3648222485 * value)
	{
		___U3CU3Ef__mgU24cache6_13 = value;
		Il2CppCodeGenWriteBarrier(&___U3CU3Ef__mgU24cache6_13, value);
	}

	inline static int32_t get_offset_of_U3CU3Ef__mgU24cache7_14() { return static_cast<int32_t>(offsetof(NativeExpressAdClient_t2805846113_StaticFields, ___U3CU3Ef__mgU24cache7_14)); }
	inline GADUNativeExpressAdViewWillPresentScreenCallback_t3478706784 * get_U3CU3Ef__mgU24cache7_14() const { return ___U3CU3Ef__mgU24cache7_14; }
	inline GADUNativeExpressAdViewWillPresentScreenCallback_t3478706784 ** get_address_of_U3CU3Ef__mgU24cache7_14() { return &___U3CU3Ef__mgU24cache7_14; }
	inline void set_U3CU3Ef__mgU24cache7_14(GADUNativeExpressAdViewWillPresentScreenCallback_t3478706784 * value)
	{
		___U3CU3Ef__mgU24cache7_14 = value;
		Il2CppCodeGenWriteBarrier(&___U3CU3Ef__mgU24cache7_14, value);
	}

	inline static int32_t get_offset_of_U3CU3Ef__mgU24cache8_15() { return static_cast<int32_t>(offsetof(NativeExpressAdClient_t2805846113_StaticFields, ___U3CU3Ef__mgU24cache8_15)); }
	inline GADUNativeExpressAdViewDidDismissScreenCallback_t784484480 * get_U3CU3Ef__mgU24cache8_15() const { return ___U3CU3Ef__mgU24cache8_15; }
	inline GADUNativeExpressAdViewDidDismissScreenCallback_t784484480 ** get_address_of_U3CU3Ef__mgU24cache8_15() { return &___U3CU3Ef__mgU24cache8_15; }
	inline void set_U3CU3Ef__mgU24cache8_15(GADUNativeExpressAdViewDidDismissScreenCallback_t784484480 * value)
	{
		___U3CU3Ef__mgU24cache8_15 = value;
		Il2CppCodeGenWriteBarrier(&___U3CU3Ef__mgU24cache8_15, value);
	}

	inline static int32_t get_offset_of_U3CU3Ef__mgU24cache9_16() { return static_cast<int32_t>(offsetof(NativeExpressAdClient_t2805846113_StaticFields, ___U3CU3Ef__mgU24cache9_16)); }
	inline GADUNativeExpressAdViewWillLeaveApplicationCallback_t548165752 * get_U3CU3Ef__mgU24cache9_16() const { return ___U3CU3Ef__mgU24cache9_16; }
	inline GADUNativeExpressAdViewWillLeaveApplicationCallback_t548165752 ** get_address_of_U3CU3Ef__mgU24cache9_16() { return &___U3CU3Ef__mgU24cache9_16; }
	inline void set_U3CU3Ef__mgU24cache9_16(GADUNativeExpressAdViewWillLeaveApplicationCallback_t548165752 * value)
	{
		___U3CU3Ef__mgU24cache9_16 = value;
		Il2CppCodeGenWriteBarrier(&___U3CU3Ef__mgU24cache9_16, value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
