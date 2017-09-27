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
// System.EventHandler`1<GoogleMobileAds.Api.Reward>
struct EventHandler_1_t344857101;
// GoogleMobileAds.iOS.RewardBasedVideoAdClient/GADURewardBasedVideoAdDidReceiveAdCallback
struct GADURewardBasedVideoAdDidReceiveAdCallback_t4169257859;
// GoogleMobileAds.iOS.RewardBasedVideoAdClient/GADURewardBasedVideoAdDidFailToReceiveAdWithErrorCallback
struct GADURewardBasedVideoAdDidFailToReceiveAdWithErrorCallback_t862929376;
// GoogleMobileAds.iOS.RewardBasedVideoAdClient/GADURewardBasedVideoAdDidOpenCallback
struct GADURewardBasedVideoAdDidOpenCallback_t587935421;
// GoogleMobileAds.iOS.RewardBasedVideoAdClient/GADURewardBasedVideoAdDidStartCallback
struct GADURewardBasedVideoAdDidStartCallback_t25341677;
// GoogleMobileAds.iOS.RewardBasedVideoAdClient/GADURewardBasedVideoAdDidCloseCallback
struct GADURewardBasedVideoAdDidCloseCallback_t2453903099;
// GoogleMobileAds.iOS.RewardBasedVideoAdClient/GADURewardBasedVideoAdDidRewardCallback
struct GADURewardBasedVideoAdDidRewardCallback_t129051320;
// GoogleMobileAds.iOS.RewardBasedVideoAdClient/GADURewardBasedVideoAdWillLeaveApplicationCallback
struct GADURewardBasedVideoAdWillLeaveApplicationCallback_t2167763867;

#include "mscorlib_System_Object2689449295.h"
#include "mscorlib_System_IntPtr2504060609.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// GoogleMobileAds.iOS.RewardBasedVideoAdClient
struct  RewardBasedVideoAdClient_t2282664017  : public Il2CppObject
{
public:
	// System.IntPtr GoogleMobileAds.iOS.RewardBasedVideoAdClient::rewardBasedVideoAdPtr
	IntPtr_t ___rewardBasedVideoAdPtr_0;
	// System.IntPtr GoogleMobileAds.iOS.RewardBasedVideoAdClient::rewardBasedVideoAdClientPtr
	IntPtr_t ___rewardBasedVideoAdClientPtr_1;
	// System.EventHandler`1<System.EventArgs> GoogleMobileAds.iOS.RewardBasedVideoAdClient::OnAdLoaded
	EventHandler_1_t1880931879 * ___OnAdLoaded_2;
	// System.EventHandler`1<GoogleMobileAds.Api.AdFailedToLoadEventArgs> GoogleMobileAds.iOS.RewardBasedVideoAdClient::OnAdFailedToLoad
	EventHandler_1_t347919082 * ___OnAdFailedToLoad_3;
	// System.EventHandler`1<System.EventArgs> GoogleMobileAds.iOS.RewardBasedVideoAdClient::OnAdOpening
	EventHandler_1_t1880931879 * ___OnAdOpening_4;
	// System.EventHandler`1<System.EventArgs> GoogleMobileAds.iOS.RewardBasedVideoAdClient::OnAdStarted
	EventHandler_1_t1880931879 * ___OnAdStarted_5;
	// System.EventHandler`1<System.EventArgs> GoogleMobileAds.iOS.RewardBasedVideoAdClient::OnAdClosed
	EventHandler_1_t1880931879 * ___OnAdClosed_6;
	// System.EventHandler`1<GoogleMobileAds.Api.Reward> GoogleMobileAds.iOS.RewardBasedVideoAdClient::OnAdRewarded
	EventHandler_1_t344857101 * ___OnAdRewarded_7;
	// System.EventHandler`1<System.EventArgs> GoogleMobileAds.iOS.RewardBasedVideoAdClient::OnAdLeavingApplication
	EventHandler_1_t1880931879 * ___OnAdLeavingApplication_8;

public:
	inline static int32_t get_offset_of_rewardBasedVideoAdPtr_0() { return static_cast<int32_t>(offsetof(RewardBasedVideoAdClient_t2282664017, ___rewardBasedVideoAdPtr_0)); }
	inline IntPtr_t get_rewardBasedVideoAdPtr_0() const { return ___rewardBasedVideoAdPtr_0; }
	inline IntPtr_t* get_address_of_rewardBasedVideoAdPtr_0() { return &___rewardBasedVideoAdPtr_0; }
	inline void set_rewardBasedVideoAdPtr_0(IntPtr_t value)
	{
		___rewardBasedVideoAdPtr_0 = value;
	}

