#pragma once

#include <Vorb/ui/IGameScreen.h>
#include <Vorb/Random.h>
#include <Vorb/RPC.h>
#include <Vorb/VorbPreDecl.inl>

#include "LoadMonitor.h"
#include "LoadBar.h"

class App;
class SoaState;
DECL_VG(class SpriteBatch; class SpriteFont);

class LoadScreen : public vui::IAppScreen<App> {
public:
    CTOR_APP_SCREEN_DECL(LoadScreen, App);
    ~LoadScreen();

    virtual i32 getNextScreen() const;
    virtual i32 getPreviousScreen() const;

    virtual void build();
    virtual void destroy(const vui::GameTime& gameTime);

    virtual void onEntry(const vui::GameTime& gameTime);
    virtual void onExit(const vui::GameTime& gameTime);

    virtual void update(const vui::GameTime& gameTime);
    virtual void draw(const vui::GameTime& gameTime);

    SoaState* getSoAState() const { return m_soaState.get(); }

private:
    void addLoadTask(const nString& name, const cString loadText, ILoadTask* task);

    // Game state
    std::unique_ptr<SoaState> m_soaState = nullptr;

    // Visualization Of Loading Tasks
    std::vector<LoadBar> _loadBars;
    vg::SpriteBatch* _sb;
    vg::SpriteFont* _sf;

    // Loading Tasks
    LoadMonitor _monitor;
    std::vector<ILoadTask*> _loadTasks;

    vcore::RPCManager m_glrpc; ///< Handles cross-thread OpenGL calls
};