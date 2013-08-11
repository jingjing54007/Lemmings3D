//====================== #INCLUDES ===================================
#include "BaseScreen.h"
#include <memory>
#include "Helpers/SpriteFont.h"
//====================================================================

class UIDockInterface;

//====================== MenuScreen Class ============================
// Description:
//		Screen Class for the main menu
// Last Modification: August 2013
// Glen De Cauwsemaecker
// www.glendc.com
//====================================================================

class ColissionEntity;

class MenuScreen: public BaseScreen
{
public:
	MenuScreen(void);
	virtual ~MenuScreen(void);

	virtual void Initialize();
	virtual void Update(const GameContext& context);
	virtual void Draw(const GameContext& context);

	virtual void BeginControl();
	virtual void EndControl();

	virtual void Activated();
	virtual void Deactivated();

private:
	shared_ptr<SpriteFont> m_pSpriteFont;
	UIDockInterface * m_MainMenuDock;

	// Disabling default copy constructor and default assignment operator.
	MenuScreen(const MenuScreen& yRef);									
	MenuScreen& operator=(const MenuScreen& yRef);
};