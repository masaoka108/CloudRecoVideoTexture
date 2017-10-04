#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>
#include <assert.h>
#include <exception>

// GoogleMobileAds.Api.InterstitialAd
struct InterstitialAd_t3805611425;
// System.String
struct String_t;
// System.EventHandler`1<System.EventArgs>
struct EventHandler_1_t1880931879;
// System.EventHandler`1<GoogleMobileAds.Api.AdFailedToLoadEventArgs>
struct EventHandler_1_t347919082;
// GoogleMobileAds.Api.AdRequest
struct AdRequest_t3179524098;
// System.Object
struct Il2CppObject;
// System.EventArgs
struct EventArgs_t3289624707;
// GoogleMobileAds.Api.AdFailedToLoadEventArgs
struct AdFailedToLoadEventArgs_t1756611910;

#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_String2029220233.h"
#include "AssemblyU2DCSharp_GoogleMobileAds_Api_AdRequest3179524098.h"
#include "mscorlib_System_Object2689449295.h"
#include "mscorlib_System_EventArgs3289624707.h"
#include "AssemblyU2DCSharp_GoogleMobileAds_Api_AdFailedToLo1756611910.h"

// System.Void GoogleMobileAds.Api.InterstitialAd::.ctor(System.String)
extern "C"  void InterstitialAd__ctor_m2702976997 (InterstitialAd_t3805611425 * __this, String_t* ___adUnitId0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void GoogleMobileAds.Api.InterstitialAd::add_OnAdLoaded(System.EventHandler`1<System.EventArgs>)
extern "C"  void InterstitialAd_add_OnAdLoaded_m1716245826 (InterstitialAd_t3805611425 * __this, EventHandler_1_t1880931879 * ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void GoogleMobileAds.Api.InterstitialAd::remove_OnAdLoaded(System.EventHandler`1<System.EventArgs>)
extern "C"  void InterstitialAd_remove_OnAdLoaded_m3884721129 (InterstitialAd_t3805611425 * __this, EventHandler_1_t1880931879 * ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void GoogleMobileAds.Api.InterstitialAd::add_OnAdFailedToLoad(System.EventHandler`1<GoogleMobileAds.Api.AdFailedToLoadEventArgs>)
extern "C"  void InterstitialAd_add_OnAdFailedToLoad_m2604002624 (InterstitialAd_t3805611425 * __this, EventHandler_1_t347919082 * ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void GoogleMobileAds.Api.InterstitialAd::remove_OnAdFailedToLoad(System.EventHandler`1<GoogleMobileAds.Api.AdFailedToLoadEventArgs>)
extern "C"  void InterstitialAd_remove_OnAdFailedToLoad_m1154787083 (InterstitialAd_t3805611425 * __this, EventHandler_1_t347919082 * ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void GoogleMobileAds.Api.InterstitialAd::add_OnAdOpening(System.EventHandler`1<System.EventArgs>)
extern "C"  void InterstitialAd_add_OnAdOpening_m1221536285 (InterstitialAd_t3805611425 * __this, EventHandler_1_t1880931879 * ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void GoogleMobileAds.Api.InterstitialAd::remove_OnAdOpening(System.EventHandler`1<System.EventArgs>)
extern "C"  void InterstitialAd_remove_OnAdOpening_m1329458460 (InterstitialAd_t3805611425 * __this, EventHandler_1_t1880931879 * ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void GoogleMobileAds.Api.InterstitialAd::add_OnAdClosed(System.EventHandler`1<System.EventArgs>)
extern "C"  void InterstitialAd_add_OnAdClosed_m230087679 (InterstitialAd_t3805611425 * __this, EventHandler_1_t1880931879 * ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void GoogleMobileAds.Api.InterstitialAd::remove_OnAdClosed(System.EventHandler`1<System.EventArgs>)
extern "C"  void InterstitialAd_remove_OnAdClosed_m3208324866 (InterstitialAd_t3805611425 * __this, EventHandler_1_t1880931879 * ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void GoogleMobileAds.Api.InterstitialAd::add_OnAdLeavingApplication(System.EventHandler`1<System.EventArgs>)
extern "C"  void InterstitialAd_add_OnAdLeavingApplication_m1199500361 (InterstitialAd_t3805611425 * __this, EventHandler_1_t1880931879 * ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void GoogleMobileAds.Api.InterstitialAd::remove_OnAdLeavingApplication(System.EventHandler`1<System.EventArgs>)
extern "C"  void InterstitialAd_remove_OnAdLeavingApplication_m3905181332 (InterstitialAd_t3805611425 * __this, EventHandler_1_t1880931879 * ___value0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void GoogleMobileAds.Api.InterstitialAd::LoadAd(GoogleMobileAds.Api.AdRequest)
extern "C"  void InterstitialAd_LoadAd_m2734591571 (InterstitialAd_t3805611425 * __this, AdRequest_t3179524098 * ___request0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean GoogleMobileAds.Api.InterstitialAd::IsLoaded()
extern "C"  bool InterstitialAd_IsLoaded_m3944774772 (InterstitialAd_t3805611425 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void GoogleMobileAds.Api.InterstitialAd::Show()
extern "C"  void InterstitialAd_Show_m2770889846 (InterstitialAd_t3805611425 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void GoogleMobileAds.Api.InterstitialAd::Destroy()
extern "C"  void InterstitialAd_Destroy_m2420841909 (InterstitialAd_t3805611425 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void GoogleMobileAds.Api.InterstitialAd::<InterstitialAd>m__0(System.Object,System.EventArgs)
extern "C"  void InterstitialAd_U3CInterstitialAdU3Em__0_m345769133 (InterstitialAd_t3805611425 * __this, Il2CppObject * ___sender0, EventArgs_t3289624707 * ___args1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void GoogleMobileAds.Api.InterstitialAd::<InterstitialAd>m__1(System.Object,GoogleMobileAds.Api.AdFailedToLoadEventArgs)
extern "C"  void InterstitialAd_U3CInterstitialAdU3Em__1_m1967517559 (InterstitialAd_t3805611425 * __this, Il2CppObject * ___sender0, AdFailedToLoadEventArgs_t1756611910 * ___args1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void GoogleMobileAds.Api.InterstitialAd::<InterstitialAd>m__2(System.Object,System.EventArgs)
extern "C"  void InterstitialAd_U3CInterstitialAdU3Em__2_m743200759 (InterstitialAd_t3805611425 * __this, Il2CppObject * ___sender0, EventArgs_t3289624707 * ___args1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void GoogleMobileAds.Api.InterstitialAd::<InterstitialAd>m__3(System.Object,System.EventArgs)
extern "C"  void InterstitialAd_U3CInterstitialAdU3Em__3_m4243372498 (InterstitialAd_t3805611425 * __this, Il2CppObject * ___sender0, EventArgs_t3289624707 * ___args1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void GoogleMobileAds.Api.InterstitialAd::<InterstitialAd>m__4(System.Object,System.EventArgs)
extern "C"  void InterstitialAd_U3CInterstitialAdU3Em__4_m1146135361 (InterstitialAd_t3805611425 * __this, Il2CppObject * ___sender0, EventArgs_t3289624707 * ___args1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