	inline static int32_t get_offset_of_rewardBasedVideoAdClientPtr_1() { return static_cast<int32_t>(offsetof(RewardBasedVideoAdClient_t2282664017, ___rewardBasedVideoAdClientPtr_1)); }
	inline IntPtr_t get_rewardBasedVideoAdClientPtr_1() const { return ___rewardBasedVideoAdClientPtr_1; }
	inline IntPtr_t* get_address_of_rewardBasedVideoAdClientPtr_1() { return &___rewardBasedVideoAdClientPtr_1; }
	inline void set_rewardBasedVideoAdClientPtr_1(IntPtr_t value)
	{
		___rewardBasedVideoAdClientPtr_1 = value;
	}

	inline static int32_t get_offset_of_OnAdLoaded_2() { return static_cast<int32_t>(offsetof(RewardBasedVideoAdClient_t2282664017, ___OnAdLoaded_2)); }
	inline EventHandler_1_t1880931879 * get_OnAdLoaded_2() const { return ___OnAdLoaded_2; }
	inline EventHandler_1_t1880931879 ** get_address_of_OnAdLoaded_2() { return &___OnAdLoaded_2; }
	inline void set_OnAdLoaded_2(EventHandler_1_t1880931879 * value)
	{
		___OnAdLoaded_2 = value;
		Il2CppCodeGenWriteBarrier(&___OnAdLoaded_2, value);
	}

	inline static int32_t get_offset_of_OnAdFailedToLoad_3() { return static_cast<int32_t>(offsetof(RewardBasedVideoAdClient_t2282664017, ___OnAdFailedToLoad_3)); }
	inline EventHandler_1_t347919082 * get_OnAdFailedToLoad_3() const { return ___OnAdFailedToLoad_3; }
	inline EventHandler_1_t347919082 ** get_address_of_OnAdFailedToLoad_3() { return &___OnAdFailedToLoad_3; }
	inline void set_OnAdFailedToLoad_3(EventHandler_1_t347919082 * value)
	{
		___OnAdFailedToLoad_3 = value;
		Il2CppCodeGenWriteBarrier(&___OnAdFailedToLoad_3, value);
	}

	inline static int32_t get_offset_of_OnAdOpening_4() { return static_cast<int32_t>(offsetof(RewardBasedVideoAdClient_t2282664017, ___OnAdOpening_4)); }
	inline EventHandler_1_t1880931879 * get_OnAdOpening_4() const { return ___OnAdOpening_4; }
	inline EventHandler_1_t1880931879 ** get_address_of_OnAdOpening_4() { return &___OnAdOpening_4; }
	inline void set_OnAdOpening_4(EventHandler_1_t1880931879 * value)
	{
		___OnAdOpening_4 = value;
		Il2CppCodeGenWriteBarrier(&___OnAdOpening_4, value);
	}

	inline static int32_t get_offset_of_OnAdStarted_5() { return static_cast<int32_t>(offsetof(RewardBasedVideoAdClient_t2282664017, ___OnAdStarted_5)); }
	inline EventHandler_1_t1880931879 * get_OnAdStarted_5() const { return ___OnAdStarted_5; }
	inline EventHandler_1_t1880931879 ** get_address_of_OnAdStarted_5() { return &___OnAdStarted_5; }
	inline void set_OnAdStarted_5(EventHandler_1_t1880931879 * value)
	{
		___OnAdStarted_5 = value;
		Il2CppCodeGenWriteBarrier(&___OnAdStarted_5, value);
	}

