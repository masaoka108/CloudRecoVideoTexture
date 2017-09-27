#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// UnityEngine.Object[]
struct ObjectU5BU5D_t4217747464;
// System.Collections.Generic.List`1<ParticleTester/FlareSystem>
struct List_1_t2103180797;

#include "UnityEngine_UnityEngine_MonoBehaviour1158329972.h"
#include "AssemblyU2DCSharp_ParticleTester_SystemType375403297.h"
#include "UnityEngine_UnityEngine_Vector22243707579.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// ParticleTester
struct  ParticleTester_t998280083  : public MonoBehaviour_t1158329972
{
public:
	// ParticleTester/SystemType ParticleTester::systemType
	int32_t ___systemType_2;
	// UnityEngine.Object[] ParticleTester::particleSystems
	ObjectU5BU5D_t4217747464* ___particleSystems_3;
	// UnityEngine.Object[] ParticleTester::loadFlareSystems
	ObjectU5BU5D_t4217747464* ___loadFlareSystems_4;
	// UnityEngine.Object[] ParticleTester::loadDirectionalSystems
	ObjectU5BU5D_t4217747464* ___loadDirectionalSystems_5;
	// System.Collections.Generic.List`1<ParticleTester/FlareSystem> ParticleTester::flareSystems
	List_1_t2103180797 * ___flareSystems_6;
	// System.Collections.Generic.List`1<ParticleTester/FlareSystem> ParticleTester::directionalSystems
	List_1_t2103180797 * ___directionalSystems_7;
	// System.Boolean ParticleTester::expBool
	bool ___expBool_8;
	// System.Boolean ParticleTester::flrBool
	bool ___flrBool_9;
	// System.Boolean ParticleTester::flmBool
	bool ___flmBool_10;
	// UnityEngine.Vector2 ParticleTester::scrollPosition
	Vector2_t2243707579  ___scrollPosition_11;
	// ParticleTester/SystemType ParticleTester::savedSystemType
	int32_t ___savedSystemType_12;

public:
	inline static int32_t get_offset_of_systemType_2() { return static_cast<int32_t>(offsetof(ParticleTester_t998280083, ___systemType_2)); }
	inline int32_t get_systemType_2() const { return ___systemType_2; }
	inline int32_t* get_address_of_systemType_2() { return &___systemType_2; }
	inline void set_systemType_2(int32_t value)
	{
		___systemType_2 = value;
	}

	inline static int32_t get_offset_of_particleSystems_3() { return static_cast<int32_t>(offsetof(ParticleTester_t998280083, ___particleSystems_3)); }
	inline ObjectU5BU5D_t4217747464* get_particleSystems_3() const { return ___particleSystems_3; }
	inline ObjectU5BU5D_t4217747464** get_address_of_particleSystems_3() { return &___particleSystems_3; }
	inline void set_particleSystems_3(ObjectU5BU5D_t4217747464* value)
	{
		___particleSystems_3 = value;
		Il2CppCodeGenWriteBarrier(&___particleSystems_3, value);
	}

	inline static int32_t get_offset_of_loadFlareSystems_4() { return static_cast<int32_t>(offsetof(ParticleTester_t998280083, ___loadFlareSystems_4)); }
	inline ObjectU5BU5D_t4217747464* get_loadFlareSystems_4() const { return ___loadFlareSystems_4; }
	inline ObjectU5BU5D_t4217747464** get_address_of_loadFlareSystems_4() { return &___loadFlareSystems_4; }
	inline void set_loadFlareSystems_4(ObjectU5BU5D_t4217747464* value)
	{
		___loadFlareSystems_4 = value;
		Il2CppCodeGenWriteBarrier(&___loadFlareSystems_4, value);
	}

