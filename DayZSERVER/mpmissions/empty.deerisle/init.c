//BBP Cement Mixers -Begin Part1-
void SpawnObject( string type, vector position, vector orientation )
{
    auto obj = GetGame().CreateObject( type, position );
    obj.SetPosition( position );
    obj.SetOrientation( orientation );
    //Force collision update
    vector roll = obj.GetOrientation();
    roll [ 2 ] = roll [ 2 ] - 1;
    obj.SetOrientation( roll );
    roll [ 2 ] = roll [ 2 ] + 1;
    obj.SetOrientation( roll );
}

void main()
{
	//BBP Cement Mixers -Begin Part2- !!! REMOVE THIS PART AFTER THE FIRST SERVER BOOT, OR YOU WILL GET DUPLICATE MIXERS !!!
	//SpawnObject("BBP_Cement_Mixer", "10054.915039 5.998347 1824.814575", "140.320999 0.000000 0.000000");				//ELEKTRO
	//SpawnObject("BBP_Cement_Mixer", "8025.974121 14.320039 3112.555664", "-134.317001 0.000000 -0.000001");				//CHERNO
	//SpawnObject("BBP_Cement_Mixer", "2259.967285 185.386688 5228.343262", "31.421862 0.000000 0.000000");				//ZELNO
	//SpawnObject("BBP_Cement_Mixer", "13320.810547 9.184664 6120.320313", "0.488000 0.002672 1.681928");					//SOLNICHY
	//SpawnObject("BBP_Cement_Mixer", "11916.333008 28.763134 14286.380859", "105.104500 0.000000 0.000000");				//NOVO
	//SpawnObject("BBP_Cement_Mixer", "8005.100098 129.204407 12594.500000", "-12.629600 -0.734632 0.240260");			//UNKNOWN
	//SpawnObject("BBP_Cement_Mixer", "5216.392578 340.970093 9886.897461", "-109.342987 -0.042234 0.007777");			//NWAF1
	//SpawnObject("BBP_Cement_Mixer", "2943.952881 220.784470 12637.526367", "-158.010208 0.018145 -0.044932");			//UNKNOWN
	//BBP Cement Mixers -End Part2- !!! REMOVE THIS PART AFTER THE FIRST SERVER BOOT, OR YOU WILL GET DUPLICATE MIXERS !!!


	//INIT WEATHER BEFORE ECONOMY INIT------------------------
	Weather weather = g_Game.GetWeather();

	weather.MissionWeather(false);    // false = use weather controller from Weather.c

	weather.GetOvercast().Set( Math.RandomFloatInclusive(0.4, 0.6), 1, 0);
	weather.GetRain().Set( 0, 0, 1);
	weather.GetFog().Set( Math.RandomFloatInclusive(0.05, 0.1), 1, 0);

	//INIT ECONOMY--------------------------------------
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

	//DATE RESET AFTER ECONOMY INIT-------------------------
	int year, month, day, hour, minute;
	int reset_month = 9, reset_day = 20;
	GetGame().GetWorld().GetDate(year, month, day, hour, minute);

	if ((month == reset_month) && (day < reset_day))
	{
		GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
	}
	else
	{
		if ((month == reset_month + 1) && (day > reset_day))
		{
			GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
		}
		else
		{
			if ((month < reset_month) || (month > reset_month + 1))
			{
				GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
			}
		}
	}
	
   //CEApi TestHive = GetCEApi();
   //TestHive.ExportProxyProto();
   //TestHive.ExportProxyData( "8096 0 8096", 16384 );
   //TestHive.ExportClusterData() ;
}

class CustomMission: MissionServer
{
	void SetRandomHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			int rndHlt = Math.RandomInt(55,100);
			itemEnt.SetHealth("","",rndHlt);
		}
	}

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");//Creates random player
		Class.CastTo(m_player, playerEnt);

		GetGame().SelectPlayer(identity, m_player);

		return m_player;
	}

	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		EntityAI itemTop;
		EntityAI itemEnt;
		ItemBase itemBs;
		float rand;

		itemTop = player.FindAttachmentBySlotName("Body");

		if ( itemTop )
		{
			itemEnt = itemTop.GetInventory().CreateInInventory("Rag");
			if ( Class.CastTo(itemBs, itemEnt ) )
				itemBs.SetQuantity(4);

			SetRandomHealth(itemEnt);

			string chemlightArray[] = { "Chemlight_White", "Chemlight_Yellow", "Chemlight_Green", "Chemlight_Red" };
			int rndIndex = Math.RandomInt(0, 4);
			itemEnt = itemTop.GetInventory().CreateInInventory(chemlightArray[rndIndex]);
			SetRandomHealth(itemEnt);

			rand = Math.RandomFloatInclusive(0.0, 1.0);
			if ( rand < 0.35 )
				itemEnt = player.GetInventory().CreateInInventory("Apple");
			else if ( rand > 0.65 )
				itemEnt = player.GetInventory().CreateInInventory("Pear");
			else
				itemEnt = player.GetInventory().CreateInInventory("Plum");

			SetRandomHealth(itemEnt);
		}
	}
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}