	inline static int32_t get_offset_of_OnAdClosed_6() { return static_cast<int32_t>(offsetof(RewardBasedVideoAdClient_t2282664017, ___OnAdClosed_6)); }
	inline EventHandler_1_t1880931879 * get_OnAdClosed_6() const { return ___OnAdClosed_6; }
	inline EventHandler_1_t1880931879 ** get_address_of_OnAdClosed_6() { return &___OnAdClosed_6; }
	inline void set_OnAdClosed_6(EventHandler_1_t1880931879 * value)
	{
		___OnAdClosed_6 = value;
		Il2CppCodeGenWriteBarrier(&___OnAdClosed_6, value);
	}

	inline static int32_t get_offset_of_OnAdRewarded_7() { return static_cast<int32_t>(offsetof(RewardBasedVideoAdClient_t2282664017, ___OnAdRewarded_7)); }
	inline EventHandler_1_t344857101 * get_OnAdRewarded_7() const { return ___OnAdRewarded_7; }
	inline EventHandler_1_t344857101 ** get_address_of_OnAdRewarded_7() { return &___OnAdRewarded_7; }
	inline void set_OnAdRewarded_7(EventHandler_1_t344857101 * value)
	{
		___OnAdRewarded_7 = value;
		Il2CppCodeGenWriteBarrier(&___OnAdRewarded_7, value);
	}

	inline static int32_t get_offset_of_OnAdLeavingApplication_8() { return static_cast<int32_t>(offsetof(RewardBasedVideoAdClient_t2282664017, ___OnAdLeavingApplication_8)); }
	inline EventHandler_1_t1880931879 * get_OnAdLeavingApplication_8() const { return ___OnAdLeavingApplication_8; }
	inline EventHandler_1_t1880931879 ** get_address_of_OnAdLeavingApplication_8() { return &___OnAdLeavingApplication_8; }
	inline void set_OnAdLeavingApplication_8(EventHandler_1_t1880931879 * value)
	{
		___OnAdLeavingApplication_8 = value;
		Il2CppCodeGenWriteBarrier(&___OnAdLeavingApplication_8, value);
	}
};