	inline static int32_t get_offset_of_loadDirectionalSystems_5() { return static_cast<int32_t>(offsetof(ParticleTester_t998280083, ___loadDirectionalSystems_5)); }
	inline ObjectU5BU5D_t4217747464* get_loadDirectionalSystems_5() const { return ___loadDirectionalSystems_5; }
	inline ObjectU5BU5D_t4217747464** get_address_of_loadDirectionalSystems_5() { return &___loadDirectionalSystems_5; }
	inline void set_loadDirectionalSystems_5(ObjectU5BU5D_t4217747464* value)
	{
		___loadDirectionalSystems_5 = value;
		Il2CppCodeGenWriteBarrier(&___loadDirectionalSystems_5, value);
	}

	inline static int32_t get_offset_of_flareSystems_6() { return static_cast<int32_t>(offsetof(ParticleTester_t998280083, ___flareSystems_6)); }
	inline List_1_t2103180797 * get_flareSystems_6() const { return ___flareSystems_6; }
	inline List_1_t2103180797 ** get_address_of_flareSystems_6() { return &___flareSystems_6; }
	inline void set_flareSystems_6(List_1_t2103180797 * value)
	{
		___flareSystems_6 = value;
		Il2CppCodeGenWriteBarrier(&___flareSystems_6, value);
	}

	inline static int32_t get_offset_of_directionalSystems_7() { return static_cast<int32_t>(offsetof(ParticleTester_t998280083, ___directionalSystems_7)); }
	inline List_1_t2103180797 * get_directionalSystems_7() const { return ___directionalSystems_7; }
	inline List_1_t2103180797 ** get_address_of_directionalSystems_7() { return &___directionalSystems_7; }
	inline void set_directionalSystems_7(List_1_t2103180797 * value)
	{
		___directionalSystems_7 = value;
		Il2CppCodeGenWriteBarrier(&___directionalSystems_7, value);
	}

	inline static int32_t get_offset_of_expBool_8() { return static_cast<int32_t>(offsetof(ParticleTester_t998280083, ___expBool_8)); }
	inline bool get_expBool_8() const { return ___expBool_8; }
	inline bool* get_address_of_expBool_8() { return &___expBool_8; }
	inline void set_expBool_8(bool value)
	{
		___expBool_8 = value;
	}

	inline static int32_t get_offset_of_flrBool_9() { return static_cast<int32_t>(offsetof(ParticleTester_t998280083, ___flrBool_9)); }
	inline bool get_flrBool_9() const { return ___flrBool_9; }
	inline bool* get_address_of_flrBool_9() { return &___flrBool_9; }
	inline void set_flrBool_9(bool value)
	{
		___flrBool_9 = value;
	}

	inline static int32_t get_offset_of_flmBool_10() { return static_cast<int32_t>(offsetof(ParticleTester_t998280083, ___flmBool_10)); }
	inline bool get_flmBool_10() const { return ___flmBool_10; }
	inline bool* get_address_of_flmBool_10() { return &___flmBool_10; }
	inline void set_flmBool_10(bool value)
	{
		___flmBool_10 = value;
	}

	inline static int32_t get_offset_of_scrollPosition_11() { return static_cast<int32_t>(offsetof(ParticleTester_t998280083, ___scrollPosition_11)); }
	inline Vector2_t2243707579  get_scrollPosition_11() const { return ___scrollPosition_11; }
	inline Vector2_t2243707579 * get_address_of_scrollPosition_11() { return &___scrollPosition_11; }
	inline void set_scrollPosition_11(Vector2_t2243707579  value)
	{
		___scrollPosition_11 = value;
	}

	inline static int32_t get_offset_of_savedSystemType_12() { return static_cast<int32_t>(offsetof(ParticleTester_t998280083, ___savedSystemType_12)); }
	inline int32_t get_savedSystemType_12() const { return ___savedSystemType_12; }
	inline int32_t* get_address_of_savedSystemType_12() { return &___savedSystemType_12; }
	inline void set_savedSystemType_12(int32_t value)
	{
		___savedSystemType_12 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
