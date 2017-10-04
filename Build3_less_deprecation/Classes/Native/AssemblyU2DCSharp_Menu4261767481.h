#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// UnityEngine.Material
struct Material_t193706927;
// UnityEngine.Texture
struct Texture_t2243626319;

#include "UnityEngine_UnityEngine_MonoBehaviour1158329972.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// Menu
struct  Menu_t4261767481  : public MonoBehaviour_t1158329972
{
public:
	// UnityEngine.Material Menu::material
	Material_t193706927 * ___material_2;
	// UnityEngine.Texture Menu::menu_icon
	Texture_t2243626319 * ___menu_icon_3;

public:
	inline static int32_t get_offset_of_material_2() { return static_cast<int32_t>(offsetof(Menu_t4261767481, ___material_2)); }
	inline Material_t193706927 * get_material_2() const { return ___material_2; }
	inline Material_t193706927 ** get_address_of_material_2() { return &___material_2; }
	inline void set_material_2(Material_t193706927 * value)
	{
		___material_2 = value;
		Il2CppCodeGenWriteBarrier(&___material_2, value);
	}

	inline static int32_t get_offset_of_menu_icon_3() { return static_cast<int32_t>(offsetof(Menu_t4261767481, ___menu_icon_3)); }
	inline Texture_t2243626319 * get_menu_icon_3() const { return ___menu_icon_3; }
	inline Texture_t2243626319 ** get_address_of_menu_icon_3() { return &___menu_icon_3; }
	inline void set_menu_icon_3(Texture_t2243626319 * value)
	{
		___menu_icon_3 = value;
		Il2CppCodeGenWriteBarrier(&___menu_icon_3, value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
