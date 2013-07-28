#pragma once

//====================== #INCLUDES ===================================
#include "Helpers/stdafx.h" 
#include "UserSettings.h"
//====================================================================

//====================== Player Class ==============
// Description:
//		Player account: containing preferences of the user.
// Last Modification: 05/06/2013
// Copyright Glen De Cauwsemaecker
// www.glendc.com
//====================================================================

struct GameContext;
class PickComponent;
class UIDockInterface;
class GameScene;
class GameObject;

class Player
{
public:
	explicit Player(const tstring & name, GameScene *pGame);
	~Player();

	const tstring & GetName() const { return m_Name; }

	void Update(const GameContext & context);
	void UpdateMenu(const GameContext & context);
	void DrawMenu(const GameContext & context);
	
	
	template <typename T>
	T GetSetting(const tstring & name)
	{
		return m_pSettings->GetSetting<T>(name);
	}

	template <typename T>
	void SetSetting(const tstring & name, const T & setting)
	{
		m_pSettings->SetSetting<T>(name, setting);
	}

	void Save();

private:
	tstring m_Name;
	UserSettings * m_pSettings;

	GameObject *m_pSelectedObject;
	GameObject *m_pPlayerObject;
	PickComponent *m_pPickComponent;
	UIDockInterface *m_pSelectionMenu;

	// -------------------------
	// Disabling default copy constructor and default 
	// assignment operator.
	// -------------------------
	Player(const Player& t);
	Player& operator=(const Player& t);
};