#include "Chams.hpp"
#include "Offsets.hpp"
#include "Features.hpp"

Chams cChams;

void Chams::doChams(EntityPlayer& cEntity) {

	if (!cFeatures.GetCvarValueFast(eVars::playerchamsenable))
		return;

	chamsColor cColor;
	cColor.r = (BYTE)cFeatures.GetCvarValueFast(eVars::playerchamscolorr);
	cColor.g = (BYTE)cFeatures.GetCvarValueFast(eVars::playerchamscolorg);
	cColor.b = (BYTE)cFeatures.GetCvarValueFast(eVars::playerchamscolorb);

	mem.Write<chamsColor>(cEntity.entityBase + Offsets.NVARS.m_clrRender, cColor);



}