#pragma once
//====================== #INCLUDES ===================================
#include "ColissionEntity.h"
//====================================================================

//====================== KeyObject Class =============================
// Description:
//		KeyObject
// Last Modification: August 2013
// Glen De Cauwsemaecker
// www.glendc.com
//====================================================================

class RigidBodyComponent;
class PhysicsMaterial;
class BaseColliderComponent;

class KeyObject : public ColissionEntity
{
private:

public:
	KeyObject();
	virtual ~KeyObject();

	virtual void Initialize();

protected:
	virtual void InitializeRigidBody();

private:
	static const int MODEL_ID = 1;

	// Disabling default copy constructor and default assignment operator.
	KeyObject(const KeyObject& yRef);									
	KeyObject& operator=(const KeyObject& yRef);
};