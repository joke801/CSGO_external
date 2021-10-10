#pragma once
#include "CommonIncludes.hpp"
#include "Entity.hpp"
class Glow {

private:

	struct color {
		float r, g, b;
	};

	struct GlowObjectDefinition_r
	{
		int    nNextFreeSlot;
		DWORD pEntity;
		color vGlowColor;
		float  flGlowAlpha;
		int   cUnk;
		float  flUnk;
		float  flBloomAmount;
		float  flUnk1;
		bool   bRenderWhenOccluded;
		bool   bRenderWhenUnoccluded;
		bool   bFullBloom;
		char   cUnk1;
		int    nFullBloomStencilTestValue;
		int    nGlowStyle;
		int    nSplitScreenSlot;

	};
	struct GlowObjectDefinition_w
	{
		color vGlowColor;
		float  flGlowAlpha;
		int   cUnk;
		float  flUnk;
		float  flBloomAmount;
		float  flUnk1;
		bool   bRenderWhenOccluded;
		bool   bRenderWhenUnoccluded;
		bool   bFullBloom;
		char   cUnk1;
		int    nFullBloomStencilTestValue;
		int    nGlowStyle;
		int    nSplitScreenSlot;
	};


	struct glow_obj_manager_t {
		uintptr_t m_objects_ptr;
		int		m_max;
		int		unk;
		int		m_count;
		uintptr_t		m_data_ptr_last;
		int				m_first_free_slot;
		int		pad[5];
	};



public:

	void tGlow();


};
extern Glow cGlow;