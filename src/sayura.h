//
// Copyright (C) 2012~2012 by Yichao Yu
// Copyright (C) 2020~2020 by CSSlayer
// wengxt@gmail.com
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2, or (at your option)
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
#ifndef _FCITX5_SAYURA_SAYURA_H_
#define _FCITX5_SAYURA_SAYURA_H_

#include <fcitx/addonfactory.h>
#include <fcitx/addonmanager.h>
#include <fcitx/inputcontextproperty.h>
#include <fcitx/inputmethodengine.h>
#include <fcitx/instance.h>

namespace fcitx {

class SayuraState;

class SayuraEngine final : public InputMethodEngine {
public:
    SayuraEngine(Instance *instance);
    ~SayuraEngine();

    void activate(const InputMethodEntry &entry,
                  InputContextEvent &event) override;
    void keyEvent(const InputMethodEntry &entry, KeyEvent &keyEvent) override;
    void reset(const InputMethodEntry &entry,
               InputContextEvent &event) override;
    void deactivate(const fcitx::InputMethodEntry &,
                    fcitx::InputContextEvent &event) override;

private:
    Instance *instance_;
    FactoryFor<SayuraState> factory_;
};

class SayuraFactory : public AddonFactory {
public:
    AddonInstance *create(AddonManager *manager) override {
        return new SayuraEngine(manager->instance());
    }
};

} // namespace fcitx

#endif // _FCITX5_SAYURA_SAYURA_H_
