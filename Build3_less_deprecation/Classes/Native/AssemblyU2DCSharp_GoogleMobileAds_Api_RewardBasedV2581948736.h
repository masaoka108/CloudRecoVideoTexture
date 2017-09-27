#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// GoogleMobileAds.Common.IRewardBasedVideoAdClient
struct IRewardBasedVideoAdClient_t4030846478;
// GoogleMobileAds.Api.RewardBasedVideoAd
struct RewardBasedVideoAd_t2581948736;
// System.EventHandler`1<System.EventArgs>
struct EventHandler_1_t1880931879;
// System.EventHandler`1<GoogleMobileAds.Api.AdFailedToLoadEventArgs>
struct EventHandler_1_t347919082;
// System.EventHandler`1<GoogleMobileAds.Api.Reward>
struct EventHandler_1_t344857101;

#include "mscorlib_System_Object2689449295.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// GoogleMobileAds.Api.RewardBasedVideoAd
struct  RewardBasedVideoAd_t2581948736  : public Il2CppObject
{
public:
	// GoogleMobileAds.Common.IRewardBasedVideoAdClient GoogleMobileAds.Api.RewardBasedVideoAd::client
	Il2CppObject * ___client_0;
	// System.EventHandler`1<System.EventArgs> GoogleMobileAds.Api.RewardBasedVideoAd::OnAdLoaded
	EventHandler_1_t1880931879 * ___OnAdLoaded_2;
	// System.EventHandler`1<GoogleMobileAds.Api.AdFailedToLoadEventArgs> GoogleMobileAds.Api.RewardBasedVideoAd::OnAdFailedToLoad
	EventHandler_1_t347919082 * ___OnAdFailedToLoad_3;
	// System.EventHandler`1<System.EventArgs> GoogleMobileAds.Api.RewardBasedVideoAd::OnAdOpening
	EventHandler_1_t1880931879 * ___OnAdOpening_4;
	// System.EventHandler`1<System.EventArgs> GoogleMobileAds.Api.RewardBasedVideoAd::OnAdStarted
	EventHandler_1_t1880931879 * ___OnAdStarted_5;
	// System.EventHandler`1<System.EventArgs> GoogleMobileAds.Api.RewardBasedVideoAd::OnAdClosed
	EventHandler_1_t1880931879 * ___OnAdClosed_6;
	// System.EventHandler`1<GoogleMobileAds.Api.Reward> GoogleMobileAds.Api.RewardBasedVideoAd::OnAdRewarded
	EventHandler_1_t344857101 * ___OnAdRewarded_7;
	// System.EventHandler`1<System.EventArgs> GoogleMobileAds.Api.RewardBasedVideoAd::OnAdLeavingApplication
	EventHandler_1_t1880931879 * ___OnAdLeavingApplication_8;

public:
	inline static int32_t get_offset_of_client_0() { return static_cast<int32_t>(offsetof(RewardBasedVideoAd_t2581948736, ___client_0)); }
	inline Il2CppObject * get_client_0() const { return ___client_0; }
	inline Il2CppObject ** get_address_of_client_0() { return &___client_0; }
	inline void set_client_0(Il2CppObject * value)
	{
		___client_0 = value;
		Il2CppCodeGenWriteBarrier(&___client_0, value);
	}

	inline static int32_t get_offset_of_OnAdLoaded_2() { return static_cast<int32_t>(offsetof(RewardBasedVideoAd_t2581948736, ___OnAdLoaded_2)); }
	inline EventHandler_1_t1880931879 * get_OnAdLoaded_2() const { return ___OnAdLoaded_2; }
	inline EventHandler_1_t1880931879 ** get_address_of_OnAdLoaded_2() { return &___OnAdLoaded_2; }
	inline void set_OnAdLoaded_2(EventHandler_1_t1880931879 * value)
	{
		___OnAdLoaded_2 = value;
		Il2CppCodeGenWriteBarrier(&___OnAdLoaded_2, value);
	}

	inline static int32_t get_offset_of_OnAdFailedToLoad_3() { return static_cast<int32_t>(offsetof(RewardBasedVideoAd_t2581948736, ___OnAdFailedToLoad_3)); }
	inline EventHandler_1_t347919082 * get_OnAdFailedToLoad_3() const { return ___OnAdFailedToLoad_3; }
	inline EventHandler_1_t347919082 ** get_address_of_OnAdFailedToLoad_3() { return &___OnAdFailedToLoad_3; }
	inline void set_OnAdFailedToLoad_3(EventHandler_1_t347919082 * value)
	{
		___OnAdFailedToLoad_3 = value;
		Il2CppCodeGenWriteBarrier(&___OnAdFailedToLoad_3, value);
	}

