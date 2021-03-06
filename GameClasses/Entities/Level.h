#pragma once

//====================== #INCLUDES ===================================
#include "Helpers/stdafx.h"
#include "Helpers/D3DUtil.h"
#include "Helpers/GeneralStructs.h"
//====================================================================

//====================== Level Class =========================
// Description:
//		Class representing a level in the Lemmings 3D Game
// Last Modification: July 2013
// Glen De Cauwsemaecker
// www.glendc.com
//====================================================================

class XMLParser;
class InstancedObject;
class PhysicsCube;
class GameEntity;
class ColissionEntity;
class SkyBox;
class PortalEnter;
class PortalExit;

class Level 
{
public:
	Level(const tstring & file, GameScene * pScene);
	~Level(void);

	void Initialize();

	void Draw(const GameContext& context);
	void Update(const GameContext& context);

	const tstring & GetLevelname() const { return m_Name; }

	const D3DXVECTOR3 & GetSnapPosition(const D3DXVECTOR3 & pos) const;
	void GetEnvironment(std::vector<D3DXVECTOR3> & envVector) const;
	const std::vector<D3DXVECTOR3> & GetEnvironment() const;

	const UINT & GetSizeXY() const { return m_SizeXZ; }
	const UINT & getSizeXYZ() const { return m_SizeXYZ; }
	const UINT & Getwidth() const { return m_Width; }
	const UINT & GetHeight() const { return m_Height; }

	const float & GetMinDepth() const { return m_MinDepth; }
	const float & GetMaxDepth() const { return m_MaxDepth; }
	const D3DXVECTOR3 & Getoffset() const { return m_Offset; }
	const D3DXVECTOR3 & GetCenter() const { return m_Center; }

	void AddEnvironmentCube(const D3DXVECTOR3 & pos, const int id);
	bool RemoveEnvironmentCube(const D3DXVECTOR3 & pos);
	bool PaintEnvironmentCube(const D3DXVECTOR3 & pos, const int id, const bool editInstance = true);
	void RecheckEnvironment();

	void Save();

	float GetLowerDepth();
	inline float GetCurrentDepth() const { return m_CurrentDepth; }
	float GetHigherDepth();

	void AddSpecialObject(UINT id, const D3DXVECTOR3 & pos);
	void CreatePortalEntrance(const D3DXVECTOR3 & pos);
	void CreatePortalExit(const D3DXVECTOR3 & pos);

	bool AddColissionEntity(ColissionEntity * pEntity);
	bool AddGameEntity(GameEntity * pEntity);
	bool AddColissionEntity(UINT model_id, const D3DXVECTOR3 & pos);
	bool AddGameEntity(UINT model_id, const D3DXVECTOR3 & pos);
	bool RemoveColissionEntity(ColissionEntity * pEntity);
	bool RemoveColissionEntity(const D3DXVECTOR3 & pos);
	void ClearColissionEntities();

	bool IsLegalToBuild(const D3DXVECTOR3 & pos);

	void EnterEditor();
	void LeaveEditor();

private:
	void CreateBlocks();
	void PaintBlocks();
	void CreateObjects();
	inline void IncreaseMinDepth() { m_MinDepth += m_HeigthDifference; CheckCurrentDepth(); } 
	inline void DecreaseMinDepth() { m_MinDepth -= m_HeigthDifference; CheckCurrentDepth(); } 
	inline void IncreaseMaxDepth() { m_MaxDepth += m_HeigthDifference; CheckCurrentDepth(); } 
	inline void DecreaseMaxDepth() { m_MaxDepth -= m_HeigthDifference; CheckCurrentDepth(); } 
	void CheckCurrentDepth();
	ColissionEntity * CreateColissionEntity(UINT model_id, const D3DXVECTOR3 & pos);
	GameEntity * CreateGameEntity(UINT model_id, const D3DXVECTOR3 & pos);

	tstring m_LevelXMLFileName;
	InstancedObject * m_pInstancedObject;

	UINT m_Width, m_Height, m_SizeXZ, m_SizeXYZ;
	float m_MinDepth, m_MaxDepth, m_CurrentDepth, m_HeigthDifference;
	tstring m_Name;

	D3DXVECTOR3 m_Offset,
				m_Center;

	XMLParser * m_pLevelParser;
	std::vector<PhysicsCube*> m_pPhysicsCubeVec;

	std::vector<ColissionEntity*> m_ColissionEntities;
	std::vector<GameEntity*> m_GameEntities;

	SkyBox * m_pSkyBox;

	PortalEnter * m_pPortalEntrance;
	PortalExit * m_pPortalExit;

	GameScene * m_pGame;

	// Disabling default copy constructorand default assignment operator
	Level(const Level& t);
	Level& operator=(const Level& t);
};

