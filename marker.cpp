#include "library.h"
#include "shared.h"
#include "shared/AML/amlmod.h"
#include "GTASA/CMessages.h"
#include "GTASA/common.h"
#include "GTASA/CHud.h"
#include "shared/CEvents.h"

//CFG
#include "mod/config.h"

//sautils
#include "isautils.h"
ISAUtils* sautils = nullptr;

#define GTAPLUGIN "GTA Android Plugin"
#define sizeofA(__aVar)  ((int)(sizeof(__aVar)/sizeof(__aVar[0])))

MYMODCFG(MarkerStyle, GTA:SA ColorMarker, 1.3.1, GTAPLUGIN);

//saves
ConfigEntry *pCfgRed;
ConfigEntry *pCfgGreen;
ConfigEntry *pCfgBlue;
ConfigEntry *pCfgAlpha;

//Sautils
char szRetText[8];
void RedChanged(int oldVal, int newVal)
{
    pCfgRed->SetInt(newVal);
    *(char*)(libs.pGame +  0x81A9D0) = newVal;
    *(char*)(libs.pGame + 0xA48230) = newVal;
    *(char*)(libs.pGame + 0x992230) = newVal;
    cfg->Save();
}
const char* RedDrawed(int newVal)
{
    sprintf(szRetText, "%d", newVal);
    return szRetText;
}
void GreenChanged(int oldVal, int newVal)
{
    pCfgGreen->SetInt(newVal);
    *(char*)(libs.pGame +  0x81A9D1) = newVal;
    *(char*)(libs.pGame + 0xA48231) = newVal;
    *(char*)(libs.pGame + 0x992231) = newVal;
    cfg->Save();
}
const char* GreenDrawed(int newVal)
{
    sprintf(szRetText, "%d", newVal);
    return szRetText;
}
void BlueChanged(int oldVal, int newVal)
{
    pCfgBlue->SetInt(newVal);
    *(char*)(libs.pGame +  0x81A9D2) = newVal;
    *(char*)(libs.pGame + 0xA48232) = newVal;
    *(char*)(libs.pGame + 0x992232) = newVal;
    cfg->Save();
}
const char* BlueDrawed(int newVal)
{
    sprintf(szRetText, "%d", newVal);
    return szRetText;
}
void AlphaChanged(int oldVal, int newVal)
{
    pCfgAlpha->SetInt(newVal);
    *(char*)(libs.pGame + 0x34A7AA) = newVal;
    *(char*)(libs.pGame + 0x5BDF8C) = newVal;
    *(char*)(libs.pGame + 0x44227A) = newVal;
    cfg->Save();
}
const char* AlphaDrawed(int newVal)
{
    sprintf(szRetText, "%d", newVal);
    return szRetText;
}
void MarkerDefault(uintptr_t screen)
{
    aml->Unprot(libs.pGame + 0x81A9D0, sizeof(char)); 
    aml->Unprot(libs.pGame + 0xA48230, sizeof(char)); 
    aml->Unprot(libs.pGame + 0x992230, sizeof(char)); //Red
        *(char*)(libs.pGame + 0x81A9D0) = 255;
        *(char*)(libs.pGame + 0xA48230) = 255;
        *(char*)(libs.pGame + 0x992230) = 255;

    aml->Unprot(libs.pGame + 0x81A9D1, sizeof(char)); 
    aml->Unprot(libs.pGame + 0xA48231, sizeof(char)); 
    aml->Unprot(libs.pGame + 0x992231, sizeof(char)); //Green
        *(char*)(libs.pGame + 0x81A9D1) = 0;
        *(char*)(libs.pGame + 0xA48231) = 0;
        *(char*)(libs.pGame + 0x992231) = 0;
    
    aml->Unprot(libs.pGame + 0x81A9D2, sizeof(char)); 
    aml->Unprot(libs.pGame + 0xA48232, sizeof(char)); 
    aml->Unprot(libs.pGame + 0x992232, sizeof(char)); //Blue
        *(char*)(libs.pGame + 0x81A9D2) = 0;
        *(char*)(libs.pGame + 0xA48232) = 0;
        *(char*)(libs.pGame + 0x992232) = 0;
}
void MarkerV(uintptr_t screen)
{

    aml->Unprot(libs.pGame + 0x81A9D0, sizeof(char)); 
    aml->Unprot(libs.pGame + 0xA48230, sizeof(char)); 
    aml->Unprot(libs.pGame + 0x992230, sizeof(char)); //Red
        *(char*)(libs.pGame + 0x81A9D0) = 255;
        *(char*)(libs.pGame + 0xA48230) = 255;
        *(char*)(libs.pGame + 0x992230) = 255;

    aml->Unprot(libs.pGame + 0x81A9D1, sizeof(char)); 
    aml->Unprot(libs.pGame + 0xA48231, sizeof(char)); 
    aml->Unprot(libs.pGame + 0x992231, sizeof(char)); //Green
        *(char*)(libs.pGame + 0x81A9D1) = 255;
        *(char*)(libs.pGame + 0xA48231) = 255;
        *(char*)(libs.pGame + 0x992231) = 255;
    
    aml->Unprot(libs.pGame + 0x81A9D2, sizeof(char)); 
    aml->Unprot(libs.pGame + 0xA48232, sizeof(char)); 
    aml->Unprot(libs.pGame + 0x992232, sizeof(char)); //Blue
        *(char*)(libs.pGame + 0x81A9D2) = 0;
        *(char*)(libs.pGame + 0xA48232) = 0;
        *(char*)(libs.pGame + 0x992232) = 0;
}
void MarkerVC(uintptr_t screen)
{
    /*252 138 242 228
252 138 242 228
252 138 242 228
252 138 242 255
252 138 242 192*/

    aml->Unprot(libs.pGame + 0x81A9D0, sizeof(char)); 
    aml->Unprot(libs.pGame + 0xA48230, sizeof(char)); 
    aml->Unprot(libs.pGame + 0x992230, sizeof(char)); //Red
        *(char*)(libs.pGame + 0x81A9D0) = 252;
        *(char*)(libs.pGame + 0xA48230) = 252;
        *(char*)(libs.pGame + 0x992230) = 252;

    aml->Unprot(libs.pGame + 0x81A9D1, sizeof(char)); 
    aml->Unprot(libs.pGame + 0xA48231, sizeof(char)); 
    aml->Unprot(libs.pGame + 0x992231, sizeof(char)); //Green
        *(char*)(libs.pGame + 0x81A9D1) = 138;
        *(char*)(libs.pGame + 0xA48231) = 138;
        *(char*)(libs.pGame + 0x992231) = 138;
    
    aml->Unprot(libs.pGame + 0x81A9D2, sizeof(char)); 
    aml->Unprot(libs.pGame + 0xA48232, sizeof(char)); 
    aml->Unprot(libs.pGame + 0x992232, sizeof(char)); //Blue
        *(char*)(libs.pGame + 0x81A9D2) = 242;
        *(char*)(libs.pGame + 0xA48232) = 242;
        *(char*)(libs.pGame + 0x992232) = 242;
}
void MarkerIII(uintptr_t screen)
{
    aml->Unprot(libs.pGame + 0x81A9D0, sizeof(char)); 
    aml->Unprot(libs.pGame + 0xA48230, sizeof(char)); 
    aml->Unprot(libs.pGame + 0x992230, sizeof(char)); //Red
        *(char*)(libs.pGame + 0x81A9D0) = 0;
        *(char*)(libs.pGame + 0xA48230) = 0;
        *(char*)(libs.pGame + 0x992230) = 0;

    aml->Unprot(libs.pGame + 0x81A9D1, sizeof(char)); 
    aml->Unprot(libs.pGame + 0xA48231, sizeof(char)); 
    aml->Unprot(libs.pGame + 0x992231, sizeof(char)); //Green
        *(char*)(libs.pGame + 0x81A9D1) = 0;
        *(char*)(libs.pGame + 0xA48231) = 0;
        *(char*)(libs.pGame + 0x992231) = 0;
    
    aml->Unprot(libs.pGame + 0x81A9D2, sizeof(char)); 
    aml->Unprot(libs.pGame + 0xA48232, sizeof(char)); 
    aml->Unprot(libs.pGame + 0x992232, sizeof(char)); //Blue
        *(char*)(libs.pGame + 0x81A9D2) = 255;
        *(char*)(libs.pGame + 0xA48232) = 255;
        *(char*)(libs.pGame + 0x992232) = 255;
}
void MarkerGrn(uintptr_t screen)
{
    aml->Unprot(libs.pGame + 0x81A9D0, sizeof(char)); 
    aml->Unprot(libs.pGame + 0xA48230, sizeof(char)); 
    aml->Unprot(libs.pGame + 0x992230, sizeof(char)); //Red
        *(char*)(libs.pGame + 0x81A9D0) = 0;
        *(char*)(libs.pGame + 0xA48230) = 0;
        *(char*)(libs.pGame + 0x992230) = 0;

    aml->Unprot(libs.pGame + 0x81A9D1, sizeof(char)); 
    aml->Unprot(libs.pGame + 0xA48231, sizeof(char)); 
    aml->Unprot(libs.pGame + 0x992231, sizeof(char)); //Green
        *(char*)(libs.pGame + 0x81A9D1) = 255;
        *(char*)(libs.pGame + 0xA48231) = 255;
        *(char*)(libs.pGame + 0x992231) = 255;
    
    aml->Unprot(libs.pGame + 0x81A9D2, sizeof(char)); 
    aml->Unprot(libs.pGame + 0xA48232, sizeof(char)); 
    aml->Unprot(libs.pGame + 0x992232, sizeof(char)); //Blue
        *(char*)(libs.pGame + 0x81A9D2) = 0;
        *(char*)(libs.pGame + 0xA48232) = 0;
        *(char*)(libs.pGame + 0x992232) = 0;
}
void MarkerWhite(uintptr_t screen)
{
    aml->Unprot(libs.pGame + 0x81A9D0, sizeof(char)); 
    aml->Unprot(libs.pGame + 0xA48230, sizeof(char)); 
    aml->Unprot(libs.pGame + 0x992230, sizeof(char)); //Red
        *(char*)(libs.pGame + 0x81A9D0) = 255;
        *(char*)(libs.pGame + 0xA48230) = 255;
        *(char*)(libs.pGame + 0x992230) = 255;

    aml->Unprot(libs.pGame + 0x81A9D1, sizeof(char)); 
    aml->Unprot(libs.pGame + 0xA48231, sizeof(char)); 
    aml->Unprot(libs.pGame + 0x992231, sizeof(char)); //Green
        *(char*)(libs.pGame + 0x81A9D1) = 255;
        *(char*)(libs.pGame + 0xA48231) = 255;
        *(char*)(libs.pGame + 0x992231) = 255;
    
    aml->Unprot(libs.pGame + 0x81A9D2, sizeof(char)); 
    aml->Unprot(libs.pGame + 0xA48232, sizeof(char)); 
    aml->Unprot(libs.pGame + 0x992232, sizeof(char)); //Blue
        *(char*)(libs.pGame + 0x81A9D2) = 255;
        *(char*)(libs.pGame + 0xA48232) = 255;
        *(char*)(libs.pGame + 0x992232) = 255;
}
void MarkerBlck(uintptr_t screen)
{
    aml->Unprot(libs.pGame + 0x81A9D0, sizeof(char)); 
    aml->Unprot(libs.pGame + 0xA48230, sizeof(char)); 
    aml->Unprot(libs.pGame + 0x992230, sizeof(char)); //Red
        *(char*)(libs.pGame + 0x81A9D0) = 0;
        *(char*)(libs.pGame + 0xA48230) = 0;
        *(char*)(libs.pGame + 0x992230) = 0;

    aml->Unprot(libs.pGame + 0x81A9D1, sizeof(char)); 
    aml->Unprot(libs.pGame + 0xA48231, sizeof(char)); 
    aml->Unprot(libs.pGame + 0x992231, sizeof(char)); //Green
        *(char*)(libs.pGame + 0x81A9D1) = 0;
        *(char*)(libs.pGame + 0xA48231) = 0;
        *(char*)(libs.pGame + 0x992231) = 0;
    
    aml->Unprot(libs.pGame + 0x81A9D2, sizeof(char)); 
    aml->Unprot(libs.pGame + 0xA48232, sizeof(char)); 
    aml->Unprot(libs.pGame + 0x992232, sizeof(char)); //Blue
        *(char*)(libs.pGame + 0x81A9D2) = 0;
        *(char*)(libs.pGame + 0xA48232) = 0;
        *(char*)(libs.pGame + 0x992232) = 0;
}
//AML plugin entrance
extern "C" void OnModLoad()
{
	ALOGI(GTAPLUGIN, "libMarkerStyle.so init...");
	
	pCfgRed = cfg->Bind("Red", 255, "Marker");
    pCfgGreen = cfg->Bind("Green", 255, "Marker");
    pCfgBlue = cfg->Bind("Blue", 0, "Marker");
    pCfgAlpha = cfg->Bind("Alpha", 255, "Marker");
    
    aml->Unprot(libs.pGame + 0x81A9D0, sizeof(char)); 

    aml->Unprot(libs.pGame + 0xA48230, sizeof(char)); 

    aml->Unprot(libs.pGame + 0x992230, sizeof(char)); //Red
        *(char*)(libs.pGame + 0x81A9D0) = pCfgRed->GetInt();
        *(char*)(libs.pGame + 0xA48230) = pCfgRed->GetInt();
        *(char*)(libs.pGame + 0x992230) = pCfgRed->GetInt();

    aml->Unprot(libs.pGame + 0x81A9D1, sizeof(char)); 
    aml->Unprot(libs.pGame + 0xA48231, sizeof(char)); 
    aml->Unprot(libs.pGame + 0x992231, sizeof(char)); //Green
        *(char*)(libs.pGame + 0x81A9D1) = pCfgGreen->GetInt();
        *(char*)(libs.pGame + 0xA48231) = pCfgGreen->GetInt();
        *(char*)(libs.pGame + 0x992231) = pCfgGreen->GetInt();
    
    aml->Unprot(libs.pGame + 0x81A9D2, sizeof(char)); 
    aml->Unprot(libs.pGame + 0xA48232, sizeof(char)); 
    aml->Unprot(libs.pGame + 0x992232, sizeof(char)); //Blue
        *(char*)(libs.pGame + 0x81A9D2) = pCfgBlue->GetInt();
        *(char*)(libs.pGame + 0xA48232) = pCfgBlue->GetInt();
        *(char*)(libs.pGame + 0x992232) = pCfgBlue->GetInt();
    
    aml->Unprot(libs.pGame + 0x34A7AA, sizeof(char)); 
    aml->Unprot(libs.pGame + 0x5BDF8C, sizeof(char)); 
    aml->Unprot(libs.pGame + 0x44227A, sizeof(char)); //Alpha
        *(char*)(libs.pGame + 0x34A7AA) = pCfgAlpha->GetInt();
        *(char*)(libs.pGame + 0x5BDF8C) = pCfgAlpha->GetInt();
        *(char*)(libs.pGame + 0x44227A) = pCfgAlpha->GetInt();

    sautils = (ISAUtils*)GetInterface("SAUtils");
    if(sautils != nullptr)
    {
    //Marker_Color_Settings
    sautils->AddSettingsTab("Marker_Color_Settings", "menu_mainsettings");
    
    //Marker_Color_Settings-Items
    sautils->AddSliderItem(Marker, "MarkerRed", pCfgRed->GetInt(), 0, 255, RedChanged, RedDrawed);
    sautils->AddSliderItem(Marker, "MarkerGreen", pCfgGreen->GetInt(), 0, 255, GreenChanged, GreenDrawed);
    sautils->AddSliderItem(Marker, "MarkerBlue", pCfgBlue->GetInt(), 0, 255, BlueChanged, BlueDrawed);
    sautils->AddSliderItem(Marker, "MarkerAlpha", pCfgAlpha->GetInt(), 0, 255, AlphaChanged, AlphaDrawed);
    
    //Marker_Preset
    sautils->AddSettingsTab("Marker_Preset", "menu_mainsettings");
    
    //Marker_Preset-Items
    sautils->AddButton(Preset, "Default", MarkerDefault);
    sautils->AddButton(Preset, "Gta V", MarkerV);
    sautils->AddButton(Preset, "Gta VC", MarkerVC);
    sautils->AddButton(Preset, "Gta III", MarkerIII);
    sautils->AddButton(Preset, "Green", MarkerGrn);
    sautils->AddButton(Preset, "White", MarkerWhite);
    sautils->AddButton(Preset, "Black", MarkerBlck);
    
    }
}