#include "Radar.hpp"
#include "Features.hpp"
#include "Offsets.hpp"
#include "Memory.hpp"

Radar cRadar;

void Radar::doRadar(EntityPlayer &cEntity) {

    bool status = (bool)cFeatures.GetCvarValueFast(eVars::playerradarenable);

    if (!status && this->toggledOff == true) {
        return;
    }

    mem.Write<bool>(cEntity.entityBase + Offsets.NVARS.m_bSpotted, status);

    if (!status)
        this->toggledOff = true;
    else
        this->toggledOff = false;
}

