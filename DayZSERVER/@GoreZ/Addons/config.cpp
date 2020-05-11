class CfgPatches
{
	class GoreZ
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Scripts",
			"DZ_Data",
			"DZ_Weapons_Optics"
		};
	};
};
class CfgMods
{
	class GoreZ
	{
		dir="GoreZ";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="GoreZ";
		credits="mung";
		author="mung";
		authorID="0";
		version="1.0";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"World",
			"Game"
		};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"GoreZ/3_game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"GoreZ/4_world"
				};
			};
		};
	};
};
class CfgSoundCurves
{
	class CfgSoundCurvesFliesbuzzing
	{
		points[]=
		{
			{0,1},
			{0.1,0.98000002},
			{0.2,0.92000002},
			{0.30000001,0.80000001},
			{0.40000001,0.64999998},
			{0.5,0.5},
			{0.60000002,0.34999999},
			{0.69999999,0.2},
			{0.80000001,0.079999998},
			{0.89999998,0.02},
			{1,0}
		};
	};
};
class CfgSound3DProcessors
{
	class default3DProcessingFliesbuzzing
	{
		type="emitter";
		innerRange=15;
		range=10;
		radius=5;
		volume=8;
	};
	class default3DProcessingTypeSpeech
	{
		type="emitter";
		innerRange=15;
		range=10;
		radius=5;
		volume=0.30118722;
	};
};
class CfgSoundShaders
{
	class base_SoundShaderFlies
	{
		range=10;
		rangeCurve="CfgSoundCurvesFliesbuzzing";
		volume=8;
	};
	class Fliesbuzzing_SoundShader: base_SoundShaderFlies
	{
		samples[]=
		{
			
			{
				"GoreZ\sounds\FliesBuzzing",
				1
			}
		};
		volume=8;
		range=10;
		rangeCurve="CfgSoundCurvesFliesbuzzing";
	};
};
class CfgSoundSets
{
	class base_SoundSet
	{
		sound3DProcessingType="default3DProcessingFliesbuzzing";
		spatial=1;
		doppler=0;
		loop=1;
	};
	class base_SoundSetSpeech
	{
		sound3DProcessingType="default3DProcessingTypeSpeech";
		spatial=1;
		doppler=0;
		loop=0;
	};
	class FliesBuzzing_SoundSet: base_SoundSet
	{
		soundShaders[]=
		{
			"Fliesbuzzing_SoundShader"
		};
		volume=8;
	};
};