	inline static int32_t get_offset_of_OnAdOpening_4() { return static_cast<int32_t>(offsetof(RewardBasedVideoAd_t2581948736, ___OnAdOpening_4)); }
	inline EventHandler_1_t1880931879 * get_OnAdOpening_4() const { return ___OnAdOpening_4; }
	inline EventHandler_1_t1880931879 ** get_address_of_OnAdOpening_4() { return &___OnAdOpening_4; }
	inline void set_OnAdOpening_4(EventHandler_1_t1880931879 * value)
	{
		___OnAdOpening_4 = value;
		Il2CppCodeGenWriteBarrier(&___OnAdOpening_4, value);
	}

	inline static int32_t get_offset_of_OnAdStarted_5() { return static_cast<int32_t>(offsetof(RewardBasedVideoAd_t2581948736, ___OnAdStarted_5)); }
	inline EventHandler_1_t1880931879 * get_OnAdStarted_5() const { return ___OnAdStarted_5; }
	inline EventHandler_1_t1880931879 ** get_address_of_OnAdStarted_5() { return &___OnAdStarted_5; }
	inline void set_OnAdStarted_5(EventHandler_1_t1880931879 * value)
	{
		___OnAdStarted_5 = value;
		Il2CppCodeGenWriteBarrier(&___OnAdStarted_5, value);
	}

	inline static int32_t get_offset_of_OnAdClosed_6() { return static_cast<int32_t>(offsetof(RewardBasedVideoAd_t2581948736, ___OnAdClosed_6)); }
	inline EventHandler_1_t1880931879 * get_OnAdClosed_6() const { return ___OnAdClosed_6; }
	inline EventHandler_1_t1880931879 ** get_address_of_OnAdClosed_6() { return &___OnAdClosed_6; }
	inline void set_OnAdClosed_6(EventHandler_1_t1880931879 * value)
	{
		___OnAdClosed_6 = value;
		Il2CppCodeGenWriteBarrier(&___OnAdClosed_6, value);
	}

	inline static int32_t get_offset_of_OnAdRewarded_7() { return static_cast<int32_t>(offsetof(RewardBasedVideoAd_t2581948736, ___OnAdRewarded_7)); }
	inline EventHandler_1_t344857101 * get_OnAdRewarded_7() const { return ___OnAdRewarded_7; }
	inline EventHandler_1_t344857101 ** get_address_of_OnAdRewarded_7() { return &___OnAdRewarded_7; }
	inline void set_OnAdRewarded_7(EventHandler_1_t344857101 * value)
	{
		___OnAdRewarded_7 = value;
		Il2CppCodeGenWriteBarrier(&___OnAdRewarded_7, value);
	}

	inline static int32_t get_offset_of_OnAdLeavingApplication_8() { return static_cast<int32_t>(offsetof(RewardBasedVideoAd_t2581948736, ___OnAdLeavingApplication_8)); }
	inline EventHandler_1_t1880931879 * get_OnAdLeavingApplication_8() const { return ___OnAdLeavingApplication_8; }
	inline EventHandler_1_t1880931879 ** get_address_of_OnAdLeavingApplication_8() { return &___OnAdLeavingApplication_8; }
	inline void set_OnAdLeavingApplication_8(EventHandler_1_t1880931879 * value)
	{
		___OnAdLeavingApplication_8 = value;
		Il2CppCodeGenWriteBarrier(&___OnAdLeavingApplication_8, value);
	}
};

struct RewardBasedVideoAd_t2581948736_StaticFields
{
public:
	// GoogleMobileAds.Api.RewardBasedVideoAd GoogleMobileAds.Api.RewardBasedVideoAd::instance
	RewardBasedVideoAd_t2581948736 * ___instance_1;

public:
	inline static int32_t get_offset_of_instance_1() { return static_cast<int32_t>(offsetof(RewardBasedVideoAd_t2581948736_StaticFields, ___instance_1)); }
	inline RewardBasedVideoAd_t2581948736 * get_instance_1() const { return ___instance_1; }
	inline RewardBasedVideoAd_t2581948736 ** get_address_of_instance_1() { return &___instance_1; }
	inline void set_instance_1(RewardBasedVideoAd_t2581948736 * value)
	{
		___instance_1 = value;
		Il2CppCodeGenWriteBarrier(&___instance_1, value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