struct RewardBasedVideoAdClient_t2282664017_StaticFields
{
public:
	// GoogleMobileAds.iOS.RewardBasedVideoAdClient/GADURewardBasedVideoAdDidReceiveAdCallback GoogleMobileAds.iOS.RewardBasedVideoAdClient::<>f__mg$cache0
	GADURewardBasedVideoAdDidReceiveAdCallback_t4169257859 * ___U3CU3Ef__mgU24cache0_9;
	// GoogleMobileAds.iOS.RewardBasedVideoAdClient/GADURewardBasedVideoAdDidFailToReceiveAdWithErrorCallback GoogleMobileAds.iOS.RewardBasedVideoAdClient::<>f__mg$cache1
	GADURewardBasedVideoAdDidFailToReceiveAdWithErrorCallback_t862929376 * ___U3CU3Ef__mgU24cache1_10;
	// GoogleMobileAds.iOS.RewardBasedVideoAdClient/GADURewardBasedVideoAdDidOpenCallback GoogleMobileAds.iOS.RewardBasedVideoAdClient::<>f__mg$cache2
	GADURewardBasedVideoAdDidOpenCallback_t587935421 * ___U3CU3Ef__mgU24cache2_11;
	// GoogleMobileAds.iOS.RewardBasedVideoAdClient/GADURewardBasedVideoAdDidStartCallback GoogleMobileAds.iOS.RewardBasedVideoAdClient::<>f__mg$cache3
	GADURewardBasedVideoAdDidStartCallback_t25341677 * ___U3CU3Ef__mgU24cache3_12;
	// GoogleMobileAds.iOS.RewardBasedVideoAdClient/GADURewardBasedVideoAdDidCloseCallback GoogleMobileAds.iOS.RewardBasedVideoAdClient::<>f__mg$cache4
	GADURewardBasedVideoAdDidCloseCallback_t2453903099 * ___U3CU3Ef__mgU24cache4_13;
	// GoogleMobileAds.iOS.RewardBasedVideoAdClient/GADURewardBasedVideoAdDidRewardCallback GoogleMobileAds.iOS.RewardBasedVideoAdClient::<>f__mg$cache5
	GADURewardBasedVideoAdDidRewardCallback_t129051320 * ___U3CU3Ef__mgU24cache5_14;
	// GoogleMobileAds.iOS.RewardBasedVideoAdClient/GADURewardBasedVideoAdWillLeaveApplicationCallback GoogleMobileAds.iOS.RewardBasedVideoAdClient::<>f__mg$cache6
	GADURewardBasedVideoAdWillLeaveApplicationCallback_t2167763867 * ___U3CU3Ef__mgU24cache6_15;

public:
	inline static int32_t get_offset_of_U3CU3Ef__mgU24cache0_9() { return static_cast<int32_t>(offsetof(RewardBasedVideoAdClient_t2282664017_StaticFields, ___U3CU3Ef__mgU24cache0_9)); }
	inline GADURewardBasedVideoAdDidReceiveAdCallback_t4169257859 * get_U3CU3Ef__mgU24cache0_9() const { return ___U3CU3Ef__mgU24cache0_9; }
	inline GADURewardBasedVideoAdDidReceiveAdCallback_t4169257859 ** get_address_of_U3CU3Ef__mgU24cache0_9() { return &___U3CU3Ef__mgU24cache0_9; }
	inline void set_U3CU3Ef__mgU24cache0_9(GADURewardBasedVideoAdDidReceiveAdCallback_t4169257859 * value)
	{
		___U3CU3Ef__mgU24cache0_9 = value;
		Il2CppCodeGenWriteBarrier(&___U3CU3Ef__mgU24cache0_9, value);
	}

	inline static int32_t get_offset_of_U3CU3Ef__mgU24cache1_10() { return static_cast<int32_t>(offsetof(RewardBasedVideoAdClient_t2282664017_StaticFields, ___U3CU3Ef__mgU24cache1_10)); }
	inline GADURewardBasedVideoAdDidFailToReceiveAdWithErrorCallback_t862929376 * get_U3CU3Ef__mgU24cache1_10() const { return ___U3CU3Ef__mgU24cache1_10; }
	inline GADURewardBasedVideoAdDidFailToReceiveAdWithErrorCallback_t862929376 ** get_address_of_U3CU3Ef__mgU24cache1_10() { return &___U3CU3Ef__mgU24cache1_10; }
	inline void set_U3CU3Ef__mgU24cache1_10(GADURewardBasedVideoAdDidFailToReceiveAdWithErrorCallback_t862929376 * value)
	{
		___U3CU3Ef__mgU24cache1_10 = value;
		Il2CppCodeGenWriteBarrier(&___U3CU3Ef__mgU24cache1_10, value);
	}

	inline static int32_t get_offset_of_U3CU3Ef__mgU24cache2_11() { return static_cast<int32_t>(offsetof(RewardBasedVideoAdClient_t2282664017_StaticFields, ___U3CU3Ef__mgU24cache2_11)); }
	inline GADURewardBasedVideoAdDidOpenCallback_t587935421 * get_U3CU3Ef__mgU24cache2_11() const { return ___U3CU3Ef__mgU24cache2_11; }
	inline GADURewardBasedVideoAdDidOpenCallback_t587935421 ** get_address_of_U3CU3Ef__mgU24cache2_11() { return &___U3CU3Ef__mgU24cache2_11; }
	inline void set_U3CU3Ef__mgU24cache2_11(GADURewardBasedVideoAdDidOpenCallback_t587935421 * value)
	{
		___U3CU3Ef__mgU24cache2_11 = value;
		Il2CppCodeGenWriteBarrier(&___U3CU3Ef__mgU24cache2_11, value);
	}

