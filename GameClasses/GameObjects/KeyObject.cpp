//================================ INCLUDES =========================
#include "KeyObject.h"
#include "OverlordComponents.h"
#include "../Managers/ParameterManager.h"
#include "../Entities/ParameterClass.h"
#include "../XML/XMLConverter.h"
#include "../Materials/BaseModelMaterial.h"
#include "../Lib/GlobalParameters.h"
#include "../GameObjects/ColissionEntity.h"
#include "../GameObjects/Lemming.h"
//===================================================================

KeyObject::KeyObject()
	: ColissionEntity (
		MaterialType::MatCustom)
{
	auto & container = ParameterManager::GetInstance()->CreateOrGet(_T("Models"));

	tstring name = XMLConverter::ConvertToTString(MODEL_ID);

	tstringstream strstr;
	strstr << _T("./Resources/Lemmings3D/models/") << container.GetChildParameter<tstring>(name, _T("MODEL"));
	m_VisualResourcePath = strstr.str();
	strstr.str(_T(""));
	strstr << _T("./Resources/Lemmings3D/textures/") << container.GetChildParameter<tstring>(name, _T("TEXTURE"));
	tstring texture_path = strstr.str();

	BaseModelMaterial * pMaterial = new BaseModelMaterial();
	pMaterial->SetDiffuse(texture_path);
	pMaterial->SetAlpha(1.0f);
	m_pVisualMaterial = pMaterial;	

	strstr.str(_T(""));
	strstr << _T("./Resources/Lemmings3D/models/") << container.GetChildParameter<tstring>(name, _T("CONVEX"));
	tstring collission_path = strstr.str();

	AddMeshCollider(collission_path, true, false, true);

	m_Name = _T("Key");
}

KeyObject::~KeyObject()
{

}

void KeyObject::Initialize()
{
	ColissionEntity::Initialize();
}

void KeyObject::InitializeRigidBody()
{
	ColissionEntity::InitializeRigidBody();
	m_pRigidBody->SetOnTriggerCallBack([this](RigidBodyComponent* trigger, RigidBodyComponent* receiver, TriggerAction action)
	{
		if(action == TriggerAction::ENTER)
		{
			auto owner = dynamic_cast<Lemming*>(receiver->GetParentObject());
			if(owner != nullptr)
			{
				owner->GiveKey(this);
				Translate(D3DXVECTOR3(-9999,-9999,-999));
			}
		}
	});
	m_pRigidBody->SetStatic(true);
}