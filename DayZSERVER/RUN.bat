@echo off
    :: DEFINE the following variables where applicable to your install
    SET SteamLogin=fajny_serwer AdamKul12
    SET DayZBranch=223350
    SET DayZServerPath="C:\Users\adamk\Desktop\DayZSERVERS\DayZSERVER"
    SET SteamCMDPath="C:\Users\adamk\Desktop\DayZSERVERS\SteamCMD"
    :: _______________________________________________________________
 
echo.
echo     Checking for DayZ server update
echo        DayZ Server Dir: %DayZServerPath%
echo        SteamCMD Dir: %SteamCMDPath%
echo.
%SteamCMDPath%\steamcmd.exe +login %SteamLogin% +force_install_dir %DayZServerPath% +"app_update %DayZBranch%" +quit
echo .
echo     Your DayZ server is up to date
 
start DayZServer_x64.exe -instanceId=1 -config=serverDZ.cfg -profiles=Profile -port=2302 -cpuCount=4 -noFilePatching -dologs -adminlog -freezecheck -mod=@BuilderItems;@ArmaWeaponPack;@BuildAnywhere;@Cl0ud'sMilitaryGear;@Ear-Plugs;@FlipTransport;@GoreZ;@ModularVestSystem;@MoreGuns;@MosinScope;@MunghardsItempack;@NoVehicleDamage;@VAZ-2107;@CF;@MoreFood;@LumberJack;@PsychoDayZVehicleExpansion;@ZomBerryAdminTools;