	inline static int32_t get_offset_of_U3CU3Ef__mgU24cache3_12() { return static_cast<int32_t>(offsetof(RewardBasedVideoAdClient_t2282664017_StaticFields, ___U3CU3Ef__mgU24cache3_12)); }
	inline GADURewardBasedVideoAdDidStartCallback_t25341677 * get_U3CU3Ef__mgU24cache3_12() const { return ___U3CU3Ef__mgU24cache3_12; }
	inline GADURewardBasedVideoAdDidStartCallback_t25341677 ** get_address_of_U3CU3Ef__mgU24cache3_12() { return &___U3CU3Ef__mgU24cache3_12; }
	inline void set_U3CU3Ef__mgU24cache3_12(GADURewardBasedVideoAdDidStartCallback_t25341677 * value)
	{
		___U3CU3Ef__mgU24cache3_12 = value;
		Il2CppCodeGenWriteBarrier(&___U3CU3Ef__mgU24cache3_12, value);
	}

	inline static int32_t get_offset_of_U3CU3Ef__mgU24cache4_13() { return static_cast<int32_t>(offsetof(RewardBasedVideoAdClient_t2282664017_StaticFields, ___U3CU3Ef__mgU24cache4_13)); }
	inline GADURewardBasedVideoAdDidCloseCallback_t2453903099 * get_U3CU3Ef__mgU24cache4_13() const { return ___U3CU3Ef__mgU24cache4_13; }
	inline GADURewardBasedVideoAdDidCloseCallback_t2453903099 ** get_address_of_U3CU3Ef__mgU24cache4_13() { return &___U3CU3Ef__mgU24cache4_13; }
	inline void set_U3CU3Ef__mgU24cache4_13(GADURewardBasedVideoAdDidCloseCallback_t2453903099 * value)
	{
		___U3CU3Ef__mgU24cache4_13 = value;
		Il2CppCodeGenWriteBarrier(&___U3CU3Ef__mgU24cache4_13, value);
	}

	inline static int32_t get_offset_of_U3CU3Ef__mgU24cache5_14() { return static_cast<int32_t>(offsetof(RewardBasedVideoAdClient_t2282664017_StaticFields, ___U3CU3Ef__mgU24cache5_14)); }
	inline GADURewardBasedVideoAdDidRewardCallback_t129051320 * get_U3CU3Ef__mgU24cache5_14() const { return ___U3CU3Ef__mgU24cache5_14; }
	inline GADURewardBasedVideoAdDidRewardCallback_t129051320 ** get_address_of_U3CU3Ef__mgU24cache5_14() { return &___U3CU3Ef__mgU24cache5_14; }
	inline void set_U3CU3Ef__mgU24cache5_14(GADURewardBasedVideoAdDidRewardCallback_t129051320 * value)
	{
		___U3CU3Ef__mgU24cache5_14 = value;
		Il2CppCodeGenWriteBarrier(&___U3CU3Ef__mgU24cache5_14, value);
	}

	inline static int32_t get_offset_of_U3CU3Ef__mgU24cache6_15() { return static_cast<int32_t>(offsetof(RewardBasedVideoAdClient_t2282664017_StaticFields, ___U3CU3Ef__mgU24cache6_15)); }
	inline GADURewardBasedVideoAdWillLeaveApplicationCallback_t2167763867 * get_U3CU3Ef__mgU24cache6_15() const { return ___U3CU3Ef__mgU24cache6_15; }
	inline GADURewardBasedVideoAdWillLeaveApplicationCallback_t2167763867 ** get_address_of_U3CU3Ef__mgU24cache6_15() { return &___U3CU3Ef__mgU24cache6_15; }
	inline void set_U3CU3Ef__mgU24cache6_15(GADURewardBasedVideoAdWillLeaveApplicationCallback_t2167763867 * value)
	{
		___U3CU3Ef__mgU24cache6_15 = value;
		Il2CppCodeGenWriteBarrier(&___U3CU3Ef__mgU24cache6_15, value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
