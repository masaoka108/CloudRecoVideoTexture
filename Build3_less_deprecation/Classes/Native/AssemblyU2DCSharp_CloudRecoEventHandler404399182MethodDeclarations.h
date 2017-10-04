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

// CloudRecoEventHandler
struct CloudRecoEventHandler_t404399182;
// System.Collections.IEnumerator
struct IEnumerator_t1466026749;
// System.String
struct String_t;
// VideoPlaybackBehaviour
struct VideoPlaybackBehaviour_t222960481;
// UnityEngine.WWW
struct WWW_t2919945039;
// UnityEngine.GameObject
struct GameObject_t1756533147;

#include "codegen/il2cpp-codegen.h"
#include "Vuforia_UnityExtensions_Vuforia_TargetFinder_InitStat4409649.h"
#include "Vuforia_UnityExtensions_Vuforia_TargetFinder_Updat1473252352.h"
#include "Vuforia_UnityExtensions_Vuforia_TargetFinder_Targe1958726506.h"
#include "mscorlib_System_String2029220233.h"
#include "AssemblyU2DCSharp_VideoPlaybackBehaviour222960481.h"
#include "UnityEngine_UnityEngine_WWW2919945039.h"
#include "UnityEngine_UnityEngine_GameObject1756533147.h"

// System.Void CloudRecoEventHandler::.ctor()
extern "C"  void CloudRecoEventHandler__ctor_m3879971889 (CloudRecoEventHandler_t404399182 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CloudRecoEventHandler::Start()
extern "C"  void CloudRecoEventHandler_Start_m2082864233 (CloudRecoEventHandler_t404399182 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CloudRecoEventHandler::OnInitialized()
extern "C"  void CloudRecoEventHandler_OnInitialized_m2703231136 (CloudRecoEventHandler_t404399182 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CloudRecoEventHandler::OnInitError(Vuforia.TargetFinder/InitState)
extern "C"  void CloudRecoEventHandler_OnInitError_m1449609749 (CloudRecoEventHandler_t404399182 * __this, int32_t ___initError0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CloudRecoEventHandler::OnUpdateError(Vuforia.TargetFinder/UpdateState)
extern "C"  void CloudRecoEventHandler_OnUpdateError_m2350942173 (CloudRecoEventHandler_t404399182 * __this, int32_t ___updateError0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CloudRecoEventHandler::OnStateChanged(System.Boolean)
extern "C"  void CloudRecoEventHandler_OnStateChanged_m339865190 (CloudRecoEventHandler_t404399182 * __this, bool ___scanning0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IEnumerator CloudRecoEventHandler::timeStop()
extern "C"  Il2CppObject * CloudRecoEventHandler_timeStop_m2851488432 (CloudRecoEventHandler_t404399182 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CloudRecoEventHandler::OnNewSearchResult(Vuforia.TargetFinder/TargetSearchResult)
extern "C"  void CloudRecoEventHandler_OnNewSearchResult_m3228078767 (CloudRecoEventHandler_t404399182 * __this, TargetSearchResult_t1958726506  ___targetSearchResult0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CloudRecoEventHandler::CloseErrorDialog()
extern "C"  void CloudRecoEventHandler_CloseErrorDialog_m2773445607 (CloudRecoEventHandler_t404399182 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CloudRecoEventHandler::ShowScanLine(System.Boolean)
extern "C"  void CloudRecoEventHandler_ShowScanLine_m4283924362 (CloudRecoEventHandler_t404399182 * __this, bool ___show0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CloudRecoEventHandler::ShowError(System.String,System.String)
extern "C"  void CloudRecoEventHandler_ShowError_m3307080002 (CloudRecoEventHandler_t404399182 * __this, String_t* ___title0, String_t* ___msg1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CloudRecoEventHandler::RestartApplication()
extern "C"  void CloudRecoEventHandler_RestartApplication_m1409927294 (CloudRecoEventHandler_t404399182 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CloudRecoEventHandler::PauseOtherVideos(VideoPlaybackBehaviour)
extern "C"  void CloudRecoEventHandler_PauseOtherVideos_m2458947422 (CloudRecoEventHandler_t404399182 * __this, VideoPlaybackBehaviour_t222960481 * ___currentVideo0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CloudRecoEventHandler::CountUp(System.String)
extern "C"  void CloudRecoEventHandler_CountUp_m1969343329 (CloudRecoEventHandler_t404399182 * __this, String_t* ___targetId0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CloudRecoEventHandler::InsAccessLog(System.String)
extern "C"  void CloudRecoEventHandler_InsAccessLog_m1601977235 (CloudRecoEventHandler_t404399182 * __this, String_t* ___targetId0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IEnumerator CloudRecoEventHandler::WaitForRequest(UnityEngine.WWW)
extern "C"  Il2CppObject * CloudRecoEventHandler_WaitForRequest_m2886297868 (CloudRecoEventHandler_t404399182 * __this, WWW_t2919945039 * ___www0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CloudRecoEventHandler::connectionEnd(UnityEngine.WWW)
extern "C"  void CloudRecoEventHandler_connectionEnd_m1219642028 (CloudRecoEventHandler_t404399182 * __this, WWW_t2919945039 * ___www0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Collections.IEnumerator CloudRecoEventHandler::CountUp2(System.String)
extern "C"  Il2CppObject * CloudRecoEventHandler_CountUp2_m2672419853 (CloudRecoEventHandler_t404399182 * __this, String_t* ___targetId0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CloudRecoEventHandler::showHideGameObject(UnityEngine.GameObject)
extern "C"  void CloudRecoEventHandler_showHideGameObject_m1642865077 (CloudRecoEventHandler_t404399182 * __this, GameObject_t1756533147 * ___obj0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CloudRecoEventHandler::fadeInGameObject(UnityEngine.GameObject)
extern "C"  void CloudRecoEventHandler_fadeInGameObject_m276987487 (CloudRecoEventHandler_t404399182 * __this, GameObject_t1756533147 * ___obj0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void CloudRecoEventHandler::fadeOutGameObject(UnityEngine.GameObject)
extern "C"  void CloudRecoEventHandler_fadeOutGameObject_m1836851184 (CloudRecoEventHandler_t404399182 * __this, GameObject_t1756533147 * ___obj0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
