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

// UnityEngine.ParticleSystem
struct ParticleSystem_t3394631041;
// UnityEngine.ParticleSystem/IteratorDelegate
struct IteratorDelegate_t2419492168;
// UnityEngine.Transform
struct Transform_t3275118058;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_ParticleSystem3394631041.h"
#include "UnityEngine_UnityEngine_ParticleSystem_IteratorDel2419492168.h"
#include "UnityEngine_UnityEngine_Transform3275118058.h"

// System.Boolean UnityEngine.ParticleSystem::Internal_Play(UnityEngine.ParticleSystem)
extern "C"  bool ParticleSystem_Internal_Play_m2372735108 (Il2CppObject * __this /* static, unused */, ParticleSystem_t3394631041 * ___self0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.ParticleSystem::Internal_Clear(UnityEngine.ParticleSystem)
extern "C"  bool ParticleSystem_Internal_Clear_m661664011 (Il2CppObject * __this /* static, unused */, ParticleSystem_t3394631041 * ___self0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.ParticleSystem::Play()
extern "C"  void ParticleSystem_Play_m4171585816 (ParticleSystem_t3394631041 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.ParticleSystem::Play(System.Boolean)
extern "C"  void ParticleSystem_Play_m1705837075 (ParticleSystem_t3394631041 * __this, bool ___withChildren0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.ParticleSystem::Clear()
extern "C"  void ParticleSystem_Clear_m550005313 (ParticleSystem_t3394631041 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void UnityEngine.ParticleSystem::Clear(System.Boolean)
extern "C"  void ParticleSystem_Clear_m4048064080 (ParticleSystem_t3394631041 * __this, bool ___withChildren0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.ParticleSystem::IterateParticleSystems(System.Boolean,UnityEngine.ParticleSystem/IteratorDelegate)
extern "C"  bool ParticleSystem_IterateParticleSystems_m1240416587 (ParticleSystem_t3394631041 * __this, bool ___recurse0, IteratorDelegate_t2419492168 * ___func1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.ParticleSystem::IterateParticleSystemsRecursive(UnityEngine.Transform,UnityEngine.ParticleSystem/IteratorDelegate)
extern "C"  bool ParticleSystem_IterateParticleSystemsRecursive_m3260878897 (Il2CppObject * __this /* static, unused */, Transform_t3275118058 * ___transform0, IteratorDelegate_t2419492168 * ___func1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.ParticleSystem::<Play>m__0(UnityEngine.ParticleSystem)
extern "C"  bool ParticleSystem_U3CPlayU3Em__0_m4250446697 (Il2CppObject * __this /* static, unused */, ParticleSystem_t3394631041 * ___ps0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean UnityEngine.ParticleSystem::<Clear>m__2(UnityEngine.ParticleSystem)
extern "C"  bool ParticleSystem_U3CClearU3Em__2_m1781329972 (Il2CppObject * __this /* static, unused */, ParticleSystem_t3394631041 * ___ps0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
